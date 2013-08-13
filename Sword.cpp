/* 
 * File:   Sword.cpp
 * Author: Niclas
 * 
 * Created on den 27 augusti 2012, 22:58
 */

#include "Sword.h"

using namespace std;
namespace AdventureWorld {

    Sword::Sword() {
        this->type = "Sword";
        this->name = random_name();
        this->dmg = rand() % 5 + 1;
    }

    Sword::Sword(const Sword& orig) {
    }

    Sword::~Sword() {
    }

    string Sword::get_type() const {
        return this->type;
    }

    string Sword::get_name() const {
        return this->name;
    }

    int Sword::get_dmg() const {
        return this->dmg;
    }

    string Sword::random_name() {
        int num = rand() % 4 + 1;
        switch (num) {
            case 1: // Note the colon, not a semicolon
                return "Demon Slayer";
            case 2: // Note the colon, not a semicolon
                return "Goblin Decapitator";
            case 3: // Note the colon, not a semicolon
                return "Brutalizer";
            case 4: // Note the colon, not a semicolon
                return "Viper Fang";
            default: // Note the colon, not a semicolon
                cout << "Error! Wrong in randomization, number was " << num << endl;
                break;
        }


    }

    ostream& Sword::print(ostream& out) const {
        // Since operator<< is a friend of the Point class, we can access
        // Point's members directly.

        out << this->get_type() << " - " << this->get_name() << " (" << this->get_dmg() << ")";

        return out;
    }

}
