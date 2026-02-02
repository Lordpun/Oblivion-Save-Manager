#ifndef GUIINIT_H
#define GUIINIT_H

#include <gtkmm.h>

class Window : public Gtk::Window {
public:
	Window();
};

int setup(int argc, char *argv[]);

#endif