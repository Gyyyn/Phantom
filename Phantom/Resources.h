////////////////////////////////////////////////////////////
/// Resources::, ResourceHolder:: Contains all asset
///	handling and interaction functions
////////////////////////////////////////////////////////////

#include "memory"
#include "SFML\Graphics.hpp"

namespace Resources {
	enum class Textures	{
		Landscape,
		PlayerModel,
		Laser
	};

	enum class Fonts {
		IBM
	};
}

class ResourceHolder {
public:
	void LoadResource(Resources::Textures id, const std::string& filename);
	void LoadResource(Resources::Fonts id, const std::string& filename);

	sf::Texture& GetTexture(Resources::Textures id);
	sf::Font& GetFont(Resources::Fonts id);

private:
	std::map<Resources::Textures, std::unique_ptr<sf::Texture>> mTextureMap;
	std::vector<std::pair<Resources::Fonts, std::unique_ptr<sf::Font>>> mFonts;
};