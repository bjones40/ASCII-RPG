#ifndef _PLAYERMOVEMENT_H_
#define _PLAYERMOVEMENT_H_

#include "terrain.h"

class Player
{
    public:
        Player(WINDOW * win, int y, int x, char c, Terrain * map, Hero * playerparam);

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();
        void setkeypad(bool condition);

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        char map_char;
        WINDOW * curwin;
        Terrain * curmap;
        Hero * player;
};

Player::Player(WINDOW * win, int y, int x, char c, Terrain * map, Hero * playerparam)
{
    curwin = win;
    curmap = map;
    player = playerparam;
    yLoc = y;
    xLoc = x;
    //getmaxyx(curwin, yMax, xMax);
    yMax = curmap->get_map_yMax();
    xMax = curmap->get_map_xMax();
    character = c;
    display();
}

void Player::setkeypad(bool condition)
{
    keypad(curwin, condition);
}

void Player::mvup()
{
    if (!curmap->tiles[xLoc][yLoc-1].get_traverse())
        return;
    if (curmap->tiles[xLoc][yLoc-1].get_tilechar() == 'X' || curmap->tiles[xLoc][yLoc-1].get_tilechar() == 's')
    {
        Terrain * nextmap = new Terrain(curwin);
        nextmap->generatetiles(curmap->tiles[xLoc][yLoc-1].get_teleport_id(), curmap->tiles[xLoc][yLoc-1].get_teleport_startY(), curmap->tiles[xLoc][yLoc-1].get_teleport_startX());
        xLoc = nextmap->get_xplayer_start();
        yLoc = nextmap->get_yplayer_start();
        yMax = nextmap->get_map_yMax();
        xMax = nextmap->get_map_xMax();
        player->Update_Location(xLoc, yLoc, nextmap->get_map_id());
        curmap = nextmap;
        return;

    }
    yLoc--;
    if(yLoc < 2)
        yLoc = 2;

    player->Update_Location(xLoc, yLoc, curmap->get_map_id());
}

void Player::mvdown()
{
    if (!curmap->tiles[xLoc][yLoc+1].get_traverse())
        return;
    if (curmap->tiles[xLoc][yLoc+1].get_tilechar() == 'X' || curmap->tiles[xLoc][yLoc+1].get_tilechar() == 's')
    {
        Terrain * nextmap = new Terrain(curwin);
        nextmap->generatetiles(curmap->tiles[xLoc][yLoc+1].get_teleport_id(), curmap->tiles[xLoc][yLoc+1].get_teleport_startY(), curmap->tiles[xLoc][yLoc+1].get_teleport_startX());
        xLoc = nextmap->get_xplayer_start();
        yLoc = nextmap->get_yplayer_start();
        yMax = nextmap->get_map_yMax();
        xMax = nextmap->get_map_xMax();
        player->Update_Location(xLoc, yLoc, nextmap->get_map_id());
        curmap = nextmap;
        return;

    }
    yLoc++;
    if(yLoc > yMax - 2)
        yLoc = yMax - 2;
    player->Update_Location(xLoc, yLoc, curmap->get_map_id());
}

void Player::mvleft()
{
    if (!curmap->tiles[xLoc-1][yLoc].get_traverse())
        return;
    if (curmap->tiles[xLoc-1][yLoc].get_tilechar() == 'X' || curmap->tiles[xLoc-1][yLoc].get_tilechar() == 's')
    {
        Terrain * nextmap = new Terrain(curwin);
        nextmap->generatetiles(curmap->tiles[xLoc-1][yLoc].get_teleport_id(), curmap->tiles[xLoc-1][yLoc].get_teleport_startY(), curmap->tiles[xLoc-1][yLoc].get_teleport_startX());
        xLoc = nextmap->get_xplayer_start();
        yLoc = nextmap->get_yplayer_start();
        yMax = nextmap->get_map_yMax();
        xMax = nextmap->get_map_xMax();
        player->Update_Location(xLoc, yLoc, nextmap->get_map_id());
        curmap = nextmap;
        return;

    }
    xLoc--;
    if(xLoc < 2)
        xLoc = 2;
    player->Update_Location(xLoc, yLoc, curmap->get_map_id());
}

void Player::mvright()
{
    if (!curmap->tiles[xLoc+1][yLoc].get_traverse())
        return;
    if (curmap->tiles[xLoc+1][yLoc].get_tilechar() == 'X' || curmap->tiles[xLoc+1][yLoc].get_tilechar() == 's')
    {
        Terrain * nextmap = new Terrain(curwin);
        nextmap->generatetiles(curmap->tiles[xLoc+1][yLoc].get_teleport_id(), curmap->tiles[xLoc+1][yLoc].get_teleport_startY(), curmap->tiles[xLoc+1][yLoc].get_teleport_startX());
        xLoc = nextmap->get_xplayer_start();
        yLoc = nextmap->get_yplayer_start();
        yMax = nextmap->get_map_yMax();
        xMax = nextmap->get_map_xMax();
        player->Update_Location(xLoc, yLoc, nextmap->get_map_id());
        curmap = nextmap;
        return;

    }
    xLoc++;
    if(xLoc > xMax - 2)
        xLoc = xMax - 2;
    player->Update_Location(xLoc, yLoc, curmap->get_map_id());
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
        case 'i':
            choice = 2;
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
