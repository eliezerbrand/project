#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#else
#error "Unrecognized configuration!"
#endif

#include <SFML/Graphics.hpp>
#include "Controller.h"
#include <iostream>
#include "Menu.h"

//***************************************************************************//
//**							main	
//***************************************************************************//
int main()
{
	srand(time(NULL));

	Menu menu;
	menu.run();

	return 0;
}