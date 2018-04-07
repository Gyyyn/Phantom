#include <SFML/Graphics.hpp>

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
	void Print(std::string string, float x, float y, int size);
private:
	static const sf::Time TimePerFrame;
	static float PlayerSpeed;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
	float SpeedMultiplier;

	sf::RenderWindow mWindow;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
	sf::Text mStatisticsText;
	sf::Texture mPlayerTexture;
	sf::Texture mBackgroundTexture;
	sf::Sprite mPlayer;
	sf::Sprite mBackground;
	sf::Font mFont;
	sf::Text PrintText;
	sf::Shader mShader;
};

