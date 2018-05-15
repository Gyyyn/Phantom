#include "Engine.h"

////////////////////////////////////////////////////////////
/// Engine:: Stores all basic data structures and
/// models used everywhere else in the engine.
////////////////////////////////////////////////////////////

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

// TODO load scenes from script here
Engine::Scene::Scene() {
}

void Engine::Scene::Change(Screens s) {
	sCurrent = s;
}

Engine::Scene::Screens Engine::Scene::GetCurrent() {
	return sCurrent;
}

////////////////////////////////////////////////////////////
/// Time Functions,
/// TODO: make clocks that can be started and accesed
///	independent of function.
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

////////////////////////////////////////////////////////////
/// Relay: interfunction messaging bus
////////////////////////////////////////////////////////////

Engine::Relay::Relay() {
	std::unique_ptr<std::string> s(new std::string);
	s->assign("Relay is ready for messages.");
	LastBeamed.insert(std::make_pair(Lists::Global, std::move(s)));
}

// Sends a message globally
void Engine::Relay::Beam(std::string msg) {
	std::unique_ptr<std::string> s(new std::string);
	s->assign(msg);
	LastBeamed.insert(std::make_pair(Lists::Global, std::move(s)));
}

// Sends a message to a specific list
void Engine::Relay::Beam(Lists i, std::string msg) {
	std::unique_ptr<std::string> s(new std::string);
	s->assign(msg);
	LastBeamed.insert(std::make_pair(i, std::move(s)));
}

// Checks globally for messages
std::string Engine::Relay::Recieve() {
	auto a = LastBeamed.find(Lists::Global);
	return *a->second;
}

// Check a specific relay list for updates
std::string Engine::Relay::Recieve(Lists i) {
	auto a = LastBeamed.find(i);
	return *a->second;
}

// Returns true only of a certain message has been relayed
bool Engine::Relay::WaitFor(std::string msg) {
	auto a = LastBeamed.find(Lists::Global);
	if (*a->second == msg)
		return true;
	else
		return false;
}