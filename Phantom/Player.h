////////////////////////////////////////////////////////////
/// Player:: contains player handling including input
///	etc.
////////////////////////////////////////////////////////////

#include "SFML\Graphics.hpp"
#include "Engine.h"

// Contains inputtable player actions
namespace Controls {

	enum class Actions {
		Move,
		Stop,
		Shoot
	};

	enum class Directions {
		Top,
		Left,
		Bottom,
		Right
	};
}

class Player : public Engine::Entity {
public:
	Player();

	void Update(sf::Vector2f loc);
	void Update(sf::Texture texture);
	void Update(Controls::Directions d);
	void Update(Controls::Actions a);

	bool pIsMoving;
	Controls::Actions pAction;
	Controls::Directions pDirection;

	sf::Vector2f GetLocation();
	sf::Texture GetTexture();
	sf::Sprite GetSprite();

	float PlayerSpeed;
	float PlayerForce;
	float PlayerAccel;
	float PlayerMass;

	sf::Vector2f pLocation;
	sf::Texture pTexture;
	sf::Sprite pSprite;

	// Virtual representation of the player's actions
	std::map<sf::Keyboard::Key, bool> pVirtual;
};