#include "Game.h"

////////////////////////////////////////////////////////////
/// Game:: Contains main game loop and branches off to
///	all non-engine scripting and tasks.
////////////////////////////////////////////////////////////

// TODO: move this to a more appropiate location
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game():
	// TODO: dynamic video mode
	mWindow(sf::VideoMode(1000, 480), "Pew", sf::Style::Close),
	mPlayer(),
	mShader(),
	Textures(),
	Fonts(),
	Player()
{
	// TODO: dynamic resource loading
	Textures.LoadResource(Resources::Textures::PlayerModel, "Media/Textures/Player.png");
	Textures.LoadResource(Resources::Textures::Landscape, "Media/Textures/Space.png");
	Fonts.LoadResource(Resources::Fonts::IBM, "Media/Fonts/PxPlusIBMVGA8.ttf");

	Player.Update(Textures.GetTexture(Resources::Textures::PlayerModel));
	Player.Update(sf::Vector2f(100.f, 100.f));

	Scripts.LoadResource(Resources::Scripts::Main, "Game/Script/main.phantom");

	mBackground.setTexture(Textures.GetTexture(Resources::Textures::Landscape));
	mBackground.setPosition(0.f, 0.f);
}

void Game::Run() {
	sf::Clock Clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;
	std::string LastRelayedMessage = Relay.Recieve();
	Engine::Log(LastRelayedMessage);

	while (mWindow.isOpen()) {
		// Start deltatime clock
		sf::Time elapsedTime = Clock.restart();
		TimeSinceLastUpdate += elapsedTime;

		while (TimeSinceLastUpdate > TimePerFrame) {
			TimeSinceLastUpdate -= TimePerFrame;

			ProcessEvents();
			Update(TimePerFrame);
		}

		if (Relay.Recieve() != LastRelayedMessage) {
			Engine::Log(LastRelayedMessage);
		}

		UpdateStatistics(elapsedTime);
		Render();
	}
}

void Game::Update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);

	if (Player.pIsMoving == true) {
		switch (Player.pDirection) {

		case Controls::Directions::Top:
			movement.y -= Player.PlayerSpeed;
			break;

		case Controls::Directions::Bottom:
			movement.y += Player.PlayerSpeed;
			break;

		case Controls::Directions::Left:
			movement.x -= Player.PlayerSpeed;
			break;

		case Controls::Directions::Right:
			movement.x += Player.PlayerSpeed;
			break;

		default:
			break;
		}
	}

	Player.Update((movement * deltaTime.asSeconds()));
}

// TODO: dynamic rendering with Engine::Scene
void Game::Render() {

	mWindow.clear();
	mWindow.draw(mBackground);
	mWindow.draw(Player.GetSprite());
	mWindow.draw(mStatisticsText);
	mWindow.draw(PrintText);
	mWindow.display();
}

// TODO: move this to a hud function
void Game::UpdateStatistics(sf::Time elapsedTime) {
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;
	mStatisticsText.setFont(Fonts.GetFont(Resources::Fonts::IBM));
	mStatisticsText.setCharacterSize(16);

	if (mStatisticsUpdateTime >= sf::seconds(0.1f)) {
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames * 10) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "u/s" + "\n");

		mStatisticsUpdateTime -= sf::seconds(0.1f);
		mStatisticsNumFrames = 0;
	}
}

void Game::HandlePlayerInput(sf::Keyboard::Key key,
	bool isPressed) {

	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		Player.Update(Controls::Directions::Top);
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		Player.Update(Controls::Directions::Bottom);
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		Player.Update(Controls::Directions::Left);
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		Player.Update(Controls::Directions::Right);
	else if (key == sf::Keyboard::Q) {
		Print("Goodbye!", 500.f, 240.f, 50, sf::seconds(0.5));
		mWindow.close();
	}

	if (isPressed)
		Player.Update(Controls::Actions::Move);

	if (!isPressed) {
		Player.Update(Controls::Actions::Stop);
	}
}

void Game::ProcessEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

// TODO: replace this with a hud
void Game::Print(std::string string, float x, float y, int size, sf::Time lenght) {
	PrintText.setFont(Fonts.GetFont(Resources::Fonts::IBM));
	PrintText.setCharacterSize(size);
	PrintText.setPosition(x, y);
	PrintText.setString(string);
}

// TODO: replace this with a hud
void Game::Print(std::string string) {
	PrintText.setFont(Fonts.GetFont(Resources::Fonts::IBM));
	PrintText.setCharacterSize(50);
	PrintText.setPosition(500.f, 240.f);
	PrintText.setString(string);
}

////////////////////////////////////////////////////////////
/// GAME EVENTS
///	TODO: replace this with script handling
////////////////////////////////////////////////////////////

Game::Aircraft::Aircraft(Type type) : eType(type) {

}