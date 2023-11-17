/*
 MIT License

 Copyright(c) 2023 Emanuel Bierschneider

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files(the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions :

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/
#ifndef MENUE_H
#define MENUE_H

#include "console.h"
#include <windows.h>
#include <cstdio>
#include <string>
#include <conio.h>
#include <list>
#include <cstring>
using namespace std;

class Menu
{
public:
	class Element
	{
	public:
		Element(string name_menu = "") { menu_name = name_menu; }
		string toString() { return menu_name; }
		string menu_name;
	};
	void display_menue(int menu_line_num)
	{
		int i;
		clrscr(BLACK);
		setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		gotoxy((120-89)/2, (25-19)/2);
		centerstr("  ************  ***           ***       *****        ***      ***  ***********\n\r");
		centerstr("  ************  ***           ***      *** ***       ***     ***   ***********\n\r");
		centerstr("  ***           ****          ***     ***   ***      ***    ***    ***        \n\r");
		centerstr("  ***           *****         ***    ***     ***     ***   ***     ***        \n\r");
		centerstr("  ***           ******        ***   ***       ***    ***  ***      ***        \n\r");
		centerstr("  ***           *** ***       ***  ***         ***   *** ***       ***        \n\r");
		centerstr("  ***           ***  ***      ***  ***          ***  ******        ***        \n\r");
		centerstr("  ************  ***   ***     ***  ***          ***  *****         ***********\n\r");
		centerstr("  ************  ***    ***    ***  ***          ***  *****         ***********\n\r");
		centerstr("           ***  ***     ***   ***  ****************  ******        ***        \n\r");
		centerstr("           ***  ***      ***  ***  ****************  *** ***       ***        \n\r");
		centerstr("           ***  ***       *** ***  ***          ***  ***  ***      ***        \n\r");
		centerstr("           ***  ***        ******  ***          ***  ***   ***     ***        \n\r");
		centerstr("           ***  ***         *****  ***          ***  ***    ***    ***        \n\r");
		centerstr("  ************  ***          ****  ***          ***  ***     ***   ***********\n\r");
		centerstr("  ************  ***           ***  ***          ***  ***      ***  ***********\n\r");
		centerstr("\n\n");
		
		gotoxy(1, (25-2+15)/2);
		list<Element *>::iterator it;
		for(i=1, it = pElem.begin(); it != pElem.end(); it++, i++)
		{
			if(menu_line_num==i)                                 //menue item selected
			{
				string help;
				help = "->" + (*it)->menu_name + "<-" + "\n";
				centerstr(help);
			}
			else                                                 //other menue item not selected
			{
				string help;
				help =(*it)->menu_name + "\n";
				centerstr(help);
			}
		}
	}
	int menu_fct(void)                                           //menu function
	{
		unsigned int menu_line=1;
		char inpchar='s'; 
		
		clrscr(BLACK);
		display_menue(menu_line);
		for(;;)
		{
			if(_kbhit())
			{
				inpchar=_getch(); 
		
				if(inpchar=='s' || inpchar==80)                  //80 cursor down
				{ 
					menu_line++;
					 if(menu_line>Menu::pElem.size())            //start at the beginning
						   menu_line=1;
					 Beep(264, 200);
				}
				if(inpchar=='w' || inpchar==72)                  //72 cursor up
				{
					menu_line--;
					if(menu_line < 1)                            //jumpt to the end
						menu_line=Menu::pElem.size();
					Beep(440, 200);
				}
				if(inpchar==13 || inpchar== 10)                  //10 = line feed(linux) 13 = line feed(windows)
				{
					Beep(330, 200);
					break;                                       //jump to last selected menu item
				}
				if(inpchar==27)                                  //27 fuer Taste ESC
				{
					Beep(528, 200);                              // c
					menu_line = 0;
					break;
				}
				display_menue(menu_line);
				
				/*
								 //f [Hz]
				Beep(264, 500);  //c 264
				Beep(330, 300);  //d 297
				Beep(440, 100);  //e 330
								 //f 352
								 //g 396
								 //a 440
								 //h 495
								 //c 528
				 */
			}
		}
		return(menu_line);
	} 
	list<Element *> pElem;
};
#endif