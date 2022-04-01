
#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "glue.h"
#include "playermovement.h"
#include "terrain.h"

using namespace std;

int main(int argc, char ** argv) 
{
    //Basic States
    bool movement_state = 1;
    bool combat_state = 0;


    //Ncurses start
    initscr();
    noecho(); //hides key press input
    cbreak(); //allows exit on ctrl-c
    curs_set(0);

    //borders for windows
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';

    //Ncurses window declaration
    WINDOW * playwin = newwin(53, 165, 0, 0); //Window for player movement and combat
    WINDOW * logwin = newwin(17, 165, 53, 0); //Window for exploration and combat logs
    WINDOW * controlswin = newwin(36, 25, 0, 165); //Window for displaying controls

    //Get the max width and length of the windows
    int playxMax, playyMax, logxMax, logyMax, controlsxMax, controlsyMax;
    getmaxyx(playwin, playyMax, playxMax);
    getmaxyx(logwin, logyMax, logxMax);
    getmaxyx(controlswin, controlsyMax, controlsxMax);

    //creating window borders
    wborder(playwin, left, right, top, bottom, tlc, trc, blc, brc);
    wborder(logwin, left, right, top, bottom, tlc, trc, blc, brc);
    wborder(controlswin, left, right, top, bottom, tlc, trc, blc, brc);
    refresh();
    wrefresh(playwin);
    wrefresh(logwin);
    wrefresh(controlswin);

    //displaying strings for controlswin
    for (int i = 2; i < controlsyMax-4; i++)
    {
        mvwaddstr(controlswin, i, 3, "C-Controls Example");
    }
    wrefresh(controlswin);

    
    Terrain * map = new Terrain(playwin);
    Player * p = new Player(playwin, 46, 5, '@', map);
    //map->generatetiles();

    Hero player = Hero("man",1,0,5,5,5,5,0,0,0);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);

    

    if (movement_state)
    {
        do
        {
            p->display();
            wrefresh(playwin);

            if (p->getmv() == 'x')
            {
                movement_state = 0;
                combat_state = 1;
                refresh();
            }

        }while(movement_state);
    }
    if (combat_state)
    {
        do
        {
            //map->
            Combat_Loop(player,enemy);


        }while(combat_state);
    }

    //Ncurses end
    getch();
    endwin();
    
    return 0;
}