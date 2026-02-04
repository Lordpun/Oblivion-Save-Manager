#include "getSaves.h"
#include "config.h"
#include "SimpleIni.h"
#include <iostream>
#include <filesystem>
#include <fstream>

// Gets the current loaded character
std::string getLoadedCharacter() {
	std::string savePath = getPath("Saves");

	if (savePath == "Failed") {
		return "Failed to get save path.";	
	}

	std::string iniPath = savePath + "/oblivion.ini";
	CSimpleIniA ini;
  ini.LoadFile(iniPath.c_str());
  
  SI_Error rc = ini.LoadFile(configPath.c_str());
	if (rc < 0) {
		std::cerr << "Failed to load oblivion.ini" << std::endl;
		return "Failed";
	}

	return savePath + "/" ini.GetValue("General", "SLocalSavePath");
}