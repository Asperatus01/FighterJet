#include "../Include/player.h"
#include "../Include/command_queue.h"
#include "../Include/aircraft.h"

#include <map>
#include <string>
#include <algorithm>


struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	// ”становите начальные прив€зки клавиш
	mKeyBinding[sf::Keyboard::A] = MoveLeft;
	mKeyBinding[sf::Keyboard::D] = MoveRight;
	mKeyBinding[sf::Keyboard::W] = MoveUp;
	mKeyBinding[sf::Keyboard::S] = MoveDown;

	// ”становите начальные прив€зки к действию
	initializeActions();

	// ѕрисвойте самолетам игрока все категории
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// ѕроверьте, отображаетс€ ли нажата€ клавиша в прив€зке клавиш, запустите команду, если это так
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// ѕройдитесь по всем назначенным клавишам и проверьте, нажаты ли они
	for (auto pair : mKeyBinding)
	{
		// ≈сли клавиша нажата, выполн€етс€ поисковое действие и запускаетс€ соответствующа€ команда
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// ”далите все ключи, которые уже соответствуют действию
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// ”становите новую прив€зку
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.f;

	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	    case MoveLeft:
	    case MoveRight:
	    case MoveDown:
	    case MoveUp:
		    return true;

	    default:
		    return false;
	}
}


