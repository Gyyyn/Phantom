#include "Player.h"

Player::Player()
{
	PlayerSpeed = 500.f;
	PlayerForce = 0.f;
	PlayerAccel = 0.f;
	PlayerMass = 10.f;
}

void Player::Update(sf::Vector2f loc) {
	pSprite.move(loc);

	pLocation.x = pSprite.getPosition().x;
	pLocation.y = pSprite.getPosition().y;
}

void Player::Update(sf::Texture texture) {
	pTexture = texture;
	pSprite.setTexture(pTexture);
}

void Player::Update(Controls::Directions d) {
	pDirection = d;
}

void Player::Update(Controls::Actions a) {
	if (a == Controls::Actions::Stop)
		pIsMoving = false;

	if (a == Controls::Actions::Move)
		pIsMoving = true;
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