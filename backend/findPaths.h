#ifndef FINDPATHS_H
#define FINDPATHS_H

#include <gtkmm.h>

void findPath(Gtk::Window& parent, std::string pathName, std::function<void(std::string)> callback);

#endif