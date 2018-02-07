#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "menu.h"
#include "SLList.h"
#include "DynArray.h"

using namespace std;

class menuManager
{
private:
	SLList<menu> * activeMenus;

public:
	menuManager();
	~menuManager();

};