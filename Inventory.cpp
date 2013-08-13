/* 
 * File:   Inventory.cpp
 * Author: Niclas
 * 
 * Created on den 27 augusti 2012, 22:48
 */

#include "Inventory.h"
#include <stdio.h>
#include <iostream>
using namespace std;
namespace AdventureWorld {

    Inventory::Inventory() {
        item_vec = new vector<Item*>();
    }

    Inventory::Inventory(const Inventory& orig) {
        this->item_vec = orig.item_vec;
    }

    Inventory::~Inventory() {
        delete [] item_vec;
    }

    void Inventory::add(Item * i) {
        item_vec->push_back(i);
    }
    
    vector<Item*> * Inventory::get_items() {
        return item_vec;
    }

    ostream& operator<<(ostream &out, Inventory &i) {
        // Since operator<< is a friend of the Point class, we can access
        // Point's members directly.
        vector<Item*>::iterator it;

        for (it = i.item_vec->begin(); it != i.item_vec->end(); ++it) {
            (*it)->print(out) << endl;
        }
        return out;
    }
}
