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
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void Player::mvup()
{
    if (!curmap->tiles[xLoc][yLoc-1].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    mvwaddch(curwin, yLoc, xLoc, map_char);
    yLoc--;
    if(yLoc < 1)
        yLoc = 1;
}

void Player::mvdown()
{
    if (!curmap->tiles[xLoc][yLoc+1].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    mvwaddch(curwin, yLoc, xLoc, map_char);
    yLoc++;
    if(yLoc > yMax - 2)
        yLoc = yMax - 2;
}

void Player::mvleft()
{
    if (!curmap->tiles[xLoc-1][yLoc].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    mvwaddch(curwin, yLoc, xLoc, map_char);
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
}

void Player::mvright()
{
    if (!curmap->tiles[xLoc+1][yLoc].get_traverse())
        return;
    map_char = curmap->tiles[xLoc][yLoc].get_tilechar();
    mvwaddch(curwin, yLoc, xLoc, map_char);
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
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);

}

#endif
