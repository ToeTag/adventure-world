//
//  GameMap.h
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-13.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include "Area.h"
using namespace std;

namespace AdventureWorld
{
	class GameMap
	{	
             
   
		public:
			GameMap(int, int);
                        ~GameMap(void);
			//friend GameMap operator+<>(const GameMap&, const GameMap&);
                        //friend GameMap operator-<>(const GameMap&, const GameMap&);
                        void print_areas() const;
                        void move_character(Character * c, Area *);
                        Area * find_character(Character *) const;
                        Area * get_area_from_coords(int row, int col) const;
                        void refresh_map();
                        void get_coords_from_area(Area * a, int & out_row, int & out_col) const;
			
		private:
                    void assign_neighbours(void);
                    Area **areas ;
                    int cols;
                    int rows;
	};
}
#endif