/* 
 * File:   Spellbook.cpp
 * Author: Niclas
 * 
 * Created on den 13 December 2013, 22:21
 */

#include "Spellbook.h"
#include <stdio.h>
#include <iostream>
using namespace std;
namespace AdventureWorld {

    Spellbook::Spellbook() {
        spell_vec = new vector<Spell*>();
    }

    Spellbook::Spellbook(const Spellbook& orig) {
        this->spell_vec = orig.spell_vec;
    }

    Spellbook::~Spellbook() {
        delete [] spell_vec;
    }

    void Spellbook::add(Spell * i) {
        spell_vec->push_back(i);
    }
    
    vector<Spell*> * Spellbook::get_spells() {
        return spell_vec;
    }

    ostream& operator<<(ostream &out, Spellbook &i) {
        // Since operator<< is a friend of the Point class, we can access
        // Point's members directly.
        vector<Spell*>::iterator it;
        
        for (it = i.spell_vec->begin(); it != i.spell_vec->end(); ++it) {
            (*it)->print(out) << endl;
        }
        return out;
    }
}
