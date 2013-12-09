//
//  GameMap.cpp
//  AdventureWorld
//
//  Created by Niclas Kempe on 2012-08-13.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

/*
Position of the Characters (Structure the areas as 4- or 16-tile squares/matrices?)
Store the characters in the tiles (Each tile is a container)
Environment details in the tiles (Each tile is a container)

So each tile is represented by a container-class able to contain both Environment and-
Characters.

The navigation can be done with a binary tree, if a right-child-node and/or left-child-node 
is present those are feasible choices for navigation. Each area is built up by a binary-tree
where each node is a "tile". Travel is done by stepping through the binary-tree.

*/



#define NORTH "NORTH"
#define WEST "WEST"
#define EAST "EAST"
#define SOUTH "SOUTH"
#define ROOT "ROOT"


#include "gamemap.h"
#include "Area.h"
#include <string>



namespace AdventureWorld
{	
	
        GameMap::GameMap(int r, int c)
	{
                // Allocate memory
            this->rows = r;
            this->cols = c;
                areas = new Area*[rows];
                for (int i = 0; i < rows; ++i)
                {
                        areas[i] = new Area[cols];
                        //cout << (i+1)*cols << " Areas created.." << endl;
                        
                }
                
                assign_neighbours();
                
	}	
        
        void GameMap::assign_neighbours()
        {
            for(int i = 0; i < rows; i++)
                        {
                            for(int j = 0; j < cols; j++)
                            {
                                //North west corner
                                if (i == 0 && j == 0)
                                {
                                    cout << "NW neighbours added" << endl;
                                    (areas[i][j]).north = 0;
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = 0;
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                                //North east corner
                                else if (i == 0 && j == cols-1)
                                {
                                    cout << "NE neighbours added" << endl;
                                    (areas[i][j]).north = 0;
                                    (areas[i][j]).east = 0;
                                    (areas[i][j]).west = &areas[i][j-1];;
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                                //South east corner
                                else if (i == rows-1 && j == cols-1)
                                {
                                    cout << "SE corner neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = 0;
                                    (areas[i][j]).west = &areas[i][j-1];
                                    (areas[i][j]).south = 0;
                                }
                                //South west corner
                                else if (i == rows-1 && j == 0)
                                {
                                    cout << "SW corner neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = 0;
                                    (areas[i][j]).south = 0;
                                }
                                //Edge left
                                else if ((i != 0 && j == 0) && (i != rows-1))
                                {
                                    cout << "Left neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = 0;
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                                 //Edge right
                                else if ((i != 0 && j == cols-1) && (i != rows-1))
                                {
                                    cout << "Right neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = 0;
                                    (areas[i][j]).west = &areas[i][j-1];
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                                //Edge top
                                else if ((i == 0 && j != 0) && (j != cols-1))
                                {
                                    cout << "Top neighbours added" << endl;
                                    (areas[i][j]).north = 0;
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = &areas[i][j-1];
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                                //Edge bot
                                else if ((i == rows-1 && j != 0) && (j != cols-1))
                                {
                                    cout << "Bot neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = &areas[i][j-1];
                                    (areas[i][j]).south = 0;
                                }
                                 //Others
                                else if ((i != 0 && j != 0) && (i != rows-1 && j != cols-1))
                                {
                                    cout << "Mid neighbours added" << endl;
                                    (areas[i][j]).north = &areas[i-1][j];
                                    (areas[i][j]).east = &areas[i][j+1];
                                    (areas[i][j]).west = &areas[i][j-1];
                                    (areas[i][j]).south = &areas[i+1][j];
                                }
                            }
                        }
        }
        
        GameMap::~GameMap()
        {
            for (int i = 0; i < rows; ++i)
                        delete [] areas[i];
                delete [] areas;
        }
	
        Area * GameMap::get_area_from_coords(int row, int col) const
        {
            return &areas[row][col];
        }
        
        void GameMap::get_coords_from_area(Area * a, int & out_row, int & out_col) const
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                if (this->areas[i][j] == *a)
                {
                    out_row = i;
                    out_col = j;
                }
                
            }
        }
        
        Area* GameMap::find_character(Character * c) const
        {
            
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                if ((this->areas[i][j]).is_character_present(c) == true)
                {
                    return &(this->areas[i][j]);
                }
                
            }
        }
        
        void GameMap::move_character(Character * c, Area * direction_ptr)
        {
            Area * cur_area = find_character(c);
            Area * new_area = direction_ptr;

	    if (new_area != NULL){
	      new_area->spawn_character(c);
	      cur_area->remove_character(c);
	    } else {
	      cout << "\nYou can't move any further in that direction!" << endl; 
	    } 
        }
        
        void GameMap::refresh_map()
        {
         for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    (this->areas[i][j]).clear_corpses();
                }
                
            }
        }

        void GameMap::print_areas() const
        {
            cout << "Printing the map, amount of characters in each area within parenthesises" << endl;
            cout << "----------------------- MAP -----------------------" << endl;
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    cout << "(" << (this->areas[i][j]).num_of_characters() << ")";
                    //cout << (this->areas[i][j]).get_name() << "(" << (this->areas[i][j]).num_of_characters() << ")" << "\t\t\t"; 
                }
                cout << endl;
            }
            cout << "\n" << endl;
        }

      
       /* GameMap operator+(const GameMap& a, const GameMap& b)
        {
            //declare a matrix temp of type T to store the result and return this matrix
            GameMap temp;
            for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            temp.areas[i][j] = a.areas[i][j] + b.areas[i][j];
            return temp;
        }

       
        GameMap operator-(const GameMap& a, const GameMap& b)
        {
            GameMap temp;
            for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            temp.areas[i][j] = a.areas[i][j] - b.areas[i][j];
            return temp;
        }
        */
}



///*
//			Pseudo code for N,E,W,S
//			If player chooses N,E,W,S that will be set as the next pointer in the new node.
//			
//			Player -> East
//			if (East == 0)
//				new_area
//				new_area->east = last_area->east
//			Player -> West
//				new_area
//				new_area->west = last_area->east
//			Player -> South
//				new_area
//				new_area->south = last_area->north
//			Player -> North
//				new_area
//				new_area->north = last_area->south
//		*/
//            /*
//             //Backup
//             
//             Area *temp = 0;
//	     temp = new_area;
//	     temp->next = head;
//             head = temp; 
//             
//             */
//           
//			Area *temp = 0;
//			temp = new_area;
//			temp->north = head->south;
//                        temp->east = new Area();
//                        temp->west = new Area();
//                        temp->south = new Area();
//			head = temp;
//                        
//                        
//                        
//           
//                        
//		this->num_of_areas++;
//	}
//	
//	/*GameMap * GameMap::get_instance()
//	{
//		GameMap * map = new GameMap();
//		return map;
//	}*/
//	
//	
//	
//	Area * GameMap::print(int Position)
//	{
//		/*Area *Current = head;
//		for(int i = get_num_of_areas() - 1; i > Position && Current != NULL; i--)
//		{
//			Current = Current->next;
//		}
//		return Current;*/
//	}
//	
//	int GameMap::get_num_of_areas()
//	{
//		return num_of_areas;
//	}
//	
//        Area * GameMap::get_pos_of_character(Character * c)
//        {
//             /*Area *temp = 0;
//	     temp = new_area;
//	     temp->next = head;
//             head = temp; */
//             
//             Area *Current = head;
//
//                for(int i = get_num_of_areas() - 1; i > 0 && Current != 0; i--)
//
//                {
//                    Area * area_found = Current->get_character_area(c);
//                    if (area_found != 0)
//                    {
//                        return area_found;
//                    }
//                    Area * next = North;
//                    while(Current->next != 0)
//                    {
//                        Current = Current->next;
//                    }
//                    Current = head;
//                    next = East;
//                    
//                    //GÅ IFRÅN LÄNKADE LISTOR??? BLIR FÖR KOMPLEXT MED 4 RIKTNINGAR???
//                }
//
//
//
//                return Current;
//        }
//        
//	void GameMap::move_character_to(Character * character, string dir)
//	{
//           Area * position = 
//          switch ( dir ) {
//		  case NORTH:            // Note the colon, not a semicolon
//			
//			break;
//		  case EAST:            // Note the colon, not a semicolon
//                  {
//                      if ((position->east) == 0)
//                      {
//                          position->east = new Area();
//                      }
//                      
//                      if((position->north)->east == 0)
//                      {
//                          (position->east)->north = new Area();
//                      }
//                      
//                      if((position->south)->east == 0)
//                      {
//                          (position->east)->south = new Area();
//                      }
//                      break;
//                  }
//			
//		  case SOUTH:            // Note the colon, not a semicolon
//			
//			break;
//		  case WEST:            // Note the colon, not a semicolon
//			
//			break;
//		  default:            // Note the colon, not a semicolon
//			cout << "Error! Wrong in randomization, number was " << num << endl;
//			break;
//		  }      
//		
//                
//	}
