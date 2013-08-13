//
//  Human.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Adventurer.h"

using namespace std;
namespace AdventureWorld
{
	class Human : 
		public Adventurer
	{
		public:
			Human(string name_string);
			~Human(void);
			int life(void) const;
			virtual string damage_type(void) const; //implemented
			virtual string type(void) const; //implemented
                        virtual void fight(Character * c);
                        virtual int  action(void);
                        
       
		protected:
			string dmg_type;
			string character_type;
                   
	};
}

#endif