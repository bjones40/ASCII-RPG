/*-----------------------------------
 *  
 * Soup Sea - Dungeon (Floor 3)
 *
 *-----------------------------------
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ColorLib.h"


using namespace std;

#define  ROWS 24
#define  COLUMNS 76


//#define StartingX 1
//#define StartingY 1


char MAP[][COLUMNS] =	
{
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
    "|*************************************************************************|",
    "+*************************************************************************+",
    "|*****###############################################################*****|",
    "+*****## s ##             #       #     #           #     #        ##*****+",
    "|*****##   ##  ######  #  ######  #  #  #  #  ####  #  #  #   ##   ##*****|",
    "+*****##   ##  #    #  #          #  #  #  #     #  #  #      ##   ##*****+",
    "|*****##   ##  #  # #  ############  #  #  ####  #  ######    ##   ##*****|",
    "+*****##   ##  #  # #                #        #  #            ##   ##*****+",
    "|*****##   ##  #  # ########  #  #####  ####  ##################   ##*****|",
    "+*****##   ##  #  #        #  #      #     #  #    #          ##   ##*****+",
    "|*****##   ##  #  #######  #  #####  ####  #  # #  #  ######  ##   ##*****|",
    "+*****##   ##     #        #      #     #  #  ###  #  #    #  ##   ##*****+",
    "|*****##   ##############  #  ##  ####  #  #       #  #  # #  ##   ##*****|",
    "+*****##   ##          ##  #   #     #  #  #########  #  # #  ##   ##*****+",
    "|*****##   ##          ##  #  #####  #  #             #  # #  ##   ##*****|",
    "+*****##   ##          #####  #####  #  ###############  # #  ##   ##*****+",
    "|*****##   ##          /      #####  #                   #T#  ##   ##*****|",
    "+*****##   #####################################################   ##*****+",
    "|*****##                                                           ##*****|",
    "+*****###############################################################*****+",
    "|*****###############################################################*****|",
    "+*************************************************************************+",
    "|*************************************************************************|",   
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};
//--------------------------------------------------------------------
//
//  For stairs:
//      - 's' is initial spawn to dungeon
//      - 's' also leads back to 2nd floor
//      
//  Other:
//      - 'T' is for treasure
//
//--------------------------------------------------------------------
void printMap()
{

    for(int rows=0; rows <= ROWS; rows++)
    {
        for (int columns=0; columns < COLUMNS; columns++)
        {   if( MAP[rows][columns] == '+' || MAP[rows][columns] == '-' || MAP[rows][columns] == '|' || MAP[rows][columns] == 's' )
            {
                cout << ChangeToBlue();
            }
            else if( MAP[rows][columns] == '#' || MAP[rows][columns] == '*' || MAP[rows][columns] == 'X' )  
            {
                cout << ChangeToWhite();
            }
            else if( MAP[rows][columns] == 'T' ) 
            {
                cout << ChangeToYellow();
            }   
            else if( MAP[rows][columns] == '/' )
            {
                cout << ChangeToMagenta();
            }    
                
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



 
