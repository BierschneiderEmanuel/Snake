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
#ifndef SNAKE_H
#define SNAKE_H

#include "console.h"
#include "display.h"
#include "menu.h"
#include "highscore.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
using namespace std;

class S_N_A_K_E
{
public:
	S_N_A_K_E(int X=0, int Y=0, int I=0)
	{
		x=X;
		y=Y;
		i=I;
	}
	int x;
	int y;
	int i;    //distance from last added snake item to the head of the snake(score)
};            //snake item
class Snake
{
public:
	Snake(void)
	{
		mode=1, time=250, i=0, game_over=0, recently_eaten=0;	           //time [ms]
		food_x_old=0, food_y_old=0, score=0;
		inpchar='w', last_key='w', inpchar_skill='w', inpchar_options='w', inpchar_mode='w';
	}
	int one_eighty(char inpchar, char last_inpchar)                        //detect if snake bites itself
	{
		int status=0;

		if(inpchar=='a' || inpchar=='A' || inpchar==75)						//75 cursor left
			if(last_inpchar=='d' || last_inpchar=='D' || last_inpchar==77)	//77 cursor right
				status=1;													//snake turned 180°
		if(inpchar=='d' || inpchar=='D' || inpchar==77)						//77 cursor right
			if(last_inpchar=='a' || last_inpchar=='A' || last_inpchar==75)	//75 cursor left
				status=1;													//snake turned 180°

		if(inpchar=='w' || inpchar=='W' || inpchar==72)						//72 cursor up
			if(last_inpchar=='s' || last_inpchar=='S' || last_inpchar==80)	//80 cursor down
				status=1;													//snake turned 180°
		if(inpchar=='s' || inpchar=='S' || inpchar==80)						//80 cursor down
			if(last_inpchar=='w' || last_inpchar=='W' || last_inpchar==72)	//72 cursor up
				status=1;													//snake turned 180°
		if(status)
			return 1;
		else
			return 0;
	}
	void insert(void)
	{
		SNAKE.x = curx;
		SNAKE.y = cury;
		SNAKE.i = score;
		SNAKE_LIST.push_front(SNAKE);

		if(recently_eaten)
		{
			recently_eaten = 0;
		}
		else
		{
			SNAKE = SNAKE_LIST.back();
			gotoxy(SNAKE.x, SNAKE.y);
			printf(" ");
			SNAKE_LIST.pop_back();
		}

		for(it=SNAKE_LIST.begin(); it!=SNAKE_LIST.end(); it++)
		{   //print snake
			gotoxy((*it).x, (*it).y);
			printf("x");
		}
	}
	int mode, time, i, game_over, recently_eaten;	//time [ms]
	int food_x, food_y, food_x_old, food_y_old, curx, cury, score;
	char inpchar, last_key, inpchar_skill, inpchar_options, inpchar_mode;
	list<S_N_A_K_E> SNAKE_LIST;
	list<S_N_A_K_E>::iterator it;
    S_N_A_K_E SNAKE;
};
#endif