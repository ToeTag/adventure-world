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
	
	Spider::Spider(string name_string) : Enemy(10, "venomous", "spider", name_string) {
        this->dmg = 2; //TODO: Change to dynamic damage depending on weapon.
        cout << "A huge " << this->type() << " with " << this->life() << " hitpoints, doing " << this->damage_type() << " damage" << " appears in front of you!" << endl;
    }

    Spider::~Spider(void) {

    }

    string Spider::damage_type(void) const {
        return dmg_type;
    }

    int Spider::damage(void) const {
        return dmg;
    }

    string Spider::type(void) const {
        return character_type;
    }

   
    
   

    void Spider::action() {
        //Do something when it is this creatures turn!
        //Fight, walk, flee, get_angry etc..
        //Switch (life)?
    }
}