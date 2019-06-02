#pragma once
#include <string>

class NamedObject
{
protected:
	const std::string _uid;
	
	NamedObject(const std::string& uid) : _uid(uid)
	{}


public: 
	std::string getUid()
	{
		return _uid;
	}
};