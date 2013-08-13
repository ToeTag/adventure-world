/* 
 * File:   Weapon.h
 * Author: Niclas
 *
 * Created on den 28 augusti 2012, 00:35
 */

#ifndef WEAPON_H
#define	WEAPON_H

#include "Item.h"
using namespace std;
namespace AdventureWorld
{
    class Weapon : public Item {
    public:
        Weapon();
        Weapon(const Weapon& orig);
        virtual ~Weapon();
        virtual string get_type() const = 0;
        virtual string get_name() const = 0;
        virtual int get_dmg() const = 0;
        virtual ostream& print(ostream& out) const = 0;
    private:
        
    };
}
#endif	/* WEAPON_H */

