//
//  Enemy.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Spider.h"
#include "Enemy.h"
using namespace std;
namespace AdventureWorld
{
	Spider::Spider(void) : hitpoints(10), dmg_type("Venomous")
	{
		cout << "A Huge Spider!" << endl;
	}
	
	Spider::~Spider(void)
	{
	
	}
	
	int Spider::life(void)
	{
		return hitpoints;
	}
	
	
	string Spider::damage_type(void)
	{
		return dmg_type;
	}
}