#include "Script.h"

////////////////////////////////////////////////////////////
/// Script:: Script parsing
////////////////////////////////////////////////////////////

Script::Script() {
	PhsNewCommand = "--";
	PhsEndCommand = ";";
	PhsExtendCommand = ".";
	PhsCommandLoad = "Load";
	PhsCommandLoadExtensions = {
		"Font",
		"Script",
		"Shader",
		"Texture"
	};
}

std::string Script::RawLoad(std::string filen) {
	std::ifstream RawScr(filen);
	std::string str;

	RawScr.seekg(0, std::ios::end);
	str.reserve(RawScr.tellg());
	RawScr.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(RawScr)),
		std::istreambuf_iterator<char>());

	return str;
}

std::vector<std::string> Script::Load(std::string filen) {
	std::string s = RawLoad(filen);
	return Parse(s);
}

// TODO: extended commands
std::vector<std::string> Script::Parse(std::string RawLoad) {
	size_t strStart = 0, strEnd = 0, strData = 0;
	std::string cmd,
		PhsNewCommand = "--",
		PhsEndCommand = ";",
		PhsExtendCommand = ".",
		PhsCommandLoad = "Load",
		PhsDataAccessCommand = ":";
	std::vector<std::string> PhsCommandLoadExtensions = {
		"Font",
		"Script",
		"Shader",
		"Texture"
	};
	std::vector<std::string> rtrn;

	for (size_t i = 0; RawLoad.size() != 0; i++) {
		if (RawLoad != "\n") {
			strStart = RawLoad.find(PhsNewCommand);
			strEnd = RawLoad.find(PhsEndCommand);
			strData = RawLoad.find(PhsDataAccessCommand);
			cmd = RawLoad.substr(strData, strEnd);
			RawLoad.erase(strStart, strEnd + 1);
			rtrn.push_back(cmd);
		}
		else
			RawLoad = "";
	}
	return rtrn;
}
