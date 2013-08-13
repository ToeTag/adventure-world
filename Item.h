/* 
 * File:   Item.h
 * Author: Niclas
 *
 * Created on den 27 augusti 2012, 22:49
 */

#ifndef ITEM_H
#define	ITEM_H

#include <string>
using namespace std;
namespace AdventureWorld
{
    class Item {
    public:
        Item();
        Item(const Item& orig);
        virtual ~Item();
        virtual string get_type() const = 0;
        virtual string get_name() const = 0;
        virtual int get_dmg() const = 0;
        virtual ostream& print(ostream& out) const = 0;
    private:


    };
}
#endif	/* ITEM_H */

