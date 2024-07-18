#ifndef LOADING_STATE_H
#define LOADING_STATE_H


#include <state.h>
#include <parallel_task.h>

#include <SFML/Graphics.hpp>


class LoadingState : public State
{
public:
	LoadingState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

	void					setCompletion(float percent);

private:
	sf::Text				mLoadingText;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
};

#endif // LOADING_STATE_H

