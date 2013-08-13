//
//  Character.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Inventory.h"
//#include "Area.h"
using namespace std;

//Temporary predeclarations
class Direction;
//class Character;
class Object;



namespace AdventureWorld
{
        enum e_status {DEAD, INJURED, HEALTHY};
	class Character
	{
	public:
	
		
	
		
		
		//Constructors
		Character(int hitpoints, string dmg_type, string character_type, string name_str);
		virtual ~Character(void);
		
		//Info
		virtual string type(void) const = 0;
		virtual string damage_type(void) const = 0;
		int life() const;
		string name(void) const;
		
		//Actions
		virtual void fight(Character * a) = 0;
		
		//Character Status TODO: make visible to the fighting system only
		virtual void reduce_life(int);
		virtual void increase_life(int);
		e_status health_status() const;
                Inventory * get_inventory() const;
                void pick_up(Item * i);
                void set_under_attack(bool);
                bool is_under_attack() const;
                virtual int damage(void) const;
		void kill();
                virtual void loot_items(Character *);
                
                
		
	protected:
		int hitpoints;
		string name_string;
		string character_type;
		string dmg_type;
		e_status status;
                bool attack_status;
                Inventory * inventory;
                int dmg;
                
                
		
		
        private:
             
		/*virtual bool go(Direction) = 0;
	
		virtual bool pick_up(Object) = 0; 
		virtual bool drop(Object) = 0;
		virtual string talk_to(Character) = 0; */
	};
}

#endif