#pragma once
#include "NamedObject.h"




/* All commands act upon objects of this class. */




class Actor : public NamedObject
{
public:
	/* 
		a dummy representation of Actor's state. 
		this could be anything, really.
	*/
	int state;


	/*
		create the actor, initializing it's original state.
	*/
	Actor(const std::string&& uid) : NamedObject(uid), state(0)
	{}
};
