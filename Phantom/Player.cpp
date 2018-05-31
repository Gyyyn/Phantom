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

// TODO: replace this, hackiest shit here.
std::string Player::HandleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
	if (isPressed)
		Update(Controls::Actions::Move);

	if (!isPressed)
		Update(Controls::Actions::Stop);

	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		return "MoveUp";
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		return "MoveDown";
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		return "MoveLeft";
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		return "MoveRight";
	else if (key == sf::Keyboard::Tilde && isPressed)
		return "ToggleDrawConsole";
	else if (key == sf::Keyboard::Q)
		return "Die";
	else
		return "";
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