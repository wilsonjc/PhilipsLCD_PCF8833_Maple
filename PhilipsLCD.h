// This library has been created by Markos Kyritsis. The stuff is all copyleft, so go ahead and do whatever you like
// with it. Please contribute to the community and upload all changes to the arduino playground for everyone else to 
// use. Enjoy!
#ifndef	PhilipsLCD_h

#define PhilipsLCD_h
#include <stdint.h>
#include "WProgram.h"


//  *****************************************************************************
//			LCD Include File for Philips PCF8833 STN RGB- 132x132x3 Driver
//
//	  		Taken from Philips data sheet Feb 14, 2003
//  *****************************************************************************

// Philips PCF8833 LCD controller command codes
#define NOP			0x00     // nop
#define SWRESET		0x01     // software reset
#define BSTROFF		0x02     // booster voltage OFF
#define BSTRON		0x03     // booster voltage ON
#define RDDIDIF		0x04     // read display identification
#define RDDST		0x09     // read display status
#define SLEEPIN		0x10     // sleep in
#define SLEEPOUT	0x11     // sleep out
#define PTLON		0x12     // partial display mode
#define NORON		0x13     // display normal mode
#define INVOFF		0x20     // inversion OFF
#define INVON		0x21     // inversion ON
#define DALO		0x22     // all pixel OFF
#define DAL		0x23     // all pixel ON
#define SETCON		0x25     // write contrast
#define DISPOFF		0x28     // display OFF
#define DISPON		0x29     // display ON
#define CASET		0x2A     // column address set
#define PASET		0x2B     // page address set
#define RAMWR		0x2C     // memory write
#define RGBSET		0x2D     // colour set
#define PTLAR		0x30     // partial area
#define VSCRDEF		0x33     // vertical scrolling definition
#define TEOFF		0x34     // test mode
#define TEON		0x35     // test mode
#define MADCTL		0x36     // memory access control
#define SEP		0x37     // vertical scrolling start address
#define IDMOFF		0x38     // idle mode OFF
#define IDMON		0x39     // idle mode ON
#define COLMOD		0x3A     // interface pixel format
#define SETVOP		0xB0	 // set Vop  
#define BRS		0xB4     // bottom row swap
#define TRS		0xB6     // top row swap
#define DISCTR		0xB9     // display control
#define DOR		0xBA     // data order
#define TCDFE		0xBD     // enable/disable DF temperature compensation
#define TCVOPE		0xBF     // enable/disable Vop temp comp
#define EC		0xC0	 // internal or external  oscillator
#define SETMUL		0xC2	 // set multiplication factor
#define TCVOPAB		0xC3	 // set TCVOP slopes A and B
#define TCVOPCD		0xC4	 // set TCVOP slopes c and d
#define TCDF		0xC5	 // set divider frequency
#define DF8COLOR	0xC6	 // set divider frequency 8-color mode
#define SETBS		0xC7	 // set bias system
#define RDTEMP		0xC8	 // temperature read back
#define NLI		0xC9	 // n-line inversion
#define RDID1		0xDA     // read ID1
#define RDID2		0xDB     // read ID2
#define RDID3		0xDC     // read ID3


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
void LCDPutChar(char c, int  x, int  y, int size, int fColor, int bColor);
void LCDPutStr(char *pString, int  x, int  y, int Size, int fColor, int bColor);

};
extern PhilipsLCD LCDP;    
#endif
