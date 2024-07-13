#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "world.h"
#include "player.h"

class Game : private sf::NonCopyable
{
public:
	Game();
	void run();
private:
	void processInput();
	void update(sf::Time deltaTime);
	void render();
	void updateStatistics(sf::Time elapsedTime);
	
private:
	static const sf::Time   TimePerFrame;

	sf::RenderWindow mWindow;
	World            mWorld;
	Player           mPlayer;

	sf::Font		 mFont;
	sf::Text		 mStatisticsText;
	sf::Time		 mStatisticsUpdateTime;
	std::size_t	     mStatisticsNumFrames;
};
#endif

