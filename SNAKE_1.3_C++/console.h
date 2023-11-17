#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <conio.h>
#include <string>
#include <cstring>
using namespace std;

/*------color_codes------------------------------------------------------------------------------------------------------------*/
#define BLACK		0x0000
#define BLUE		0x0001
#define GREEN	    0x0002
#define CYAN		0x0003
#define RED		    0x0004
#define MAGENTA	    0x0005
#define YELLOW	    0x0006
#define GREY		0x0007
#define GREY1		0x0008
#define BLUE1		0x0009
#define GREEN1	    0x000A
#define CYAN1		0x000B
#define RED1	    0x000C
#define MAGENTA1	0x000D
#define YELLOW1	    0x000E
#define WHITE		0x000F

enum CursorMode
{
	CURSOR_OFF,
	CURSOR_INSERT,
	CURSOR_OVERWRITE
};

void setcolor(const WORD wAttributes);     //sets color for output on console window

void textbackground(unsigned short color); //set background color

void textcolor(unsigned short color);      //set text color

void clrscr(const WORD wAttributes);       //clears console window with special color

void cls(void);                            //clears console window (white text on black background)

void gotoxy(const int x, const int y);     //sets cursor to given position (1, 1) means upper left corner

void home(void);                           //sets cursor to (1, 1)

int wherex(void);                          //gets current cursor position (X)

int wherey(void);                          //gets current cursor position (Y)

int getdimensionx(void);                   //gets current screen dimension (X)

int getdimensiony(void);                   //gets current screen dimension (Y)

void setcursor(enum CursorMode mode);      // sets cursor mode

void settitle(LPCWSTR title);              //sets title of console window

char readkey(void);                        //read a character

int keypressed(void);                      //if key press

int centerstr(char* t);                    // ZENTRIERT EINEN TEXT

int centerstr(string t);				   //center a string/

char pressanykey(void);                    //continue after any key press

int middle(int zeilen, int max_zeilen);    //set cursor to the middle of the console

int kbhitdurations(void);                  //determine key press duration

int sgn(int x);                            //signum function
#endif
