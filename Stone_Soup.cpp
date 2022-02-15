#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    Hello_World();
    Hero player = Hero("man",1,0,5,5,5,5);
    cout << "Hero damage before: " << player.Get_Attack() << endl;
    Combat_Loop(player);
    cout << "Hero damage after: " <<player.Get_Attack() << endl;
    cout << player.Show_Info();
    return 0;
}