//
//  Adventurer.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ADVENTURER_H
#define ADVENTURER_H
#include <iostream>
#include "Character.h"
#include "gamemap.h"
#include "Direction.h"
//#include "Adventurer.h"

using namespace std;
namespace AdventureWorld
{
	class Adventurer : 
		public Character
	{
		public:
			Adventurer(int hitpoints, string dmg_type, string character_type, string name_string);
			virtual ~Adventurer(void);
			virtual string damage_type(void) const = 0;
			virtual string type(void) const = 0;
			virtual int action(void);
                        virtual void fight(Character *) = 0;
			virtual void move(GameMap * gm);
                        // action(GameMap * gm);
		protected:
			
			
	};
}

#endif
