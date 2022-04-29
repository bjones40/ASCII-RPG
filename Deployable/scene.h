#ifndef SCENE_H
#define SCENE_H
#include<ncurses.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<panel.h>
namespace myScene
{
    class Scene{
        public:
            Scene();
            ~Scene();
            void startCurses();
            void endCurses();
            int getInput();
            void sceneUpdate();
            void setSize(int, int);
            int getSize();
            void main_menu(WINDOW*, int);
			void start_screen(WINDOW*,WINDOW*,WINDOW*, int, int);
            void draw_borders(WINDOW*);
		
        private:
            int termSize;
			/*int highlight;
			int selection;*/
			//int n_list;
			//int n_list = sizeof(list) / sizeof (char *);
    };

	Scene::Scene(){
/*
		WINDOW *main_menuwin,
			   *playwin,
			   *logwin,
			   *controlswin,
			   *inventorywin,
			   *statwin,
			   *battlewin;

		highlight = 1;
		selection = 0;
		n_list = 0;
        setSize(30,10);
        startCurses();
        main_menuwin = newwin(30, 15, 80, 24);
		playwin = newwin(53, 165, 0, 0);
		logwin = newwin(17, 165, 0, 0);		
		keypad(main_menuwin, TRUE);
		curs_set(0);
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
        mvchgat(0, 0, -1, A_BLINK, 1, NULL);
		start_screen(main_menuwin,playwin,logwin, highlight, selection);
		startCurses();*/
		//n_list = 0;
	}

	Scene::~Scene(){
		endCurses();
	}

	void Scene::startCurses(){
		initscr();
		raw();
		keypad(stdscr, TRUE);
		start_color;
		clear();
		noecho();
		cbreak();
        curs_set(0);
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

	void Scene::main_menu(WINDOW *main_menuwin, int highlight){
			/*int x, y, i;
			char const *list[] = {
  				"New Game",
			    "Load Save",
			    "Exit",
			};
			if(n_list == 0){
					n_list = sizeof(list) / sizeof(char *);
			}
			x = 2;
			y = 2;
			box(main_menuwin, 0, 0);
			for(i = 0; i < n_list; ++i)
			{       if(highlight == i + 1)
					{       wattron(main_menuwin, A_REVERSE);
							mvwprintw(main_menuwin, y, x, "%s", list[i]);
							wattroff(main_menuwin, A_REVERSE);
					}
					else
							mvwprintw(main_menuwin, y, x, "%s", list[i]);
					++y;
			}
			wrefresh(main_menuwin);*/
	}
	
	void Scene::start_screen(WINDOW *main_menuwin,WINDOW *playwin,WINDOW *logwin, int highlight, int n_list){
		/*int s;
		refresh();
		mvprintw(12, 40, "Boulder Stew");
		
		main_menu(main_menuwin, highlight, n_list);
		s = wgetch(main_menuwin);
		char const *list[] = {
					"New Game",
					"Load Save",
					"Exit",
		};
			switch(s)
				{       
						case KEY_UP:
								if(highlight == 1)
										highlight = n_list;
								else
										--highlight;

						main_menu(main_menuwin, highlight, n_list);
								break;
						case KEY_DOWN:
								if(highlight == n_list)
										highlight = 1;
								else
										++highlight;

						main_menu(main_menuwin, highlight, n_list);
								break;
						case 10:
								selection = highlight;
			refresh();

			wborder(playwin, 0, 0, 0, 0, 0, 0, 0, 0);
			mvwaddstr(playwin, 1, 1, "Map");
			wrefresh(playwin);

			wborder(logwin, 0, 0, 0, 0, 0, 0, 0, 0);
			mvwaddstr(logwin, 1, 1, "Message Log");
			wrefresh(logwin);

			keypad(main_menuwin, FALSE);

								break;
						default:
								mvprintw(24, 0, " ", selection, selection);
								refresh();
								break;
				}
	//print menu
				if(selection == 3)
						exit(0);*/
	}

	void draw_borders(WINDOW *screen){
	}
}
#endif
