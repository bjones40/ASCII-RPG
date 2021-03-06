#ifndef _PLAYERMOVEMENT_H_
#define _PLAYERMOVEMENT_H_

#include "terrain.h"

class Player
{
    public:
        Player(WINDOW * win, int y, int x, char c, Terrain * map);

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        char map_char;
        WINDOW * curwin;
        Terrain * curmap;
};

Player::Player(WINDOW * win, int y, int x, char c, Terrain * map)
{
    curwin = win;
    curmap = map;
    yLoc = y;
    xLoc = x;
    //getmaxyx(curwin, yMax, xMax);
    yMax = curmap->get_map_yMax();
    xMax = curmap->get_map_xMax();
    keypad(curwin, true);
    character = c;
    display();
}

void Player::mvup()
{
    if (!curmap->tiles[xLoc][yLoc-1].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    //mvwaddch(curwin, yLoc, xLoc, map_char);
    yLoc--;
    if(yLoc < 2)
        yLoc = 2;
}

void Player::mvdown()
{
    if (!curmap->tiles[xLoc][yLoc+1].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    //mvwaddch(curwin, yLoc, xLoc, map_char);
    yLoc++;
    if(yLoc > yMax - 2)
        yLoc = yMax - 2;
}

void Player::mvleft()
{
    if (!curmap->tiles[xLoc-1][yLoc].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    //mvwaddch(curwin, yLoc, xLoc, map_char);
    xLoc--;
    if(xLoc < 2)
        xLoc = 2;
}

void Player::mvright()
{
    if (!curmap->tiles[xLoc+1][yLoc].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    //mvwaddch(curwin, yLoc, xLoc, map_char);
    xLoc++;
    if(xLoc > xMax - 2)
        xLoc = xMax - 2;
}

int Player::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            mvup();
            choice = 1;
            break;
        case KEY_DOWN:
            mvdown();
            choice = 1;
            break;
        case KEY_LEFT:
            mvleft();
            choice = 1;
            break;
        case KEY_RIGHT:
            mvright();
            choice = 1;
            break;
        default:
            break;
    }
    return choice;
}

void Player::display()
{
    //mvwaddch(curwin, yLoc, xLoc, character);
    curmap->displayCamera(yLoc, xLoc, character);
    //mvwaddch(curwin, yLoc, xLoc, character);
}

#endif
