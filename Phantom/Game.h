﻿#include "SFML/Graphics.hpp"

#include "iostream"
#include "string"

#include "Resources.h"
#include "Player.h"

class Game {
public:
	void Run();
	Game();
private:
	void ProcessEvents();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void Update(sf::Time elapsedTime);
	void UpdateStatistics(sf::Time elapsedTime);
	void Render();
	void Print(std::string string, float x, float y, int size, sf::Time lenght);
	void Print(std::string string);
	void PlayerPhysics(bool isMoving, float TimeMoving);
private:
	static const sf::Time TimePerFrame;

	float SpeedMultiplier;

	ResourceHolder Textures;
	ResourceHolder Fonts;

	Player Player;

	sf::RenderWindow mWindow;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
	sf::Text mStatisticsText;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	sf::Sprite mBackground;
	sf::Text PrintText;
	sf::Shader mShader;

	/// GAME EVENTS

	class Aircraft : public Engine::Entity {
	public:
		enum class Type {
			Eagle,
			Raptor
		};

		explicit Aircraft(Type type);

	private:
		Type eType;
	};
};
