////////////////////////////////////////////////////////////
/// Engine:: Stores all basic data structures and
/// models used everywhere else in the engine.
////////////////////////////////////////////////////////////

#include "SFML\System.hpp"
#include "iostream"
#include "map"
#include "memory"
#include "vector"

class Engine {
public:
	Engine();
	static void Log(std::string string);

	static std::map<int, bool, sf::Clock> eClocks;

	////////////////////////////////////////////////////////////
	/// Time Functions,
	/// TODO: make clocks that can be started and accesed
	///	independent of function.
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
		// TODO: Replace this with scripting
		enum class Screens {
			Main,
			Test
		};

	public:
		// TODO: everything here.
		Scene();

		void Change(Screens s);
		Screens GetCurrent();

	private:
		Screens sCurrent;
	};

	////////////////////////////////////////////////////////////
	/// Entities: NPCs, items, etc.
	////////////////////////////////////////////////////////////

	class Entity {
	public:
		Entity();

		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity() const;

		void Draw();

	private:
		sf::Vector2f eVelocity;
	};

	////////////////////////////////////////////////////////////
	/// Relay: interfunction messaging bus
	////////////////////////////////////////////////////////////

	class Relay {
	public:
		Relay();

		void Beam(std::string msg);
		std::string Recieve();
		bool WaitFor(std::string msg);

	private:
		std::string LastBeamed;
	};
};

