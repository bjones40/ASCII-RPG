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
        int get_teleport_id();
        int get_teleport_startX();
        int get_teleport_startY();

        //setters
        void set_traverse(bool value);
        void set_tilechar(char tilechar);
        void set_teleport_id(int id);
        void set_teleport_startX(int xlocation);
        void set_teleport_startY(int ylocation);
        

        int xLoc, yLoc;
    private:
        //int xLoc, yLoc;
        char maintile;
        bool has_item;
        bool has_npc;
        bool has_enemy;
        bool can_traverse;

        int teleportid;
        int teleportx;
        int teleporty;

};

Tile::Tile()
{
    has_item = 0;
    has_npc = 0;
    has_enemy = 0;
    can_traverse = 1;
    maintile = '$';
}

int Tile::get_teleport_id()
{
    return teleportid;
}
int Tile::get_teleport_startX()
{
    return teleportx;
}
int Tile::get_teleport_startY()
{
    return teleporty;
}

void Tile::set_teleport_id(int id)
{
    teleportid = id;
}
void Tile::set_teleport_startX(int xlocation)
{
    teleportx = xlocation;
}
void Tile::set_teleport_startY(int ylocation)
{
    teleporty = ylocation;
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

        void generatetiles(int mapid, int pstartX, int pstartY);
        void cleanmap();
        void displayCamera(int pyLoc, int pxLoc, char pchar);
        int get_map_xMax();
        int get_map_yMax();
        int get_map_id();
        
        int get_xplayer_start();
        int get_yplayer_start();
        void set_xplayer_start(int newstartX);
        void set_yplayer_start(int newstartY);
    
    private:
        WINDOW * curwin;
        int mapxMax, mapyMax, CamxMax, CamyMax;
        int pstartX, pstartY;
        int thisid;
};

Terrain::Terrain(WINDOW * win)
{
    curwin = win;
    getmaxyx(curwin, CamyMax, CamxMax);
}

int Terrain::get_map_id()
{
    return thisid;
}

int Terrain::get_xplayer_start()
{
    return pstartX;
}
int Terrain::get_yplayer_start()
{
    return pstartY;
}
void Terrain::set_xplayer_start(int newstartX)
{
    pstartX = newstartX;
}
void Terrain::set_yplayer_start(int newstartY)
{
    pstartY = newstartY;
}


int Terrain::get_map_xMax()
{
    return mapxMax;
}
int Terrain::get_map_yMax()
{
    return mapyMax;
}

void Terrain::generatetiles(int mapid, int pstartYparam, int pstartXparam)
{
    set_xplayer_start(pstartXparam);
    set_yplayer_start(pstartYparam);
    thisid = mapid;
    
    char map[200][200];

    int totalportals = 0;

    // getting data for chosen map

    switch (mapid)
    {
        case Dessert_Desert:
            {
            //pstartX = 37;
            //pstartY = 31;
            mapxMax = 126;
            mapyMax = 42;
            totalportals = 2;

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
        case Dessert_Desert_Village:
            {
            //pstartX = 6;
            //pstartY = 46;
            mapxMax = 128;
            mapyMax = 52;
            totalportals = 1;

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
                " +                  #     #        # #lccKKlccccKccccccKKKKccccl#       #                    #                               X +",
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
        case Dessert_Desert_Dungeon:
            {
                mapxMax = 200;
                mapyMax = CamyMax+1;

                char DessertDesertDungeon[200][200] = 
                {
                    "                                                                                                                                                 ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                                     ",
                    " |*************************************************************************|                                                                     ",
                    " +*************************************************************************+                                                                     ",
                    " |**********************##############################################*****|                                                                     ",
                    " +**********************#                         #                  #*****+                                                                     ",
                    " |**********************#                                       T T  #*****|                                                                     ",
                    " +**********************#                         #             T T  #*****+                                                                     ",
                    " |**********************#                         #                  #*****|                                                                     ",
                    " +**********************#                         #                  #*****+                                                                     ",
                    " |**********************#                         #                  #*****|                                                                     ",
                    " +**********************#                         #                  #*****+                                                                     ",
                    " |**********************#                         #   ################*****|                                                                     ",
                    " +**********************#                                      #     #*****+                                                                     ",
                    " |**********************#                                      #  T  #*****|                                                                     ",
                    " +**********************#                                            #*****+                                                                     ",
                    " |**********************#                                      #     #*****|                                                                     ",
                    " +**********************#####################    #####################*****+                                                                     ",
                    " |**********************#                                  #         #*****|                                                                     ",
                    " +**********************#                                  #      X  #*****+                                                                     ",
                    " |**********************#                                            #*****|                                                                     ",
                    " +**********************##############################################*****+                                                                     ",
                    " |*************************************************************************|                                                                     ",
                    " +*************************************************************************+                                                                     ",
                    " |*************************************************************************|                                                                     ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                                     ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 ",
                    "                                                                                                                                                 "
                };

                memcpy(map, DessertDesertDungeon, 200*200*sizeof(char));
            }
            break;
        default:
            break;
    }
    
    
    int currentportal = 0;
    
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
            else if (temptile == 'X')
            {
                switch (thisid)
                {
                    case Dessert_Desert:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(Dessert_Desert_Dungeon);
                                tiles[j][i].set_teleport_startY(19);
                                tiles[j][i].set_teleport_startX(64);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(Dessert_Desert_Village);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Dessert_Desert_Village:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(Dessert_Desert);
                                tiles[j][i].set_teleport_startY(31);
                                tiles[j][i].set_teleport_startX(37);
                                break;
                        }
                        break;
                    case Dessert_Desert_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(Dessert_Desert);
                                tiles[j][i].set_teleport_startY(13);
                                tiles[j][i].set_teleport_startX(61);
                                break;
                        }
                        break;
                    case Cabbage_Campo1:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Cabbage_Campo1_Village:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Cabbage_Campo1_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Cabbage_Campo2:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Cabbage_Campo2_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Carrot_Canyon1:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Carrot_Canyon1_Village:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Carrot_Canyon1_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Carrot_Canyon2:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Carrot_Canyon2_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Soup_Sea1:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Soup_Sea1_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Soup_Sea2_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                    case Soup_Sea3_Dungeon:
                        switch (currentportal)
                        {
                            case 0:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                currentportal++;
                                break;
                            case 1:
                                tiles[j][i].set_teleport_id(1);
                                tiles[j][i].set_teleport_startY(46);
                                tiles[j][i].set_teleport_startX(6);
                                break;
                        }
                        break;
                }
            }
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
