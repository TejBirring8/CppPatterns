#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "NamedObject.h"
#include "Actor.h"




/* 

This class represents an archetypical command 
that can be executed upon a particular Actor object.

All commands must derive from this class. 

*/




class Command : public NamedObject
{
	/* 
		allow ActionedCommand object to access 
		this class's execute and undo function
	*/
	friend class ActionedCommand; 


private:
	/* performs an action on actor */
	void execute(Actor& actor);

	/* performs the reverse (exact opposite) action on actor */
	void undo(Actor& actor);


protected:
	Command(const std::string& uid);
	virtual ~Command() = 0;

	/* the 'execute' logic - to be implemented in subclass */
	virtual void executeImplementation(Actor& actor) = 0;

	/* the 'undo' logic - to be implemented in subclass */
	virtual void undoImplementation(Actor& actor) = 0;
};



