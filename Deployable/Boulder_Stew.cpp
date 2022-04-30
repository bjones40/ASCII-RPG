#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <limits>
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


void print_menu(WINDOW *menu_win, int highlight);
void setup_playwindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3);
void setup_inventorywindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3);
void setup_battlewindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3, WINDOW * setup4);
//void print_battle(HERO & player, MONSTER & enemy, WINDOW * setup1, WINDOW * setup2);
void waitforseconds(int seconds);

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
    string inventory_controls[6] = {"UP - Move Up", "DOWN - Move Down", "D - Delete Item", "E - Equip Item", "I - Close Inventory"};
    srand(time(NULL));
    int encounterchance = 0;

    //Ncurses start
    curs_set(0);
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
    WINDOW * inventorywin = newwin(34, 120, 6, 0); //Window for displaying inventory
    WINDOW * statwin = newwin(6, 120, 0, 0); //Window for displaying character stats
    WINDOW * battlewin = newwin(55, 120, 0, 0); //Window for displaying battle scene
    WINDOW * newgamewin = newwin(24, 80, 0, 0); //Window for displaying new game scene
	
    //Get the max width and length of the windows
    int playxMax, playyMax, logxMax, logyMax, controlsxMax, controlsyMax;
    getmaxyx(playwin, playyMax, playxMax);
    getmaxyx(logwin, logyMax, logxMax);
    getmaxyx(controlswin, controlsyMax, controlsxMax);
    
    
    if(new_game == 0)
	{
        //New game menu attributes
        refresh();
        mvwaddstr(newgamewin, 1, 1, "BOULDER STEW");
        keypad(newgamewin, TRUE);
        s = wgetch(newgamewin);
        wborder(newgamewin, left, right, top, bottom, tlc, trc, blc, brc);
        wrefresh(newgamewin);
        mvchgat(0, 0, -1, A_BLINK, 1, NULL);
        //refresh();
        print_menu(newgamewin, highlight);
  
        switch(s)
        {	
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_list;
                else
                    --highlight;

                print_menu(newgamewin, highlight);
                break;
            case KEY_DOWN:
                if(highlight == n_list)
                    highlight = 1;
                else 
                    ++highlight;

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
    int newgamestartx = 37;
    int newgamestarty = 31;
    map->generatetiles(Dessert_Desert, newgamestarty, newgamestartx); 

    Hero player = Hero("man",1,0,5,5,3,5,newgamestartx,newgamestarty,Dessert_Desert);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);
    
    Player * p = new Player(playwin, map->get_yplayer_start(), map->get_xplayer_start(), '@', map, &player);

    int stepcounter = 0;
    
    //Demo player items/spells
	Item taco = Item("Taco",1,1,consumable);
    Item burrito = Item("Burrito",2,2,consumable);
    Item sword = Item("Sword",10,10,weapon);
    Item clothing = Item("Clothing",5,5,armor);
    player.Gain_Item(sword);
	//player.Use_Item(0); 
    player.Gain_Item(clothing);
    player.Gain_Item(taco);
    player.Gain_Item(burrito);
    player.Gain_Item(burrito);

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
                    stepcounter++;

                    int currentmap = player.Get_Current_Map();

                    switch (currentmap)
                    {
                        case Dessert_Desert_Village:
                        case Cabbage_Campo1_Village:
                        case Carrot_Canyon1_Village:
                            encounterchance = 0;
                            break;
                        default:
                            encounterchance = rand() % 500 + 1;
                            break;
                    }
                    

                    if (stepcounter >= 5 && encounterchance > 0 && encounterchance <= 10)
                    {
                        int seconds = 2;

                        movement_state = 0;

                        while (seconds-- >= 1)
                        {
                            sleep(1);
                        }
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
                //Print controls
                for (int i = 0; i < 6; i++)
                {
                    mvwaddstr(controlswin, 1+i, 1, inventory_controls[i].c_str());
                }
                wrefresh(controlswin);
                //Print statwin
                mvwaddstr(statwin, 2, 2, player.Show_Info().c_str());
                wrefresh(statwin); 
                //Print inventorywin
                mvwaddstr(inventorywin, 2, 2, player.Inventory_Menu().c_str());
                wrefresh(inventorywin); 

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
            //wresize(logwin, 55, 120);
            setup_battlewindows(playwin, logwin, controlswin, statwin, battlewin, controlswin, logwin);

            keypad(battlewin, true);
            
            if (encounterchance == 10)
                enemy = Parse_Monster_Tables(player,rare_enemy);
            else
                enemy = Parse_Monster_Tables(player,normal_enemy);
            
            do
            {
                if(Combat_Loop(player, enemy, logwin, controlswin, battlewin))
                {
                    movement_state = 1;
                    combat_state = 0;
                    encounterchance = 0;
                    stepcounter = 0;
                    //print_battle(player, enemy, logwin, battlewin);
                }
                else
                {
                    movement_state = 0;
                    combat_state = 0;
                    death_state = 1;
                    encounterchance = 0;
                    stepcounter = 0;
                }

            }while(combat_state);
            //wresize(logwin, 15, 120);
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
    mvwaddstr(setup3, 1, 1, "Message Log");
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

void setup_battlewindows(WINDOW * cleared1, WINDOW * cleared2, WINDOW * cleared3, WINDOW * setup1, WINDOW * setup2, WINDOW * setup3, WINDOW * setup4)
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
    mvwaddstr(setup2, 1, 1, "Battle");
    wrefresh(setup2); 
    wborder(setup3, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup3, 1, 1, "Controls");
    wrefresh(setup3);
    wborder(setup4, left, right, top, bottom, tlc, trc, blc, brc);
    mvwaddstr(setup4, 1, 1, "Message Log");
    wrefresh(setup4);
    refresh();
}

/*void print_battle(HERO * player, MONSTER * enemy, WINDOW * setup1, WINDOW * setup2);
{

}*/

