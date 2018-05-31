////////////////////////////////////////////////////////////
/// Developer Console
////////////////////////////////////////////////////////////

#include "Console.h"

Console::Console():
	Draw(false)
{
	ConsoleProper.setSize(sf::Vector2f(0, 0));
	ConsoleProper.setOutlineColor(sf::Color::Red);
	ConsoleProper.setOutlineThickness(1);
	ConsoleProper.setPosition(0, 0);
	ConsoleProper.setFillColor(sf::Color::Transparent);
}

void Console::Trigger(std::string action) {
	if (action == "ToggleDrawConsole") {
		if (Draw == false)
			Draw = true;
		else
			Draw = false;
	}
}