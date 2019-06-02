#pragma once
#include "Command.h"




/* 
	ActionedCommand is the class that reifies 
	an executed command, and allows for the 
	action to be "undone" from state S+1 back 
	to state S.

	So long as the chain of ALL ActionedCommands are chronological 
	and executed in reverse order, an ActionedCommand need
	not store the 'pre-execution' or 'post-execution'
	state.

	Note:	For clarity sake, the creation of an ActionedCommand
			also executes the action; this ensures sensible
			code flow.
*/




class ActionedCommand
{
private:
	Command& _command;
	Actor& _actor;


public:
	/* 
		Constructor. 
		Executes the 'Command' on the 'Actor' object.
		Takes Actor's state from current (S0) to next state S1.
	*/
	ActionedCommand(Command& command, Actor& actor) :
		_command(command), _actor(actor)
	{
		_command.execute(_actor);
	}

	/*
		Undo the 'Command' actioned on the 'Actor' object. 
		Takes Actor's state from S1 to previous state (S0).
	*/
	void undo()
	{
		_command.undo(_actor);
	}
};

