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
#include <stdlib.h>
#include "Enemy.h"

using namespace std;
namespace AdventureWorld
{
	class Spider : 
		public Enemy
	{
		public:

			Spider(string name_string);
			~Spider(void);
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