#include "Command.h"




using namespace std;




void Command::execute(Actor& actor)
{
	std::cout << _uid << " executing on " << actor.getUid() << "." << std::endl;
	// 1. things to do before 
	// ...
	// 2. execute sub-class implementation
	executeImplementation(actor);
	// 3. things to do afterwards
	// ...
	std::cout << _uid << " executed on " << actor.getUid() << "." << std::endl;
}




void Command::undo(Actor& actor)
{
	std::cout << _uid << " undoing on " << actor.getUid() << "." << std::endl;
	// 1. things to do before
	// ...
	// 2. execute sub-class implementation
	undoImplementation(actor);
	// 3. things to do afterwards
	// ...
	std::cout << _uid << " undone on " << actor.getUid() << "." << std::endl;
}




Command::Command(const std::string& uid) : NamedObject(uid)
{
	std::cout << _uid << " created." << std::endl;
}




Command::~Command()
{
	std::cout << _uid << " destroyed." << std::endl;
}