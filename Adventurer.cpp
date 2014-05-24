//
//  Adventurer.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-07.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Adventurer.h"
#include "gamemap.h"
#include <iostream>
#include <sstream>
//#include "North.h"

#define NORTH "north"
#define WEST "west"
#define EAST "east"
#define SOUTH "south"



namespace AdventureWorld
{	
	Adventurer::Adventurer(int hitpoints, 
				string dmg_type, 
				string character_type, 
				string name_string) : Character(hitpoints, 
											dmg_type, 
										    character_type, 
											name_string)
	{
		//game_map = Map::getMap();
		//this->current_area_pointer = game_map.get_root_area(); //Get the root area
		
		//1. GET MAP
		//2. GET ROOT AREA
	}	

	Adventurer::~Adventurer(void)
	{
		//Empty destructor
	}
      
  int Adventurer::action(){
     int choice = 0;
        if (is_under_attack() == false) {

            cout << "\nWhat do you want to do?" << endl;
            cout << "1. Move" << endl;
            cout << "2. Inventory" << endl;
            cout << "3. Spellbook" << endl;
            cout << "4. See" << endl;
            cout << "5. Directions" << endl;
	        cout << "6. Map" << endl;
        }
        else if (is_under_attack() == true)
        {
            cout << "\nYou are under attack! pick a choice!" << endl;
            cout << "7. Flee" << endl;
            cout << "8. Fight back" << endl;
        }
       
        cin >> choice;
        string dummyStr;
        getline(cin, dummyStr); //Eats the /n from cin
        return choice;
  }

  void Adventurer::fight(Character * c) { 

        Spell * choosen_spell = 0;
        Item * choosen_item = 0; 
        int spell_count = 0;
        int item_count = 0;
        int index_count = 0;

        vector<Spell*> * spells = (this->spellbook)->get_spells();
        vector<Spell*>::iterator it;
        
        vector<Item*> * items = (this->inventory)->get_items();
        vector<Item*>::iterator item_it;

        for(item_it = items->begin(); item_it != items->end(); ++item_it) {
            //if((*item_it)->get_type() == "Weapon") {
                item_count++;
                index_count++;
                cout << index_count << ". " << (*item_it)->get_name() << "(" << (*item_it)->get_dmg() << ")" << endl;
            //}
        }

        for (it = spells->begin(); it != spells->end(); ++it) {
            if ((*it)->get_type() == "Spell") {
                spell_count++;
                index_count++;
                cout << index_count << ". " << (*it)->get_name() << "(" << (*it)->get_dmg() << ")" << endl;  
            }
        }
        if ((item_count > 0) || (spell_count > 0)) {
            cout << "\n\nChoose an action:" << endl;
            int choice = 0;
            cin >> choice;
            string dummyStr;
            getline(cin, dummyStr); //Eats the /n from cin
            if(((int)choice) <= item_count){
                cout << "index: " << ((int)choice)-1 << endl;
                choosen_item = items->at(((int)choice)-1);
            } else {
                cout << "index: " << ((int)choice)-1-item_count << endl;
                choosen_spell = spells->at(((int)choice)-1-item_count);
            }

            
        }

        
        
        if ((this->life()) > 0)
        {   

                int dmg = 0;

                if (choosen_spell != 0) {
                    dmg = choosen_spell->get_dmg();
                } else if (choosen_item != 0){
                    dmg = choosen_item->get_dmg();
                } else {
                    dmg = this->damage();
                }
               
                cout << this->name() << " attacks " << c->name() << " and hit for " << dmg << " damage!" << endl;
                c->reduce_life(dmg);
                if (c->life() == 0)
                {
                    this->set_under_attack(false);
                    this->loot(c);
                }
        }
        else
        {
            this->set_under_attack(false);
            //cout << this->name() << "is dead!" << endl;
        }

        item_count = 0;
        spell_count = 0;
        //if (Inventory contains spells)
        //cout << "1. Throw spell" << endl;
        // Throw spell

        //else if (Weapon is mounted)
        //cout << "2. Wield weapon" << endl;

        //else if (Spell & Weapon)
        //cout << "1. Throw spell" << endl;
        //cout << "2. Wield weapon" << endl;
        //Do what the player chooses

    }

	void Adventurer::move(GameMap * gm)
	{
                Area * area = gm->find_character(this);
                gm->print_areas();
                cout << "\nWhat direction would you like to go?\nanswer with a direction, for example: north\n" << endl;
                if (area->north != 0)
                        cout << "north -> " << (area->north)->get_name() << endl; 
                if (area->east != 0)
                        cout << "east -> " << (area->east)->get_name() << endl;
                if (area->west != 0)
                        cout << "west -> " << (area->west)->get_name() << endl; 
                if (area->south != 0)
                        cout << "south -> " << (area->south)->get_name() << endl; 
                
                string direction;
		getline(cin, direction);
                
                if (direction == NORTH)         
                        gm->move_character(this, area->north);
                else if(direction == EAST)
                        gm->move_character(this, area->east); 
                else if(direction == WEST)
                        gm->move_character(this, area->west); 
                else if(direction == SOUTH)
                        gm->move_character(this, area->south);
                else
                    cout << "faulty input, try again" << endl;
                    
			
		 
		/*TODO: The original purpose of this function was to
		create a new area and add it to the game map, then add the character to that map
		however, since you ought to be able to get directions 
		(i.e see what areas are next to you) it would be better if neighbour-areas were 
		created when a new area was created, then this move-
		function would not call add_area(), rather it should call 
		GameMap::move_character_to(Direction). */
		
		//GameMap::move_character_to(this_character, d);
		
		//REQUIRES STATIC GameMap!
		//TA BORT DETTA NÄR DET OVAN ÄR LÖST!
	}
	
}
