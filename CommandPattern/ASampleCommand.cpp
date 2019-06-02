#include "ASampleCommand.h"

using namespace std;

void ASampleCommand::executeImplementation(Actor& actor)
{
	int old_state = actor.state;
	++actor.state;
	cout << actor.getUid() << ": " << old_state << "==>" << actor.state << endl;
}

void ASampleCommand::undoImplementation(Actor& actor)
{
	int old_state = actor.state;
	--actor.state;
	cout << actor.getUid() << ": " << old_state << "==>" << actor.state << endl;
}