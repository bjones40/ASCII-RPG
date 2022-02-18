// Matthew's main function for testing player movement

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include<ctime>
#include "player.h"

using namespace std;

int main(int argc, char ** argv)
{
    // initialize screen
    // set up memory and clear screen
    initscr();
    cbreak(); // allows exit on ctrl-c
    noecho(); // hides key press input
    
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * menuwin = newwin(20, 50, (yMax/2)-10, 10);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    Player * p = new Player(menuwin, 1, 1, '@');
    while(p->getmv() != 'x')
    {
        p->display();
        wrefresh(menuwin);
    }

    /*
    // allows use of arrow keys
    keypad(menuwin, true);

    string choices[3] = {"Walk", "Attack", "Defend"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight)
            {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 3)
                    highlight = 2;
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }

    printw("Your choice was: %s", choices[highlight].c_str());
    */
    
    /*
    int y, x, yBeg, xBeg, yMax, xMax;

    WINDOW * win = newwin(10, 20, 10, 10);

    getyx(stdscr, y, x);
    getbegyx(win, yBeg, xBeg);
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(yMax/2, xMax/2, "y:%d x:%d yB:%d xB:%d yM:%d xM:%d", y, x, yBeg, xBeg, yMax, xMax);
    
    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;


    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh(); // refreshes entire screen

    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';

    //box(win, (int)c, (int)b);
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc); // creates and customizes border
    mvwprintw(win, 1,1, "this is a box");
    wrefresh(win); // refreshes specific window
*/

    // waits for user input, returns int value of key press
    getch();
    
    endwin();
    // deallocates memory and ends ncurses
    


    // moves the cursor to specified location (y, x) for some reason
    //move(y, x);

    // prints a string(const char *) to a window
    //printw("Wassup");

    // refreshes screen to match memory
    //refresh();

    //clear(); // clears the screen

    //mvprintw(0,0, "%d was pressed", c);

    return 0;
}
