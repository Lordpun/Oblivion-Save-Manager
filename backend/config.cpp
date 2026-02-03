#include "config.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Linux only for now
std::string setupConfig() {
	const char* xdg = std::getenv("XDG_CONFIG_HOME");
  if (xdg) return std::string(xdg) + "/OSM/";
  return std::string(std::getenv("HOME")) + "/.config/OSM/";
}

int makeConfigFiles() {
	std::string filePath = getConfigPath;

	if (!fs::exists(filePath)) {
		fs::create_directory(filePath);
	}

	if (!fs::exists(filePath + "/config.ini")) {
		std::ofstream configFile(filePath + "/config.ini");
	}

	return 0;
}