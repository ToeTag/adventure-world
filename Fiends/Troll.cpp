//
//  Enemy.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Troll.h"
#include "Enemy.h"
using namespace std;
namespace AdventureWorld
{
	Troll::Troll(void) : hitpoints(15), dmg_type("Physical")
	{
		cout << "A Vicious Troll!" << endl;
	}
	
	Troll::~Troll(void)
	{
	
	}
	
	int Troll::life(void)
	{
		return hitpoints;
	}
	
	
	string Troll::damage_type(void)
	{
		return dmg_type;
	}
}