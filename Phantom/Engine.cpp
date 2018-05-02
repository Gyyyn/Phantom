#include "Engine.h"

Engine::Engine()
{
}

void Engine::Log(std::string string) {
	std::cout << string << "\n";
}

////////////////////////////////////////////////////////////
/// Scene Functions,
/// how the engine handles switching between levels,
/// menus to gameplay, etc.
////////////////////////////////////////////////////////////

Engine::Time::Time() {
}

void Engine::Time::Start() {
	if (!IsRunning) {
		IsRunning = true;
		
		Engine::Log("Started a clock.");
	} else
		Engine::Log("Tried to start a clock when it was already running.");
}

void Engine::Time::Stop() {
	IsRunning = false;

	Engine::Log("Ran a clock for" + std::to_string(GetElapsedTime().asMilliseconds()) + " seconds.");
}

bool Engine::Time::GetIsRunning() {
	return IsRunning;
}

sf::Time Engine::Time::GetElapsedTime() {
	return Clock.getElapsedTime();
}

void Engine::Time::Restart() {
	Clock.restart();
}

////////////////////////////////////////////////////////////
/// Entities: NPCs, items, etc.
////////////////////////////////////////////////////////////

Engine::Entity::Entity() {

}

void Engine::Entity::setVelocity(sf::Vector2f velocity) {
	eVelocity = velocity;
}

void Engine::Entity::setVelocity(float vx, float vy) {
	eVelocity.x = vx;
	eVelocity.y = vy;
}

sf::Vector2f Engine::Entity::getVelocity() const {
	return eVelocity;
}

void Engine::Entity::Draw() {
	
}