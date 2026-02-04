#include "config.h"
#include "findPaths.h"
#include "../SimpleIni.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Gets the file path for configs
// Currently only supports Linux
std::string getConfigPath() {
	const char* xdg = std::getenv("XDG_CONFIG_HOME");
  if (xdg) return std::string(xdg) + "/OSM/";
  return std::string(std::getenv("HOME")) + "/.config/OSM/";
}

// Sets up the config file
int setupConfig(Gtk::Window& parent, std::string configPath) {
  findPath(parent, "Oblivion", [configPath, &parent](std::string oblivionPath) {
      
    if (oblivionPath == "Failed") return;

    findPath(parent, "Saves (Select the one before saves with oblivion.ini in it)", [configPath, oblivionPath](std::string savePath) {
        
    if (savePath == "Failed") return;

    CSimpleIniA ini;
    ini.LoadFile(configPath.c_str());
    
    ini.SetValue("SavePaths", "Oblivion", oblivionPath.c_str());
    ini.SetValue("SavePaths", "Saves", savePath.c_str());

    ini.SaveFile(configPath.c_str());
    std::cout << "Config saved successfully!" << std::endl;
    });
  });

  return 0;
}

// Makes the config file (This is the entry point of this file)
int makeConfig(Gtk::Window& parent) {
	std::string filePath = getConfigPath();

	if (!fs::exists(filePath)) {
		fs::create_directory(filePath);
	}

	if (!fs::exists(filePath + "/config.ini")) {
		std::ofstream configFile(filePath + "/config.ini");
		configFile.close();
		int result = setupConfig(parent, filePath + "/config.ini");
		if (result == 1) { return result; }
	}

	return 0;
}

// Gets the path from the config
std::string getPath(std::string name) {
	std::string configPath = getConfigPath() + "/config.ini";

	CSimpleIniA ini;

	SI_Error rc = ini.LoadFile(configPath.c_str());
	if (rc < 0) {
		std::cerr << "Failed to load config.ini" << std::endl;
		return "Failed";
	}

	return ini.GetValue("SavePaths", name.c_str());
}