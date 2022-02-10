#ifndef SOUP_H_GUARD
#define SOUP_H_GUARD

class Hero{
    protected:
        int hp;
        int tmphp;
        int attack;
        int defense;
        int mp;
        int tmpmp;
    public:
        Hero(int hp,int mp,int attack,int defense);
        int gethp();
};
void Hello_World();
int Combat_Loop(Hero);

#endif