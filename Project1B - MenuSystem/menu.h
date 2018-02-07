#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "SLList.h"
#include "DynArray.h"

using namespace std;

class menu
{
private:

	struct menuItem
	{
		string name;
		bool is_subMenu;
		string subMenuPath;
	};

	string title;
	DynArray<menuItem> * choices;
	unsigned int currSelection;

public:
	menu()
	{
		title = "";
		currSelection = 0;
	}
	~menu();

	void ReadFile(SLList<menu> _menu)
	{
		{
			menu * m;
			char nstring[32];
			int rcount;
			fstream fin;

			fin.open("save.mnu", ios_base::in);

			if (fin.is_open())
			{
				while (true)
				{
					fin.getline(nstring, INT_MAX, '\n');
					if (fin.eof())
						break;
					fin >> m->title;
					fin.ignore(INT_MAX, '\n');

					fin.getline(nstring, INT_MAX, '\n');
					if (fin.eof())
						break;
					fin >> rcount;
					m->choices->reserve(rcount);

					fin.ignore(INT_MAX, '\n');

					for (int i = 0; i < rcount; ++i)
					{
						fin.getline(nstring, INT_MAX, ' ');
						if (nstring == "MENU")
						{
							m->choices->
						}
					}
					_menu.addHead(*m);
				}

				fin.close();
			}
			else
				cout << "File didn't open... check the name maybe?";
		}

	}
};
