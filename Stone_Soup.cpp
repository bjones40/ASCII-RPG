#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    Hello_World();
    Hero player = Hero("man",1,0,5,5,5,5);
    cout << player.Show_Info();
    Item taco = Item("Taco",1,1,0);
    Monster enemy = Monster("slime",6,1,1,50,100,1,taco);
    Combat_Loop(player,enemy);
    cout << player.Show_Info();
    return 0;
}