#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    Hello_World();
    Hero player = Hero(5,5,5,5);
    cout << Combat_Loop(player);
    return 0;
}