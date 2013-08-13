//
//  Enemy.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef TROLL_H
#define TROLL_H


#include <iostream>
#include <string.h>
#include "Enemy.h"

namespace AdventureWorld
{
	class Troll : 
	virtual public Enemy
	{
	public:
		Troll(void);
		~Troll(void);
		int life(void);
		string damage_type(void);
		string type();
	private:
		int hitpoints;
		string dmg_type;
	};
}

#endif