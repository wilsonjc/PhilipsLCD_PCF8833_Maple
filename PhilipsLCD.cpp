// This library has been created by Markos Kyritsis. The stuff is all copyleft, so go ahead and do whatever you like
// with it. Please contribute to the community and upload all changes to the arduino playground for everyone else to 
// use. Enjoy!


#include "PhilipsLCD.h"
#include "Image.h"
#include <stdint.h>
#include "WProgram.h"

HardwareSPI Spi(2);

 PhilipsLCD::PhilipsLCD(int pinRST, int CS, int MISO, int MOSI, int SCLK){
//  get all the pin values in to the 
this->pinRST=pinRST;
this->CS= CS;
this->MISO=MISO;
this->MOSI=MOSI;
this->SCLK=SCLK;

//   The SPI port we will be using
  Spi.begin(SPI_4_5MHZ , MSBFIRST, 0);   		     // starts the SPI port

}

void PhilipsLCD::LCDClear(int color)	// Clear the whole screen with the specified colour
{

		LCDCommand(0x2B);
		LCDData(0);
		LCDData(132);
		LCDCommand(0x2A);
		LCDData(0);
		LCDData(132);
		LCDCommand(0x2C);
	for(int i=0; i < (132*132)/2; i++)
	{
		LCDData((color>>4)&0x00FF);
		LCDData(((color&0x0F)<<4)|(color>>8));
		LCDData(color&0x0FF);
	}
}



void PhilipsLCD::LCDInit(void)	// Initialise the screen
{
LCDCommand(0x11);
LCDCommand(0x03);
LCDCommand(0x21);
LCDCommand(0x36);
LCDData(0xC8);
LCDCommand(0x3A);
LCDCommand(0x25);
LCDData(0x30);	
LCDCommand(0x00);

LCDCommand(0x29);

}

void PhilipsLCD::LCDCommand(unsigned char data) // Send a hex command through the serial port (MOSI 0 first)
{

unsigned char temp[2]={0b0000,data};    // 
digitalWrite(CS, LOW);		// disable CS
Spi.send(temp,sizeof(temp));
digitalWrite(CS, HIGH);


}

void PhilipsLCD::LCDData(unsigned char data) // Send hex data through the serial port (MOSI 1 first)
{

unsigned char temp[2]={0b0001,data};     
digitalWrite(CS, LOW);		// disable CS
Spi.send(temp,sizeof(temp));
digitalWrite(CS, HIGH);

}

void PhilipsLCD::DrawPixel(int color, unsigned char x, unsigned char y) // 12bit pixel information FORMAT: RGB, four bits for each. MAX = FFF MIN = 000
{
		LCDCommand(0x2B);   // x start
		LCDData(x);
		LCDData(132);
  
		LCDCommand(0x2A);   // y start
		LCDData(y);
		LCDData(132);
  
		LCDCommand(0x2C);    // write
		
		LCDData((unsigned char)((color>>4)&0x00FF));
		LCDData((unsigned char)(((color&0x0F)<<4)|0x00));
}


void PhilipsLCD::DrawCircle(int colour, uint8_t x0, uint8_t y0, uint8_t radius)  //Midpoint circle algorithm
  {
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;
 
    DrawPixel(colour,x0, y0 + radius);
    DrawPixel(colour,x0, y0 - radius);
    DrawPixel(colour,x0 + radius, y0);
    DrawPixel(colour,x0 - radius, y0);
 
    while(x < y)
    {
      if(f >= 0) 
      {
        y--;
        ddF_y += 2;
        f += ddF_y;
      }
      x++;
      ddF_x += 2;
      f += ddF_x;    
      DrawPixel(colour,x0 + x, y0 + y);
      DrawPixel(colour,x0 - x, y0 + y);
      DrawPixel(colour,x0 + x, y0 - y);
      DrawPixel(colour,x0 - x, y0 - y);
      DrawPixel(colour,x0 + y, y0 + x);
      DrawPixel(colour,x0 - y, y0 + x);
      DrawPixel(colour,x0 + y, y0 - x);
      DrawPixel(colour,x0 - y, y0 - x);
    }
}



void  PhilipsLCD::DrawBrLine(int colour, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) { // Bresenham Line Algorithm
   int Dx = x1 - x0; 
   int Dy = y1 - y0;
   int steep = (abs(Dy) >= abs(Dx));
   if (steep) {

int a = x0;
int b = y0;
x0=b;
y0=a;

 a = x1;
 b = y1;
x1=b;
y1=a;

       // recompute Dx, Dy after swap
       Dx = x1 - x0;
       Dy = y1 - y0;
   }
   int xstep = 1;
   if (Dx < 0) {
       xstep = -1;
       Dx = -Dx;
   }
   int ystep = 1;
   if (Dy < 0) {
       ystep = -1;		
       Dy = -Dy; 
   }
   int TwoDy = 2*Dy; 
   int TwoDyTwoDx = TwoDy - 2*Dx; // 2*Dy - 2*Dx
   int E = TwoDy - Dx; //2*Dy - Dx
   int y = y0;
   int xDraw, yDraw;	
   for (int x = x0; x != x1; x += xstep) {		
       if (steep) {			
           xDraw = y;
           yDraw = x;
       } else {			
           xDraw = x;
           yDraw = y;
       }
       // plot
       DrawPixel(colour,xDraw, yDraw);
       // next
       if (E > 0) {
           E += TwoDyTwoDx; //E += 2*Dy - 2*Dx;
           y = y + ystep;
       } else {
           E += TwoDy; //E += 2*Dy;
       }
   }
}

void PhilipsLCD::FillRectangle(int colour, uint8_t x0, uint8_t y0, uint8_t width, uint8_t height)
{
for (uint8_t i = y0+1; i < y0+height; i++) {
DrawBrLine(colour, x0, i, x0+width, i);
}

}

void PhilipsLCD::DrawRectangle(int colour, uint8_t x0, uint8_t y0, uint8_t width, uint8_t height)
{
// Draw Top side
DrawBrLine(colour,x0, y0, x0+width+1, y0);

// Draw Bottom side 
DrawBrLine(colour,x0, y0+height, x0+width+1, y0+height);

// Now the sides
for (uint8_t i = y0+1; i < y0+height; i++) {
DrawPixel(colour,x0,i);
DrawPixel(colour,x0+width,i);
}
}

void PhilipsLCD::DrawBitmap(int xpos, int ypos) {
int count = 0;
for (int j = 0; j < sheight; j++) {
for (int i = 0; i < swidth; i++) {
DrawPixel(  header_data[count],xpos+i,ypos+j);
count++;
}
}

}


//PhilipsLCD LCDP = PhilipsLCD();

