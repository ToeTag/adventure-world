//
//  Character.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//



#include <iostream>
#include "Character.h"
#include "debug.h"
using namespace std;
namespace AdventureWorld
{	
	Character::Character(int hitpoints, 
				string dmg_type, 
				string character_type, 
				string name_str) : hitpoints(hitpoints), 
									dmg_type(dmg_type), 
									character_type(character_type), 
									name_string(name_str),
									status(HEALTHY)
	{
           
    	inventory = new Inventory();
    	spellbook = new Spellbook();
    }

	Character::~Character(void)
	{
    	delete inventory;
    	delete spellbook;
	}
	void Character::reduce_life(int diff)
	{
		if ((this->life())-diff <= 0)
		{
			this->kill();
		}
		else
		{
			this->hitpoints = (this->life())-diff;
			cout << "The " << this->type() << " lost " << diff << " life, and now has " << this->life() << " left! " << endl;
			if (this->life() <= 0)
			{
				this->kill();
			}
		}
	}
	void Character::increase_life(int diff)
	{
		if (this->life() <= 0)
		{
			this->hitpoints = (this->life())+diff;
		}
		else
		{
			this->kill();
            this->status == DEAD;
		}
	}
        
	
	void Character::kill(void)
	{
		this->hitpoints = 0;
		cout << "The " << this->type() << " is dead! " << endl;
	}
        
	string Character::name(void) const
	{
		return name_string;
	}
	
	e_status Character::health_status(void) const
	{
		return status;
	}
	
	int Character::life(void) const
	{
		return hitpoints;
	}

	string Character::type(void) const
	{
		return character_type;
	}

	string Character::damage_type(void) const
	{
		return dmg_type;
	}
        
    void Character::set_under_attack(bool atk)
    {
        this->attack_status = atk;
    }
        
        bool Character::is_under_attack() const
	{
		return attack_status;
	}
        
    void Character::pick_up(Item * i)
    {
        inventory->add(i);
        DEBUG_PRINT("Picked up " << i->get_type());
    }

    void Character::pick_up(Spell * i)
    {
        spellbook->add(i);
        DEBUG_PRINT("Picked up " << i->get_type());
    }
    
    int Character::damage() const
    {
        return dmg;
    }
    
    Inventory * Character::get_inventory() const
    {
        return inventory;
    }	

    Spellbook * Character::get_spellbook() const
    {
        return spellbook;
    }	
    
    void Character::loot(Character * from)
    {
       vector<Item*> * looted_item_vec = (from->get_inventory())->get_items();
       vector<Item*>::iterator it;
        
	    for (it = looted_item_vec->begin(); it != looted_item_vec->end(); ++it) {
	        cout << "looted: " << (*it)->get_type() << " - " << (*it)->get_name() << " (" << (*it)->get_dmg() << ")" <<endl;
	        inventory->add(*it);
	    }  

	    vector<Spell*> * looted_spell_vec = (from->get_spellbook())->get_spells();
        vector<Spell*>::iterator it_s;
        
	    for (it_s = looted_spell_vec->begin(); it_s != looted_spell_vec->end(); ++it_s) {
	        cout << "looted: " << (*it_s)->get_type() << " - " << (*it_s)->get_name() << " (" << (*it_s)->get_dmg() << ")" <<endl;
	        spellbook->add(*it_s);
	    }      
    }


}
