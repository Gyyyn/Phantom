////////////////////////////////////////////////////////////
/// Developer Console
////////////////////////////////////////////////////////////

#include "Console.h"

Console::Console():
	Draw(false)
{
	ConsoleProper.setSize(sf::Vector2f(100, 50));
	ConsoleProper.setOutlineColor(sf::Color::Red);
	ConsoleProper.setOutlineThickness(5);
	ConsoleProper.setPosition(10, 20);
}

void Console::Trigger(std::string action) {
	if (action == "ToggleDrawConsole") {
		if (Draw == false)
			Draw = true;
		else
			Draw = false;
	}
}