
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
    bool death_state = 0;
    bool playing = 1;

    string movement_controls[5] = {"UP - Move Up", "DOWN - Move Down", "LEFT - Move Left", "RIGHT - Move Right", "E - Interact"};
    srand(time(NULL));
    int encounterchance = 0;

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
    WINDOW * playwin = newwin(40, 120, 0, 0); //Window for player movement and combat
    WINDOW * logwin = newwin(15, 120, 40, 0); //Window for exploration and combat logs
    WINDOW * controlswin = newwin(30, 25, 0, 120); //Window for displaying controls

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

    
    Terrain * map = new Terrain(playwin);
    map->generatetiles();
    Player * p = new Player(playwin, 20, 60, '@', map);
    //map->generatetiles(163, 51, stuff);

    Hero player = Hero("man",1,0,5,5,5,5,0,0,0);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);

    

    while (playing)
    {
        if (movement_state)
        {
            do
            {
                for (int i = 0; i < 5; i++)
                {
                    mvwaddstr(controlswin, 1+i, 1, movement_controls[i].c_str());
                }
                wrefresh(controlswin);

                p->display();
                wrefresh(playwin);

                if (p->getmv() == 1)
                {
                    encounterchance = rand() % 100 + 1;

                    if (encounterchance > 0 && encounterchance <= 10)
                    {
                        movement_state = 0;
                        combat_state = 1;

                        for (int i = 0; i < 5; i++)
                        {
                            mvwaddstr(controlswin, 1+i, 1, "                  ");
                        }
                        wrefresh(controlswin);
                        refresh();
                    }
                }
                //mvwaddstr(logwin, 1, 1, logarray.c_str());
                //wrefresh(logwin);

            }while(movement_state);
        }
        if (combat_state)
        {
            if (encounterchance == 10)
                enemy = Parse_Monster_Tables(player,rare_enemy);
            else
                enemy = Parse_Monster_Tables(player,normal_enemy);
            
            do
            {
                if(Combat_Loop(player, enemy, logwin, controlswin))
                {
                    movement_state = 1;
                    combat_state = 0;
                    encounterchance = 0;
                }
                else
                {
                    movement_state = 0;
                    combat_state = 0;
                    death_state = 1;
                    encounterchance = 0;
                }

            }while(combat_state);
        }
        if (death_state)
        {
            mvwaddstr(logwin, 1, 1, "You ded man");
            mvwaddstr(playwin, playyMax/2, playxMax/2, "RIPPERONI");
        }
    }

    //Ncurses end
    getch();
    endwin();
    
    return 0;
}
