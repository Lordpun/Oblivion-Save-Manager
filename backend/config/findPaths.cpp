#include "findPaths.h"
#include <iostream>

void findPath(Gtk::Window& parent, std::string pathName, std::function<void(std::string)> callback) {
  auto dialog = Gtk::make_managed<Gtk::FileChooserDialog>(
    parent, 
    "Select " + pathName, 
    Gtk::FileChooser::Action::SELECT_FOLDER
  );

  dialog->set_modal(true);
  dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
  dialog->add_button("_Open", Gtk::ResponseType::OK);

  dialog->signal_response().connect([dialog, callback](int response_id) {
	  std::string result = "Failed";

	  if (response_id == (int)Gtk::ResponseType::OK) {
      auto file = dialog->get_file();
      if (file) {
        result = file->get_path();
      }
	  }

	  callback(result);

	  dialog->hide();
  });

  dialog->show();
}