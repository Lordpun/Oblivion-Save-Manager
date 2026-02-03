#include "GUI/GUIinit.h"
#include "backend/config.h"
#include <iostream>

int main(int argc, char* argv[]) {
	setupConfig();
	
	return setup(argc, argv);
}