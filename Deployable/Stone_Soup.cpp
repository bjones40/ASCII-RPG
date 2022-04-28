#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "glue.h"
#include "scene.h"
#include "playermovement.h"
#include "terrain.h"

using namespace std;
using namespace myScene;
//New game menu constants
char const *list[] = {
    "New Game",
    "Load Save",
    "Exit",
};

int n_list = sizeof(list) / sizeof(char *);
//New game menu print with highlight
void print_menu(WINDOW *menu_win, int highlight){
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_list; ++i)
	{	if(highlight == i + 1) 
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", list[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", list[i]);
		++y;
	}
	wrefresh(menu_win);
}

void setup_playwindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3);
void setup_inventorywindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3);

int main(int argc, char ** argv) 
{
    //Basic States
    bool movement_state = 1;
    bool combat_state = 0;
    bool death_state = 0;
    bool inventory_state = 0;
    bool playing = 0;
	bool new_game = 0;

    string movement_controls[6] = {"UP - Move Up", "DOWN - Move Down", "LEFT - Move Left", "RIGHT - Move Right", "E - Interact", "I - Inventory"};
    srand(time(NULL));
    int encounterchance = 0;

    //Ncurses start
    /*initscr();
    noecho(); //hides key press input
    cbreak();*/ //allows exit on ctrl-c
    curs_set(0);

	//Creating scene object
	myScene::Scene scene;
	int highlight = 1, selection = 0, s = 0;
	scene.startCurses();
    
    
    //borders for windows
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';

    //Ncurses window declaration
    WINDOW * playwin = newwin(40, 120, 0, 0); //Window for player movement and combat
    WINDOW * logwin = newwin(15, 120, 40, 0); //Window for exploration and combat logs
    WINDOW * controlswin = newwin(30, 25, 0, 120); //Window for displaying controls
    WINDOW * inventorywin = newwin(30, 120, 6, 0); //Window for displaying inventory
    WINDOW * statwin = newwin(6, 120, 0, 0); //Window for displaying character stats
    WINDOW * battlewin = newwin(40, 120, 0, 0); //Window for displaying battle scene
    WINDOW * newgamewin = newwin(24, 80, 0, 0); //Window for displaying new game scene
	
    //Get the max width and length of the windows
    int playxMax, playyMax, logxMax, logyMax, controlsxMax, controlsyMax;//, invyMax, invxMax, statyMax, statxMax, battleyMax, battlexMax;
    getmaxyx(playwin, playyMax, playxMax);
    getmaxyx(logwin, logyMax, logxMax);
    getmaxyx(controlswin, controlsyMax, controlsxMax);
    //getmaxyx(inventorywin, invyMax, invxMax);
    //getmaxyx(statwin, statyMax, statxMax);
    //getmaxyx(battlewin, battleyMax, battlexMax);
    
    
    if(new_game == 0)
	{
        //New game menu attributes
        mvprintw(0,0, "STONE SOUP");
        keypad(newgamewin, TRUE);
        s = wgetch(newgamewin);
        wborder(newgamewin, left, right, top, bottom, tlc, trc, blc, brc);
        refresh();
        wrefresh(newgamewin);
        mvchgat(0, 0, -1, A_BLINK, 1, NULL);
        refresh();
        print_menu(newgamewin, highlight);
  
        switch(s)
        {	
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_list;
                else
                    --highlight;

                //scene.main_menu(newgamewin, highlight);
                print_menu(newgamewin, highlight);
                break;
            case KEY_DOWN:
                if(highlight == n_list)
                    highlight = 1;
                else 
                    ++highlight;

                //scene.main_menu(menu_win, highlight);
                print_menu(newgamewin, highlight);
                break;
            case 10:
                s = highlight;
                refresh();
				//delwin(newgamewin);
				//refresh();

                wborder(playwin, left, right, top, bottom, tlc, trc, blc, brc);
                //mvwaddstr(map, 1, 1, "Map");
                wrefresh(playwin);

                wborder(logwin, left, right, top, bottom, tlc, trc, blc, brc);
                mvwaddstr(logwin, 1, 1, "Message Log"); 
                wrefresh(logwin);
                
                wborder(controlswin, left, right, top, bottom, tlc, trc, blc, brc);
                mvwaddstr(controlswin, 1, 1, "Controls");
                wrefresh(controlswin);
                
                keypad(newgamewin, FALSE);
                new_game = 1;
                playing = 1;
                break;
            default:
                mvprintw(24, 0, " ", s, s);
                refresh();
                break;
        }
        //Exit game 
        //if(selection == 3)	
              //return (0);
    }//End newgamewin 	
    
    Terrain * map = new Terrain(playwin);
    map->generatetiles();
    Player * p = new Player(playwin, 46, 6, '@', map);
    //map->generatetiles(163, 51, stuff);

    Hero player = Hero("man",1,0,5,5,5,5,0,0,0);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);


    while (playing)
    {
		
        if (movement_state)
        {
            p->setkeypad(true);
            setup_playwindows(inventorywin, statwin, controlswin, playwin, logwin, controlswin);

            do
            {
                for (int i = 0; i < 6; i++)
                {
                    mvwaddstr(controlswin, 1+i, 1, movement_controls[i].c_str());
                }
                wrefresh(controlswin);

                p->display();
                wrefresh(playwin);

                char player_select = p->getmv();

                if (player_select == 1)
                {
                    encounterchance = rand() % 100 + 1;

                    if (encounterchance > 0 && encounterchance <= 10)
                    {
                        movement_state = 0;
                        combat_state = 1;

                        for (int i = 0; i < 10; i++)
                        {
                            mvwaddstr(controlswin, 1+i, 1, "                  ");
                        }
                        wrefresh(controlswin);
                        refresh();
                    }
                }
                
                //Inventory scene call
                else if(player_select == 2)
                {
                    inventory_state = 1;
                    movement_state = 0;
                    p->setkeypad(false);
                }
            
            }while(movement_state);
        }
        if (inventory_state)
        {
            setup_inventorywindows(playwin, logwin, controlswin, statwin, inventorywin, controlswin);
            keypad(inventorywin, true);

            do
            {
                //print_inventory(inventorywin)

                //placeholder print
                for(int i=0; i<27;i++){
                    mvwprintw(inventorywin, i+2, 2, "Inventory list item");
                    mvwprintw(controlswin, i+2, 2, "Key");
                }
                wrefresh(inventorywin); 
                wrefresh(controlswin);

                char inventory_select = wgetch(inventorywin);
                if (inventory_select == 'i')
                {
                    inventory_state = 0;
                    movement_state = 1;
                    keypad(inventorywin, false);
                }

            }while(inventory_state);
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

void setup_playwindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3)
{
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';
    
    wclear(cleared1);
    wclear(cleared2);
    wclear(cleared3);
    refresh();

    wborder(setup1, left, right, top, bottom, tlc, trc, blc, brc);
    wrefresh(setup1); 
    wborder(setup2, left, right, top, bottom, tlc, trc, blc, brc);
    wrefresh(setup2); 
    wborder(setup3, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup3, 1, 1, "Controls");
    wrefresh(setup3);
    refresh();

}

void setup_inventorywindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3)
{
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = '|';
    top = bottom = '-';
    tlc = trc = blc = brc = '+';
    
    wclear(cleared1);
    wclear(cleared2);
    wclear(cleared3);
    refresh();

    wborder(setup1, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup1, 1, 1, "Character Stats");
    wrefresh(setup1); 
    wborder(setup2, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup2, 1, 1, "Inventory");
    wrefresh(setup2); 
    wborder(setup3, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup3, 1, 1, "Controls");
    wrefresh(setup3);
    refresh();
}

