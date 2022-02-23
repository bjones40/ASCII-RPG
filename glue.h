#ifndef SOUP_H_GUARD
#define SOUP_H_GUARD
#include <string>

using namespace std;

class Item{
    protected:
        string name;
        int value;
        int attack;
        int defense;
        int healing;
        int type;
    public:
        Item();
        Item(string name, int value,int modifier,int type);
        string Full_Display();
        string Get_Name();
        int Get_Value();
        int Get_Attack();
        int Get_Defense();
        int Get_Healing();
        int Get_Type();
};

class Character{
    protected:
        string name;
        int hp;
        int tmp_hp;
        int attack;
        int defense;
    public:
        Character();
        Character(string name,int hp, int attack, int defense);
        string Get_Name();
        int Get_HP();
        int Get_tmp_hp();
        int Get_Attack();
        int Get_Defense();

        void Set_Name(string change);
        void Set_HP(int change);
        void Set_tmp_hp(int change);
        void Set_Attack(int change);
        void Set_Defense(int change);
};

class Monster: public Character{
    private:
        int exp_drop;
        int gold;
        int ai_type;
        Item drop;
    public:
        Monster(string name, int hp, int attack, int defense, int exp_drop, int gold, int ai_type, Item drop);
        int Get_Exp_Drop();
        int Get_Gold();
        int Get_Ai_Type();
        Item Get_Drop();
};

class Hero: public Character{
    private:
        Item inventory[100];
        Item equipped_weapon;
        Item equipped_armor;
        int inventory_count;
        int level;
        int exp;
        int mp;
        int tmp_mp;

    public:
        Hero(string name,int level,int exp,int hp,int mp,int attack,int defense);
        int Get_Level();
        int Get_Exp();
        int Get_MP();
        int Get_tmp_mp();
        int Get_Inventory_Count();
        Item Get_Equipped_Weapon();
        Item Get_Equipped_Armor();
        Item * Show_Inventory();
        Item Show_Inventory_Item(int target);

        void Set_Level(int change);
        void Set_Exp(int change);
        void Set_MP(int change);
        void Set_tmp_mp(int change);

        void Gain_Item(Item get);
        string Show_Info();
};

void Hello_World();
void Combat_Loop(Hero &,Monster enemy);

#endif