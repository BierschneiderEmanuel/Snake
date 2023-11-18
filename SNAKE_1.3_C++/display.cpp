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
#include "console.h"
#include "display.h"
#include "snake.h"

#include <windows.h>

using namespace std;

/*-------------------------------------------------------------display_matchfield---------------------------------------*/
void Display::display_matchfield(void)
{
	static int x, y;

	setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (x = 1; x <= getdimensionx(); x++)					//print matchfield towards x dimension
	{
		gotoxy(x, 1);										//print first x*#
		printf("#");
		gotoxy(x, 24);
		printf("#");                                        //print last x*#
	}

	for(y = 1; y <= 24; y++)
	{
		gotoxy(1, y);
		printf("#");									    //print matchfield towards y dimension on left side
		gotoxy(getdimensionx(), y);
		printf("#");                                        //print matchfield towards y dimension on right side
	}
}

/*-------------------------------------------------------------display_food_target--------------------------------------*/
void Display::display_food_target(int fressen_x, int fressen_y)
{
	gotoxy(fressen_x, fressen_y);         
	printf("X");											//print X food target
}
/*-------------------------------------------------------------display_score--------------------------------------------*/
void Display::display_score(int score)
{
	gotoxy(1, 25);											//jump to end
	printf("Score: %d", score);								//print score
}
/*-------------------------------------------------------------display_SNAKE--------------------------------------------*/
void Display::display_SNAKE(void)
{
	gotoxy(wherex(), (25-19)/2);
	printf("  ************  ***           ***       *****        ***      ***  ***********\n\r"
           "  ************  ***           ***      *** ***       ***     ***   ***********\n\r"
           "  ***           ****          ***     ***   ***      ***    ***    ***        \n\r"
           "  ***           *****         ***    ***     ***     ***   ***     ***        \n\r"
           "  ***           ******        ***   ***       ***    ***  ***      ***        \n\r"
           "  ***           *** ***       ***  ***         ***   *** ***       ***        \n\r"
           "  ***           ***  ***      ***  ***          ***  ******        ***        \n\r"
           "  ************  ***   ***     ***  ***          ***  *****         ***********\n\r"
           "  ************  ***    ***    ***  ***          ***  *****         ***********\n\r"
           "           ***  ***     ***   ***  ****************  ******        ***        \n\r"
           "           ***  ***      ***  ***  ****************  *** ***       ***        \n\r"
           "           ***  ***       *** ***  ***          ***  ***  ***      ***        \n\r"
           "           ***  ***        ******  ***          ***  ***   ***     ***        \n\r"
           "           ***  ***         *****  ***          ***  ***    ***    ***        \n\r"
           "  ************  ***          ****  ***          ***  ***     ***   ***********\n\r"
           "  ************  ***           ***  ***          ***  ***      ***  ***********\n\r");
	printf("\n\n");
}
