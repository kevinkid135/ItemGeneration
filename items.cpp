/*
 * items.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: Kevin
 */
#include <iostream>
#include <string>
#include "items.h"

using namespace std;

/*Methods for picking up items *pseudocode*
Item::getItem( Item right ){
	if(item.def > player.def){
		player.def = item.def;
		print ("You equiped " + item.name)
	}
}
*/

Item::Item(){
	name = "";
	description = "";
	quantity = 0;
}
Item::~Item(){}

Item::Item(const string nam) : name(nam), description("this is a tooltip"), quantity(1) {}

Item::Item(const string nam, int num) : name(nam), description("this is a tooltip"), quantity(num) {}

string Item::getName() const {
	return name;
}
string Item::getDescr() const {
	return description;
}
int Item::getQtty() const {
	return quantity;
}

Potion::Potion(const string nam, int h, int s, int d) : Item(nam), hp(h), str(s), def (d){}

void Potion::getPotion(){
	cout << getName() << endl;
	cout << getDescr() << endl;
	cout << getQtty() << endl;
	cout << hp << endl;
	cout << str << endl;
	cout << def << endl;
}

Weapon::Weapon(const string nam, int s) : Item(nam), str(s){}

void Weapon::getWeapon(){
	cout << getName() << endl;
	cout << getDescr() << endl;
	cout << getQtty() << endl;
	cout << str << endl;
}

Armour::Armour(string n, int id, int defence) : Item(n), type(id), def(defence){}

void Armour::getArmour(){
	cout << type << endl;
	cout << def << endl;
}

Gold::Gold(int a) : Item("Gold"), amount(a){}

int Gold::getAmount() {
	return amount;
}
Item Item::generateItem(){
string posAdjLis1[] = {
    "Large",
    "Stirdy",
    "Impressive",
    "Friendly",
    "Interesting",
    "Ethereal",
    "Dark",
    "Courageous",
    "New",
    "Wide",
    "Broad",
    "Zealous",
    "Trinity",
    "Holy",
    "Powerful",
    "Enchanted",
    "Solid",
    "Righteous",
    "Solid",
    "Glowing"
};
vector <string> posAdjLis (posAdjLis1, posAdjLis1 + 20);
string negAdjLis1[] = {
    "Tiny",
    "Rusty",
    "Flimsy",
    "Plastic",
    "Chippted",
    "Damaged",
    "Bent",
    "Broken",
    "Prototype",
    "Strange",
    "Triggered",
    "Pale",
    "Cursed",
    "Dull",
    "Economic",
    "Limp",
    "Flacid"
};
vector <string> negAdjLis (negAdjLis1, negAdjLis1 + 17);

string materialLis1[] = {
    "Bronze",
    "Silver",
    "Gold",
    "Platinum",
    "Diamond"
};
vector <string> materialLis (materialLis1, materialLis1 + 5);

string weaponNameLis1[] = {
    "Sword",
    "Club",
    "Spear",
    "Mace",
    "Shield",
    "Stick",
    "Axe",
    "Dagger",
    "Door",
    "Sickle",
    "Trident",
    "Halberd",
    "War Hammer"
};
vector <string> weaponNameLis(weaponNameLis1, weaponNameLis1 + 13);

string armourNameLis1[] = {
    "Helmet",
    "Chest",
    "Legs",
    "Boots"
};
vector <string> armourNameLis(armourNameLis1, armourNameLis1 + 4);

	int level = 1;

	srand(time(NULL)); // seed for random generator
	int itemType = rand() % 10; //changed from 100 -Blaise
	cout << itemType << endl;

	// attributes
	int mult = level * 10;
	int stat = rand() % 9;

	// create weapon, armour, potion, gold
	if (itemType < 2) { // weapon or armour
		string adj;
		// select adjective
		if (stat % 2 == 0) {
			adj = random(negAdjLis);
			//cout << adj<< "hello\n";
		} else {
			adj = random(posAdjLis);
			//cout << adj << "hello\n";
		}

		// select material
		string material;
		if (stat <= 1) {
			material = materialLis[0];
		} else if (stat <= 3) {
			material = materialLis[1];
		} else if (stat <= 5) {
			material = materialLis[2];
		} else if (stat <= 7) {
			material = materialLis[3];
		} else if (stat <= 9) {
			material = materialLis[4];
		}

		if (itemType == 0) {
			// weapon
			string wepName = adj + " " + material + " " + random(weaponNameLis);
			return Weapon(wepName, mult + stat);
		} else if (itemType == 1) {
			// armour
			int armType = rand() % 4;
			string armName = adj + " " + material + " " + armourNameLis1[armType];
			return Armour(armName, armType + 1, mult + stat);
		}
	} else if (itemType < 5) { // potion
		// select item type
		int potType = rand() % 7;
		string potName;
		if (potType <= 1) {
			return Potion("HP Potion", stat, 0, 0);
		} else if (potType <= 3) {
			return Potion("Str Potion", 0, stat, 0);
		} else if (potType <= 5) {
			return Potion("Def Potion", 0, 0, stat);
		} else { // potType == 6
			return Potion("? Potion", rand() % 9, rand() % 9, rand() % 9);
		}
	} else if (itemType < 10) { // gold
		return Gold(mult + stat);
	} else {
		// no item is generated.
		return Item();
	}
}

string Item::random(vector <string> arr) {
    // pick random number
    int index = rand() % arr.size();
    //cout << arr.at(index) << "hello\n";
    return arr.at(index);
    //return arr[index];
    //return "";
}

