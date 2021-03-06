#include <iostream>
#include "ASampleCommand.h"
#include "ActionedCommand.h"

using namespace std;

// an ORDERED collection of actioned commands, ordering is important
// to allow for 'undo' functionality without keeping state
// in the 'ActionedCommand' object.
vector<unique_ptr<ActionedCommand>> actionedCommands;

// executes 'Command' on the 'Actor' object and stores the
// reification in the ordered collection.
void executeCommand(Command& cmd, Actor& act)
{
	actionedCommands.push_back(make_unique<ActionedCommand>(cmd, act));
}

// undoes the last executed 'Command' on the 'Actor' upon
// which it was actioned, and subsequently removes
// the reification of that actioned command.
void undoLastCommand()
{
	if (actionedCommands.size() <= 0)
		return;

	ActionedCommand& last = *actionedCommands.back();
	last.undo();
	actionedCommands.pop_back();
}


/* 
	A working demonstration of the command pattern implementation.
	Notice the abstraction it provides!
*/
int main()
{
	// create actors 
	Actor actor1("actor1");
	Actor actor2("actor2");

	// create commands to execute on those actors
	// note: the commands themselves have the
	//       potential to be parameterized!
	ASampleCommand aSampleCommand("aSampleCommand");

	// a basic test
	executeCommand(aSampleCommand, actor1);
	executeCommand(aSampleCommand, actor1);
	executeCommand(aSampleCommand, actor2);
	executeCommand(aSampleCommand, actor2);
	undoLastCommand();
	executeCommand(aSampleCommand, actor1);
	undoLastCommand();
	undoLastCommand();
	undoLastCommand();
	undoLastCommand();
	undoLastCommand();
}