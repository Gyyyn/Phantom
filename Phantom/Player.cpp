#include "Player.h"

////////////////////////////////////////////////////////////
/// Player:: contains player handling including input
///	etc.
////////////////////////////////////////////////////////////

Player::Player()
{
	PlayerSpeed = 500.f;
	PlayerForce = 0.f;
	PlayerAccel = 0.f;
	PlayerMass = 10.f;

	// Initialize the player's virtual representation with the bound actions.
	// TODO: Make this process automated
	pVirtual.insert(std::make_pair(sf::Keyboard::W, false));
	pVirtual.insert(std::make_pair(sf::Keyboard::A, false));
	pVirtual.insert(std::make_pair(sf::Keyboard::S, false));
	pVirtual.insert(std::make_pair(sf::Keyboard::D, false));
}

// Location updater overload
void Player::Update(sf::Vector2f loc) {
	pSprite.move(loc);

	pLocation.x = pSprite.getPosition().x;
	pLocation.y = pSprite.getPosition().y;
}

// Sprite texture updater overload
void Player::Update(sf::Texture texture) {
	pTexture = texture;
	pSprite.setTexture(pTexture);
}

// Direction updater overloade
void Player::Update(Controls::Directions d) {
	pDirection = d;
}

// Controls updater overload
// TODO: handle multiple input at once !IMPORTANT!
void Player::Update(Controls::Actions a) {
	if (a == Controls::Actions::Stop)
		pIsMoving = false;

	if (a == Controls::Actions::Move)
		pIsMoving = true;
}

// TODO: this
void HandleMouseInput() {
}

sf::Vector2f Player::GetLocation() {
	return pLocation;
}

sf::Texture Player::GetTexture() {
	return pTexture;
}

sf::Sprite Player::GetSprite() {
	return pSprite;
}