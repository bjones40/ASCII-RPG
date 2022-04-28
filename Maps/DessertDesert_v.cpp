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
	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
	"|                                                                                                                             |",
	"+               #########################################################################################################     +",
	"|               #                                                                                                       #     |",
	"+               #                                                                                                       #     +",
	"|               #                                                                                                       #     |",
	"+               ###     #######################################################          ####                           #     +",
	"|                 #     #llllllllllllllllllllllllllllllllllllllllllllllllllllll          lll#                           #     |",
	"+                 #     #llcKckKccKcc KcccKccKcccKc cKKKcKcc  KKccKccKc KcKcccK cccKccKKccll#                           #     +",
	"|                 #     #lllllllllllllllllllKcKKc KccKccKcKKcKKcK KcccccKccKKcKcKcc KccKccll#                           #     |",
	"+  ################     ##################llcc KcKcccKKcKKc cKcKKckcccKccKccK cccKKccKcKKcll#                           #     +",
	"|  #                                     #llKccKccKcc KccKcKccccKKccKc cKcccKKccKKKKKccK cll#                           #     |",
	"+  #                                     #llcc KccKcKKKcccKcK cKcKccKcKcKKKKccKc KcccKcKcK      ^^^   ^^^   ^^^   ^^^   #     +",
	"|  #    CCCCCCCCCC         VVVVVVVVVV    #llccKccKKcc KcKKKcccccKKccKcK ccKcKKcKcKKcc KKcc      ^^^   ^^^   ^^^   ^^^   #     |",
	"+  #    CCCCCCCCCC         VVVVVVVVVV    #ll ccccKKcccKcccKc cKKccKcKcKKcKKcKcc ccKKKKccKcll#                           #     +",
	"|  #    CCCCCCCCCC         VVVVVVVVVV    #llcccKcKKccKKccK cKKccKKKcKcKc ccKccKccKccKKKcKcll#                           #     |",
	"+  #                                     #llcKcKK cccKccccKK KcKKccccKcKKcccKcc KcKccKKKccll#   ^^^   ^^^   ^^^   ^^^   #     +",
	"|  #    CCCCCCCCCC         VVVVVVVVVV    #llcccccKcccc ccKKccKKcKcc cKcKcKKKcKcKccKcKKKcccll#   ^^^   ^^^   ^^^   ^^^   #     |",
	"+  #    CCCCCCCCCC         VVVVVVVVVV    #llcc KKccKcccKcKcKK ccKcKccccKKKcc KKcKcKKKK cKcll#                           #     +",
	"|  #    CCCCCCCCCC         VVVVVVVVVV    #llllllllllllllllllllllllllllllllllllllllllllllllll#                           #     |",
	"+  #                                     ####################################################   ^^^   ^^^   ^^^   ^^^   #     +",
	"|  #                                                                                            ^^^   ^^^   ^^^   ^^^   #     |",
	"+  #    SSSSSSSSSS         PPPPPPPPPP                                                                                   #     +",
        "|  #    SSSSSSSSSS         PPPPPPPPPP                                                                                   #     |",
	"+  #    SSSSSSSSSS         PPPPPPPPPP    #######################       ######################   ^^^   ^^^   ^^^   ^^^   #     +",
	"|  #                                     #llllccKKclllccKccllll#       #                    #   ^^^   ^^^   ^^^   ^^^   #     |",
	"+  #    SSSSSSSSSS         PPPPPPPPPP    #llcccKccccKcKKcccKcll#       #                    #                           #     +",
	"|  #    SSSSSSSSSS         PPPPPPPPPP    #lcccKccKccccccKKKKccl#       #                    #                           #     |",
	"+  #    SSSSSSSSSS         PPPPPPPPPP    #lcKcccKccKccKccKccccl#       #                    #   ^^^   ^^^   ^^^   ^^^   #     +",
	"|  #                                     #lcKccccKcccKccccKKKcl#       #                    #   ^^^   ^^^   ^^^   ^^^   #     |",
	"+  #                                     #lcKcccccKKcccKKcccccl#       #                    #                           ######+",
	"|  #################     ##########/######lcccccccccKcccccccccl#       #                    #                                 |",
	"+                  #     #        # #lccKKlccccKccccccKKKKccccl#       #                    #                                 +",
	"|                  #     #        # #lcKccllcKcccccKKcccccccKll#       #                    #                                 |",
	"+                  #     #        # #lcccclllcccKcccccKccKcclll#       #                    #                           ######+",
	"|                  #     #        # #lKKcKllllccccKccccccccllll#       #                    #                           #     |",
	"+                  #     #        # #lcKcclllllllcKKcccKlllllll#       #                    #                           #     +",
	"|                  #     #        # #llllll#######################   ###################    #                           #     |",
	"+                  #     #        # #lcKccl#             #                  #          #    #                           #     +",
	"|                  #     #        # #lKcKcl#                                #  $       #    #                           #     |",
	"+                  #     #        # #lKcccl#             ####################          #    #                           #     +",
	"|                  #     #        # #llllll#                   #            #          #    #      rrrrr   rrrrr        #     |",
	"+#########         #     #        # ########                   #            ######     #    #    rrrrrrr  rrrrrrrrrrrr  #     +",
	"|        #         #     #        #                                                    #    ####rrrrrrrr########rrrrrrr##r    |",
	"+        ###########     #        ##########                   #                       #     rrrrrrrrrrrrrrrrrrrrrrrrrrrrr    +",
	"|                        #                 #                   #                       #   rrrrrrrrrrr  rrrrrrrrrrrrrrrrrrrr  |",
	"+        #################                 #                   #                       #    rrrrrrrrrrrr rrrrrrrrrrrrrrrr     +",
	"|        #                                 #############################################  rrr   rrrrrrrrrr  rrrrrrrr  rrrrr   |",
	"+#########                                                                                 rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr   +",
	"|                                                                                   rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr|",
	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
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




