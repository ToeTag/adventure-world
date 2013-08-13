/* 
 * File:   Inventory.h
 * Author: Niclas
 *
 * Created on den 27 augusti 2012, 22:48
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

#include <vector>
#include "Item.h"
using namespace std;
namespace AdventureWorld
{

    class Inventory {
    public:
        Inventory();
        Inventory(const Inventory& orig);
        virtual ~Inventory();
        void add(Item *);
        vector<Item*> * get_items();
        friend ostream& operator<< (ostream &, Inventory &);
    private:
         vector<Item*> * item_vec;

    };
}
#endif	/* INVENTORY_H */

