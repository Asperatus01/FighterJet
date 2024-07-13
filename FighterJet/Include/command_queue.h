#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_HPP

#include "command.h"

#include <queue>


class CommandQueue
{
public:
	void push(const Command& command);
	Command	pop();
	bool isEmpty() const;

private:
	std::queue<Command>			mQueue;
};

#endif
