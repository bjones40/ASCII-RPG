#include "glue.h"
using namespace std;
//Generic Item Class
Item::Item(){
    this->name = "Empty";
    this->value = 0;
}
Item::Item(string name, int value)
{
    this-> name = name;
    this-> value = value;
}
string Item::Get_Name(){
    return name;
}
int Item::Get_Value(){
    return value;
}

//Weapon Class
Weapon::Weapon(string name, int value, int attack):Item::Item(name,value){
    this-> attack = attack;
}
int Weapon::Get_Attack(){
    return attack;
}

//Hero Class
Hero::Hero(int hp,int mp,int attack,int defense)
{
    this->hp = hp;
    this->tmphp = hp;
    this->attack = attack;
    this->defense = defense;
    this->mp = mp;
    this->tmpmp = mp;
    this->inventory_count = 0;
}

//Hero Getters
int Hero::Get_HP(){
    return hp;
}
int Hero::Get_Tmphp(){
    return tmphp;
}
int Hero::Get_Attack(){
    return attack;
}
int Hero::Get_Defense(){
    return defense;
}
int Hero::Get_MP(){
    return mp;
}
int Hero::Get_Tmpmp(){
    return tmpmp;
}

//Adds passed item to lowest slot in inventory
void Hero::Gain_Item(Item get){
    inventory[inventory_count] = get;
    inventory_count++;
}

//Returns pointer to inventory for various uses
Item * Hero::Show_Inventory(){
    return inventory;
}