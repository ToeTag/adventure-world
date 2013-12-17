//
//  main.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "debug.h"
#include "Character.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Human.h"
#include "Area.h"
#include "Item.h"
#include "Sword.h"
#include "Event.h"
#include "Fireball.h"
#include <sstream>
#include <ctime>

#define NORTH "NORTH"
#define WEST "WEST"
#define EAST "EAST"
#define SOUTH "SOUTH"

#define MOVE 1
#define INVENTORY 2
#define SPELLBOOK 3
#define SEE 4
#define GET_DIRECTIONS 5
#define MAP 6
#define FLEE 7
#define FIGHT 8

//#include "Troll.h"
//#include "Spider.h"
using namespace std;
using namespace AdventureWorld;

Adventurer * create_character(Area * a) {

  int myNumber = 0;
  while (myNumber == 0) { 
    cout << "\n\n\nIt is time to create a character, what type of character would you like to create?\n" << endl;
    cout << "1. Human " << endl;
    string input = "";
    getline(cin, input);
    
    // This code converts from string to number safely.
    
    stringstream myStream(input);
    if (!(myStream >> myNumber)) {
      	cout << "Invalid number, please try again" << endl;        
    }

    DEBUG_PRINT("myNumber: " << myNumber);
    //cout << "myNumber: " <<  myNumber << endl;

    }

    
    switch (myNumber) {
        case 1: 
        {
            cout << "\n\n\nHuman! Great choice indeed! \n" << endl;
            cout << "What will the name of your character be? : \n" << endl;
            string name = "";
            getline(cin, name);
            Adventurer * player = new Human(name);
            a->spawn_character(player);
            return player;
        }
        case 2:
	    cout << "NOT IMPLEMENTED YET!" << endl;
	    break;
        case 3: 
            cout << "NOT IMPLEMENTED YET!" << endl;
            break;
        default:
            cout << "Error, bad input, quitting\n";
            break;
    }

}

GameMap * create_map(GameMap * gm) {
    
    //Create map and adds areas
  return gm = new GameMap(4,4);
}

Adventurer * add_player(Adventurer * player, GameMap * gm) {
    //Add the player to the starting point, tile (1,1)
    Area * start_area = gm->get_area_from_coords(0, 0);

    //Create the adventurer
    player = create_character(start_area);
    return player;
}

int read_num_input() {
    string input = "";
    int myNumber = 0;
    getline(cin, input);
    // This code converts from string to number safely.
    stringstream myStream(input);
    if (myStream >> myNumber) {
        cout << "Invalid number, please try again" << endl;
    }
    return myNumber;
}

string read_str_input() {
    string input = "";
    getline(cin, input);
    return input;
}

int game(Adventurer * player, GameMap * gm) {
    Area * cur_area = gm->find_character(player);
    string area_name = cur_area->get_name();
    cout << "\n\nYou're standing on a path, it is hardly distinguishable in the high grass. The rain is pooring down, suddenly you see a sign infront of you, it says: ";
    cout << "Welcome to " << area_name << endl;
    cout << "Seems like the path leads somewhere even though it haven't been travelled for long..." << endl;

    Event event;
    Enemy * enemy = 0;

    //(player->get_inventory())->add(new Sword());
    string input = ""; // = read_str_input();
    while (player->life() > 0) {
        if (enemy != 0) { //TODO: Fix so that the enemy pointer can be reset and a new enemy can spawn
            if (enemy->life() == 0)
            {
                enemy = 0;
            }
        }
        cur_area = gm->find_character(player);
        gm->refresh_map();
        int action = player->action();
        int num = rand() % 2 + 1;

        if (action == MOVE) {
            player->move(gm);

            if (num == 1 && enemy == 0) {
                enemy = event.spawn_enemy();
                cur_area->spawn_character(enemy);
                enemy->pick_up(new Sword());
                enemy->pick_up(new Fireball());
                event.ambush(player, enemy);
            }
        }
        if (action == INVENTORY) {
            cout << "Your inventory contains: " << endl;
            cout << *(player->get_inventory()) << endl;
        } else if (action == FLEE) {
            player->move(gm);
            if (enemy != 0 && (enemy->life() > 0)) {
                //Enemy * en = dynamic_cast<Enemy*>(enemy);
                enemy->follow_player(player, gm);

            }
        } else if (action == FIGHT && (enemy->life() > 0)) {
            player->fight(enemy);
            enemy->fight(player);
        } else if (action == GET_DIRECTIONS) {
            cur_area->print_neighbours();
        } else if (action == SEE) {
            cur_area->print_characters();
        } else if (action == MAP) {
	        gm->print_areas();
	    } else if (action == SPELLBOOK) {
            cout << "Your spellbook contains: " << endl;
            cout << *(player->get_spellbook()) << endl;
        }
    }
    cout << "You are dead! Game Over" << endl;
}

int menu(Adventurer * player, GameMap * gm) {
    string input = "";
    cout << "Menu: " << endl;
    cout << "1. New Game " << endl;
    cout << "2. Load Game " << endl;
    cout << "3. Quit " << endl;

    int myNumber = 0;
    getline(cin, input);
    // This code converts from string to number safely.
    
    stringstream myStream(input);
    if (!(myStream >> myNumber)) {
        cout << "Invalid number, please try again" << endl;
    }

    cout << "You entered: " << myNumber << endl << endl;

    switch (myNumber) {
        case 1: 
            gm = create_map(gm);
            player = add_player(player, gm);
            game(player, gm);
            break;
        case 2: 
            //cout << "NOT IMPLEMENTED YET!" << endl;
            break;
        case 3: 
            //cout << "NOT IMPLEMENTED YET!" << endl;
            break;
        default:
            cout << "Error, bad input, quitting\n";
            break;
    }
}

 

int main(int argc, const char * argv[]) {

#ifdef DEBUG
  cout << "\n\n\nSTARTING ADVENTURE WORLD IN DEBUG MODE!" << endl;
#endif

    std::cout << "\n\n\n##################################" << endl;
    std::cout << "#   Welcome to AdventureWorld!   #" << endl;
    std::cout << "##################################\n\n\n" << endl;
    std::cout << 
R"(   #         ,      ,        # 
   #        /(.-""-.)\       # 
   #    |\  \/      \/  /|   #
   #    | \ / =.  .= \ / |   #
   #    \( \   o\/o   / )/   #
   #     \_, '-/  \-' ,_/    #
   #       /   \__/   \      #
   #       \ \__/\__/ /      #
   #     ___\ \|--|/ /___    #
   #   /`    \      /    `\  #
   #  /       '----'       \ #)";
    cout << endl;
    cout << endl;
    srand(time(0));
    Adventurer * player = 0;
    GameMap * gm = 0;
    menu(player, gm);
    
    return 0;
}

//TODO: 1. Måste vara på samma area för att kunna slåss 
//      2. Lägg till random spawns när man förflyttar sig mellan areor
//              Random spawns fixat via event, ej förflyttningstrigger
//      3. Items, bags, inventory
//             - Items och Inventory inlaggt, ej bags, ej heller begränsning i inventoryt
//             - Om en bag hittas som är större än inventoryt, ge möjlighet att byta.
//             - Fler vapen och items, spells.
//               - Item-slots (Vapen, hjälm, rustning osv)
//             - Spellbook
//      4. Spells
//              - Ge val vid fight, kasta spell (om lärd) eller slåss med melee
//      5. Loot/Drop från monster
//              Fixa drop on kill osv -> random drop? ge möjlighet att plocka upp
//      5. Utöka så gamemap är en area (Zooma ut ett steg)






/* cout << "\n\n\nCharacters in area: \n" << endl;
    start_area->print_characters();
    cout << "-----------------" << endl;
    adv->move(game_map, NORTH);
    cout << "\n\n\nCharacters in area after move: \n" << endl;
    start_area->print_characters();
    cout << "-----------------" << endl;
    cout << "-----------------" << endl; */
//Game loop
/*while(player->health_status() != 0)
{
                    
}*/



//Area * second_area = new Area();
//game_map->add(second_area);


/*cout << "\n\n\nAreas: \n" << endl;
Area* a = game_map->print(0);
//Area* b = game_map->print(1);
		
cout << a->get_name() << endl;
//cout << b->get_name() << endl;
		
		
cout << "\n\n\n" << endl;*/

//Troll Troll1;

/*
		
Goblin * Goblin1 = new Goblin("Gargamel");
Goblin * Goblin2 = new Goblin("Hobgoblin"); 
Human1->fight(Goblin1);
//Goblin1->fight(Goblin2);
Goblin1->reduce_life(4);
Goblin1->reduce_life(1);
		
 */

//Goblin1->reduce_life(2);
//cout << Goblin1.damage_type() << endl;
//cout << Goblin1.life() << endl;

/*Troll Troll1;
cout << Troll1.damage_type() << endl;
cout << Troll1.life() << endl;
cout << "-----------------" << endl;
Spider Spider1;
cout << Spider1.damage_type() << endl;
cout << Spider1.life() << endl;*/

//Spider Spider1;

//delete [] game_map;




/*Event event;

           Character * new_enemy = event.spawn_enemy();
           Sword * sword1 = new Sword();
           Sword * sword2 = new Sword();
           //Item * new_weap = event.spawn_weapon();
           Inventory * inv = new_enemy->get_inventory();
           inv->add(sword1);
           inv->add(sword2);*/

//cout << "Inventory: \n" << *inv << endl;
//cout << "new_weap: " << sword << endl;

//Item * item_sw = new Sword();
//Item * sw = dynamic_cast<Sword*>(item_sw);



/*cout << "\n\n\n" << endl;
    game_map->print_areas();

    cout << "moving character...." << endl;
    player1->move(game_map, SOUTH);
    game_map->print_areas();
    cout << "moving character...." << endl;
    player2->move(game_map, EAST);
    game_map->print_areas();

    //Adventurer * adv = new Human("Adventurer");
    Human * hu = new Human("TEST");

    hu->fight(player2);
    player2->fight(hu);

    Goblin * gob = new Goblin("Gorgom");
    (start_area->south)->spawn_character(gob);

    cout << "GOBLIN IS OF TYPE: " << gob->type() << endl;
    cout << "GOBLIN IS DOING DMG: " << gob->damage() << endl;

    player1->fight(gob);



    //player1->fight(player2);

    cout << "-----------------" << endl;
    game_map->print_areas();
    cout << "-----------------" << endl;
 */
