//
//  Goblin.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#ifndef GOBLIN_H
#define GOBLIN_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Enemy.h"

using namespace std;
namespace AdventureWorld
{
	class Goblin : 
		public Enemy
	{
		public:
			Goblin(string name_string);
			~Goblin(void);
			virtual string damage_type(void) const;
			virtual string type(void) const;
                        virtual int damage(void) const;
			virtual void action();
                        
                        
		private:
			
			int status;
                        int dmg;
			
		
	};
}

#endif