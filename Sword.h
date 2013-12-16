/* 
 * File:   Sword.h
 * Author: Niclas
 *
 * Created on den 27 augusti 2012, 22:58
 */

#ifndef SWORD_H
#define	SWORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include "Weapon.h"
#include <utility>
using namespace std;
namespace AdventureWorld
{
    class Sword : 
        public Weapon {
    public:
        Sword();
        Sword(const Sword& orig);
        virtual ~Sword();
        virtual string get_type() const;
        virtual string get_name() const;
        virtual int get_dmg() const;
        ostream& print(ostream& out) const;
    private:
        string random_name();
        int dmg;
        string name;
        string type;
        string info;
        
    };
}
#endif	/* SWORD_H */

