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
            mapxMax = 125;//126;
            mapyMax = 42;
            totalportals = 2;

            char DessertDesert[200][200] = 
            {
                "                                                                                                                                                           ",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                           ",
                " |~~~~~~~~~~MMMMttttttttttttttt, ., . ,.,., ., ., ., ., ., .ttttttttttMMM~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~MMMttttttttttttttttttt., ., ., ,. , tttttttttttttttttttttttttMM~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~MMMtttttttttttttttttttt,,, .. , . , ttttttttttttttttttttHHHHHHHHHMMMMM~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~MMMHHHHHHHHHttttHHHHHt, ., ., . ,. ttttttttttttttttttttttttHHHHHMM~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~MMMMMMMHHtttttttttHHHtt. ., .,., ., .tttttttttttttttttttttttttHHHHMMM~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~MMHHHHHHHHHHHttttHHHttt., . ,. , .,. ,tttttt., ., ., ., . ,..ttHMMMM~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~MMMMMHHHHHHHHHHHHHMMMMMt.,. ., . ,.. ,tMttttttt., . , . ,. , tHHHMMM~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~MMMHHHHHHHHHHHHHHHHHHMMMM.. ., ., , tttMMMHHHttt. ., ., ., ., tHHMM~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~MMMMMMMHHHHHHHHHHHHHHMMMMt, ., ., .,. tttMMMMHHHtt. ., , ,., ,ttMM~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~MMMMMMHHHHHHHHHHHHMMMMtt, ., ., ., .,,tMMMMMHHHHtt., .# #. ,.ttMMM~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~MMMMMMMMMMMMMMMMMttt., ., .,,. . ,, ttMMMMHHHttttt### ###ttMMMMM~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~MMMMMMMMMMMMMMtt., ., .,., ,. ,,.ttMMMMMMHtttttt#     #tMMMM~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~MMMMMMMMMMtt,., ., ,. , ., , .,tMMMMMMMMMMtttt#  X  #tttMMM~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~MMMMMMMMMMttt,. ., ,. ,. ., ,. , ttMMMMMMMMMMMttt#     #ttttMM~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~MMMMMMMMttt, ., ., ,. ., ., ,. ,.,ttMMMMMMMMMMMtt#######tttM~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~MMMMMttt., . ., ,. .,, . ,. ,.., ,ttttMMMMMMMMMtttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~MMMtt, ., . . ,. , ., .,., ,. , ,.. tttMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~MMMt.,. ., ., ,. .,., . .,. ,., ., . ,ttttMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~MMMM., ., .,., ., ., ,. . , .,,. ,. , ,. tttMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~MMMMtttt. ,., ., , . , . ,. ,. ,. ,. , .,  ,,ttMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~MMMMtt., . . , ., ., ,. , . ,. ,. ,.,. ,ttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~Mt. ,., ,. ., ., ., ., ., . ,. , .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~Mtttt., . , ., . . , ., . ,.,. ,. ,ttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~MMHHtt., ., ,. ,. ,. ., ,. ,. ,. . .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~MMMHtttttt., ., ., ., ., ., ., ., ,.ttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~MMHtttttttttttt., ., , . ., ., ., tttttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~MHHttttttttttttt,. , ., ., ., ,,.ttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~MMMHHHHHHttttttt.,. .# #, .,ttttttttttHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~MMMHHHHtttttttttt### ###tttttttttttttHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~~~~MMHHttttttttttt#     #tttttttttHHHHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~~MMMHHttttttttttt#  X  #ttttttttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~~~~MMHHHHHHHtttttt#     #tttttttttttHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~~~~~MMMMMHHHHHttt#######ttttttttttttHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~~~~~~~~~~~MMMHHHtttttttttttttttttttttHHHHMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHttttttttttttttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMMMMMMMttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                           ",
                " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                           ",
                " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                           "
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
                mapxMax = 180;
                mapyMax = 180;

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
        case Cabbage_Campo1:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 101;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 42;

                char CabbageCampo1[200][200] = 
                {
                    "                                                                                                                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |~~~~~~~~~~~MMMMMMMHHHHH,. ., . ,. , . , . . ., .ttttttt. ,. , ,. , .  ,.  ,. .tttttttttttHHMM|                                                    ",
                    " +~~~~~~~~~~MMMMMMMHHHH, ., . , .,., . , ., .. ,.ttttttttt., ., . ### ###. ,. ,. ttttttttttttHM+                                                    ", 
                    " |~~~~~~~MMMMMMMMHHHH,. ., ., ,. ., . ,. , ,,. ,ttttttttttt., ,.  #     # . ,, ,ttttttttttttttH|                                                    ",
                    " +~~~~~MMMMMMMMMHHHH, . ,. ,. ., ,. ., ,, ., ., ttttttttttt.,######     ######, .,tttttttttttHH+                                                    ",
                    " |~~~MMMMMMMMMHHHHHH,. ., . ,. ,. , ., . , . ,, ttttttttttt,,#               #., .ttttttt. , . |                                                    ",
                    " +~~MMMMMMMHHHHHHtttttt,. ., . ,, .tttttt., . . .ttttttttt, ,#       X       # ., ,.ttttt,. ,. +                                                    ", 
                    " |~MMMMMHHHHHHHHttttttttt, , .  .ttttttttt,. , . , ttttt., ,.#               # .,. tttt. .. ., |                                                    ",
                    " +MMMMMMHHHHHHtttttttttt,. ., .ttttttttttttt,. .,.  ..ttt. ..#               #, ,. .ttttttt,. ,+                                                    ",
                    " |MMMMMMMHHHHHHHtttttttt, .,, ..ttttttttttt., ., .,.tttttt.,,#################.,.ttttttttt,.. ,|                                                    ",
                    " +~MMMMMMHHHHHHHHHHtttt,. ., . .ttttttttttt.,, . . .tttttt., . ,. ,., . ,. , ,ttttttttttt,. , .+                                                    ",
                    " |~~MMMMMMMHHH,. ., . ,. ,.  . ,. ttttttt., ., ,., .,ttt.,. ., ., ., ., ., . .ttttttttttt,., . |                                                    ",
                    " +~~MMMMMMHHHHHHH,. ., . ,.  .,,. ,. ,. . . , . ,  .,. , . .ttttttt,, ., . . ,ttttttttttt., ., +                                                    ",
                    " |~MMMMMMMHHHHHHHHH, ., . ,., .,  ., . , ., . , . ,. ,. ,.ttttttttttt., , , ,. ttttttttt, ., . |                                                    ",
                    " +~MMMMMMMHHHHHHH,., ,. ,. ,.  , . ..,  ., . ,. , ., . .,ttttttttttttt, ., . ,..ttttttt. ,,. .,+                                                    ",
                    " |~~MMMMMMMMHHHHHHHHH,. ., . ,, ., ,. , .,. , . ,,  , .,.ttttttttttttt, ., . ,. ., . ,. ,. , . |                                                    ",
                    " +~~~MMMMMMMMHHHHHH,. ., . ., ., . , ., ,. , ., . . , ., ttttttttttttt,. ., ., ., . , ., . ,. .+                                                    ",
                    " |~~~MMMMMMMHHHHHHHHHHHHHH,,. ., . , . , , ., ., . ,. , . ttttttttttt.,. ,. . , ., . ,.. ,..  ,|                                                    ",
                    " +~~~MMMMMMMMHHHHHHH,.. ., ., . ,. ,. . , .  ., . ,. , .. ,. ttttt,. ., ., . , ., , ., ., , .. +                                                    ",
                    " |~~MMMMMMMMHHHHHHHHHHH,. ., ., ,., .., , . ,. , ., . , .,., ., , ., . ,. ,. ,. ,., . ., ,. . ,|                                                    ",
                    " +~MMMMMMMMMMHHHHHHHH,., ., . ,. ,, .., . , ,. ,. ,. ,, .,.., , .., ,. ,. , . ,.  . , . ,. , ..+                                                    ",
                    " |~MMMMMMMMMMHHHHHHH, ,. .,, ., ., ., ., ., . .,. ,.,. , ,.. , . ,. ., ,. ., . ,. ., .. , ., . |                                                    ",
                    " +~~MMMMMMMMHHHHHHHHHHH,. ., . .,tttttttttt,. ., . ,. , . ,. , . ,, ., ., ,, , . . ,. .,. ,. ,.+                                                    ",
                    " |~~~MMMMMMHHHHHHHHHHHH, ., ., .tttttttttttt. ,., ., ,. ., , , ,. , . ,. , ., ., .,., ., ., . .|                                                    ",
                    " +~~~MMMMMMMHHHHHHHH.,. ., . ,tttttttttttttttt,., . ,. ,. ,., . ,tttttttttttttttttt,., ., .,. ,+                                                    ",
                    " |~~~MMMMMMMHHHHHHHHHHH, ., .,tttttttttttttttt., . , ., . , .,ttttttttttttttttttttttttt,, ., . |                                                    ",
                    " +~~~~MMMMMHHHHHHHH,. ,.  ,. ,tttttttttttttttt. .,  ., , . .ttttttttttttttttttttttttttttt., ., +                                                    ",
                    " |~~MMMMMMMHHHHHHHHHHHHH, ,. ., tttttttttttt,. . ,, ., . ttttttttttttttttttttttttttttttttttt. .|                                                    ",
                    " +~MMMMMMMHHHHHHHHHHH., ., . ,.,  tttttttt. .,  ., ., ,.ttttttttttttttttttttttttttttttttttttt.,+                                                    ",
                    " |~MMMMMHHHHHHH,. ., . , ., ., ., ., .., ., ., . ,. , .,ttttttttttttttttttttttttttttttttttttt ,|                                                    ",
                    " +MMMMMMHHHHHHHHHHHHH, ., ., ,. ., , . , ., ., . ,., ., ttttttttttttttttttttttttttttttttttttt. +                                                    ",
                    " |~MMMMMMHHHHHHHH., ., . ,,. ., ,. ,  ., ., ., ., . ,. , ,ttttttttttttttttttttttttttttttHHMMMMM|                                                    ",
                    " +~~MMMMMMHHHHHHHHH, . ,. . ,. ,. ,, .tttttttt., ., . ,, ,.tttttttttttttttttttttttttHHHMMMMMM~~+                                                    ",
                    " |~~~MMMMMMHHHHHHHHH,. ., ,. , . ,.,ttttttttttt,. ., ., ., ,.tttttttttttttttttHHHHMMMMMMMM~~~~~|                                                    ",
                    " +~~~~~MMMMMHHHHHHHHHHH,., ., ., ., .ttttttttttt, ., . , , ., .,ttttttttttHHHHMMMMMMMMM~~~~~~~~+                                                    ",
                    " |~~~~~MMMMMHHHH,.,. ., . ,. , . . . ,ttttttttt., . ., .  . , ., ,tttttttttHHHMMMMMMM~~~~~~~~~~|                                                    ",
                    " +~~~~~~MMMMMMHHHHHH., . ,. ., ., ,. ., ,ttttt ., . ,. , .,. ., ., ,.,. ., HHHMMMMMM~~~~~~~~~~~+                                                    ",
                    " |~~~~~~MMMMMHHHHHHHHHH., . , , . ,. ,. ,.ttt. ,. , ., . , ,. ,. ., ., .HHHHMMMMMM~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~MMMMMHHHH, ., . ,.  ., . , . ., ,. .,., ., ., , ,..,., ., .HHHHHMMMMMM~~~~~~~~~~~~~~~~+                                                    ",   
                    " |~~~~~~~MMMMHHHHHHHH,. ., . ,. , . ,. ,, .,., . ,. ,. ., ,.HHHMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CabbageCampo1, 200*200*sizeof(char));
            }
            break;
        case Cabbage_Campo1_Village:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 121;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 52;

                char CabbageCampo1Village[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
                    " |., ,. ., . , ################################# ., ,. ., ., ., ,.. , ., ., ., ,  ., ., .,. , ., ., . .,. ., . ,. ,. , ., . . ,|",
                    " +., ,  . ,. .,#0000000000000000000000000000000# , ,, . ,  ., , . , . ,.  ,, . ., ,.., , .,  , ., .,  ., . , .,  .,  .,  ., . ,+",
                    " | ., ., ,. .,,#0000000000000000000000000000000# ., ., ., ,.  ,. ., xxxxxxxxxxxxxxxxxxxxxxxxxxxx. . , ., . ,,#############. , .|",
                    " +,. ., ., .  .#0000000000000000000000000000000# ., . ., . , ,. ., ,x                          x, , . , . , .#00000000000# . ,,+",
                    " | ., ., ., .  #0000000000000000000000000000000# ., ., ., ,. . , ., x   xxxxxxxxxxxxxxxxxx     x. , .,  . , .#00000000000# ., .|",
                    " +. , ., .,, . #0000000000000000000000000000000# . , ., . , ,.  , .,x   x.  , . , . ,. .,x     xxxxxxxxxx. , #00000000000# . . +",
                    " |. , ,. ., .,.############000000000############ ., ., ,. ,. , ., .,x   x ,. , ,. ., ., .x              x. , ####00000#### ,. .|",
                    " +., ., ,. ,. . ,., ., ., #000000000# .,  . ,. ., , . ,. ., .,  ,. ### ###  ., ,. ,.  ., x     xxxxxxx  x ., . .#00000# ., . , +",
                    " |., ., , . , . , ., ,. , #000000000#.,  ., ., ., ., ., ., ., ., . #00000# ., , .  , . , x     x, . ,x  x., ., .### ###. , . , |",
                    " +., ., . , .  . ,. ,. ., ####   #### ., , . , ., .,  ., . ,. . ####00000#### ., ., ., . x     x.,  .x  x. , ., .x   x, ., . .,+",
                    " |,. . , ., , . , . ,. ., . x     x. , ., . ,. . . , . ,. ,. , .#00000000000#. , . ., . ,x     x ., .x  xxxxxxxxxx   x .,  .,. |",
                    " +. , , . , ., . ,.  ., , .,x     x ., ., . ,. , ., . ,. , . , .#00000000000#. , . ,. ., x     x. ,. x               x , ., . .+",
                    " |. ,. ,. , ,. . ,. ,. ,. . x     x ,. ., . ,. , ., ., ., . ,.. #00000000000# ., . , ,. ,x     x ., .xxxxxxxxxxxxxxxxx., ., ., |",
                    " +., . , ,. ,. ., .,. , .,  x     x ., ., . , ., ., ., ., . , . #############., ,. ,. ., x     x, ., ,., ., . ,. , ., . ., ., .+", 
                    " |., ., . , ., ., ., ., ., ,x     x.,  ., ., , . . , . , . , .  . .,  ., , ,. ., .,,.  .,x     x., ., ., .,  ., ., ., ., ., ., |",
                    " +, .. , . ., ,. ,. ,. ,. .,x     x., . ,. , . ,., ., ., ,. ., ,. ., ., .,  ., ., ., ., .x     xxxxxxxxxxxxx, . , ., ., ., ., .+",
                    " |xxxxxxxxxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx .x                 x ., .,., ., ., .,. |",
                    " +                                                                                    x. x     xxxxxxxxx   x., ., ., ,. ,. ,. .+",
                    " |                                                                                    xxxx     x, ,. .,x   x. ,. ,. ., ., ,.., |",
                    " +                                                                                             x , . . x   x,  , ., . ,, . .. ,+",
                    " |xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxxxxx              x . , .### ###, . . , ., . ,. . |",
                    " +., ., ,. ., . . , . , . , ,. , , ., ., . , ,. ,. ., , ,x     x. , ., ., . , . x              x.,.  ,#00000#. , . , . ,. , ,. +",
                    " |., ,. ., , . ., ,. ., ., ,. ,. ., . ,. , ., ., ., ., .,x     x.,  ,. ., .,  . x     xxxxxxxxxx . ####00000#### ., . . , ., ,.|",
                    " +,. ,. ,. ,. ,. ,. . , ,. , . , . ., ., .  ,, ., ,. , . x     x., . ,, . , ., .x     x , . , ., . #00000000000# . , ., ,. .  ,+",
                    " |. , ., . ,. ., ., ,. ,. , ., ., ,. .,., ,. ., ., ,. , .x     x. ,,. , ., ,. , x     x. ,  . .,  .#00000000000# ,. ., ., , . .|",
                    " +. ,. , ., . ., ., ., ,. ., . , , . ., . , ., .,  ., ., x     x., , ,. ,. ., . x     x , ,. . .,, #00000000000#., ,. . . , ,. +",
                    " |. , ., . ., . ,. ,.  ,. , .,., ., . ,. . ., ., ., . , .x     x. ,, ., ., ,. . x     x., ., . . , #############., . , . , . .,|",
                    " +###################.. ,., . ,. , ., ., .,. ., . ,., .  x     x. ,. , ,.  ,.. ,x     x ,., , ., , . , . ,,. ,. . ,., ,., . , .+",
                    " |#00000000000000000# .,. , ., . ,. .,. , ., ., . , .,  ,x     x .,. ,. , ., ., x     x,  ., . ,. , . ,. . . ., .  ,., . ,.  ..|",
                    " +#00000000000000000# ,. . ,. , . .,, ., .. ,. ,. ,., . .x     x ,.. ,. ,. , ., x     x., ,. ,. ,. ,. ., .,. , . ,. . ,.,. , . +",
                    " |#00000000000000000#. ,. ,. ., . ,. .,. , ., . ,. , .,. x     x., . ,. . . , .,x     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|",
                    " +#00000000000000000######., . , . ,. ,. , . , . . ,. ., x     x. ,., . ,. ,. ,.x                                              +",
                    " |#0000000000000000000000#., . , . ,. ., ., ., ., ., . .,x     x. ,.  . ,. ,.. ,x                                              |",
                    " +#0000000000000000000000#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     x., . , ., ,. , .x                                              +",
                    " |#0000000000000000000000#                                     x., . ,. . , . . x     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|",
                    " +#0000000000000000000000                                      x ., . , ,.  , . x     x. ,. ,. ,. . , . ,. , ., . ,, . ,.  . , +",
                    " |#0000000000000000000000#                                     x ., ,., ., . ,. x     x, , . , . ,. , . ,., .. ,. . , ., . . , |",
                    " +#0000000000000000000000#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ., ,. ., ,. ,  x     x ., . , ., ,. , . ,. ,, .,. . , .., .,  +",
                    " |#0000000000000000000000#. ,, ., . , ., , . . ,. , . , ,. ,. , .,. , .,.,. ,. .x     x , ,. . , ., . . ,. , . ,,. , ., . . , .|",
                    " +#00000000000000000###### . ., ., ., ., . ,. .  , ,. , ., , ., . ,,  , . ,., ####   #### ., , ., ., .,. ,. , ,  ., . ,.  , . ,+",
                    " |#00000000000000000#,. ., . , . , , ., . ,. , . ., , .,., .,. , . , ., . , ..#000000000# ., ., . , . ., . ,. , ., . . , ., ., |",
                    " +#00000000000000000#. , ., ., ., , . ,. .  ,.., ., . ,. ,., ., . ., .,  ,. . #000000000#. ,.  ., ,. .,. ,. . , ,. , . ,.  . ,.+",
                    " |#00000000000000000# ., ,. .,  . ,. ., ., ., ., ., .,., ., . , .. ############000000000############., , ., ., ,. ,. ., .  . ,.|",
                    " +################### ., ., , ., . ,. ,.  ,. ., ,. ,. ., . ,. , ., #0000000000000000000000000000000# ., ,. .,. ,  ,. , .,  ., ,+",
                    " |., ,. ., ,. . , ., ., . ,. , ., , .,.. ,. ., ., ., . ,. , ., ., .#0000000000000000000000000000000#. , ., . .,  .,.  ., .,  .,|",
                    " + . , . , . , ,. , . ,. , ., ., ., ., ., .,. ,. ,, ., ,. ., ,. .,.#0000000000000000000000000000000# .,. ,,. , . , . ,. ., .. .+",
                    " |. , ., ., ., ,.. ,. ,., . ,. . , ,. ,. , ,. , ., . ,. . , ., ., .#0000000000000000000000000000000#. ,. ,., ., . ,. , ., ., . |",
                    " + ., .,., . ,. ,. ,. , ,. ,. . ,. , . , , ., . , ,.., ,. . ,. .,. #0000000000000000000000000000000#. , ., . , . ,., .. , .,  .+",
                    " |., ., ., , .,., . ,.., ., , . , ., .,. ,. ,. ., . , , . ,. ,. , .#################################. , ., ., ,. , ., . ., ., .|", 
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
                };

                memcpy(map, CabbageCampo1Village, 200*200*sizeof(char));

            }
            break;
        case Cabbage_Campo1_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char CabbageCampo1Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |********************************########################################*|                                                    ",
                    " +**########################******#                                      #*+                                                    ",
                    " |**#                      #******#                                      #*|                                                    ",
                    " +**#                      #******####################                   #*+                                                    ",
                    " |**#                      #*************************#                   #*|                                                    ",
                    " +**#                      ######################****#                   #*+                                                    ",
                    " |**#                      #                    #****########### #########*|                                                    ",
                    " +**#                      #                    #**************# #*********+                                                    ",
                    " |**#                                           #**************# #*********|                                                    ",
                    " +**#                      #                    ################ #######***+                                                    ",
                    " |**########### ############                    #                      #***|                                                    ",
                    " +************# #**********#                    #                      #***+                                                    ",
                    " |************# #**********#                                           #***|                                                    ",
                    " +************# #**********#                    #                      #***+                                                    ",
                    " |**########### ########***#                    #                      #***|                                                    ",
                    " +**#                  #***######################                      #***+                                                    ",
                    " |**#                  #************************#                      #***|                                                    ",
                    " +**#                  #************************#                      #***+                                                    ",
                    " |**#                  #************************################## #####***|                                                    ",
                    " +**#  s               #*****************************************# #*******+                                                    ",
                    " |**#                  #**************************************#### ####****|                                                    ",
                    " +**####################**************************************#   s   #****+                                                    ",
                    " |************************************************************#########****|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CabbageCampo1Dungeon, 200*200*sizeof(char));

            }
            break;
        case Cabbage_Campo2:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 101;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 42;

                char CabbageCampo2[200][200] = 
                {
                    "                                                                                                                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |MMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~|                                                    ",
                    " +MMMHHHttttHHHHHHHHHHHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~+                                                    ", 
                    " |HHH, tttttt,. , . .. ., . ttttttttttt ., ., ., , . ,,.  HHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMM~~~|                                                    ",
                    " +HH,.tttttttt ,. .., ., .,ttttttttttttt. , ., . , ., ., ,. ,. ,HHHHHHHHHHMMMMMMMMMMMMMMMMMMM~~+                                                    ",
                    " |,. .tttttttt., . ,. ,. ,.ttttttttttttt,, .ttttttt, ., , . .,  ., .HHHHHHHHHHHHHHHMMMMMMMMMMM~|                                                    ",
                    " +. ,.  ttttt,. , ., . , ., ttttttttttt . ,ttttttttt. , ., ., ., . ,. .HHHHHHHHHHHHHHHMMMMMM~~~+                                                    ", 
                    " |,. ., , t,. .. , ,. ., ., .tttttttt. , ttttttttttttt. , ., ., . , ., ., .HHHHHHHHHHHHHMMMMMM~|                                                    ",
                    " +., . . , .., ., .,., . ,.  ,.tttt . . ,ttttttttttttt , .,. ., ., ., ,. .,.,HHHHHHHHHHHHMMMMM~+                                                    ",
                    " |,. .,. ,. ,. tttttt., ., ,, . ,. ,. , . ttttttttttt, . . , . ,. , ., . HHHHHHHHHHHHHHHHHMMM~~|                                                    ",
                    " +. ., ., ., tttttttttt ., ., ., ,. ,. ,. . ttttttt. , ., . ,.  ., , , ., .HHHHHHHHHHHHHHHHMM~~+                                                    ",
                    " |,. . ,., ttttttttttttt . ., . ,. , . , ., . ,. , .. , .., . ,. ., ., ., ., .HHHHHHHHHHHHHHMM~|                                                    ",
                    " +,. ., ,.ttttttttttttttt. ,., ., ttt, , ,. ., .,,. ., ., .,,. ,. ,., ., .,,. . ,HHHHHHHHHHHMM~+                                                    ",
                    " |., . ,. ttttttttttttttt ,.. , .ttttt. ,. , ., . ,. ,.  ., . ,.ttt , . ,. ,. ,HHHHHHHHHHHHHHM~|                                                    ",
                    " +, ., ., ,tttttttttttt,. , .., . ttt, ., ., .,  tttt,. , .,   ttttt.. . .. HHHHHHHHHHHHHHHHHHM+                                                    ",
                    " |., ., ., ,tttttttttt ., . ., . , ., ., ., . , tttttt . ,. ,tttttttt., . , ,. ,. ,.HHHHHHHHHHM|                                                    ",
                    " +,. .  ,. . .ttttt., . ,. , ., . ,. ,. , . ,. ,.tttt. ,  , ttttttttttt  ., . ,. HHHHHHHHHHHHHH+                                                    ",
                    " |. ,. .,, . , , , ., ., ., . ,. ttt , . ,.  ., . tt  ,. , .ttttttttttttt , ., ., . ,. HHHHHHHH|                                                    ",
                    " +. , .., ., ., . , ., ., .  , .ttttt. , . ., . ,  , .,. , . tttttttttt, .,. ,. ., .HHHHHHHHHHH+                                                    ",
                    " |, ., . ,. . ,. ,. ,. , .,. ,.ttttttt . ,. .  . , . ,.  .. ,, ttttttt,. ,.  .HHHHHHHHHHHHHHHHH|                                                    ",
                    " +., .,.ttt ., . , ., ., . ,. ,ttttttt ., . . . , . ., .,   , ., ., . , .,  , ., .HHHHHHHHHHHHM+                                                    ",
                    " |,. .,ttttt ,. , ., ., . , ., .ttttt., .  . ,ttttttttttt, ., . ,. ,. . ,, . ,. ., . ,HHHHHHHHM|                                                    ",
                    " +,. ,. ttt, . ,. ,. ,. , ., ., .ttt., . ,tttttttttttttttttttt  ., .  ,. , ., . ,. HHHHHHHHHHHM+                                                    ",
                    " |., ., .,. ,. ,. , . ,. ,. , . , . ., tttttt.   .  .   , ttttttt ,. ,. ,. , . HHHHHHHHHHHHHHHM|                                                    ",
                    " +. ., ., ., . ,. . ttttttt,. , ., ttttttt.  , .   ,   .   ,tttttttt.,., ,. .,., ,.HHHHHHHHHHHM+                                                    ",
                    " |., ., .,. , . ,. ttttttttt., . ,tttttt      .### ### .     . ttttttt.  ., . . ., ,HHHHHHHHHM~|                                                    ",
                    " +., . ,. . , . ,.ttttttttttt, ttttttt   .  ,  #     #,     ,   ,tttttt , ., .HHHHHHHHHHHHHMM~~+                                                    ",
                    " |H., . ,., . , .,tttttttttt ttttttt.     ######     ###### .  .,  .tttttHHHHHHHHHHHHHHHHMMM~~~|                                                    ",
                    " +HH, tttt , .,. , tttttttt ttttttt .    ,#               #     ,  ,   tttttHHHHHHHHHHHMMMMMM~~+                                                    ",
                    " |MHHHtttttt. ,. ,. tttttt,ttttttt   ,  . #       X       #    ,   , .HHHHHHHHHHHHHHHHMMMMMMMM~|                                                    ",
                    " +~MMHHHttttt,.  ., ,. . .,ttttttt,       #               #,     , HHHHHHHHHHHHHHHHHMMMMMMMMMM~+                                                    ",
                    " |~~MMMMHtttt ,. , ., ., . ttttttt.  ,   .#               # ,  ,    . ,  HHHHHHHHHHMMMMMMMMM~~~|                                                    ",
                    " +~~~MMMMHHt ,. , . ,. , .ttttttt,    .  .#################     . ,. , HHHHHHHHHHHMMMMMMMMMMM~~+                                                    ",
                    " |~~~~MMMMMHH., . , .,. ,.ttttttt,        ,      .   ,     ,  .. .HHHHHHHHHHHHHMMMMMMMMMMMMMMM~|                                                    ",
                    " +~~~~~~~MMMHHH. ,. , ., .ttttttt, .  .      .  , .       ,. , HHHHHHHHHHHHHHMMMMMMMMMMMMMMM~~~+                                                    ",
                    " |~~~~~~~~~~MMHHHH.,. ,. ,ttttttt ., .   ,  . . ,   .  .HHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMM~~|                                                    ",
                    " +~~~~~~~~~~~~MMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMM~~~~+                                                    ",   
                    " |~~~~~~~~~~~~~~~MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    " 
                };

                memcpy(map, CabbageCampo2, 200*200*sizeof(char));

            }
            break;
        case Cabbage_Campo2_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char CabbageCampo2Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |**#######################************************************************|                                                    ",
                    " +**#                     #*********####################################***+                                                    ",
                    " |**#                     ######****#                                  #***|                                                    ",
                    " +**#                          #****#                                  #***+                                                    ",
                    " |**#                     #### #****#                                  #***|                                                    ",
                    " +**##### #################**# #****#                                  #***+                                                    ",
                    " |******# #******************# #****#                                  #***|                                                    ",
                    " +******# #################**# #****#                                  #***+                                                    ",
                    " |******#                 #**# ######                                  #***|                                                    ",
                    " +******################# #**#                                         #***+                                                    ",
                    " |**********************# #**########                                  #***|                                                    ",
                    " +**###################*# #*********#                                  #***+                                                    ",
                    " |**#                 #*# #*********#                                  #***|                                                    ",
                    " +**#                 ### #*********########################## #########***+                                                    ",
                    " |**#                     #**********************************# #***********|                                                    ",
                    " +**#                 #####***#####################**********# #***********+                                                    ",
                    " |**#                 #*******#                   #**********# #***********|                                                    ",
                    " +**#                 #****####                   ############ ###########*+                                                    ",
                    " |**#                 #****#                                             #*|                                                    ",
                    " +**#  s              #****#                                             #*+                                                    ",
                    " |**#                 #****#                                             #*|                                                    ",
                    " +**###################****#                                             #*+                                                    ",
                    " |*************************###############################################*|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CabbageCampo2Dungeon, 200*200*sizeof(char));

            }
            break;
        case Carrot_Canyon1:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 101;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 42;

                char CarrotCanyon1[200][200] = 
                {
                    "                                                                                                                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ",     
                    " +MMMMMMMMMMMMMMMMM, .. ,MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH+                                                    ",
                    " |MMMMMMMMMMMMMM.. ,., ., , . .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHH|                                                    ",
                    " +MMMMMMMMMMMM, .,.MMMMMMMMM.  . .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHH+                                                    ",
                    " |MMMMMMMMMMM. ,.,MMMMMMMMMMMMMM,  ., ,HHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHH|                                                    ",
                    " +MMMMMMMMMM### ###MMMMMMMMMMMMMMHHHH, ., ,HHHHHHHHHHMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHH+                                                    ",
                    " |MMMMMMMMMM#     #MMMMMMMMMMMMMMMMMMHHHHH. ,. . .,,HHHMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHH|                                                    ", 
                    " +MMMMM######     ######MMMMMMMMMMMMMMMMMMHHHH. ,. .,,HHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH+                                                    ",    
                    " |MMMMM#               #MMMMMMMMMMMMMMMMMMMMMHHHH. ,, ..HHHMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|                                                    ", 
                    " +MMMMM#       X       #MMMMMMMMMMMMMMMMMMMMMMMMHHHH, ., ,HHMMHHHHHHHHHHHHHHHHHHHHHHHHH. ., ., +                                                    ", 
                    " |MMMMM#               #MMMMMMMMMMMMMMMMMMMMMMMMMMMMHHH. ,..HHHHHHHHHHHHHHHH,,. . , ., ., ., .,|                                                    ", 
                    " +MMMMM#               #MMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHH, . ,HHHHH. ttttt ., ,. ., ., ., ,. .,+                                                    ", 
                    " |MMMMM#################MMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHH, ., , . ,ttttttt., ., ,. ., ., ,. ,.|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHH.. , ., .,ttttttt, ., . , .,., ., ,. +                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH,,. . , . ,..ttttt,. ., ,. ,. ,. . ,. ,|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH. ,. ., ., ., ., , .,., ., ,. .,  ., ., .+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH. ttttt ., ,.,. .,., ., ,. ., . ,ttttt. ., ,.|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHH, .,ttttttt ,. ., .,,. ., ,. ., ., ttttttt,, . .+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHH. ., .,ttttttt.,., ., ., ., . , , . , ttttttt., ..,|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHH, ,. ., ., ttttt. ,.,  .,., ., ., ,. ., .,ttttt. ..HHH+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHH, ., ., ., .,., .,  ., ., . ., ., ., ., ,. ,. ,. ,.,HHHHM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH., . ,. , .,. , . , .. , ., ., ,. .,. ,. , ., ., ,..,HHHHHMM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH., ttttt , ., ,, . , ., ,. .,.,. , .,. , ., .,.,  .,.HHHHHMMMM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMHHHHHHHHHH,  ttttttt, , . ,. .,, ., ., ttttt,. ,. , ., ., . ,HHHHHHHMMMMM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMHHHHHHHHHHHH.., ttttttt , ,. . , ,., . ,.ttttttt,., ., ., ..HHHHHHHHMMMMMMMM|                                                    ", 
                    " +MMMMMMMMMMMMMMHHHHHHHHHHHHHHH, ., ttttt., ., ,. ., ., ., ,ttttttt .,,  ..HHHHHHHHHHHMMMMMMMMM+                                                    ", 
                    " |MMMMMMMMMMHHHHHHHHHHHHHHHHHHH ,., ., ., . , , ., ,. ,. ., .ttttt,.HHHHHHHHHHHHHHHHMMMMMMMMMMM|                                                    ", 
                    " +MMMMMMMMHHHHHHHHHHHHHHHHHHHHH.., , ., .,., ,. . ,. ,, ., ,HHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMM+                                                    ", 
                    " |MMMMMMMHHHHHHHHHHHHHHHHHHHH,., ,. ., ., ,. , ., ., .HHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMM|                                                    ", 
                    " +MMMMMMHHHHHHHHHHHHHHHHHH.., ., .,. , . ., . ,,HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMM+                                                    ", 
                    " |MMMMMHHHHHHHHHHHHHHHHH,.,  ,.. , .. , ..HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +MMMMMHHHHHHHHHHHHH. ., ,. ,.,. . ,. ,HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMM+                                                    ", 
                    " |MMMMHHHHHHHHHHH,., ., ,. .,.,  .,.HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +MMMHHHHHHHHHH. ., ., . , . ,. ..HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+                                                    ", 
                    " |MMMHHHHHHHHHH., ., ., ., ,.. .HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +MMHHHHHHHHHHH, .,. ,. ,. , .HHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+                                                    ", 
                    " |MHHHHHHHHHH. , ., , .,  .,,HHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +HHHHHHHHHH. .,, .  , ., .,HHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+                                                    ", 
                    " |HHHHHHHH, ,. .,, ., ,. .,HHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CarrotCanyon1, 200*200*sizeof(char));

            }
            break;
        case Carrot_Canyon1_Village:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 131;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 52;

                char CarrotCanyon1Village[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
                    " |., ., . ,. , ., ., ., . , ., .,. ,. , ., ., . ., ., . ,., . , ., ., ., ., . ,. , ., ., ., ., ., . , ., ., . ., . ,. ,. , ., .|",
                    " +. ,., . ,. , ., ., ., ., ,. ., . . , ., ., . , ., ., .,., ., ,. ., ., .,. ,. , ., ., ., ., ., ., . ,. , ., ., ., . ,. ., . . +",
                    " |., ., ., ., , .. , ., ,..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ., ., ., . , ., ., . , .|",
                    " +. , ,. .,. , ., ., . , .,x                                                                         x., , ., ., ., ., . ,, .  +",
                    " |., ., ., ,. ., . , ,. ., x                                                                         x. ,,. . , . , ., ., . ,. |",
                    " +. ,. ,, . , ., ., . ,. .,x                                                                         x ., ,. ,. . ,. , ., ,. .,+",
                    " |., ., ,. . ,, .. , ., . ,x         xxxxxxxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxxxxxxxxxxxx         x. ,,. . , . ,. ., ,. ,.. |",
                    " +, . , ., . , ,. , ., ., ,x         x., ,. . ,. , ., , . , .x     x,. ., ,. ., ., . . , .,x         x ., ., ., ,. ., . , .,  .+",
                    " |., ,. . ,,.  ., ., ,. ., x         x., ., ,. . , ,. ,. .,. x     x., ,. ,. ,. ,. .,  . ,.x         x., ., ., ., ,. ., . , ., |",
                    " +., ,. ., . , . ,. , .,. ,x         x., ,. ., ,. ., ., ,. ,.x     x., ., ., ., . ,. ., . ,x         x., , ., ,. ., ., ., ., . +",
                    " |., ., . ,. ,, ., . , ., .x         x., ., ., ., ., ,. ., ..x     x. , ., ., ., ,  ., .,.,x         x. ,., ,. ., ,. ., ,. ,. .|",
                    " +. ,. , ., ., ., ., . , .,x         x., ,. ., ,. ,. , .,.  .x     x,.., ,. ,. ,. ,. .,  .,x         x., . ,,. ., ., ,. ., .,. +",
                    " |. ,. ,. ,. , ., ,. ., ,. x         x., ., .,  ,. ., . . , .x     x., ., ,. ,. ,. ,. .,  .x         x. ,. ,,. ., . , ., ., .,.|",
                    " +., . ,,. ., ,. . ,. , ., x         x., ., ., ., ., ,. ,. .,x     x., ,. ., ., ,. ., ,.. ,x         x., ., . ,. ,. , ., ,. ,. +", 
                    " |., . , ., . , ., .,,.  .,x         x. ,,.  , . ,. .,,. ,., x     x,. ., ., ,. ,. ., ,.  ,x         x., ,. ., ., ., ., ,. ., .|",
                    " +., ., ., . , ., ., ., . ,x         x,. ,. ,. ., ,. ,. ., . x     x., ,. ,. ., ,. ,. .,  .x         x. , ., . , ., ., ,.. , .,+",
                    " |., . ,. , ., ., ., ,. ,. x         x., ,. ,. ,.  ,. ,. ,.. x     x., , ., ,. ., . , .,,..x         x., ,. . ,. , ,. ., ,. .,.|",
                    " +., . ,. ,., . ,. , ., ,..x         x., ., ,. ,. ., ,. ######## ########., ,. ., , . ,. . x         x., , ., , ., . , . ,. , ,+",
                    " |., . , ,. , ., ,. , ., . x         x,. ,. ., ., . ., ,#000000000000000#., ,. . , ., .,.. x         x., , ., ., ., ., . , ,.. |",
                    " +. ,. ,., . ,. , ., , . ,.x         x., ,. , , ., ,. .,#000000000000000#., ., , . , ., . ,x         x., ., ., ., ,. .,, . ,,. +",
                    " |., ., ., . , ., ,. , ., .x         x., ,. . , ., ,. .,#000000000000000#., ,. . , .  ,.  .x         x., ., ., ., . , ., ., .,.|",
                    " +., ., , . , ., .,.  ., .,x         x., ,. . , .,.######000000000000000######., , . ,. , ,x         x., .,., .,. , ., ., ., .,+",
                    " |., ., ., . ,. , . ,. , ..x         x., ,. ., ,. .#0000000000000000000000000#. , ., ,. ., x         x ., ., ., ., ., . . ,. . |",
                    " +xxxxxxxxxxxxxxxxxxxxxxxxxx         x., ., ,. . , #0000000000000000000000000#., ., , . ,. x         xxxxxxxxxxxxxxxxxxxxxxxxxx+",
                    " |                                   x., ,. ,. ., .#0000000000000000000000000#. ,. ,. ., . x                                   |",
                    " +                                   x .,. , ,.. .,#0000000000000000000000000#., ., ,. ., .x                                   +",
                    " |                                   x. ,,. ,. . . #0000000000000000000000000#., ., .,  .,.x                                   |",
                    " +xxxxxxxxxxxxxxxxxxxxxxxxxx         x., ,. ., .,  #0000000000000000000000000#., ., ., . ,.x         xxxxxxxxxxxxxxxxxxxxxxxxxx+",
                    " |., ,. , . ,, . , ,.. , .,x         x. , .,. . ,,.#0000000000000000000000000#,. ,. ., . ,.x         x. , ., ,. ., ., ., ., ,..|",
                    " +. , .,,. . ,, . ,. ,. ,.,x         x. ,,.  ., ,. ###########################. ,,. ., ,. .x         x. , ,.. , ,. ., , .,  ., +",
                    " | ., ., ., ., . ,. ,. , ..x         x., ,. . ,, . , ., .,  ., ., ,. ,. ,. ,. ,. ,. ,. ,. .x         x ., ,. ., , ,. ,. ., ,.. |",
                    " + ., ., , . , . ,. , ., .,x         x., ,. ., ., ,. , .  ,., . ., ,. ., ., ,. ,. ,. ,. ,. x         x ,.,  ,. ,. ,. ,. ,. .,. +",
                    " |., ., ,. . ,. , ., . ,. ,x         x. ,,.  ., , ., . ,. ., .,  ., ,. ., ,. ., ,. ., . , .x         x. , , ,. ,.., , ., ., ,..|",
                    " +., ., ., ., ,. . , ., , .x         x., ,. . ,. ., ., . , . , .,.  , ., ., .,., .,. ,.,  .x         x ,. ., ,. ., ., ., ., ,. +",
                    " |,. , ., ,. ., ., ., , .. x         x .,., . , ., ., ., , . , ., , . ,,. ,  ,.. , .,, .. ,x         x., , . , ., ,. ,. ,. ,. ,|",
                    " +., ., . ,. , ., ., ., ,. x         x., ,. ., ., . ., ., ., . ,, . ,,. ., . , . ,. ,. ,. .x         x,. .,,. ,. ,. ., ., ., . +",
                    " |., ., . ,. , ., ,. ., .,.x         x. ,,  .,,. ., ,. .,, ., ,. ., ., ,. ., , .., ., . ,. x         x., ,. , ,. ., , .,., ., ,|",
                    " +., , . ,. , ., ., ,. ., .x         x., , . , ., ,. ,. ., ,.., , .,  ,.,  ,.,. ,. ,. ., . x         x ,.,. . , ., ,. ., . , .,+",
                    " |. ,.,  ., ., ., ., ., ., x         x., ,. . , , .,,. ., ,.., ., ., ., ., ., ., ., ., ,. ,x         x., ,. . , ., , .,  , ,. ,|",
                    " +. ,. , ., ., ., ., . , . x         x ., ., ,. ., ., ., ., .,. , .,. ., ., ., . ,., , .., x         x,. ,. ,. ., ,. ., , ., , +",
                    " |., ,. ,. ,. . . , ., ... x         x. ,., ., ., ., . , ., ., ., ., ., ., ., ., ,. ., ., .x         x., ,. ,. ,. ,. ,. ,. ,. ,|",
                    " +., ,. ., ., ., . , ., ., x         x,. ., ,. ,. ,. ,. ., ,., . , . ,.. , ,.. , ,.. , ., .x         x,. . ., . , ., , ., ,. . +",
                    " |., ., , ., , . , ,. .,. ,x         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         x, . , . , ,.  ,., . ., . |",
                    " +., , . , ., ,. ,. ,. ., ,x                                                                         x., ,. ., ,. , . ,. . ,. .+",
                    " |., ,. , . , ., ,. ,. ,. ,x                                                                         x., ,. ., ,. . , ., ., ,. |",
                    " +., ,.  ., ., ., ., ., ., x                                                                         x, ., ., ., ., ., ., ,. ,.+",
                    " |., ., ., . , ., ., ., . ,xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ., ., ,. ,. ,. ., ,. ,. |",
                    " + ., ,. ., ,. ., ., ,. ,. ,. ., ,. ,. ,. ., . , . , ., ., .,., ., ., ., ,. ., ,. ., ., ., . ,. ., ,. ., ,. ,. , ,.. , ,.. ,,. +",
                    " |. ., ., .. , . ,. ., ,. ,. ,. ., ., , ., , ,. ,. ,.  ., ., . , , ., ., ., . ,., . ,.,  ., . ., ., ,. ,. ,. ,. ., . ,. ,. ,, .|", 
                };

                memcpy(map, CarrotCanyon1Village, 200*200*sizeof(char));

            }
            break;
        case Carrot_Canyon1_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char CarrotCanyon1Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*#######################################################################*+                                                    ",
                    " |*##                        ##   ##  T T T         ##        ##        ##*|                                                    ",
                    " +*##   ##################   ##   ##         ##     ##   ##   ##   ##   ##*+                                                    ",
                    " |*##   ##              ##        ##  ##     ##     ##   ##   ##   ##   ##*|                                                    ",
                    " +*##   ##              ##   ##       ##     ##     ##   ##   ##   ##   ##*+                                                    ",
                    " |*##   ##                   ##   ####################   ##   ##   ##   ##*|                                                    ",
                    " +*##           #######      ##       ##     ##     ##   ##   ##   ##   ##*+                                                    ",
                    " |*##   ##########   ##      ##       ##     ##     ##   ##   ##   ##   ##*|                                                    ",
                    " +*##   ##           ##############   ##     ##     ##   ##   ##   ##   ##*+                                                    ",
                    " |*##   ##                       ##   ##     ##     ##   ##        ##   ##*|                                                    ",
                    " +*##   ##              ######   ##                      ############   ##*+                                                    ",
                    " |*##   ##         ##            ##############  #########       ####   ##*|                                                    ",
                    " +*##   ##         ## s          ##                              ####   ##*+                                                    ", 
                    " |*##   ##         ##            ##############  #########       ####   ##*|                                                    ",
                    " +*## T ##         ###########   ##                     #############   ##*+                                                    ",
                    " |*###########     ##                ##          ##     ##              ##*|                                                    ",
                    " +*##       ###########################          ##     ##              ##*+                                                    ",
                    " |*##      ##    ##                      ########################//#######*|                                                    ",
                    " +*##  s   ##    #########################  ##            ##            ##*+                                                    ",
                    " |*##                                              ##            ##     ##*|                                                    ",
                    " +*#######################################################################*+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CarrotCanyon1Dungeon, 200*200*sizeof(char));

            }
            break;
        case Carrot_Canyon2:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 101;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 42;

                char CarrotCanyon2[200][200] = 
                {
                    "                                                                                                                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~|                                                    ",     
                    " +HHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~~+                                                    ",
                    " |HHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~|                                                    ",
                    " +HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~+                                                    ",
                    " |HHHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~#########|                                                    ",
                    " +HHHHHHHHHHHtttttttHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMM ., ,. ., ,. ####wwwwwwww+                                                    ",
                    " |HHHHHHHHHHHtttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMM. ,. , . . , ,.     wwwwwwww|                                                    ", 
                    " +HHHHHHHHHHHHtttttHHHHHHHHHHHHHHHtttttHHHHHHHHHHHHMMMMMMMMMMMMMM., ,.  ,. ., ,. ,.####wwwwwwww+                                                    ",    
                    " |t t t t t t t t  t t t tHHHHHHHtttttttHHHHHHHHHHHHHHMMMMMMMMMM., ,.  . ,. .,.MMMMMM~#########|                                                    ", 
                    " +.. . , ., ,. .,. .,., ,.ttttHHHtttttttHHHHHHHHHHHHHHHHHHMMttttttt., . . , .MMMMM~~~~~~~~~~~~~+                                                    ", 
                    " |. ,. , ,.  ., ., ., ., ., .,tttttttttHHHHHHHHHHHHHHHHHHHHttttttttt., ., ,.MMMM~~~~~~~~~~~~~~~|                                                    ", 
                    " +. ,., ., . ,. ., . ,. ., ., .,.,ttt t t  t t t t t t t t ttttttttt ,. .,MMM~~~~~~~~~~~~~~~~~~+                                                    ", 
                    " |., ,. ., ,. ,. . , .,,. ., ,. ., ,., .,. ,. ,., ., ., .,,.tttttttHHMMMMMMMMMMM~~~~~~~~~~~~~~~|                                                    ", 
                    " +., ., ,. ., ., ,. . ,., . ,., . , ., ., . ,. , ., . , ., , .tHHHHHHHHHMMMMMMMMMMMMM~~~~~~~~~~+                                                    ", 
                    " |. ,., ,. ,. ., ., ., ., . . , ., . , ., ,. ., ., . , ., ,. . .tHHHHHHHHHMMMMMMMMMMMMMMMMM~~~~|                                                    ", 
                    " +., ., ., ,. ., .  .,. ,. , ., ., . .,. ., ,. , ., ,.,. . ., ,tHHHHHHHHHHHHHMMMMMMMMMMMMMMMM~~+                                                    ", 
                    " |., ., . , . ., , ., . , ,.. , .,t t t t t t t  t t t tt t,. ,.,tHHHHHHHHHHHHHMMMMMMMMMMMMMMM~|                                                    ", 
                    " + ,. , ., ., ,.  ., ., ,. ,..tttttHHHHHHHHHHHHHHHHHtttttHtt.,  ,tHHHHHHHHHHHHHHHMMMMMMMMMMMMMM+                                                    ", 
                    " |, ,. ., ,., ,.,. , . . ,ttttttHHHHHHHHHHHHHHHHHHHtttttttHt, ., .,tHHHHHHHHHHHHHHHMMMMMMMMMMMM|                                                    ", 
                    " +t t t t t  t t t t t t tHHHHHHHHHHHHHHHHHHHHHHHHHtttttttHHt., . .tHHHHHHHHHHHtttttMMMMMMMMMMM+                                                    ", 
                    " |HHHHHHHtttttHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHHtttttHHHt. ., ..ttttttHHHHtttttttHMMMMMMMMM|                                                    ", 
                    " +HMHHHHtttttttHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHt., ., .  .,,tttHtttttttHHMMMMMMMM+                                                    ", 
                    " |HHMHHHtttttttHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHt, ., .,, . ,. .,ttttttHHHHHMMMMMM|                                                    ", 
                    " +HHMMHHHtttttHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHtt.., . ,. . , .,.tHHHHHHHHHMMMMM+                                                    ", 
                    " |HHHMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMHHHMttttttt, ., , ., .,.,tHHHHHHMMMM|                                                    ", 
                    " +HHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMHtttttHHMMMtttttt.., ,, . .ttHHHHMMM+                                                    ", 
                    " |MHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHtttttttHMMMMMMMMMMMMM### ###HHHHHHMM|                                                    ", 
                    " +MMHHHHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHtttttttHMMMMMMMMMMMMM#     #HHHHHHHM+                                                    ", 
                    " |MMMMMHHHHHHHHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMHtttttHMMMMMMMMM######     ######HHM|                                                    ", 
                    " +MMMMMMMMHHHHHHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHHHHHMMMMMMMMMM#               #HHM+                                                    ", 
                    " |MMMMMMMMMMMMHHHHHHHHHHMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH#       X       #HHM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMHHHHHHHMMMMMMMMMMHHHHHHHHHHHHHHHMMMMMHHHHHHHHHHHHHHHHHHHH#               #HHM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH#               #HMM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHH#################MMM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHMMMM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHMMMMMMM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+                                                    ", 
                    " |MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|                                                    ", 
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CarrotCanyon2, 200*200*sizeof(char));
                
            }
            break;
        case Carrot_Canyon2_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char CarrotCanyon2Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +**#####################################################################**+                                                    ",
                    " |**##                                                                 ##**|                                                    ",
                    " +**##  s                                                           T  ##**+                                                    ",
                    " |**##                                                                 ##**|                                                    ",
                    " +**#####################################################################**+                                                    ", 
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, CarrotCanyon2Dungeon, 200*200*sizeof(char));

            }
            break;
        case Soup_Sea1:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 101;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 42;

                char SoupSea1[200][200] = 
                {
                    "                                                                                                                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +####################~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |wwwwwwwwwwwwwwwwwww#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +wwwwwwwwwwwwwwwwwww#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |wwwwwwwwwwwwwwwwwww#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +####################~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMM   MMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMM   MMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMM   MMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMM ., ,. ,. ., .MMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMM ., ,. ,. ,. ,. ,. MMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMM,. .,  ..,### ### ,. ,. ,. MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM. , ., ,. ,.#     #,. .,. , . MMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMM. , .,######     ######., ,. MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMM. , . #               #,. ,.MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM ,.. .#       X       #., . MMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMM. , .,#               #., . ,MMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMM. , . #               #., ,.MMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM. , #################. ,MMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMM,. ,  . ,  ., ., MMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMM,  ., ., MMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                                                    ",
                    " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                                                    ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, SoupSea1, 200*200*sizeof(char));

            }
            break;
        case Soup_Sea1_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char SoupSeaDungeon1[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*****#             ######               ###                        #*****+                                                    ",
                    " |*****#  s          ######                                          #*****|                                                    ",
                    " +*****#                                  ###   ######     ###########*****+                                                    ",
                    " |*****#     ########                     ###   ######     ###########*****|                                                    ",
                    " +*****#     ########     ###################   ###                  #*****+                                                    ",
                    " |*****#     ###                          ###   ###                  #*****|                                                    ",
                    " +*****#     ###                          ###   #############        #*****+                                                    ",
                    " |*****#                                  ###   #############        #*****|                                                    ",
                    " +*****#                                  ###   ###                  #*****+                                                    ",
                    " |*****##############     ###################   ###   ###   ##########*****|                                                    ",
                    " +*****##############     ###################   ###   ###   ##########*****+                                                    ",
                    " |*****#                  ###                   ###   ###           ##*****|                                                    ",
                    " +*****#   ##########     ###  s                ###   ###           ##*****+                                                    ",
                    " |*****#   ##########     ###                   ### T ###           ##*****|                                                    ",
                    " +*****#                     #########################################*****+                                                    ",
                    " |*****#   ###    ###        #########################################*****|                                                    ",
                    " +*****#   ###    ###                                             T  #*****+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",   
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, SoupSeaDungeon1, 200*200*sizeof(char));

            }
            break;
        case Soup_Sea2_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char SoupSea2Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*****#     ##      ##       ##                              ##     #*****+                                                    ",
                    " |*****#  2  ##      ##   4   ##     ######                   ##  3  #*****|                                                    ",
                    " +*****#             ##       ##     ######                          #*****+                                                    ",
                    " |*****########      ## ########     ###        ######################*****|                                                    ",
                    " +*****########      ## ########     ###        ######################*****+                                                    ",
                    " |*****#             ##           #########                    ##   ##*****|                                                    ",
                    " +*****#             ##   #########################            ## T ##*****+                                                    ",
                    " |*****#                  ########## 3   ##########            ##   ##*****|                                                    ",
                    " +*****################   ##########     ##########            ##   ##*****+                                                    ",
                    " |*****################   ##########   T ##########     #########   ##*****|                                                    ",
                    " +*****################   #########################     #########   ##*****+                                                    ",
                    " |*****##############             #########                         ##*****|                                                    ",
                    " +*****##############   ###          ###         ########     ########*****+                                                    ",
                    " |*****##############   ###          ###         ########     ########*****|                                                    ",
                    " +*****#          ###   ###       ######            ##               #*****+                                                    ",
                    " |*****#  1  ##   ###   ###       ######            ##        ##  2  #*****|                                                    ",
                    " +*****#     ##         ###                         ##        ##     #*****+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",   
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, SoupSea2Dungeon, 200*200*sizeof(char));

            }
            break;
        case Soup_Sea3_Dungeon:
            {
                if (mapxMax < CamxMax)
                    mapxMax = 200;
                else
                    mapxMax = 77;
                if (mapyMax < CamyMax)
                    mapyMax = 200;
                else
                    mapyMax = 26;

                char SoupSea3Dungeon[200][200] = 
                {
                    "                                                                                                                                ",
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    ",
                    " |*************************************************************************|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*****## s ##             #       #     #           #     #        ##*****+                                                    ",
                    " |*****##   ##  ######  #  ######  #  #  #  #  ####  #  #  #   ##   ##*****|                                                    ",
                    " +*****##   ##  #    #  #          #  #  #  #     #  #  #      ##   ##*****+                                                    ",
                    " |*****##   ##  #  # #  ############  #  #  ####  #  ######    ##   ##*****|                                                    ",
                    " +*****##   ##  #  # #                #        #  #            ##   ##*****+                                                    ",
                    " |*****##   ##  #  # ########  #  #####  ####  ##################   ##*****|                                                    ",
                    " +*****##   ##  #  #        #  #      #     #  #    #          ##   ##*****+                                                    ",
                    " |*****##   ##  #  #######  #  #####  ####  #  # #  #  ######  ##   ##*****|                                                    ",
                    " +*****##   ##     #        #      #     #  #  ###  #  #    #  ##   ##*****+                                                    ",
                    " |*****##   ##############  #  ##  ####  #  #       #  #  # #  ##   ##*****|                                                    ",
                    " +*****##   ##          ##  #   #     #  #  #########  #  # #  ##   ##*****+                                                    ",
                    " |*****##   ##          ##  #  #####  #  #             #  # #  ##   ##*****|                                                    ",
                    " +*****##   ##          #####  #####  #  ###############  # #  ##   ##*****+                                                    ",
                    " |*****##   ##          /      #####  #                   #T#  ##   ##*****|                                                    ",
                    " +*****##   #####################################################   ##*****+                                                    ",
                    " |*****##                                                           ##*****|                                                    ",
                    " +*****###############################################################*****+                                                    ",
                    " |*****###############################################################*****|                                                    ",
                    " +*************************************************************************+                                                    ",
                    " |*************************************************************************|                                                    ",                                                       
                    " +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                                                    "
                };

                memcpy(map, SoupSea3Dungeon, 200*200*sizeof(char));

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
                                tiles[j][i].set_teleport_startY(33);
                                tiles[j][i].set_teleport_startX(123);
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
