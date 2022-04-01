#ifndef _TERRAIN_H_
#define _TERRAIN_H_

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

        void generatetiles();
        void generatemap();
        void cleanmap();
    private:
        WINDOW * curwin;
        int xMax, yMax;
};

Terrain::Terrain(WINDOW * win)
{
    curwin = win;
    getmaxyx(curwin, yMax, xMax);
    //keypad(curwin, true);
    //Tile tilemap[xMax][yMax];
    generatetiles();
}

void Terrain::generatetiles()
{
    //Tile tilemap[xMax][yMax];
/*
    char map[16][49] = {{"   AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"},
                        {"                AAAAAAAAAAAAAAA                 "},
                        {"AAAAAAAAAA    AAAAAAA          AAAAA  A      AAA"},
                        {"AA     AA     AAAAAAAAAA     AAAAA        AA    "},
                        {"                AAAAA  AAA    A   **  * *** **AA"},
                        {"AAAAAAA  AA     AA  A   A     AAAA******* *  ***"},
                        {"AAAA  AAA  AA   AAAAAA   AA  AA      **  *   **A"},
                        {"AAA       ***** ^^ ^^^^ ** ^ *^*^*          AAAA"},
                        {"AA ^^^*^*        ^**^*^            *^*        AA"},
                        {"AAAA                ^^  ^  ^          ** ^   ^ A"},
                        {"AAA             ^^   ^^ ** ^ *^             AAAA"},
                        {"AA ^^            ^**^*^            *^*        AA"},
                        {"AAAA                ^^  ^  ^          ** ^   ^ A"},
                        {"AAA       *  **         ** ^ *^*^*          AAAA"},
                        {"AA ^  *^*        ^  ^*^            *^*        AA"},
                        {"AAAA                ^^  ^             ** ^   ^ A"}};
*/

    int columns = 163;
    int rows = 51;
    char map[][columns] = 
    {
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
    "|~~~~~~~~~~~~~~~#                                                                                                                                                 |",
    "+~~~~~~~~~~~~~~~#############################################################################################################################################  cc +",
    "|~~~~~~~~~~~~~~~#                                                                                                                                           #  cc |",
    "+~~~~~~~~~~~~~~~#                                                                                                                                           #     +",
    "|~~~~~~~~~~~~~~~#                                                                                                                                           #     |",
    "+~~~~~~~~~~~~~~~###     #######################################################          ####                                                               #     +",
    "|~~~~~~~~~~~~~~~~~#     #llllllllllllllllllllllllllllllllllllllllllllllllllllll          lll#                                                               #     |",
    "+~~~~~~~~~~~~~~~~~#     #lcc        K         cc           KK         cc           cccccc  l#                                                               #     +",
    "|~~~~~~~~~~~~~~~~~#     #llllllllllllllllll   cc           KK          c      K    cKccKc  l#                                                               #     |",
    "+~~################     ##################l          cc                            cccKcc  l#                                                               #     +",
    "|~~#                                     #l          cc         ccc         c              l#                               ^^^   ^^^   ^^^   ^^^           #     |",
    "+~~#                                     #l  K                  cKc         c      K                                        ^^^   ^^^   ^^^   ^^^           #     +",
    "|~~#    CCCCCCCCCC         vvvvvvvvvv    #l              K      ccc    KK  cc                                                                               #     |",
    "+~ #    CCCCCCCCCC         vvvvvvvvvv    #l              K                 ccc         cc  l#                                                               #     +",
    "|~ #    CCCCCCCCCC         vvvvvvvvvv    #lccc       c                K               ccc  l#                                                               #     |",
    "+~ #                                     #lcKc        cc      ccc                     cccc l#                               ^^^   ^^^   ^^^   ^^^           #     +",
    "|~ #    CCCCCCCCCC         vvvvvvvvvv    #lccc        cc      cKc       ccc          ccccc l#                               ^^^   ^^^   ^^^   ^^^           #     |",
    "+~ #    CCCCCCCCCC         vvvvvvvvvv    #l      K            ccc       ccc                l#                                                               #     +",
    "|  #    CCCCCCCCCC         vvvvvvvvvv    #llllllllllllllllllllllllllllllllllllllllllllllllll#                                                               #     |",
    "+  #                                     ####################################################                               ^^^   ^^^   ^^^   ^^^           #     +",
    "|  #                                                                                                                        ^^^   ^^^   ^^^   ^^^           #     |",
    "+  #                                                                                                                                                        #     +",
    "|  #                                                                                                                                                        #     |",
    "+  #                                     #######################       ######################                               ^^^   ^^^   ^^^   ^^^           #     +",
    "|  #                                     #llllccccclllcccccllll#       #                    #                               ^^^   ^^^   ^^^   ^^^           #     |",
    "+  #                                     #llcccKcccccccccccKcll#       #                    #                                                               #     +",
    "|  #                                     #lcccKcccccccccccccccl#       #                    #                                                               #     |",
    "+  #                                     #lccccccccccccKccccccl#       #                    #                               ^^^   ^^^   ^^^   ^^^           #     +",
    "|  #                                     #lcccccccccccccccccccl#       #                    #                               ^^^   ^^^   ^^^   ^^^           #     |",
    "+  #                                     #lcKccccccccccKKcccccl#       #                    #                                                     ################+",
    "|  #                                     #lcccccccccKcccccccccl#       #                    #                                                                     |",
    "+  #                                     #lccccKccccccccccccccl#       #                    #                                                                     +",
    "|  #                                     #llcccccccccccccccccll#       #                    #                                                                     |",
    "+  #                                     #lllccccccccccccKcclll#       #                    #                                                     ################+",
    "|  #                                     #llllccccKccccccccllll#       #                    #                                                               #     |",
    "+  #################     ##########/######lllllllccccccclllllll#       #                    #                                                               #     +",
    "|                  #     #        # #llllll#######################   ###################    #                                                               #     |",
    "+                  #     #        # #lcKccl#             #                  #          #    #                                                               #     +",
    "|                  #     #        # #lKcKcl#                                #  $       #    #                                                               #     |",
    "+                  #     #        # #lKcccl#             ####################          #    #                                                               #     +",
    "|                  #     #        # #llllll#                   #            #          #    #      rrrrrrr                                   rrrrrrrrr      #     |",
    "+#########         #     #        # ########                   #            ######     #    #    rrrrrrrrrrrr                            rrrrrrrrrrrrrrrrr  #     +",
    "|        #         #     #        #                                                    #    ####rrrrrrrrrrrrrrrrrr###################rrrrrrrrrrrrrrrrrrrrr##r     |",
    "+        ###########     #        ##########                   #                       #      rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr    +",
    "|                        #                 #                   #                       #         rrrrrrrrrrrrrrrrrrrrrrr  rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr     |",
    "+        #################                 #                   #                       #       rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr     +",
    "|        #                                 #############################################    rrrrrrr   rrrrrrrrrrrrrrrr  rrrrrrrrrrrrrrrrrrrrrr  rrrrrrrrrrr       |",
    "+#########                                                                                  rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr     +",
    "|                                                                                   rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr|",
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"};
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            tiles[j+1][i+1].set_tilechar(map[i][j]);
            
            //tiles[i][j].xLoc = i;
            //tiles[i][j].yLoc = j;
            //mvwaddch(curwin, j, i, tiles[i][j].get_tilechar());
        }
    }

    for (int i = 1; i < xMax-1; i++)
    {
        for (int j = 1; j < yMax-1; j++)
        {
            tiles[i][j].xLoc = i;
            tiles[i][j].yLoc = j;

            if (tiles[i][j].get_tilechar() == '#')
                tiles[i][j].set_traverse(0);

            mvwaddch(curwin, j, i, tiles[i][j].get_tilechar());
        }
    }
    wrefresh(curwin);

}

#endif