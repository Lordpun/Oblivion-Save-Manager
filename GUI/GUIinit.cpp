#include <iostream>
#include "GUIinit.h"

Window::Window() {
	set_title("OSM");
	set_default_size(800, 600);
}

int setup(int argc, char *argv[]) {
	auto app = Gtk::Application::create("org.osm.base");

  return app->make_window_and_run<Window>(argc, argv);	
}