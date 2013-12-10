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
            cout << "3. Directions" << endl;
            cout << "4. See" << endl;
	        cout << "5. Map" << endl;
        }
        else if (is_under_attack() == true)
        {
            cout << "\nYou are under attack! pick a choice!" << endl;
            cout << "6. Flee" << endl;
            cout << "7. Fight back" << endl;
        }
       
        cin >> choice;
        string dummyStr;
        getline(cin, dummyStr); //Eats the /n from cin
        return choice;
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
