/* 
 * File:   Event.cpp
 * Author: Niclas
 * 
 * Created on den 28 augusti 2012, 01:12
 */
#include "Event.h"
using namespace std;
namespace AdventureWorld {

    Event::Event() {
    }

    Event::Event(const Event& orig) {
    }

    Event::~Event() {
    }

    Enemy * Event::spawn_enemy() {
        return random_enemy();
    }

    Item * Event::spawn_weapon() {
        return random_weapon();
    }

    void Event::ambush(Character * on, Enemy * from) {
        from->fight(on);
    }

    Enemy * Event::random_enemy() {
        int num = rand() % 4 + 1;
        switch (num) {
            case 1: 
            {
                return new Goblin("Gezubr");
            }
            case 2:
            {
                return new Goblin("Gezubr"); //TODO: Add more types
            }
            case 3: 
            {
               return new Goblin("Gezubr"); //TODO: Add more types
            }
            case 4: 
            {
               return new Goblin("Gezubr"); //TODO: Add more types
            }
            default: 
                cout << "Error! Wrong in randomization, number was " << num << endl;
                break;
        }



    }

    Item * Event::random_weapon() { 
        int num = rand() % 4 + 1;
        switch (num) {
            case 1: 
            {
                return new Sword();
            }
            case 2: 
            {
                return new Sword(); //TODO: Add more types
            }
            case 3: 
            {
                return new Sword(); //TODO: Add more types
            }
            case 4: 
            {
                return new Sword(); //TODO: Add more types
            }
            default: // Note the colon, not a semicolon
                cout << "Error! Wrong in randomization, number was " << num << endl;
                break;
        }
    }
}
