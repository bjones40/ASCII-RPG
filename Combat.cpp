#include "glue.h"
#include <iostream>
using namespace std;
//Currently just showing successful function calls
int Combat_Loop(Hero player){
    Weapon knife = Weapon("Knife",6,6);
    cout << "Oh shit it's a "<<knife.Get_Name()<<" it's valued at "<<knife.Get_Value()<<" and hits for "<<knife.Get_Attack()<<"!!!\n";
    player.Gain_Item(knife);
    player.Gain_Item(knife);
    Item * dump;
    dump = player.Show_Inventory();
    int position = 0;
    while(dump[position].Get_Name() != "Empty"){
        cout << dump[position].Get_Name() << endl;
        position++;
    }
    return player.Get_HP();
}