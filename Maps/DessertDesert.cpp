#include <iostream>


#include <stdlib.h>
#include <string.h>
#include "ColorLib.h"


using namespace std;

#define  ROWS 50 
#define  COLUMNS 168


//#define StartingX 1
//#define StartingY 1


char MAP[][COLUMNS] =	
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
	"|  #       t                             #lcccKcccccccccccccccl#       #                    #                                                               #     |",
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
	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

//--------------------------------------------------------------------
void printMap()
{
	// we want to redraw the map so move the cursor back so we print in the same place
	//PositionCursor(0,0);

	//cout << ChangeToBlue() ;
	for(int rows=0;rows <= ROWS  ;rows++)
	{
		for (int columns=0;columns < COLUMNS;columns++)
		{   if( MAP[rows][columns] == 'c' )
            {
                cout << ChangeToMagenta();
            }
            else if( MAP[rows][columns] == '+' || MAP[rows][columns] == '-' || MAP[rows][columns] == '|' || MAP[rows][columns] == '/')
            {
                cout << ChangeToBlue();
            }
            else if( MAP[rows][columns] == '#' || MAP[rows][columns] == '^')
            {
                cout << ChangeToWhite();
            }
            else if( MAP[rows][columns] == 'K')
            {
                cout << ChangeToLightPurple();
            }
            else if( MAP[rows][columns] == 'r' || MAP[rows][columns] == 'v')
            {
                cout << ChangeToYellow();
            }
            else if( MAP[rows][columns] == '$' || MAP[rows][columns] == '~')
            {
                cout << ChangeToRed();
            }
            else if( MAP[rows][columns] == 'l' || MAP[rows][columns] == 'C')
            {
                cout << ChangeToGreen();
            }

            else if( MAP[rows][columns] == 't')
            {
                cout << ChangeToIdk();
            }


            //PositionCursor(rows,columns);
            cout <<  MAP[rows][columns];
        }
        cout <<"\n";
    }
}
//---------------------------------------------------------------------

int main()
{

    system("clear");
    printMap();


    return 0;
}




