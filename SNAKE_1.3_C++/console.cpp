#include "console.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*---setcolor----------------------------------------------------------------------------------------------------------------*/
void setcolor(const WORD wAttributes)           //sets color for output on console window
{
   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return;

   SetConsoleTextAttribute(Hnd, wAttributes);  //clears console window with special color
}

/*---textbackground----------------------------------------------------------------------------------------------------------*/
void textbackground(unsigned short color)      //zum Setzen der Hintergrundfarbe
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (csbi.wAttributes & 0xFF0F) | (((WORD)color & 0x000F) << 0x0004));
}

/*---textcolor---------------------------------------------------------------------------------------------------------------*/
void textcolor(unsigned short color)            //zum Setzen der Textfarbe
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (csbi.wAttributes & 0xFFF0) | ((WORD)color & 0x000F));
}

/*---clrscr------------------------------------------------------------------------------------------------------------------*/
void clrscr(const WORD wAttributes)  //clears console window with special color
{
   CONSOLE_SCREEN_BUFFER_INFO screen_info;
   SMALL_RECT screensize;
   CHAR_INFO* buffer;
   CHAR_INFO charinfo = {' ', 0};
   COORD buffsize;
   static const COORD upperleftcorner = {0, 0};
   int i;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return;

   //fetch actual settings of scr buffer
   GetConsoleScreenBufferInfo(Hnd, &screen_info);

   //take screen size
   screensize.Left = 0;
   screensize.Top = 0;
   screensize.Right = screen_info.dwSize.X - 1;
   screensize.Bottom = screen_info.dwSize.Y - 1;

   //alloc buffer for the number of character contained on the screen
   buffer = (CHAR_INFO*)malloc(sizeof(CHAR_INFO) * screen_info.dwSize.X * screen_info.dwSize.Y);
   charinfo.Attributes = wAttributes;
   for (i = 0; i < screen_info.dwSize.X * screen_info.dwSize.Y; i++)
   {
      buffer[i] = charinfo;
   }

   //that is the two dim size of our buffer
   buffsize.X = screen_info.dwSize.X;
   buffsize.Y = screen_info.dwSize.Y;

   WriteConsoleOutput(Hnd,
                      buffer,
                      buffsize,
                      upperleftcorner,
                      &screensize);

   free(buffer);

   //cursor to home position
   home();

   //restore old color info
   setcolor(screen_info.wAttributes);
}

/*---cls--------------------------------------------------------------------------------------------------------------------*/
void cls(void)                                  //clears console window (white text on black background)
{
   clrscr(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

/*---gotoxy-----------------------------------------------------------------------------------------------------------------*/
void gotoxy(const int x, const int y)           //sets cursor to given position (1, 1) means upper left corner
{
   COORD coords;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return;

   coords.X = (x - 1);
   coords.Y = (y - 1);
   SetConsoleCursorPosition(Hnd, coords);
}

/*---wherex-----------------------------------------------------------------------------------------------------------------*/
int wherex(void)                                //gets current cursor position (X) 
{
   CONSOLE_SCREEN_BUFFER_INFO screen_info;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return 0;

   GetConsoleScreenBufferInfo(Hnd, &screen_info);

   return screen_info.dwCursorPosition.X + 1;
}

/*---wherey-----------------------------------------------------------------------------------------------------------------*/
int wherey(void)                                //gets current cursor position (Y)
{
   CONSOLE_SCREEN_BUFFER_INFO screen_info;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return 0;

   GetConsoleScreenBufferInfo(Hnd, &screen_info);

   return screen_info.dwCursorPosition.Y + 1;
}

/*---getdimensionx----------------------------------------------------------------------------------------------------------*/
int getdimensionx(void)                         //gets current screen dimension (X)
{
   CONSOLE_SCREEN_BUFFER_INFO screen_info;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return 0;

   GetConsoleScreenBufferInfo(Hnd, &screen_info);

   return screen_info.dwMaximumWindowSize.X;
}

/*---getdimensiony----------------------------------------------------------------------------------------------------------*/
int getdimensiony(void)                         //gets current screen dimension (Y)
{
   CONSOLE_SCREEN_BUFFER_INFO screen_info;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return 0;

   GetConsoleScreenBufferInfo(Hnd, &screen_info);

   return screen_info.dwMaximumWindowSize.Y;
}

/*---setcursor--------------------------------------------------------------------------------------------------------------*/
void setcursor(enum CursorMode mode)            //sets cursor mode
{
   CONSOLE_CURSOR_INFO cursor_information;

   HANDLE Hnd = GetStdHandle(STD_OUTPUT_HANDLE);
   if (Hnd == INVALID_HANDLE_VALUE)
      return;

   switch (mode)
   {
   case CURSOR_OFF:
	   cursor_information.bVisible = FALSE;
	   cursor_information.dwSize = 10;
       break;
   case CURSOR_INSERT:
	   cursor_information.bVisible = TRUE;
	   cursor_information.dwSize = 10;          //show 10 percent
       break;
   case CURSOR_OVERWRITE:
	   cursor_information.bVisible = TRUE;
	   cursor_information.dwSize = 100;         //show 100 percent
       break;
   }

   SetConsoleCursorInfo(Hnd, &cursor_information);
}
/*--settitle----------------------------------------------------------------------------------------------------------------*/
void settitle(LPCWSTR title)                   //sets title of console window
{
   SetConsoleTitle((LPCWSTR)title);
}
/*---home-------------------------------------------------------------------------------------------------------------------*/
void home(void)                                 //sets cursor to (1, 1)
{
   gotoxy(1, 1);
};
/*---keypressed-------------------------------------------------------------------------------------------------------------*/
int keypressed(void)
{
	return (int)_kbhit();                       //if key pressed
}
/*---readkey----------------------------------------------------------------------------------------------------------------*/
char readkey(void)
{
	return (char)_getch();                      //read key but dont print
}

/*---centerstr--------------------------------------------------------------------------------------------------------------*/
int centerstr(char *t)                         
{
	int stringlaenge, x, b;
 
	b=getdimensionx();                          //get console width
	stringlaenge=strlen(t);  
	x=((b-stringlaenge)/2);
	gotoxy(x, wherey());
	cout << t;
	return(x);                                  //return the distance between x=0 and the start of the centered string
}

/*---centerstr--------------------------------------------------------------------------------------------------------------*/
int centerstr(string t)                         
{
	int stringlaenge, x, b;
 
	b=getdimensionx();                          //get console width
	stringlaenge=t.size();
	x=((b-stringlaenge)/2);
	gotoxy(x, wherey());
	cout << t;
	return(x);                                  //return the distance between x=0 and the start of the centered string
}

/*---pressanykey-----------------------------------------------------------------------------------------------------------*/
char pressanykey (void)
{
	char inpchar;
	while (!_kbhit())
	{
	}
	inpchar = _getch();
	return(inpchar);
}

/*---middle----------------------------------------------------------------------------------------------------------------*/
int middle(int zeilen, int max_zeilen)        //set cursor to y/2
{
	gotoxy(wherex(), (max_zeilen-zeilen)/2);
	return((max_zeilen-zeilen)/2);
}

/*---kbhitduration---------------------------------------------------------------------------------------------------------*/
int kbhitduration(void)
{
	char key='t', old_key='t';
	clock_t start, end;
	
	key=_getch();
	start = clock();
	
	while(_kbhit()) 
	{  
		key=_getch();
		old_key=key;
	} 
	
	end = clock();
	return((int)(((end -start) / (double)CLOCKS_PER_SEC) / 1000));
}

/*---sgn-------------------------------------------------------------------------------------------------------------------*/
int sgn(int x)//Signum function
{
  return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}



