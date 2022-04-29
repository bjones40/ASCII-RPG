#include "glue.h"
using namespace std;
#include <iostream>
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
//Skill Getters
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
Item::Item(string name, int type){
    this-> name = name;
    this-> type = type;
    this-> healing = -1;
    this-> attack = -1;
    this-> defense = -1;
}
Item::Item(string name, int value,int modifier,int type)
{
    this-> name = name;
    this-> value = value;
    this-> type = type;
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
//Item Getters
//-----------------------------------------------------------------------------
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
int Item::Get_Quantity(){
    return quantity;
}
//Item Setters
//-----------------------------------------------------------------------------
void Item::Set_Quantity(int input){
    quantity = input;
}
//Outputs all Item info
string Item::Full_Display(){
    string output = "";
    output += name+"\n";
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
//Store Class
Store::Store(){
    name = "Empty";
}
//Constructor
Store::Store(string name, int location, string flavor_text, Item for_sale[]){
    this -> name = name;
    this -> location = location;
    this -> flavor_text = flavor_text;
    //Strips items from provided array, putting them in the same slots, also increments the store_item_count;
    for(int i = 0;i < 20;i++){
        this -> for_sale[i] = for_sale[i];
        if(this -> for_sale[i].Get_Name() != "Empty"){
            this -> store_item_count++;
        }
    }
}
//Store Getters
Item Store::Get_Chosen_Item(int selection){
    return for_sale[selection];
}
//Store Functions
//Shows all items available along with store name <needs to add flavor text>
string Store::Show_Store_Inventory(){
    int i = 0;
    string output = "";
    output += name + "\n";
    while(for_sale[i].Get_Name() != "Empty"){
        if(i % 2 == 0){
            output += to_string(i)+": "+for_sale[i].Get_Name();
            output += "     ";
        }
        else{
            output += to_string(i)+": "+for_sale[i].Get_Name()+"\n";
        }
        i++;
    }
    return output;
}
//Checks gold to see if purchasable, returns error string or success gaining item and removing gold
string Store::Buy_Item(Hero & player,int selection){
    string result = "";
    Item target = Get_Chosen_Item(selection);
    if(player.Get_Gold_Count() >= target.Get_Value()){
        player.Set_Gold_Count(player.Get_Gold_Count()-target.Get_Value());
        player.Gain_Item(target);
        result += "Thank you very much!\n"+player.Get_Name()+" gains "+target.Get_Name()+".\n";
    }
    else{
        result = "Not enough gold!\n";
    }
    return result;
}
//Removes item and gives gold (will remove an item charge if a consumable is sold instead)
string Store::Sell_Item(Hero & player,int selection){
    string result = "";
    Item target = player.Show_Inventory_Item(selection);
    result = "I will take this "+target.Get_Name()+"\n"+player.Get_Name()+" receives "+to_string(target.Get_Value())+" gold.\n";
    player.Set_Gold_Count(player.Get_Gold_Count()+target.Get_Value());
    if(target.Get_Type() == consumable){
        player.Reduce_Charge(selection);
    }
    else{
        player.Delete_Item(selection);
    }
    return result;
}
//NPC Class
NPC::NPC(){
    this -> name = "Null";
}
NPC::NPC(string name,int x_position,int y_position){
    this -> name = name;
    this -> x_position = x_position;
    this -> y_position = y_position;
}
NPC::NPC(string name,int x_position,int y_position,Item key_item){
    this -> name = name;
    this -> x_position = x_position;
    this -> y_position = y_position;
    this -> key_item = key_item;
}
string NPC::Get_Name(){
    return name;
}
string NPC::Get_Dialogues(int world_state){
    return dialogue_list[world_state];
}
void NPC::Add_Dialogue(int world_state,string input){
    dialogue_list[world_state] = input;
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
    this->monster_skill_count = 1;
    //Attack skill is always available, x1 modifier, keeps with "modular skills" avoiding having to code each one
    monster_skills[0] = Skill("Attack","attacks!",0,1.0,phys_attack);
}
Monster::Monster(){
    this->name = "Null";
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
int Monster::Get_Monster_Skill_Count(){
    return monster_skill_count;
}
Item Monster::Get_Drop(){
    return drop;
}
Skill & Monster::Get_Monster_Skill(int target){
    return monster_skills[target];
}

//Monster Setters
void Monster::Gain_Skill(Skill get){
    monster_skills[monster_skill_count] = get;
    monster_skill_count++;
}

//Hero class (inherits Character)
Hero::Hero(string name,int level,int exp, int hp,int mp, int attack, int defense,int x,int y,int map):Character::Character(name,hp,attack,defense){
    this-> level = level;
    this-> exp = exp;
    this-> mp = mp;
    this-> tmp_mp = mp;
    this-> inventory_count = 0;
    this-> skill_count = 1;
    this-> x_position = x;
    this-> y_position = y;
    this-> current_map = map;
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
int Hero::Get_Gold_Count(){
    return gold_count;
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
int Hero::Get_X_Position(){
    return x_position;
}
int Hero::Get_Y_Position(){
    return y_position;
}
int Hero::Get_Current_Map(){
    return current_map;
}
Item Hero::Get_Equipped_Weapon(){
    return equipped_weapon;
}
Item Hero::Get_Equipped_Armor(){
    return equipped_armor;
}


//Hero setters
void Hero::Set_Level(int change){
    this->level = change;
}
void Hero::Set_Gold_Count(int change){
    this->gold_count = change;
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
void Hero::Set_Equipped_Weapon(Item weapon){
    this->equipped_weapon = weapon;
}
void Hero::Set_Equipped_Armor(Item armor){
    this->equipped_armor = armor;
}

//Hero public functions
//-----------------------------------------------------------------------------
void Hero::Update_Location(int x,int y,int map){
    this-> x_position = x;
    this-> y_position = y;
    this-> current_map = map;
}
//Adds passed item/skill to the next slot in inventory
void Hero::Gain_Skill(Skill get){
    skill_list[skill_count] = get;
    skill_count++;
}

//Displays all of Hero's info as a string
string Hero::Show_Info(){
    string output = "Name: " + name +"\t";
    output = output + "Level: " + to_string(level) + "\n\t";
    output = output + "Exp: " + to_string(exp) + "\t";
    output = output + "Gold: "+ to_string(gold_count) + "\n\t";
    output = output + "Hp: " + to_string(tmp_hp) + "/" + to_string(hp) + "\t";
    output = output + "Mp: " + to_string(tmp_mp) + "/" + to_string(mp) + "\n\t";
    output = output + "Attack: " + to_string(attack) + "\t";
    output = output + "Defense: " + to_string(defense) + "\n";
    return output;
}
//Inventory functions
//-----------------------------------------------------------------------------
string Hero::Inventory_Menu(){
    int i = 0;
    string output = "";
    if(inventory[0].Get_Name() == "Empty"){
        return "Empty";
    }
    while(inventory[i].Get_Name() != "Empty"){
        if(i % 2 == 0){
            output += to_string(i)+": "+inventory[i].Get_Name();
            if(inventory[i].Get_Type() == consumable){
                output += " Amount: "+to_string(inventory[i].Get_Quantity());
            }
            output += "\n";
        }
        else{
            output += to_string(i)+": "+inventory[i].Get_Name();
            if(inventory[i].Get_Type() == consumable){
                output += " Amount: "+to_string(inventory[i].Get_Quantity())+"\n";
            }
            else{
                output += "\n";
            }
        }
        i++;
    }
    output += "\n";
    return output;
}
//Gets item and adds to inventory/adjusts inventory count as well
void Hero::Gain_Item(Item get){
    int change = 0;
    for(int i = 0;i < inventory_count;i++){
        if(inventory[i].Get_Name() == get.Get_Name() && inventory[i].Get_Type() == consumable){
            change = inventory[i].Get_Quantity() + 1;
            inventory[i].Set_Quantity(change);
            return;
        }
    }
    inventory[inventory_count] = get;
    inventory_count++;
}
//Removes item at position, shifts inventory to compensate, adjusts inventory count too
void Hero::Delete_Item(int position){
    if(inventory_count == 0){
        return;
    }
    if(inventory[position+1].Get_Name() == "Empty"){
        inventory[position] = Item();
        inventory_count--;
        return;
    }
    while(inventory[position+1].Get_Name() != "Empty"){
        inventory[position] = inventory[position+1];
        inventory[position+1] = Item();
        position++;
    }
    inventory_count--;
}
//Reduces the charge of the selected item only if it is a consumable, will remove if 0
void Hero::Reduce_Charge(int position){
    Item target = inventory[position];
    if(target.Get_Type() == consumable){
        if(target.Get_Quantity() > 0){
            inventory[position].Set_Quantity(target.Get_Quantity()-1);
            if(inventory[position].Get_Quantity() == 0){
                Delete_Item(position);
            }
        }
    }
}
//Swaps a for b in inventory, limited by the size of it (error handler)
void Hero::Swap_Inventory_Items(int a, int b){
    if(a < inventory_count && b < inventory_count){
        Item temp;
        temp = inventory[a];
        inventory[a] = inventory[b];
        inventory[b] = temp;
    }
}
//Lengthy function for "Using" items, will equip equipment, or use an item, modifies inventory to compensate
string Hero::Use_Item(int target){
    string output = "";
    Item selected = inventory[target];
    if(selected.Get_Type() == weapon){
        if(Get_Equipped_Weapon().Get_Name() == "Empty"){
            Set_Equipped_Weapon(selected);
            Delete_Item(target);
            output = name+" dons the "+selected.Get_Name()+".\n";
            output += "Stats change, attack:" + to_string(equipped_weapon.Get_Attack())+"\n";
        }
        else{
            Item temp = equipped_weapon;
            equipped_weapon = inventory[target];
            inventory[target] = temp;
            output = name +" doffs the "+temp.Get_Name()+" and dons the "+equipped_weapon.Get_Name()+"\n";
            output += "Stats change, attack: "+to_string(equipped_weapon.Get_Attack()-inventory[target].Get_Attack())+"\n";
        }
    }
    if(selected.Get_Type() == armor){
        if(Get_Equipped_Armor().Get_Name() == "Empty"){
            Set_Equipped_Armor(selected);
            Delete_Item(target);
            output = name+" dons the "+selected.Get_Name()+".\n";
            output += "Stats change, defense:" + to_string(equipped_armor.Get_Defense())+"\n";
        }
        else{
            Item temp = equipped_armor;
            equipped_armor = inventory[target];
            inventory[target] = temp;
            output = name +" doffs the "+temp.Get_Name()+" and dons the "+equipped_armor.Get_Name()+"\n";
            output += "Stats change, defense: "+to_string(equipped_armor.Get_Defense()-inventory[target].Get_Defense())+"\n";
        }
    }
    if(selected.Get_Type() == consumable){
        if(tmp_hp != hp){
            int calculation = min(hp-tmp_hp,int(selected.Get_Healing()));
            output = name + " ate the "+selected.Get_Name()+" "+to_string(calculation)+" HP recovered.\n";
            Reduce_Charge(target);
        }
        else{
            output = name+"'s HP is full!\n";
        }
    }
    else{
        //Area for more cases
    }
    return output;
}
//Returns the targetted item from inventory
Item Hero::Show_Inventory_Item(int target){
    return inventory[target];
}
//Returns a skill from hero's skill list
Skill & Hero::Get_Target_Skill(int target){
    return skill_list[target];
}
