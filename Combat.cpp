#include "glue.h"
#include <iostream>
using namespace std;
//Currently just showing successful function calls
void Combat_Loop(Hero &player,Monster enemy){
    Item taco = Item("taco",10,1,0);
    Item tacosword = Item("tacosword",10,534543,1);
    player.Gain_Item(taco);
    player.Gain_Item(tacosword);
    cout << "Consumable: " << player.Show_Inventory_Item(0).Full_Display() << "Weapon: " <<player.Show_Inventory_Item(1).Full_Display();
}