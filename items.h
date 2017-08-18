/*
 * items.h
 *
 *  Created on: Nov 14, 2016
 *      Author: Kevin
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#define HELMET	1
#define CHEST 	2
#define LEGS	3
#define BOOTS	4

using namespace std;

class Item {
public:
	Item(); //default constructor
	Item(const string); // only name
	Item(const string, int); // name and count
	virtual ~Item(); // destructor
	Item generateItem(); // generates an item
	string random(vector <string>); // select a random element inside an array
	string getName() const; 
	string getDescr() const;
	int getQtty() const;
private:
	string name;
	string description;
	int quantity;
};

class Potion : public Item {
public:
	Potion(const string, int, int, int); // name, hp, str, def
	void getPotion(); // prints stats
private:
	int hp;
	int str;
	int def;
};

class Weapon : public Item {
public:
	Weapon(const string, int); // name, str
	void getWeapon(); // print stats
private:
	int str;
};

class Armour : public Item {
public:
	Armour(const string, int, int); // name, type, def
	void getArmour();
private:
	int type;   //type is the item id (eg, pants = 1, helmet = 2, chestplate = 3;
                // can be done through the use of #define statements.
	int def;
};

class Gold : public Item {
public:
	Gold(int a); // amount
	int getAmount();
private:
	int amount;
};
