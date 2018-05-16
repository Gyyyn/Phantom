////////////////////////////////////////////////////////////
/// Developer Console
////////////////////////////////////////////////////////////

#include "SFML/Graphics.hpp"

class Console {
public:
	Console();
	
	// Does live functions from Game::Update()
	void Trigger(std::string action);

	sf::RectangleShape ConsoleProper;
	bool Draw;
};
