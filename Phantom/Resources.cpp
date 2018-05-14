#include "Resources.h"

////////////////////////////////////////////////////////////
/// Resources::, ResourceHolder:: Contains all asset
///	handling and interaction functions
////////////////////////////////////////////////////////////

// Texture loader overload
void ResourceHolder::LoadResource(Resources::Textures id, const std::string& filename) {
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	texture->loadFromFile(filename);

	if (!texture->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::LoadResource - Failed to load "
			+ filename);

	mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

// Font loader overload
void ResourceHolder::LoadResource(Resources::Fonts id, const std::string& filename) {
	std::unique_ptr<sf::Font> font(new sf::Font());
	font->loadFromFile(filename);

	if (!font->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::LoadResource - Failed to load "
			+ filename);

	mFonts.push_back(std::make_pair(id, std::move(font)));
}

// Script loader overload
// Todo: replace with script loading
void ResourceHolder::LoadResource(Resources::Scripts id, const std::string& filename) {
	auto s = Script::Load(filename);
	mScriptMain = std::make_pair(id, std::move(s));
}

// Texture getter overload
sf::Texture& ResourceHolder::GetTexture(Resources::Textures id) {
	auto found = mTextureMap.find(id);
	return *found->second;
}

// Font getter overload
sf::Font& ResourceHolder::GetFont(Resources::Fonts id) {
	int x;
	for (unsigned int i = 0; i < mFonts.size(); i++) {
		if (mFonts[i].first == id)
			x = i;
	}

	return *mFonts[x].second;
}

// Script getter overload
std::vector<std::string> ResourceHolder::GetScript(Resources::Scripts id) {
	return mScriptMain.second;
}