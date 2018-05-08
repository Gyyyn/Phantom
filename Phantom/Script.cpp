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

std::vector<std::string> Script::Parse(std::string RawLoad) {
	return std::vector<std::string>();
}
