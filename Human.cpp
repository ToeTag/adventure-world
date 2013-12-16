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

    Human::Human(string name_string) : Adventurer(20, "physical", "human", name_string), dmg_type("physical"), character_type("human") {
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

    

  /* int Human::action() {

       
     }*/




}
