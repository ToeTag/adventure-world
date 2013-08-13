//
//  Area.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-19.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AREA_H
#define AREA_H


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Character.h"


using namespace std;

namespace AdventureWorld
{
	class Area
	{
		public:
			Area(void);
                        ~Area(void);
			Area * north;
			Area * east;
			Area * west;
			Area * south;
			string description(void) const;
			string get_name(void) const;
                        
                        // Characters
                        
			vector<Character*> * character_vec;
			void spawn_character(Character * c);
			void remove_character(Character * c);
                        bool is_character_present(Character * c) const;
                        bool clear_corpses(void);
			void print_characters() const;
                        void print_neighbours() const;
                        int num_of_characters() const;
                        
                        // Items
                        
                        vector<Item*> * item_vec;
                        void spawn_item(Item * i);
                        static int num_of_areas;
                        bool operator==(const Area &other) const;
                        friend ostream& operator<< (ostream &, Area &);
		protected:
			//void spawn_item(Item);
			//void spawn_object(Object);
			//void spawn_character(Character &);
			
			
			
			//virtual string direction(string);
			
			/*virtual string neighbour(string)
			virtual Area enter(Character);
			virtual Area leave(Character);
			virtual string type();
			virtual string random_name();
			virtual string name;
			*/
		private:
                        int num_of_chars;
			void random_name();
			string name;
	};
}

#endif