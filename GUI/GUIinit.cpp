#include "GUIinit.h"
#include <iostream>
#include <string>

// Styling
const std::string titleStyle = ".titleStyle { padding: 10px 5px; border-bottom: 1px solid #ccc; font-size: 24px; }";

Window::Window() : mainBox(Gtk::Orientation::VERTICAL, 10) {
	set_title("Oblivion Save Manager");
	set_default_size(600, 800);

	// Add attributes
	title.set_text("Oblivion Save Manager");

	// Add style
	title.set_xalign(0.0);
	title.add_css_class("titleStyle");

	mainBox.append(title);

	set_child(mainBox);
}

int setup(int argc, char *argv[]) {
	auto app = Gtk::Application::create("org.osm.base");

	auto css_provider = Gtk::CssProvider::create();
  css_provider->load_from_data(titleStyle);

  Gtk::StyleContext::add_provider_for_display(
    Gdk::Display::get_default(), 
    css_provider, 
    GTK_STYLE_PROVIDER_PRIORITY_USER
	);

  return app->make_window_and_run<Window>(argc, argv);	
}