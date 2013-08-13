//
//  Area.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-19.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Area.h"

using namespace std;

namespace AdventureWorld
{
	
	Area::Area() : north(0), east(0), west(0), south(0)
	{
		random_name();
		character_vec = new vector<Character*>();
                item_vec = new vector<Item*>();
                cout << "Area created " << endl;
	}
	
	Area::~Area()
	{
        
        }
	string Area::get_name() const
	{
		return this->name;
	}
	
	void Area::spawn_character(Character * c)
	{
                //character_vec = new vector<Character*>();
                
		character_vec->push_back(c);
                this->num_of_chars++;
	}
        
        void Area::spawn_item(Item * i) //TODO: Add similar functionality as for characters, templates?
	{
                //character_vec = new vector<Character*>();
		item_vec->push_back(i);
                //this->num_of_chars++;
	}
        
	
	void Area::remove_character(Character * c)
	{
            vector<Character*>::iterator it;

            for(it = character_vec->begin(); it != character_vec->end(); ++it)
            {
                if (*it == c)
                {
                    it = character_vec->erase(it);
                    this->num_of_chars--;
                    break;
                }
            }
            
	}
        
        void Area::print_neighbours() const
        {
             if (this->north != 0)
                        cout << "north ->1 " << (this->north)->get_name() << endl; 
                if (this->east != 0)
                        cout << "east -> " << (this->east)->get_name() << endl;
                if (this->west != 0)
                        cout << "west -> " << (this->west)->get_name() << endl; 
                if (this->south != 0)
                        cout << "south -> " << (this->south)->get_name() << endl;
        }
        
        bool Area::clear_corpses()
	{
            vector<Character*>::iterator it;
          
            for(it = character_vec->begin(); it != character_vec->end(); ++it)
            {
             
                if ((*it)->life() == 0)
                {
                    it = character_vec->erase(it);
                    this->num_of_chars--;
                    break;
                }
            }
            return false;
	}
        
        bool Area::is_character_present(Character * c) const
	{
            vector<Character*>::iterator it;

            for(it = character_vec->begin(); it != character_vec->end(); ++it)
            {
                if (*it == c)
                {
                    return true;
                }
            }
            return false;
	}
	
	void Area::print_characters() const
	{
            vector<Character*>::iterator it;

            for(it = character_vec->begin(); it != character_vec->end(); ++it)
            {
                    cout << (*it)->name() << "(" << (*it)->type() << ")" << endl;
            }
	}
        
        int Area::num_of_characters() const
	{
            return num_of_chars;
	}
        
        
	
	string Area::description() const
	{
		string desc = "this is an area";
		return desc;
	}
	
	void Area::random_name()
	{
		int num = rand() % 4 + 1;
		 switch ( num ) {
		  case 1:            // Note the colon, not a semicolon
			this->name = "The Misty Mountains  ";
			break;
		  case 2:            // Note the colon, not a semicolon
			this->name = "The Dark Swamps      ";
			break;
		  case 3:            // Note the colon, not a semicolon
			this->name = "The Barren Wastelands";
			break;
		  case 4:            // Note the colon, not a semicolon
			this->name = "The Black Forest ";
			break;
		  default:            // Note the colon, not a semicolon
			cout << "Error! Wrong in randomization, number was " << num << endl;
			break;
		  }
		
		
	}
        
        bool Area::operator==(const Area &other) const {
            return (*this == other);
        }
        
       
	

    ostream& operator<< (ostream &out, Area &a)
    {
        // Since operator<< is a friend of the Point class, we can access
        // Point's members directly.
        out << a.get_name() << "(" <<
            a.num_of_characters() << ")" << endl;
        return out;
    }
}	
	