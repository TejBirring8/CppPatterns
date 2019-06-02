#pragma once
#include "Command.h"




/* A dummy command */




class ASampleCommand : public Command
{
public:
	ASampleCommand(const std::string&& uid) : Command(uid)
	{}

private:
	void executeImplementation(Actor& actor);
	void undoImplementation(Actor& actor);
};
