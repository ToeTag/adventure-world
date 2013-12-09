//
//  Human.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Enemy.h"
#include "Human.h"

using namespace std;
namespace AdventureWorld {

    Human::Human(string name_string) : Adventurer(25, "physical", "human", name_string), dmg_type("physical"), character_type("human") {
         this->dmg = 5;
    }

    Human::~Human(void) {

    }

    int Human::life(void) const {
        return this->hitpoints;
    }

    string Human::damage_type(void) const {
        return dmg_type;
    }
   

    string Human::type(void) const {
        return character_type;
    }

    void Human::fight(Character * c) { //TODO: Move to Adventurer.cpp
        if ((this->life()) > 0)
        {   
                cout << this->name() << " attacks " << c->name() << " and hit for " << this->damage() << " damage!" << endl;
                c->reduce_life(this->damage());
                if (c->life() == 0)
                {
                    this->set_under_attack(false);
                    this->loot_items(c);
                }
        }
        else
        {
            this->set_under_attack(false);
            //cout << this->name() << "is dead!" << endl;
        }
        //if (Inventory contains spells)
        //cout << "1. Throw spell" << endl;
        // Throw spell

        //else if (Weapon is mounted)
        //cout << "2. Wield weapon" << endl;

        //else if (Spell & Weapon)
        //cout << "1. Throw spell" << endl;
        //cout << "2. Wield weapon" << endl;
        //Do what the player chooses

    }

  /* int Human::action() {

       
     }*/




}
