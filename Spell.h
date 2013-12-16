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
 			Spell(int damage, int cooldown, string name);
			Spell(const Spell& orig); 
			virtual ~Spell();
 			virtual string get_type() const;
        	virtual string get_name() const;
        	virtual int get_dmg() const;
    		virtual void cast() const;
    		virtual ostream& print(ostream& out) const;
 		protected:
 			virtual void set_cooldown(int);
 			virtual int get_cooldown() const;
 			int damage;
 			int cooldown;
 			string type;
 			string name;
 		private:
 			
 	};
 }
 #endif 