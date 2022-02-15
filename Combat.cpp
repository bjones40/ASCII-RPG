#include "glue.h"
#include <iostream>
using namespace std;
//Currently just showing successful function calls
void Combat_Loop(Hero &player,Monster enemy){
    player.Set_Attack(player.Get_Attack()+1);
    Item x = Item("test",1);
    Weapon y = Weapon("test2",1,1);
    player.Gain_Item(x);
    player.Gain_Item(y);
    cout << player.Show_Inventory_Item(0).Get_Name() << " " << player.Show_Inventory_Item(1).Get_Name() << endl;
    Item * all = player.Show_Inventory();
    for(int i = 0; i < player.Get_Inventory_Count();i++){
        cout << all[i].Get_Name() << endl;
    }
    cout << "Current friends in combat: "<<player.Get_Name()<<" and "<<enemy.Get_Name()<<endl;;
}