#include "glue.h"
using namespace std;
enum Itypes{consumable,weapon,armor};
enum Stypes{phys_attack,magic_attack,healing,buff};
//Skill class, modifies player's damage during calculations when used, different types have different costs
Skill::Skill(){
    this->name = "Dummy";
    this->modifier = 0.0;
}
Skill::Skill(string name,string flavor_text,int cost,double modifier,int type){
    this-> name = name;
    this-> flavor_text = flavor_text;
    this-> cost = cost;
    this-> modifier = modifier;
    this-> type = type;
}
string Skill::Get_Name(){
    return name;
}
string Skill::Get_Flavor(){
    return flavor_text;
}
double Skill::Get_Modifier(){
    return modifier;
}
int Skill::Get_Type(){
    return type;
}
int Skill::Get_Cost(){
    return cost;
}

//Item class, assigns values based on "Type"
Item::Item(){
    this->name = "Empty";
    this->value = 0;
}
Item::Item(string name, int value,int modifier,int type)
{
    this-> name = name;
    this-> value = value;
    this->type = type;
    if(type == consumable){
        this->healing = modifier;
        this->attack = -1;
        this->defense = -1;
    }
    else if(type == weapon){
        this->attack = modifier;
        this->defense = -1;
        this->healing = -1;
    }
    else{
        this->defense = modifier;
        this->attack = -1;
        this->healing = -1;
    }
}

string Item::Get_Name(){
    return name;
}
int Item::Get_Value(){
    return value;
}
int Item::Get_Attack(){
    return attack;
}
int Item::Get_Defense(){
    return defense;
}
int Item::Get_Healing(){
    return healing;
}
int Item::Get_Type(){
    return type;
}
string Item::Full_Display(){
    string output = "";
    output = output + name+"\n"+to_string(value)+" currency\n";
    if(type == consumable){
        output = output + "Heals "+to_string(healing)+" HP\n";
    }
    else if(type == weapon){
        output = output + to_string(attack) + " ATK\n";
    }
    else{
        output = output + to_string(defense) + " DEF\n";
    }
    return output;
}
//Character Class
//Empty (Dummy) Character
Character::Character(){
    this->name = "None";
    this->hp = 0;
    this->tmp_hp = 0;
    this->attack = 0;
    this->defense = 0;    
}
Character::Character(string name,int hp,int attack,int defense)
{
    this->name = name;
    this->hp = hp;
    this->tmp_hp = hp;
    this->attack = attack;
    this->defense = defense;
    
}

//Character Getters
string Character::Get_Name(){
    return name;
}
int Character::Get_HP(){
    return hp;
}
int Character::Get_tmp_hp(){
    return tmp_hp;
}
int Character::Get_Attack(){
    return attack;
}
int Character::Get_Defense(){
    return defense;
}

//Character Setters
void Character::Set_Name(string change){
    this->name = change;
}
void Character::Set_HP(int change){
    this->hp = change;
}
void Character::Set_tmp_hp(int change){
    this->tmp_hp = change;
}
void Character::Set_Attack(int change){
    this->attack = change;
}
void Character::Set_Defense(int change){
    this->defense = change;
}

//Monster class(inherits Character)
Monster::Monster(string name, int hp, int attack, int defense, int exp_drop, int gold, int ai_type, Item drop):Character::Character(name,hp,attack,defense){
    this->exp_drop = exp_drop;
    this->gold = gold;
    this->ai_type = ai_type;
    this->drop = drop;
}

//Monster Getters
int Monster::Get_Exp_Drop(){
    return exp_drop;
}
int Monster::Get_Gold(){
    return gold;
}
int Monster::Get_Ai_Type(){
    return ai_type;
}
Item Monster::Get_Drop(){
    return drop;
}

//Hero class (inherits Character)
Hero::Hero(string name,int level,int exp, int hp,int mp, int attack, int defense):Character::Character(name,hp,attack,defense){
    this->level = level;
    this->exp = exp;
    this->mp = mp;
    this->tmp_mp = mp;
    this->inventory_count = 0;
    this->skill_count = 0;
    //Attack skill is always available, x1 modifier, keeps with "modular skills" avoiding having to code each one
    skill_list[0] = Skill("Attack","attacks!",0,1.0,phys_attack);
}

//Hero Getters
int Hero::Get_Level(){
    return level;
}
int Hero::Get_Exp(){
    return exp;
}
int Hero::Get_MP(){
    return mp;
}
int Hero::Get_tmp_mp(){
    return tmp_mp;
}
int Hero::Get_Inventory_Count(){
    return inventory_count;
}
int Hero::Get_Skill_Count(){
    return skill_count;
}

//Hero setters
void Hero::Set_Level(int change){
    this->level = change;
}
void Hero::Set_Exp(int change){
    this->exp = change;
}
void Hero::Set_MP(int change){
    this->mp = change;
}
void Hero::Set_tmp_mp(int change){
    this->tmp_mp = change;
}

//Hero public functions
//-----------------------------------------------------------------------------
//Adds passed item/skill to the next slot in inventory
void Hero::Gain_Item(Item get){
    inventory_count++;
    inventory[inventory_count] = get;
}
void Hero::Gain_Skill(Skill get){
    skill_count++;
    skill_list[skill_count] = get;
}

//Displays all of Hero's info as a string
string Hero::Show_Info(){
    string output = "Name: " + name +"\n";
    output = output + "Level: " + to_string(level) + "\n";
    output = output + "Exp: " + to_string(exp) + "\n";
    output = output + "Hp: " + to_string(tmp_hp) + "/" + to_string(hp) + "\n";
    output = output + "Mp: " + to_string(tmp_mp) + "/" + to_string(mp) + "\n";
    output = output + "Attack: " + to_string(attack) + "\n";
    output = output + "Defense: " + to_string(defense) + "\n";
    return output;
}

//Returns pointer to inventory for various uses
//Reminder: Item * pointer = Hero.Show_Inventory(); then it works like your standard array[]
Item * Hero::Show_Inventory(){
    return inventory;
}
//Returns a specific item/skill from inventory
Item Hero::Show_Inventory_Item(int target){
    return inventory[target];
}
Skill Hero::Get_Target_Skill(int target){
    return skill_list[target];
}