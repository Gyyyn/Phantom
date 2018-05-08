////////////////////////////////////////////////////////////
/// Script:: Script parsing
////////////////////////////////////////////////////////////

#include "string"
#include "vector"
#include "fstream"
#include "streambuf"

class Script {
public:

	Script();

	static std::vector<std::string> Load(std::string filen);
	static std::string RawLoad(std::string filen);

	// Phantom Script definitions //

	std::string PhsNewCommand;
	std::string PhsEndCommand;
	std::string PhsExtendCommand;
	std::string PhsCommandLoad;
	std::vector<std::string> PhsCommandLoadExtensions;

private:
	static std::vector<std::string> Parse(std::string RawLoad);
};

