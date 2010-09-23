// This library has been created by Markos Kyritsis. The stuff is all copyleft, so go ahead and do whatever you like
// with it. Please contribute to the community and upload all changes to the arduino playground for everyone else to 
// use. Enjoy!
#ifndef	PhilipsLCD_h

#define PhilipsLCD_h
#include <stdint.h>
#include "WProgram.h"


class PhilipsLCD {

private:

typedef unsigned char byte;

//   LCD display IO pins  
int pinRST;
int CS;
int MISO;
int MOSI;
int SCLK;

public:


PhilipsLCD(int pinRST, int CS, int MISO, int MOSI, int SCLK);


void LCDCommand(unsigned char data);
void LCDData(unsigned char data);
void LCDInit(void);
void LCDClear(int color);
void DrawPixel(int color, unsigned char x, unsigned char y);
void DrawCircle(int colour, uint8_t x0, uint8_t y0, uint8_t radius);
void DrawBrLine(int colour, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1); 
void FillRectangle(int colour, uint8_t x0, uint8_t y0, uint8_t width, uint8_t height);
void DrawRectangle(int colour, uint8_t x0, uint8_t y0, uint8_t width, uint8_t height);
void DrawBitmap(int xpos, int ypos);



};
extern PhilipsLCD LCDP;    
#endif
