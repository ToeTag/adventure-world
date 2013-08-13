//
//  Enemy.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Enemy.h"
namespace AdventureWorld {

    Enemy::Enemy(int hitpoints, string dmg_type, string character_type, string name_string) : Character(hitpoints, dmg_type, character_type, name_string) {

    }

    Enemy::~Enemy(void) {
        //Empty destructor
    }

    void Enemy::follow_player(Character * player, GameMap * gm) {
        Area * player_area = gm->find_character(player);
        gm->move_character(this, player_area);
    }

    void Enemy::fight(Character * a) { //TODO: Move to Enemy.cpp
        if ((this->life()) > 0) {
            if (a->is_under_attack() != true) {
                a->set_under_attack(true);
            } else if (this->life() == 0) {
                a->set_under_attack(false);
                cout << "Fight over" << endl;
                this->loot_items(a);
            }
            cout << this->name() << " attacks " << a->name() << " and hit for " << this->damage() << " damage!" << endl;
            a->reduce_life(this->damage());
        } else {
            this->set_under_attack(false);
            // << this->name() << "is dead!" << endl;
        }

    }
    
    

   
   




}