/* 
 * File:   Fireball.h
 * Author: Niclas
 * 
 * Created on den 16 December 2013, 17:20
 */

 #ifndef FIREBALL_H
 #define FIREBALL_H
 
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Spell.h"
 using namespace std;

 namespace AdventureWorld{
 	class Fireball : public Spell 
 	{
 		public:
 			Fireball();
			//Fireball(const Fireball& orig); 
			virtual ~Fireball();
 			string get_type() const;
        	string get_name() const;
        	string damage_type() const;
        	int get_dmg() const;
 		protected:
 			void set_cooldown(int);
 			int get_cooldown();
 		private:
 			int cooldown;
 			string name;
 			string dmg_type;
 	};
 }
 #endif 