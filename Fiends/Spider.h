//
//  Enemy.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef SPIDER_H
#define SPIDER_H


#include <iostream>
#include <string.h>
#include "Enemy.h"
namespace AdventureWorld
{
	class Spider : 
	virtual public Enemy
	{
	public:
		Spider(void);
		~Spider(void);
		int life(void);
		string damage_type(void);
	private:
		int hitpoints;
		string dmg_type;
	};
}

#endif