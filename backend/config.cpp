#include "config.h"
#include "SimpleIni.h"
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
int setupConfig(std::string configPath) {
	CSimpleIniA ini;

	SI_Error rc = ini.LoadFile(configPath.c_str());
	if (rc < 0) {
		std::cerr << "Failed to load config.ini" << std::endl;
		return 1;
	}

	std::string placeholder = "Haven't coded finding the Oblivion paths yet";

	ini.SetValue("SavePaths", "Oblivion", placeholder.c_str());
	ini.SetValue("SavePaths", "Saves", placeholder.c_str());

	ini.SaveFile(configPath.c_str());

	return 0;
}

// Makes the config file
int makeConfig() {
	std::string filePath = getConfigPath();

	if (!fs::exists(filePath)) {
		fs::create_directory(filePath);
	}

	if (!fs::exists(filePath + "/config.ini")) {
		std::ofstream configFile(filePath + "/config.ini");
		configFile.close();
		int result = setupConfig(filePath + "/config.ini");
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