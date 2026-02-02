#ifndef GUIINIT_H
#define GUIINIT_H

#include <gtkmm.h>

class Window : public Gtk::Window {
public:
	Window();

private:
	Gtk::Box mainBox;
	Gtk::Label title;
};

int setup(int argc, char *argv[]);

#endif