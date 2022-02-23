#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    Hello_World();
    Hero player = Hero("man",1,0,5,5,5,5);
    Item taco = Item("Taco",1,1,0);
    Monster enemy = Monster("slime",1,1,1,1,1,1,taco);
    Combat_Loop(player,enemy);
    return 0;
}