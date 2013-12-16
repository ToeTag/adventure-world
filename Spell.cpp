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
	
	Spell::Spell() {
	}

	Spell::Spell(const Spell& orig) {
	}

	Spell::~Spell() {
	}

	void Spell::set_cooldown(int new_cooldown) {
		this->cooldown = new_cooldown;
	}

	int Spell::get_cooldown() {
		return cooldown;
	} 	
 }
