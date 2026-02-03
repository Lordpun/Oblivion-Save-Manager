#include "config.h"
#include "SimpleIni.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Linux only for now
std::string getConfigPath() {
	const char* xdg = std::getenv("XDG_CONFIG_HOME");
  if (xdg) return std::string(xdg) + "/OSM/";
  return std::string(std::getenv("HOME")) + "/.config/OSM/";
}

int makeConfigFiles() {
	std::string filePath = getConfigPath();

	if (!fs::exists(filePath)) {
		fs::create_directory(filePath);
	}

	if (!fs::exists(filePath + "/config.ini")) {
		std::ofstream configFile(filePath + "/config.ini");
		result = setupConfigFiles(filePath);
		if (result == 1) { return result; }
	}

	return 0;
}

int setupConfigFiles(std::string configPath) {
	CSimpleIniA ini;

	SI_ERROR rc = ini.load(configPath + "/config.ini");
	if (rc < 0) {
		std:cerr << "Failed to load config.ini" << std::endl;
		return 1;
	}

	std::string placeholder = "Haven't coded finding the Oblivion paths yet";

	ini.setValue("SavePaths", "Oblivion", placeholder);
	ini.setValue("SavePaths", "Saves", placeholder);

	ini.saveFile(configPath + "/config.ini");

	return 0;
}

std::string getPath(std::string name) {
	CSimpleIniA ini;

	SI_ERROR rc = ini.load(configPath + "/config.ini");
	if (rc < 0) {
		std:cerr << "Failed to load config.ini" << std::endl;
		return "Failed";
	}

	return ini.GetValue("SavePaths", name);
}