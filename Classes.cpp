#include "glue.h"
using namespace std;

Hero::Hero(int hp,int mp,int attack,int defense)
{
    this->hp = hp;
    this->tmphp = hp;
    this->attack = attack;
    this->defense = defense;
    this->mp = mp;
    this->tmpmp = mp;
}
int Hero::gethp(){
    return hp;
}