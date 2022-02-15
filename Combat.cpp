#include "glue.h"
#include <iostream>
using namespace std;
//Currently just showing successful function calls
void Combat_Loop(Hero &player){
    player.Set_Attack(player.Get_Attack()+1);
    cout << "Hero during: " << player.Get_Attack()<<endl;
}