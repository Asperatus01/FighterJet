#ifndef GAME_H
#define GAME_H

#include <world.h>
#include <player.h>

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
public:
	                 Game();
	void             run();
private:
	void             processEvents();
	void             update(sf::Time deltaTime);
	void             render();

	void             updateStatistics(sf::Time elapsedTime);
	void             handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	
private:
	static const sf::Time   TimePerFrame;

	sf::RenderWindow mWindow;
	World            mWorld;
	
	sf::Font		 mFont;
	sf::Text		 mStatisticsText;
	sf::Time		 mStatisticsUpdateTime;
	std::size_t	     mStatisticsNumFrames;
};
#endif // GAME_H

