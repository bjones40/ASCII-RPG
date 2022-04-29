#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#define MAGENTA_PAIR 1
#define BLUE_PAIR 2
#define WHITE_PAIR 3
#define CYAN_PAIR 4
#define YELLOW_PAIR 5
#define RED_PAIR 6
#define GREEN_PAIR 7

class Tile
{
    public:
        Tile();
        //getters
        char get_tilechar();
        bool get_traverse();
        bool get_has_enemy();
        bool get_has_npc();
        bool get_has_item();

        //setters
        void set_traverse(bool value);
        void set_tilechar(char tilechar);
        

        int xLoc, yLoc;
    private:
        //int xLoc, yLoc;
        char maintile;
        bool has_item;
        bool has_npc;
        bool has_enemy;
        bool can_traverse;

};

Tile::Tile()
{
    has_item = 0;
    has_npc = 0;
    has_enemy = 0;
    can_traverse = 1;
    maintile = '$';
}

char Tile::get_tilechar()
{
    return maintile;
}

bool Tile::get_traverse()
{
    return can_traverse;
}

void Tile::set_traverse(bool value)
{
    can_traverse = value;
}

void Tile::set_tilechar(char tilechar)
{
    maintile = tilechar;
}

class Terrain
{
    public:
        Terrain(WINDOW * win);

        Tile tiles[200][200];

        void generatetiles(int mapid, int mapxSize, int mapySize);
        void cleanmap();
        void displayCamera(int pyLoc, int pxLoc, char pchar);
        int get_map_xMax();
        int get_map_yMax();
        int pstartX, pstartY;
    private:
        WINDOW * curwin;
        int mapxMax, mapyMax, CamxMax, CamyMax;
};

Terrain::Terrain(WINDOW * win)
{
    curwin = win;
    getmaxyx(curwin, CamyMax, CamxMax);
    //keypad(curwin, true);
    //Tile tilemap[xMax][yMax];
    //generatetiles();
}


int Terrain::get_map_xMax()
{
    return mapxMax;
}
int Terrain::get_map_yMax()
{
    return mapyMax;
}

void Terrain::generatetiles(int mapid, int pstartX, int pstartY)
{
    pstartX = pstartX;
    pstartY = pstartY;
    char map[200][200];


    // getting data for chosen map

    switch (mapid)
    {
        case 0:
            {
            pstartX = 37;
            pstartY = 31;
            mapxMax = 126;
            mapyMax = 42;
            
            char DessertDesert[200][200] = 
            {
                "                                                                                                ",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
                " |~~~~~~~~~~MMMMttttttttttttttt, ., . ,.,., ., ., ., ., ., .ttttttttttMMM~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~MMMttttttttttttttttttt., ., ., ,. , tttttttttttttttttttttttttMM~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~MMMtttttttttttttttttttt,,, .. , . , ttttttttttttttttttttHHHHHHHHHMMMMM~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~MMMHHHHHHHHHttttHHHHHt, ., ., . ,. ttttttttttttttttttttttttHHHHHMM~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~MMMMMMMHHtttttttttHHHtt. ., .,., ., .tttttttttttttttttttttttttHHHHMMM~~~~~~~~~~~~~~~~~|",
                " +~~~~~~MMHHHHHHHHHHHttttHHHttt., . ,. , .,. ,tttttt., ., ., ., . ,..ttHMMMM~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~MMMMMHHHHHHHHHHHHHMMMMMt.,. ., . ,.. ,tMttttttt., . , . ,. , tHHHMMM~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~MMMHHHHHHHHHHHHHHHHHHMMMM.. ., ., , tttMMMHHHttt. ., ., ., ., tHHMM~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~MMMMMMMHHHHHHHHHHHHHHMMMMt, ., ., .,. tttMMMMHHHtt. ., , ,., ,ttMM~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~MMMMMMHHHHHHHHHHHHMMMMtt, ., ., ., .,,tMMMMMHHHHtt., .# #. ,.ttMMM~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~MMMMMMMMMMMMMMMMMttt., ., .,,. . ,, ttMMMMHHHttttt### ###ttMMMMM~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~MMMMMMMMMMMMMMtt., ., .,., ,. ,,.ttMMMMMMHtttttt#     #tMMMM~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~MMMMMMMMMMtt,., ., ,. , ., , .,tMMMMMMMMMMtttt#  X  #tttMMM~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~MMMMMMMMMMttt,. ., ,. ,. ., ,. , ttMMMMMMMMMMMttt#     #ttttMM~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~MMMMMMMMttt, ., ., ,. ., ., ,. ,.,ttMMMMMMMMMMMtt#######tttM~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~MMMMMttt., . ., ,. .,, . ,. ,.., ,ttttMMMMMMMMMtttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~MMMtt, ., . . ,. , ., .,., ,. , ,.. tttMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~MMMt.,. ., ., ,. .,., . .,. ,., ., . ,ttttMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~MMMM., ., .,., ., ., ,. . , .,,. ,. , ,. tttMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~MMMMtttt. ,., ., , . , . ,. ,. ,. ,. , .,  ,,ttMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~MMMMtt., . . , ., ., ,. , . ,. ,. ,.,. ,ttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~Mt. ,., ,. ., ., ., ., ., . ,. , .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~Mtttt., . , ., . . , ., . ,.,. ,. ,ttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~MMHHtt., ., ,. ,. ,. ., ,. ,. ,. . .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~MMMHtttttt., ., ., ., ., ., ., ., ,.ttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~MMHtttttttttttt., ., , . ., ., ., tttttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~MHHttttttttttttt,. , ., ., ., ,,.ttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~MMMHHHHHHttttttt.,. .# #, .,ttttttttttHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~MMMHHHHtttttttttt### ###tttttttttttttHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~~~~MMHHttttttttttt#     #tttttttttHHHHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~~MMMHHttttttttttt#  X  #ttttttttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~~~~MMHHHHHHHtttttt#     #tttttttttttHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~~~~~MMMMMHHHHHttt#######ttttttttttttHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~~~~~~~~~~~MMMHHHtttttttttttttttttttttHHHHMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHttttttttttttttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMMMMMMMttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
            };
            
            memcpy(map, DessertDesert, 200*200*sizeof(char));
            }
            break;
        case 1:
            {
            pstartX = 6;
            pstartY = 46;
            mapxMax = 131;
            mapyMax = 51;

            char DessertDesertVillage[200][200] =
            {
                "                                                                                                                                ",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
                " |                                                                                                                             |",
                " +               #########################################################################################################     +",
                " |               #                                                                                                       #     |",
                " +               #                                                                                                       #     +",
                " |               #                                                                                                       #     |",
                " +               ###     #######################################################          ####                           #     +",
                " |                 #     #llllllllllllllllllllllllllllllllllllllllllllllllllllll          lll#                           #     |",
                " +                 #     #llcKckKccKcc KcccKccKcccKc cKKKcKcc  KKccKccKc KcKcccK cccKccKKccll#                           #     +",
                " |                 #     #lllllllllllllllllllKcKKc KccKccKcKKcKKcK KcccccKccKKcKcKcc KccKccll#                           #     |",
                " +  ################     ##################llcc KcKcccKKcKKc cKcKKckcccKccKccK cccKKccKcKKcll#                           #     +",
                " |  #                                     #llKccKccKcc KccKcKccccKKccKc cKcccKKccKKKKKccK cll#                           #     |",
                " +  #                                     #llcc KccKcKKKcccKcK cKcKccKcKcKKKKccKc KcccKcKcK      ^^^   ^^^   ^^^   ^^^   #     +",
                " |  #    CCCCCCCCCC         VVVVVVVVVV    #llccKccKKcc KcKKKcccccKKccKcK ccKcKKcKcKKcc KKcc      ^^^   ^^^   ^^^   ^^^   #     |",
                " +  #    CCCCCCCCCC         VVVVVVVVVV    #ll ccccKKcccKcccKc cKKccKcKcKKcKKcKcc ccKKKKccKcll#                           #     +",
                " |  #    CCCCCCCCCC         VVVVVVVVVV    #llcccKcKKccKKccK cKKccKKKcKcKc ccKccKccKccKKKcKcll#                           #     |",
                " +  #                                     #llcKcKK cccKccccKK KcKKccccKcKKcccKcc KcKccKKKccll#   ^^^   ^^^   ^^^   ^^^   #     +",
                " |  #    CCCCCCCCCC         VVVVVVVVVV    #llcccccKcccc ccKKccKKcKcc cKcKcKKKcKcKccKcKKKcccll#   ^^^   ^^^   ^^^   ^^^   #     |",
                " +  #    CCCCCCCCCC         VVVVVVVVVV    #llcc KKccKcccKcKcKK ccKcKccccKKKcc KKcKcKKKK cKcll#                           #     +",
                " |  #    CCCCCCCCCC         VVVVVVVVVV    #llllllllllllllllllllllllllllllllllllllllllllllllll#                           #     |",
                " +  #                                     ####################################################   ^^^   ^^^   ^^^   ^^^   #     +",
                " |  #                                                                                            ^^^   ^^^   ^^^   ^^^   #     |",
                " +  #    SSSSSSSSSS         PPPPPPPPPP                                                                                   #     +",
                " |  #    SSSSSSSSSS         PPPPPPPPPP                                                                                   #     |",
                " +  #    SSSSSSSSSS         PPPPPPPPPP    #######################       ######################   ^^^   ^^^   ^^^   ^^^   #     +",
                " |  #                                     #llllccKKclllccKccllll#       #                    #   ^^^   ^^^   ^^^   ^^^   #     |",
                " +  #    SSSSSSSSSS         PPPPPPPPPP    #llcccKccccKcKKcccKcll#       #                    #                           #     +",
                " |  #    SSSSSSSSSS         PPPPPPPPPP    #lcccKccKccccccKKKKccl#       #                    #                           #     |",
                " +  #    SSSSSSSSSS         PPPPPPPPPP    #lcKcccKccKccKccKccccl#       #                    #   ^^^   ^^^   ^^^   ^^^   #     +",
                " |  #                                     #lcKccccKcccKccccKKKcl#       #                    #   ^^^   ^^^   ^^^   ^^^   #     |",
                " +  #                                     #lcKcccccKKcccKKcccccl#       #                    #                           ######+",
                " |  #################     ##########/######lcccccccccKcccccccccl#       #                    #                                 |",
                " +                  #     #        # #lccKKlccccKccccccKKKKccccl#       #                    #                                 +",
                " |                  #     #        # #lcKccllcKcccccKKcccccccKll#       #                    #                                 |",
                " +                  #     #        # #lcccclllcccKcccccKccKcclll#       #                    #                           ######+",
                " |                  #     #        # #lKKcKllllccccKccccccccllll#       #                    #                           #     |",
                " +                  #     #        # #lcKcclllllllcKKcccKlllllll#       #                    #                           #     +",
                " |                  #     #        # #llllll#######################   ###################    #                           #     |",
                " +                  #     #        # #lcKccl#             #                  #          #    #                           #     +",
                " |                  #     #        # #lKcKcl#                                #  $       #    #                           #     |",
                " +                  #     #        # #lKcccl#             ####################          #    #                           #     +",
                " |                  #     #        # #llllll#                   #            #          #    #      rrrrr   rrrrr        #     |",
                " +#########         #     #        # ########                   #            ######     #    #    rrrrrrr  rrrrrrrrrrrr  #     +",
                " |        #         #     #        #                                                    #    ####rrrrrrrr########rrrrrrr##r    |",
                " +        ###########     #        ##########                   #                       #     rrrrrrrrrrrrrrrrrrrrrrrrrrrrr    +",
                " |                        #                 #                   #                       #   rrrrrrrrrrr  rrrrrrrrrrrrrrrrrrrr  |",
                " +        #################                 #                   #                       #    rrrrrrrrrrrr rrrrrrrrrrrrrrrr     +",
                " |        #                                 #############################################  rrr   rrrrrrrrrr  rrrrrrrr  rrrrr   |",
                " +#########                                                                                 rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr   +",
                " |                                                                                   rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr|",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
            };

            memcpy(map, DessertDesertVillage, 200*200*sizeof(char));
            }
            break;
        case 2:
            {
            break;
            }
        default:
            break;
    }
    
    
    
    
    // creating the map, setting tiles, and xLoc, and yLoc of each tile
    
    for (int i = 0; i < mapyMax; i++)
    {
        for (int j = 0; j < mapxMax; j++)
        {
            tiles[j][i].set_tilechar(map[i][j]);
            tiles[j][i].xLoc = i;
            tiles[j][i].yLoc = j;

            char temptile = tiles[j][i].get_tilechar();
            
            if (temptile == '#' || temptile == '+' || temptile == '-' || temptile == '|')
                tiles[j][i].set_traverse(0);
        }
    }
}

void Terrain::displayCamera(int pyLoc, int pxLoc, char pchar)
{
    int halfCamxOffset = (CamxMax-1)/2;
    int halfCamyOffset = (CamyMax-1)/2;

    //initialize color pairs if can be displayed
    if (has_colors())
    {
        start_color();
        init_pair(MAGENTA_PAIR, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(BLUE_PAIR, COLOR_BLUE, COLOR_BLACK);
        init_pair(WHITE_PAIR, COLOR_WHITE, COLOR_BLACK);
        init_pair(CYAN_PAIR, COLOR_CYAN, COLOR_BLACK);
        init_pair(YELLOW_PAIR, COLOR_YELLOW, COLOR_BLACK);
        init_pair(RED_PAIR, COLOR_RED, COLOR_BLACK);
        init_pair(GREEN_PAIR, COLOR_GREEN, COLOR_BLACK);
    }
    
    // camera for zoomed in view of map, with its own x and y max
    for (int i = 1; i < CamxMax-1; i++)
    {
        for (int j = 1; j < CamyMax-1; j++)
        {
            int displayX, displayY;
            

            // if player is far top-left of map
            if (pxLoc < mapxMax && pxLoc <= halfCamxOffset)
            {
                displayX = i;
            }
            if (pyLoc < mapyMax && pyLoc <= halfCamyOffset)
            {
                displayY = j;
            }

            // if player is anywhere in middle of map
            if (pxLoc < mapxMax && pxLoc > halfCamxOffset)
            {
                displayX = i + (pxLoc - halfCamxOffset);
            }
            if (pyLoc < mapyMax && pyLoc > halfCamyOffset)
            {
                displayY = j + (pyLoc - halfCamyOffset);
            }

            // if player is far bottom-right of map
            if (pxLoc < mapxMax && pxLoc >= mapxMax - halfCamxOffset)
            {
                displayX = i + (mapxMax - (CamxMax - 1));
            }
            if (pyLoc < mapyMax && pyLoc >= mapyMax - halfCamyOffset)
            {
                displayY = j + (mapyMax - (CamyMax - 1));
            }

            
            // turn on colors for specified characters if colors are possible
            if (has_colors())
            {
                char displayedchar = tiles[displayX][displayY].get_tilechar();
                switch (displayedchar)
                {
                    case 'c':
                        wattron(curwin, COLOR_PAIR(MAGENTA_PAIR));
                        mvwaddch(curwin, j, i, displayedchar);
                        wattroff(curwin, COLOR_PAIR(MAGENTA_PAIR));
                        break;
                    case '+':
                    case '-':
                    case '|':
                    case '/':
                        wattron(curwin, COLOR_PAIR(BLUE_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    case '#':
                    case '^':
                        wattron(curwin, COLOR_PAIR(WHITE_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    case 'K':
                        wattron(curwin, COLOR_PAIR(CYAN_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    case 'r':
                    case 'v':
                        wattron(curwin, COLOR_PAIR(YELLOW_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    case '$':
                    case '~':
                        wattron(curwin, COLOR_PAIR(RED_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    case 'l':
                    case 'C':
                        wattron(curwin, COLOR_PAIR(GREEN_PAIR));
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        wattroff(curwin, COLOR_PAIR(BLUE_PAIR));
                        break;
                    default:
                        mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
                        break;
                }
            }
            else
            {
                mvwaddch(curwin, j, i, tiles[displayX][displayY].get_tilechar());
            }

        }
    }

    int newpyLoc, newpxLoc;
    
    // player x location adjustment for camera display
    if (pxLoc < mapxMax && pxLoc <= halfCamxOffset)
    {
        newpxLoc = pxLoc;// + 1; // 1 added due to ncurses border
    }
    
    if (pxLoc < mapxMax && pxLoc >= halfCamxOffset)
    {
        newpxLoc = halfCamxOffset; // keeps the player at the center of the screen
    }

    if (pxLoc < mapxMax && pxLoc >= mapxMax - halfCamxOffset)
    {
        newpxLoc = pxLoc - (mapxMax - (CamxMax - 1)); 
        // adjusts player's displayed position by offsetting it based on the maps edge and camera's max size
    }
    

    // player y location adjustment for camera display
    if (pyLoc < mapyMax && pyLoc <= halfCamyOffset) 
    {
        newpyLoc = pyLoc;// + 1;
    }
    
    if (pyLoc < mapyMax && pyLoc >= halfCamyOffset)
    {
        newpyLoc = halfCamyOffset;
    }
    
    if (pyLoc < mapyMax && pyLoc >= mapyMax - halfCamyOffset)
    {
        newpyLoc = pyLoc - (mapyMax - (CamyMax - 1));
    }

    mvwaddch(curwin, newpyLoc, newpxLoc, pchar);
    wrefresh(curwin);

}

#endif
