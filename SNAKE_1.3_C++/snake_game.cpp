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
#include "menu.h"
#include "snake.h"

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

//------------------------------------------------------------------------------------------------------------------------
int main(void)
{
	Display Disp;
	Snake Snake_Game;
	Highscore high_score;

	Menu men;						 //define menu container
	int menu_item_num;
	Menu::Element E1("New Game");    //add menu element
	men.pElem.push_back(&E1);
	Menu::Element E13("Highscore");
	men.pElem.push_back(&E13);
	Menu::Element E2("Options");
	men.pElem.push_back(&E2);
	Menu::Element E3("Quit");
	men.pElem.push_back(&E3);

	Menu men1;						  //add sub menu container
	int menu_sub_item_num1;
	Menu::Element E4("MODE");         //add sub menu element
	men1.pElem.push_back(&E4);
	Menu::Element E5("CONTROLES");
	men1.pElem.push_back(&E5);

	Menu men2;						  //add sub menu container
	int menu_sub_item_num2;
	Menu::Element E6("MODE1");        //add sub menu element
	men2.pElem.push_back(&E6);
	Menu::Element E7("MODE2");
	men2.pElem.push_back(&E7);


	Menu men3;						  //add sub menu container
	int menu_sub_item_num3;
	Menu::Element E8("I'M TOO YOUNG TOO DIE"); // add sub menu element
	men3.pElem.push_back(&E8);
	Menu::Element E9("HEY, NOT TO ROUGH");
	men3.pElem.push_back(&E9);
	Menu::Element E10("HURT ME PLENTY");
	men3.pElem.push_back(&E10);
	Menu::Element E11("ULTRA-VIOLENCE");
	men3.pElem.push_back(&E11);
	Menu::Element E12("NIGHTMARE");
	men3.pElem.push_back(&E12);
	string snake_game_name_str = "SNAKE 1.3";
	wstring temp_snake_game_name = wstring(snake_game_name_str.begin(), snake_game_name_str.end());
	LPCWSTR snake_game_title = temp_snake_game_name.c_str();
	settitle(snake_game_title);

    for(;;)
    {
	   cls();
	   menu_item_num=men.menu_fct();
	   if(menu_item_num==1)//NEW GAME
	   {
		   for(;;)
		   {
			  cls();
			  Snake_Game.game_over =0;
			  Snake_Game.score=0;
			  Snake_Game.recently_eaten =0;
			  Snake_Game.SNAKE_LIST.clear();
			  Snake_Game.inpchar_skill='0';
			  menu_sub_item_num3=men3.menu_fct();
			  for(;;)
			  {
				  if(menu_sub_item_num3 ==1)		//MODE 1
				  {	
				  	  Snake_Game.time=200;
					  break;
				  }
				  if(menu_sub_item_num3 ==2)		//MODE 2
				  {	
				  	  Snake_Game.time=100;
					  break;
				  }
				  if(menu_sub_item_num3 ==3)		//MODE 3
				  {	
				  	  Snake_Game.time=50;
					  break;
				  }
				  if(menu_sub_item_num3 ==4)		//MODE 4
				  {	
				  	  Snake_Game.time=30;
					  break;
				  }
				  if(menu_sub_item_num3 ==5)		//MODE 5
				  {	
				  	  Snake_Game.time=20;
					  break;
				  }
				 if(menu_sub_item_num3 ==0)		    //EXIT
				 {	
				   	 break;
				 }
			  }
			  if(menu_sub_item_num3 ==0)			//EXIT
			  {	
			   	  break;
			  }
			  //Beep(264, 500); //c
			  //Beep(297, 500); //d
			  //Beep(330, 500); //e
			  //Beep(352, 500); //f
			  //Beep(396, 500); //g
			  //Beep(440, 500); //a
			  //Beep(459, 500); //h
			  //Beep(528, 500); //c
			  Beep(264, 100);
			  Beep(297, 100);
			  Beep(330, 100);
			  Beep(396, 300);
			  Beep(352, 100);
			  Beep(440, 300);

			  cls();
			  Disp.display_matchfield();
			  Disp.display_score(Snake_Game.score);		           //print the current score

			  Snake_Game.food_x = ((getdimensionx() / 2) - 1);     //place new target
			  Snake_Game.food_y = 22;
			  Disp.display_food_target(Snake_Game.food_x, Snake_Game.food_y);

			  setcolor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);    //define snake spawn point
			  Snake_Game.curx = ((getdimensionx() / 2) -1);
			  Snake_Game.cury = 12;
			  Snake_Game.SNAKE_LIST.clear();
			  Snake_Game.SNAKE.x = Snake_Game.curx;
			  Snake_Game.SNAKE.y = Snake_Game.cury;
			  Snake_Game.SNAKE.i = Snake_Game.score;
			  Snake_Game.SNAKE_LIST.push_front(Snake_Game.SNAKE);
			  
			  for(Snake_Game.it=Snake_Game.SNAKE_LIST.begin(); Snake_Game.it!=Snake_Game.SNAKE_LIST.end(); Snake_Game.it++)
			  {
				  gotoxy((*Snake_Game.it).x, (*Snake_Game.it).y);
				  printf("x");
			  }
			
			Snake_Game.inpchar = _getch();                   //read first direction key input
			Snake_Game.last_key = Snake_Game.inpchar;        //copy direction to last input key

			while(Snake_Game.game_over ==0)					//GAME START
			{
				 Sleep(Snake_Game.time);					 //delay according game settings               
				 Snake_Game.last_key = Snake_Game.inpchar;
				 if(_kbhit())								 //wait for a key press
				 {
					Snake_Game.inpchar = _getch();		     //read key but dont print key
				 }	  

				 if(Snake_Game.inpchar=='a' || Snake_Game.inpchar=='A' || Snake_Game.last_key=='a' || Snake_Game.last_key=='A' || Snake_Game.inpchar==75)//75
				 {
					Snake_Game.curx--;                       //'a' cursor left
					Snake_Game.insert();
				 }
				 if(Snake_Game.inpchar=='d' || Snake_Game.inpchar=='D' || Snake_Game.last_key=='d' || Snake_Game.last_key=='D' || Snake_Game.inpchar==77)//77
				 {
					Snake_Game.curx++;                       //'d' cursor right
					Snake_Game.insert();
				 }
				 if(Snake_Game.inpchar=='s' || Snake_Game.inpchar=='S' || Snake_Game.last_key=='s' || Snake_Game.last_key=='S' || Snake_Game.inpchar==80)//80
				 {
					Snake_Game.cury++;                       //'s' cursor down
					Snake_Game.insert();
				 }

				 if(Snake_Game.inpchar=='w' || Snake_Game.inpchar=='W' || Snake_Game.last_key=='w' || Snake_Game.last_key=='W' || Snake_Game.inpchar==72)//72
				 {
					Snake_Game.cury--;						 //'w' cursor up
					Snake_Game.insert();
				 }
				 if((Snake_Game.curx <= 1) || (Snake_Game.curx >= getdimensionx()) || (Snake_Game.cury <= 1) || (Snake_Game.cury >= 24))//GAME OVER
				 {
					setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					setcursor(CURSOR_INSERT);
					gotoxy(36,12);
					printf("GAME OVER\n\n\n"); 
					gotoxy(40, 14);
					Sleep(2000);
					Snake_Game.SNAKE_LIST.clear();			      //clear old snake list elements
					Snake_Game.game_over=1;					      //end game
					high_score.update(Snake_Game.score);          //update highscore
				 }
				 if(Snake_Game.mode==1 && Snake_Game.game_over!=1)//start normal game mode
				 {
					 bool status=0;

					 for(status=0, Snake_Game.it=Snake_Game.SNAKE_LIST.begin(), ++Snake_Game.it; Snake_Game.it!=Snake_Game.SNAKE_LIST.end();Snake_Game.it++)
					 {
						if((*Snake_Game.it).x==Snake_Game.curx && (*Snake_Game.it).y==Snake_Game.cury)
						{
							status=1;
						}
					 }
					 if(status==1)
					 {
						setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						setcursor(CURSOR_INSERT);
						gotoxy(36,12);
						printf("GAME OVER\n\n\n"); 
						gotoxy(40, 14);
						Sleep(2000);
						Snake_Game.SNAKE_LIST.clear();			 //clear old snake list elements
						Snake_Game.game_over=1;				     //end game
						high_score.update(Snake_Game.score);     //update highscore
					 }
					 if(Snake_Game.one_eighty(Snake_Game.inpchar, Snake_Game.last_key))
					 {
						setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						setcursor(CURSOR_INSERT);
						gotoxy(36, 12);
						printf("GAME OVER\n\n\n"); 
						gotoxy(40, 14);
						Sleep(2000);
						Snake_Game.SNAKE_LIST.clear();			 //clear old snake list elements
						Snake_Game.game_over=1;				     //end game
						high_score.update(Snake_Game.score);     //update highscore
					 }
				 }
				 if((Snake_Game.curx==Snake_Game.food_x) && (Snake_Game.cury==Snake_Game.food_y))  //snake reached its target
				 {
					Snake_Game.score++;
					setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
					Beep(264, 200);

					Snake_Game.food_x_old = wherex();                                   //save old x and y of food
					Snake_Game.food_y_old = wherey();
				  
					Snake_Game.food_x = 2 + ( rand() % ( 77 - 2 + 1 ) );                //generate new food x and y
					Snake_Game.food_y = 2 + ( rand() % ( 23 - 2 + 1 ) );
					Disp.display_food_target(Snake_Game.food_x, Snake_Game.food_y);
				  
					Disp.display_score(Snake_Game.score);			          		    //print score
				  
					setcolor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);                   //print snake head @ food location
					gotoxy(Snake_Game.food_x_old, Snake_Game.food_y_old);
					Snake_Game.recently_eaten=1;
				 }
				 if(Snake_Game.inpchar==27)                                             //27 key ESC
				 {
					Beep(528, 500);
					break;
				 }
			  }
			  if(Snake_Game.inpchar==27)            //27 key ESC
			  {
				 break;
			  }
		   }
		}
		if(menu_item_num==2)					 	//highscore
		{
			high_score.show();
		}
		if(menu_item_num==3)                        //options
		{
			cls();
			for(;;)
			{
				menu_sub_item_num1=men1.menu_fct();
				if(menu_sub_item_num1==1)			//MODE SELECTION
				{	
					Snake_Game.inpchar_mode='0';
					cls();
					for(;;)
					{
						menu_sub_item_num2=men2.menu_fct();
						if(menu_sub_item_num2==1)			 //GAME MODE 1
						{	
							Snake_Game.mode=1;
							break;
						}
						if(menu_sub_item_num2==2)			 //GAME MODE 2
						{	
							Snake_Game.mode=2;
							break;
						}
						if(menu_sub_item_num2==0)			 //EXIT
						{	
							break;
						}
			
					}
					if(_kbhit())					         //in case of key press
					{
						 Snake_Game.inpchar_mode=_getch();   //read character but dont print
					}	
					if(Snake_Game.inpchar_mode==27)          //27 key ESC
					{
						Beep(528, 500);                      // c
						break;
					}
				}
				if(menu_sub_item_num1==2)                   //CONTROLS
				{
					Snake_Game.inpchar_options='0';
					cls();
					gotoxy(35, wherey());
					middle(7, 25);
					centerstr("[a][<-] for moving left \n\n");
					centerstr("[d][->] for moving righ \n\n");
					centerstr("   [|]                   \n");
					centerstr("[w][v]  for moving down \n\n");
					centerstr("[s][^]  for moving up    \n");
					centerstr("   [|]                  \n\n");
					centerstr("[ESC]   for restart      \n");
					while(Snake_Game.inpchar_options!=27)
					{
						while(!_kbhit())					//while no key pressed
						{
						}
						Snake_Game.inpchar_options=_getch();//read character but dont print
						if(Snake_Game.inpchar_options==27)  //27 key ESC
						{
							Beep(528, 500);                 //c
							break;
						}
					}
				}
				if(menu_sub_item_num1==0)
				{
					break;
				}
			}
	    }

		if(menu_item_num==4)                                //QUIT
		{
			Beep(440, 100);                                 //a
			exit(0);
		}
		if(menu_item_num==0)
		{
			cls();
			Disp.display_SNAKE();
			pressanykey();
		}
	}
}