////////////////////////////////////////////////////////////
/// Script:: Script parsing
////////////////////////////////////////////////////////////

#include "string"
#include "vector"
#include "fstream"
#include "streambuf"

class Script
{
public:
	static std::vector<std::string> Load(std::string filen);
	static std::string RawLoad(std::string filen);

private:
	static std::vector<std::string> Parse(std::string RawLoad);
};

