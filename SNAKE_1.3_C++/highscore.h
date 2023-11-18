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
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "display.h"

#include <map>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#define FILENAME "snake_highscore.dat"

using namespace std;

class Element
{
public:
	Element(int Score=0, string Name="")
	{
		score = Score;
		name = Name;
	}
	int score;
	string name;
};

class Highscore
{
public:
	void update(int snake_score)
	{
		Display Disp;
		string sName;
		char  pScore[20], pName[20], pEin[100];
		int SCORE;

		Highscore_List.clear();
		FILE *fz;

		if ((fz = fopen(FILENAME, "r")) != NULL)
		{
			while (fgets(pEin, 100, fz) != NULL)
			{
				pEin[strlen(pEin)-1] = '\0';
				strncpy(pScore, strtok(pEin, " "), 20);
				SCORE = atoi(pScore);
				score_entry.score = SCORE;
				strncpy(pName, strtok(NULL, " "), 20);
				string sName(pName);
				score_entry.name = sName;
				Highscore_List.insert(pair<int, string>(score_entry.score, score_entry.name));
			}
			fclose(fz);
		}
		else
			cerr << "File open error: " << FILENAME << endl;
		score_entry.score = snake_score;
		cls();
		Disp.display_SNAKE();
		gotoxy(1, (25-2+20)/2);
		centerstr("Name: ");
		cin.width(12);
		cin >> sName;
		score_entry.name = sName;
		Highscore_List.insert(pair<int, string>(score_entry.score, score_entry.name));
		ofstream ofs(FILENAME);
		if (ofs)
		{
			for(it=Highscore_List.begin(); it!=Highscore_List.end();it++)
			{
				ofs << it->first << " " << it->second << '\n';
			}
			if (!ofs)
				cerr << "File write error: "<< FILENAME << endl;
		}
	}
	void show(void)
	{
		Display Disp;
		string sName;
		char pScore[20], pName[20], pEntry[100];
		int SCORE;
		Highscore_List.clear();
		FILE *fz;

		if ((fz = fopen(FILENAME, "r")) != NULL)
		{
			while (fgets(pEntry, 100, fz) != NULL)
			{
				pEntry[strlen(pEntry)-1] = '\0';
				strncpy(pScore, strtok(pEntry, " "), 20);
				SCORE = atoi(pScore);
				score_entry.score = SCORE;
				strncpy(pName, strtok(NULL, " "), 20);
				string sName(pName);
				score_entry.name = sName;
				Highscore_List.insert(pair<int, string>(score_entry.score, score_entry.name));
			}
			fclose(fz);
		}
		else
			cerr << "File open error: " << FILENAME << endl;
		cls();
		Disp.display_SNAKE();
		gotoxy(1, (25-2+15)/2);
		int i=1;
		
		for(i=1, rit=Highscore_List.rbegin(); rit!=Highscore_List.rend();rit++, i++)
		{
			//setcolor
			gotoxy(17, wherey());
			cout.setf(ios::right);
			cout.width(20);
			cout << i << " ";
			cout << rit->second;
			gotoxy(51, wherey());
			cout << rit->first << endl;
		}
		pressanykey();
	}
	Element score_entry;
	multimap<int, string> Highscore_List;
	multimap<int, string>::iterator it;
	multimap<int, string>::reverse_iterator rit;
};
#endif