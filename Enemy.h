//
//  Enemy.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "Character.h"
#include "gamemap.h"
#include "Direction.h"
//#include "Enemy.h"

using namespace std;
namespace AdventureWorld {

    class Enemy :
    public Character {
    public:
        Enemy(int hitpoints, string dmg_type, string actor_type, string name_string);
        virtual ~Enemy(void);
        virtual string damage_type(void) const = 0;
        virtual string type(void) const = 0;
        virtual void follow_player(Character *, GameMap *);
        void fight(Character * a);
        //void loot_items(Character *);
   
    private:
        Area * current_area;
    };
}

#endif