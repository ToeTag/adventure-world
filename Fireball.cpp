/* 
 * File:   Fireball.cpp
 * Author: Niclas
 * 
 * Created on den 16 December 2013, 16:42
 */
 #include "Fireball.h"
 #include <iostream>

 using namespace std;

 namespace AdventureWorld {
	
	Fireball::Fireball() : Spell(50, 20, "Fireball"), cooldown(20) {
		this->name = "Fireball";
		this->dmg_type = "magical";
	}

	/*Fireball::Fireball(const Fireball& orig) {
	}*/

	Fireball::~Fireball() {
	}

	int Fireball::get_dmg() const {
		return this->damage;
	}

	string Fireball::get_type() const {
		return this->type;
	}

	string Fireball::get_name() const {
		return this->name;
	}

	string Fireball::damage_type() const {
		return this->dmg_type;
	}

	void Fireball::set_cooldown(int new_cooldown) {
		this->cooldown = new_cooldown;
	}

	int Fireball::get_cooldown() {
		return cooldown;
	} 	
 }
