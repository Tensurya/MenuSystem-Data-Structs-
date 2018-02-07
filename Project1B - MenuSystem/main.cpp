#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>
#include "SLList.h"
#include "DynArray.h"
#include "menu.h"
#include "menuManager.h"

using namespace std;



class DTSTimer
{
private:
	unsigned int startTime;

public:
	DTSTimer()
	{
		reset();
	}

	void reset()
	{
		startTime = clock();
	}

	unsigned int getElapsedTime()
	{
		return (clock() - startTime);
	}

	static void delay(const unsigned int milli)
	{
		unsigned int st = clock();
		while(clock() - st < milli){}
	}

};


int main(int argc, char ** argv)
{
	DTSTimer bob;
	SLList<menu> * m;
	string userInput;

	while(bob.getElapsedTime() < 15000)
	{

		// 1 - get user input
		if(_kbhit())
		{
			char ch = _getch();

			if(-32 == ch)
				_getch();

			// did the user press a-z?
			else if(isalpha(ch))
			{
				userInput += tolower(ch);
			}
		}

		// 2 - act on it


		// 3 - draw the screen
		system("cls");
		cout << 15 - bob.getElapsedTime()/1000;
		cout << '\n' << userInput << '\n';
	}

	return 0;
}









