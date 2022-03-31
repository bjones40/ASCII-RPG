#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    string test = "Hello Friend\nWelcome to your eternal life of sweet servitude\nBe sure to visit the healing fountain!\n";
    NPC Uther = NPC("Uther",0,0,Item("Burrito",key));
    Uther.Add_Dialogue(0,test);
    cout << Uther.Get_Name() << ": " << Uther.Get_Dialogues(0);

    Hero player = Hero("man",1,0,5,5,5,5,0,0,0);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);
    cout << player.Show_Info();
    Item taco = Item("Taco",1,1,0);
    //Monster enemy = Monster("slime",1,1,1,50,100,1,taco);
    Combat_Loop(player,enemy);
    cout << player.Show_Info();
    return 0;
}