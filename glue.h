#ifndef SOUP_H_GUARD
#define SOUP_H_GUARD
#include <string>

using namespace std;
//Differentiates item functions
enum Itypes{consumable,weapon,armor,key};
//Differentiates ability types
enum Stypes{phys_attack,magic_attack,healing,buff};
//Location enumeration
enum Maps{Dessert_Desert_Town,Dessert_Desert};
//Differentiates enemy type for calling upon appropriate table from Parse_Monster_Tables
enum Enemy_Type{normal_enemy,rare_enemy,boss};
class Skill{
    protected:
        string name;
        string flavor_text;
        int cost;
        double modifier;
        int type;
    public:
        Skill();
        Skill(string name, string flavor_text,int cost,double modifier, int type);
        string Get_Name();
        string Get_Flavor();
        double Get_Modifier();
        int Get_Type();
        int Get_Cost();
};
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
        Item(string name, int type);
        Item(string name, int value,int modifier,int type);
        string Full_Display();
        string Get_Name();
        int Get_Value();
        int Get_Attack();
        int Get_Defense();
        int Get_Healing();
        int Get_Type();
};
class NPC{
    private:
        string name;
        int x_position;
        int y_position;
        Item key_item;
        string dialogue_list[100];
    public:
        NPC();
        NPC(string name,int x_position,int y_position);
        NPC(string name,int x_position,int y_position,Item key_item);
        string Get_Name();
        string Get_Dialogues(int world_state);
        void Add_Dialogue(int world_state, string input);
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
        Skill monster_skills[100];
        int monster_skill_count;
    public:
        Monster();
        Monster(string name, int hp, int attack, int defense, int exp_drop, int gold, int ai_type, Item drop);
        int Get_Exp_Drop();
        int Get_Gold();
        int Get_Ai_Type();
        int Get_Monster_Skill_Count();
        Item Get_Drop();
        Skill & Get_Monster_Skill(int target);
        void Gain_Skill(Skill get);
};

class Hero: public Character{
    private:
        Item inventory[100];
        Skill skill_list[100];
        Item equipped_weapon;
        Item equipped_armor;
        int inventory_count;
        int skill_count;
        int gold_count;
        int level;
        int exp;
        int mp;
        int tmp_mp;
        int x_position;
        int y_position;
        int current_map;

    public:
        Hero(string name,int level,int exp,int hp,int mp,int attack,int defense,int x, int y, int map);
        int Get_Level();
        int Get_Exp();
        int Get_MP();
        int Get_tmp_mp();
        int Get_Gold_Count();
        int Get_Inventory_Count();
        int Get_Skill_Count();
        int Get_X_Position();
        int Get_Y_Position();
        int Get_Current_Map();
        Item Get_Equipped_Weapon();
        Item Get_Equipped_Armor();
        Item * Show_Inventory();
        Item Show_Inventory_Item(int target);

        Skill & Get_Target_Skill(int target);
        

        void Set_Level(int change);
        void Set_Exp(int change);
        void Set_MP(int change);
        void Set_Gold_Count(int change);
        void Set_tmp_mp(int change);

        void Gain_Skill(Skill get);
        void Gain_Item(Item get);
        void Update_Location(int x,int y, int map);
        string Show_Info();
};

//Functions from other files to make available to entire system
void Hello_World();
void Combat_Loop(Hero &,Monster enemy);
void Rewards(Hero &,Monster &);
Monster Parse_Monster_Tables(Hero,int);

#endif
