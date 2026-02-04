#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <gtkmm.h>

int makeConfig(Gtk::Window& parent);

std::string getPath(std::string name);

#endif