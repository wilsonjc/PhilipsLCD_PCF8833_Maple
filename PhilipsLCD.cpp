// This library has been created by Markos Kyritsis. The stuff is all copyleft, so go ahead and do whatever you like
// with it. Please contribute to the community and upload all changes to the arduino playground for everyone else to 
// use. Enjoy!


#include "PhilipsLCD.h"
#include "Image.h"
#include <stdint.h>
#include "WProgram.h"
#include "Fonts.h"

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

		LCDCommand(PASET);
		LCDData(0);
		LCDData(132);
		LCDCommand(CASET);
		LCDData(0);
		LCDData(132);
		LCDCommand(RAMWR);
	for(int i=0; i < (132*132)/2; i++)
	{
		LCDData((color>>4)&0x00FF);
		LCDData(((color&0x0F)<<4)|(color>>8));
		LCDData(color&0x0FF);
	}
}



void PhilipsLCD::LCDInit(void)	// Initialise the screen
{
LCDCommand(SLEEPOUT);
LCDCommand(BSTRON);
LCDCommand(INVON);
LCDCommand(MADCTL);
LCDData(RDTEMP);
LCDCommand(COLMOD);
LCDCommand(SETCON);
LCDData(PTLAR);	
LCDCommand(NOP);

LCDCommand(DISPON);

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
		LCDCommand(PASET);   // x start
		LCDData(x);
		LCDData(132);
  
		LCDCommand(CASET);   // y start
		LCDData(y);
		LCDData(132);
  
		LCDCommand(RAMWR);    // write
		
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


//  *****************************************************************************
//   						LCDPutChar.c
// 
//     Draws an ASCII character at the specified (x,y) address and color
//     
//	   Inputs:	  c       =   character to be displayed   	  
//				  x       =   row address (0 .. 131)
//				  y       =   column address  (0 .. 131)
//				  size    =   font pitch (SMALL, MEDIUM, LARGE)
//		          fcolor  =   12-bit foreground color value		rrrrggggbbbb
//		          bcolor  =   12-bit background color value		rrrrggggbbbb
//
//
//	   Returns:   nothing  
//
//  Notes:  Here's an example to display "E" at address (20,20)
//
//			LCDPutChar('E', 20, 20, MEDIUM, WHITE, BLACK);
//
//					 (27,20)        (27,27)
//						|             |
//						|             |
//				     ^	V             V
//				     :  _ # # # # # # #   0x7F
//				     :  _ _ # # _ _ _ #   0x31
//				     :  _ _ # # _ # _ _   0x34
//				     x  _ _ # # # # _ _   0x3C
//				     :  _ _ # # _ # _ _   0x34
//				     :  _ _ # # _ _ _ #   0x31
//				     :  _ # # # # # # #   0x7F
//				     :  _ _ _ _ _ _ _ _   0x00
//
//						------y----------->
//						^             ^
//						|             |
//						|             |
//					 (20,20)       (20,27)
//
//
//		The most efficient way to display a character is to make use of the "wrap-around" feature
//		of the Philips PCF8833 LCD controller chip.	
//
//		Assume that we position the character at (20, 20)  that's a  (row, col) specification.
//		With the row and column address set commands, you can specify an 8x8 box for the SMALL and MEDIUM
//		characters or a 16x8 box for the LARGE characters.
//
//			LCDCommand(PASET);		// set the row drawing limits
//			LCDData(20);			//
//			LCDData(27);			// limit rows to (20, 27)
// 
//			LCDCommand(CASET);		// set the column drawing limits
//			LCDData(20);			// 
//			LCDData(27);			// limit columns to (20,27)
//
//		When the algorithm completes col 27, the column address wraps back to 20
//		At the same time, the row address increases by one (this is done by the controller)
//
//		We walk through each row, two pixels at a time. The purpose is to create three
//		data bytes representing these two pixels in the following format (as specified by Philips
//		for RGB 4 : 4 : 4 format (see page 62 of PCF8833 controller manual).
//
//			Data for pixel 0:  RRRRGGGGBBBB
//			Data for Pixel 1:  RRRRGGGGBBBB
//
//			LCDCommand(RAMWR);				// start a memory write (96 data bytes to follow)
//
//			LCDData(RRRRGGGG);				// first pixel, red and green data
//			LCDData(BBBBRRRR);				// first pixel, blue data; second pixel, red data
//			LCDData(GGGGBBBB);				// second pixel, green and blue data
//				:
//    	and so on until all pixels displayed!
//				:
//			LCDCommand(NOP);				// this will terminate the RAMWR command
//
//
//  	Author:  James P Lynch    July 7, 2007
//  ***************************************************************************** 
void PhilipsLCD::LCDPutChar(char c, int  x, int  y, int size, int fColor, int bColor) {
	
	extern const unsigned char FONT6x8[97][8];
	extern const unsigned char FONT8x8[97][8];
	extern const unsigned char FONT8x16[97][16];
		
	int					i,j;
	unsigned int		nCols;
	unsigned int		nRows;
	unsigned int		nBytes;
	unsigned char		PixelRow;
	unsigned char		Mask;
	unsigned int		Word0;
	unsigned int		Word1;
	unsigned char		*pFont;
	unsigned char		*pChar;
	unsigned char		*FontTable[] = {(unsigned char *)FONT6x8, (unsigned char *)FONT8x8, (unsigned char *)FONT8x16}; 
	
	// get pointer to the beginning of the selected font table
	pFont = (unsigned char *)FontTable[size];	
	
	// get the nColumns, nRows and nBytes
	nCols = *pFont;
	nRows = *(pFont + 1);
	nBytes = *(pFont + 2);

	// get pointer to the last byte of the desired character
	pChar = pFont + (nBytes * (c - 0x1F)) + nBytes - 1;
	
	// Row address set  (command 0x2B)
	LCDCommand(PASET);
	LCDData(x);
	LCDData(x + nRows - 1);
  
	// Column address set  (command 0x2A)
	LCDCommand(CASET);
	LCDData(y);
	LCDData(y + nCols - 1);
	
	// WRITE MEMORY
	LCDCommand(RAMWR);
	
	// loop on each row, working backwards from the bottom to the top
	for (i = nRows - 1; i >= 0; i--) {
		
		// copy pixel row from font table and then decrement row
		PixelRow = *pChar--;
	
		// loop on each pixel in the row (left to right)
		// Note: we do two pixels each loop
		Mask = 0x80;
		for (j = 0; j < nCols; j += 2) {
		
			// if pixel bit set, use foreground color; else use the background color
			// now get the pixel color for two successive pixels
			if ((PixelRow & Mask) == 0)
				Word0 = bColor;
			else
				Word0 = fColor;
			Mask = Mask >> 1;
			if ((PixelRow & Mask) == 0)
				Word1 = bColor;
			else
				Word1 = fColor;
			Mask = Mask >> 1;
			
			// use this information to output three data bytes
			LCDData((Word0 >> 4) & 0xFF);
			LCDData(((Word0 & 0xF) << 4) | ((Word1 >> 8) & 0xF));
			LCDData(Word1 & 0xFF);
		}	
	}
	// terminate the Write Memory command
	LCDCommand(NOP);	
}



//  *************************************************************************************************
//   						LCDPutStr.c
// 
//     Draws a null-terminates character string at the specified (x,y) address, size and color
//     
//	   Inputs:	  pString =   pointer to character string to be displayed   	  
//				  x       =   row address (0 .. 131)
//				  y       =   column address  (0 .. 131)
//				  Size    =   font pitch (SMALL, MEDIUM, LARGE)
//		          fColor  =   12-bit foreground color value             rrrrggggbbbb
//		          bColor  =   12-bit background color value             rrrrggggbbbb
//
//
//	   Returns:   nothing  
//
//  Notes:  Here's an example to display "Hello World!" at address (20,20)
//
//			LCDPutChar("Hello World!", 20, 20, LARGE, WHITE, BLACK);
//
//
//  	Author:  James P Lynch    July 7, 2007
//  ************************************************************************************************* 
void PhilipsLCD::LCDPutStr(char *pString, int  x, int  y, int Size, int fColor, int bColor) {
						
	// loop until null-terminator is seen
	while (*pString != 0x00) {

		// draw the character
		LCDPutChar(*pString++, x, y, Size, fColor, bColor);	

		// advance the y position
		if (Size == SMALL)
			y = y + 6;
		else if (Size == MEDIUM)
			y = y + 8;
		else
			y = y + 8;
		
		// bail out if y exceeds 131
		if (y > 131) break;
	}
}


