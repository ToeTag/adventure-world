/* 
 * File:   Spell.cpp
 * Author: Niclas
 * 
 * Created on den 16 December 2013, 16:42
 */
 #include "spell.h"
 #include <iostream>

 using namespace std;

 namespace AdventureWorld {

	Spell::Spell(int damage, int cooldown, string name) {
		this->damage = damage;
		this->cooldown = cooldown;
		this->name = name;
		this->type = "Spell";
	}

	Spell::Spell(const Spell& orig) {
	}

	Spell::~Spell() {
	}

	void Spell::set_cooldown(int new_cooldown) {
		this->cooldown = new_cooldown;
	}

	int Spell::get_cooldown() const {
		return this->cooldown;
	} 

	string Spell::get_type() const {
		return this->type;
	}

	string Spell::get_name() const {
		return this->name;
	}

	int Spell::get_dmg() const {
		return this->damage;
	}


	void Spell::cast() const {

	}

	ostream& Spell::print(ostream& out) const {
        // Since operator<< is a friend of the Point class, we can access
        // Point's members directly.

        out << this->get_type() << " - " << this->get_name() << " (" << this->get_dmg() << ")";
		//out << "";
        return out;
    }
 }
