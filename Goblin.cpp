//
//  Goblin.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Enemy.h"
#include "Goblin.h"

#define HEALTHY = 3
#define INJURED = 2
#define BADLY_WOUNDED = 1
#define DEAD = 1;

using namespace std;
namespace AdventureWorld {

    Goblin::Goblin(string name_string) : Enemy(5, "physical", "goblin", name_string) {
        this->dmg = 2; //TODO: Change to dynamic damage depending on weapon.
        cout << "A " << this->type() << " named " << this->name() << ", with " << this->life() << " hitpoints, doing " << this->damage_type() << " appears in front of you!" << endl;
    }

    Goblin::~Goblin(void) {

    }

    string Goblin::damage_type(void) const {
        return dmg_type;
    }

    int Goblin::damage(void) const {
        return dmg;
    }

    string Goblin::type(void) const {
        return character_type;
    }

   
    
   

    void Goblin::action() {
        //Do something when it is this creatures turn!
        //Fight, walk, flee, get_angry etc..
        //Switch (life)?
    }

}
