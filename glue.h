#ifndef SOUP_H_GUARD
#define SOUP_H_GUARD
#include <string>
using namespace std;
class Item{
    protected:
        string name;
        int value;
    public:
        Item();
        Item(string name, int value);
        string Get_Name();
        int Get_Value();
};
class Weapon: public Item{
    private:
        int attack;
    public:
        Weapon(string name, int value,int attack);
    int Get_Attack();
};
class Hero{
    private:
        Item inventory[100];
        int inventory_count;
    protected:
        int hp;
        int tmphp;
        int attack;
        int defense;
        int mp;
        int tmpmp;
    public:
        Hero(int hp,int mp,int attack,int defense);
        int Get_HP();
        int Get_Tmphp();
        int Get_Attack();
        int Get_Defense();
        int Get_MP();
        int Get_Tmpmp();
        void Gain_Item(Item get);
        Item * Show_Inventory();
};

void Hello_World();
int Combat_Loop(Hero);

#endif