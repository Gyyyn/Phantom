////////////////////////////////////////////////////////////
/// Engine:: Stores all basic data structures and
/// models used everywhere else in the engine.
////////////////////////////////////////////////////////////

#include "iostream"
#include "map"

#include "SFML\System.hpp"

class Engine {
public:
	Engine();
	static void Log(std::string string);

	static std::map<int, bool, sf::Clock> eClocks;

	////////////////////////////////////////////////////////////
	/// Time Functions
	////////////////////////////////////////////////////////////

	class Time {
	public:
		Time();
		void Start();
		void Stop();

		sf::Time GetElapsedTime();
		void Restart();
		bool GetIsRunning();

	private:
		sf::Time ElapsedTime;
		sf::Clock Clock;
		bool IsRunning;
	};

	////////////////////////////////////////////////////////////
	/// Scene Functions,
	/// how the engine handles switching between levels,
	/// menus to gameplay, etc.
	////////////////////////////////////////////////////////////

	class Scene {
		enum class Screens {

		};
	};

	////////////////////////////////////////////////////////////
	/// Entities: NPCs, items, etc.
	////////////////////////////////////////////////////////////

	class Entity {
	public:
		Entity ();

		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity() const;

		void Draw();

	private:
		sf::Vector2f eVelocity;
	};
};

