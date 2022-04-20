#include "glue.h"
#include "scene.h"

#define WIDTH 30
#define HEIGHT 10
using namespace myScene;
using namespace std;

int startx = 80;
int starty = 24;

char const *list[] = {
    "New Game",
    "Load Save",
    "Exit",
};

int n_list = sizeof(list) / sizeof(char *);
//void Scene::print_menu(WINDOW *menu_win, int highlight){
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


//void draw_borders(WINDOW *screen){
/*	int x, y, i; getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
 	mvwprintw(screen, y - 1, 0, "+"); 
	mvwprintw(screen, 0, x - 1, "+"); 
	mvwprintw(screen, y - 1, x - 1, "+"); 
	for(i = 1; i < (y - 1); i++) { 
		mvwprintw(screen, i, 0, "|"); 
		mvwprintw(screen, i, x - 1, "|"); 
	} 
	for(i = 1; i < (x - 1); i++) { 
		mvwprintw(screen, 0, i, "-"); 
		mvwprintw(screen, y - 1, i, "-"); 
	}	
*/   
//}

//main 
int main(){
    myScene::Scene scene;
    //scene obj
    WINDOW *menu_win, *map, *msg, *controlswin, *inventorywin, *statwin, *battlewin;
    //menu obj
    int highlight = 1;
    int selection = 0;
    int s;
   // int n_list = sizeof(list) / sizeof(char *);
    scene.startCurses();
    scene.setSize(startx, starty);
    
    menu_win = newwin(HEIGHT, WIDTH, 80, 24);
    map = newwin(43, 165, 0, 0);
    msg = newwin(17, 165, 43, 0);
    controlswin = newwin(60, 16, 0, 165);
    keypad(menu_win, TRUE);
    mvprintw(12, 40, "Stone Soup");
    wborder(menu_win, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(menu_win); 
    curs_set(0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);
	scene.sceneUpdate();
	//scene.main_menu(menu_win, highlight);
	print_menu(menu_win, highlight);

	while(1){
    //scene.start_screen();
	//print_menu(menu_win, highlight);
	s = wgetch(menu_win);
			switch(s)
			{	case KEY_UP:
					if(highlight == 1)
						highlight = n_list;
					else
						--highlight;

			        //scene.main_menu(menu_win, highlight);
			        print_menu(menu_win, highlight);
					break;
				case KEY_DOWN:
					if(highlight == n_list)
						highlight = 1;
					else 
						++highlight;

			        //scene.main_menu(menu_win, highlight);
			        print_menu(menu_win, highlight);
					break;
				case 10:
					s = highlight;
                    scene.sceneUpdate();

                    wborder(map, 0, 0, 0, 0, 0, 0, 0, 0);
                    mvwaddstr(map, 1, 1, "Map");
                    wrefresh(map);

                    wborder(msg, 0, 0, 0, 0, 0, 0, 0, 0);
                    mvwaddstr(msg, 1, 1, "Message Log"); 
                    wrefresh(msg);
                    
                    wborder(controlswin, 0, 0, 0, 0, 0, 0, 0, 0);
                    mvwaddstr(controlswin, 1, 1, "Controls");
                    wrefresh(controlswin);
                    
                    keypad(menu_win, FALSE);

					break;
				default:
					mvprintw(24, 0, " ", s, s);
					refresh();
					break;
			}
            //print menu
			if(selection == 3)	
				break;
	}	
    //delwin(map);
	//delwin(msg);   
	scene.sceneUpdate();	
	scene.endCurses();

    return 0;
}
