/* 
 * File:   Spell.h
 * Author: Niclas
 * 
 * Created on den 16 December 2013, 16:42
 */
 #ifndef SPELL_H
 #define SPELL_H
 
#include <string.h>
#include <stdlib.h>
#include <iostream>
 using namespace std;

 namespace AdventureWorld{
 	class Spell 
 	{
 		public:
 			Spell();
			Spell(const Spell& orig); 
			~Spell();
 			virtual string get_type() const = 0;
        	virtual string get_name() const = 0;
        	virtual int get_dmg() const = 0;
 		protected:
 			virtual void set_cooldown(int);
 			virtual int get_cooldown();
 		private:
 			int cooldown;
 	};
 }
 #endif 