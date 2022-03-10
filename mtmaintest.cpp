// Matthew's main function for testing player movement

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "terrain.h"

using namespace std;

int main(int argc, char ** argv)
{
    //NCURSES START
    initscr();
    noecho(); // hides key press input
    cbreak(); // allows exit on ctrl-c
    curs_set(0);
    
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * playwin = newwin(20, 50, (yMax/2)-10, 10);
    
    //box(menuwin, 0, 0);
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';
    
    wborder(playwin, left, right, top, bottom, tlc, trc, blc, brc); // creates and customizes border
    refresh();
    wrefresh(playwin);

    Terrain * map = new Terrain(playwin);
    Player * p = new Player(playwin, 1, 1, 'P', map);
    map->generatetiles();
    do {
        p->display();
        wrefresh(playwin);
    } while(p->getmv() != 'x');

    getch();
    endwin();
    //NCURSES END
    
    return 0;
}
