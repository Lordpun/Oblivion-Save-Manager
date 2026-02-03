#include "GUI/GUIinit.h"
#include "backend/config.h"
#include <iostream>

int main(int argc, char* argv[]) {
	makeConfig();
	
	return setup(argc, argv);
}