#include <string>
#include <Game.h>

Game::Game():
	mWindow(sf::VideoMode(1000, 480), "SFML Application", sf::Style::Close),
	mPlayer(),
	mIsMovingUp(false),
	mIsMovingDown(false),
	mIsMovingLeft(false),
	mIsMovingRight(false),
	mPlayerTexture(),
	mBackgroundTexture(),
	mFont(),
	mShader()
{
	if (!mPlayerTexture.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}
	if (!mBackgroundTexture.loadFromFile("Media/Textures/Space.png"))
	{
		// Handle loading error
	}
	if (!mFont.loadFromFile("Media/Fonts/PxPlusIBMVGA8.ttf"))
	{
		// Handle loading error
	}
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setRotation(90);

	mBackground.setTexture(mBackgroundTexture);
	mBackground.setPosition(0.f, 0.f);

	if (!mShader.loadFromFile("Media/Shaders/bloom.c", "fragment")) {

	}
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			ProcessEvents();
			Update(TimePerFrame);
		}
		UpdateStatistics(elapsedTime);
		Render();
	}
}

void Game::Update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::Render() {
	mWindow.clear();
	mWindow.draw(mBackground);
	mWindow.draw(mPlayer, &mShader);
	mWindow.draw(mStatisticsText);
	mWindow.draw(PrintText);
	mWindow.display();
}

void Game::UpdateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;
	mStatisticsText.setFont(mFont);
	mStatisticsText.setCharacterSize(16);

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "u/s");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

float Game::PlayerSpeed = 500.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

void Game::HandlePlayerInput(sf::Keyboard::Key key,
	bool isPressed) {
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::Z)
		Print("Pew", 500.f, 240.f, 50);
	else if (key == sf::Keyboard::Q) {
		Print("Goodbye!", 500.f, 240.f, 50);
		mWindow.close();
	} else
		Print("", 0.f, 0.f, 0);
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

void Game::Print(std::string string, float x, float y, int size) {
	PrintText.setFont(mFont);
	PrintText.setCharacterSize(size);
	PrintText.setPosition(x, y);
	PrintText.setString(string);
}