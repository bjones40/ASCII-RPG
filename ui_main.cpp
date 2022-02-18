#include <ncurses.h>
#include <panel.h>
#include <string.h>
#include <stdio.h>
#include "glue.h"

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
void print_menu(WINDOW *menu_win, int highlight);
/*Scene(){
    startCurses();
}
~Scene(){
    endCurses();
}*/

void Scene::startCurses(){
    initscr();
    raw();
    keypad(stdscr, TRUE);
    start_color;
    clear();
    noecho();
    cbreak();
}

void Scene::endCurses(){
    endwin();
}

int Scene::getInput(){
    return getch();
}

void Scene::sceneUpdate(){
    refresh();
}

int Scene::getSize(){
    return termSize;
}

void Scene::setSize(int r, int c){
    termSize = (stdscr , r, c);
}
//
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
       

//main 
int main(){
    Scene scene;
    WINDOW *menu_win;
    int highlight = 1;
    int selection = 0;
    int s;
    scene.startCurses();
    scene.setSize(startx, starty);
    
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(12, 40, "Stone Soup");
    
    curs_set(0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);
	scene.sceneUpdate();

	print_menu(menu_win, highlight);

	while(1){
	s = wgetch(menu_win);
			switch(s)
			{	case KEY_UP:
					if(highlight == 1)
						highlight = n_list;
					else
						--highlight;
					break;
				case KEY_DOWN:
					if(highlight == n_list)
						highlight = 1;
					else 
						++highlight;
					break;
				case 10:
					selection = highlight;
					break;
				default:
					mvprintw(24, 0, " ", s, s);
					refresh();
					break;
			}
            //print menu
			print_menu(menu_win, highlight);
			if(selection != 0)	
				break;
	}	
	scene.sceneUpdate();	
	scene.endCurses();

    return 0;
}
