/* 
 * File:   Event.h
 * Author: Niclas
 *
 * Created on den 28 augusti 2012, 01:12
 */

#ifndef EVENT_H
#define	EVENT_H
#include "Character.h"
#include "Item.h"
#include "Weapon.h"
#include "Sword.h"
#include "Enemy.h"
#include "Goblin.h"


using namespace std;
namespace AdventureWorld
{
    class Event {
    public:
        Event();
        Event(const Event& orig);
        virtual ~Event();
        Enemy * spawn_enemy();
        Item * spawn_weapon();
        void ambush(Character * on, Enemy * from);
        
        
    private:
        Enemy * random_enemy();
        Item * random_weapon();
    };
}
#endif	/* EVENT_H */

