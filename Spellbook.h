/* 
 * File:   Spellbook.h
 * Author: Niclas
 *
 * Created on den 15 December 2013, 22:19
 */

#ifndef SPELLBOOK_H
#define	SPELLBOOK_H

#include <vector>
#include "Spell.h"
using namespace std;
namespace AdventureWorld
{

    class Spellbook {
    public:
        Spellbook();
        Spellbook(const Spellbook& orig);
        virtual ~Spellbook();
        void add(Spell *);
        vector<Spell*> * get_spells();
        friend ostream& operator<< (ostream &, Spellbook &);
    private:
         vector<Spell*> * spell_vec;

    };
}
#endif	/* INVENTORY_H */

