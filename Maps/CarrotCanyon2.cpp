/*------------------------------------
 *
 * Carrot Canyon (Area 2) - World Map
 * 
 *------------------------------------
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ColorLib.h"


using namespace std;

#define  ROWS 40 
#define  COLUMNS 100


char MAP[][COLUMNS] =	
{
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~|",     
    "+HHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~~+",
    "|HHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~|",
    "+HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~~~~~~~~+",
    "|HHHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~#########|",
    "+HHHHHHHHHHHtttttttHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMM ., ,. ., ,. ####wwwwwwww+",
    "|HHHHHHHHHHHtttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMM. ,. , . . , ,.     wwwwwwww|", 
    "+HHHHHHHHHHHHtttttHHHHHHHHHHHHHHHtttttHHHHHHHHHHHHMMMMMMMMMMMMMM., ,.  ,. ., ,. ,.####wwwwwwww+",    
    "|t t t t t t t t  t t t tHHHHHHHtttttttHHHHHHHHHHHHHHMMMMMMMMMM., ,.  . ,. .,.MMMMMM~#########|", 
    "+.. . , ., ,. .,. .,., ,.ttttHHHtttttttHHHHHHHHHHHHHHHHHHMMttttttt., . . , .MMMMM~~~~~~~~~~~~~+", 
    "|. ,. , ,.  ., ., ., ., ., .,tttttttttHHHHHHHHHHHHHHHHHHHHttttttttt., ., ,.MMMM~~~~~~~~~~~~~~~|", 
    "+. ,., ., . ,. ., . ,. ., ., .,.,ttt t t  t t t t t t t t ttttttttt ,. .,MMM~~~~~~~~~~~~~~~~~~+", 
    "|., ,. ., ,. ,. . , .,,. ., ,. ., ,., .,. ,. ,., ., ., .,,.tttttttHHMMMMMMMMMMM~~~~~~~~~~~~~~~|", 
    "+., ., ,. ., ., ,. . ,., . ,., . , ., ., . ,. , ., . , ., , .tHHHHHHHHHMMMMMMMMMMMMM~~~~~~~~~~+", 
    "|. ,., ,. ,. ., ., ., ., . . , ., . , ., ,. ., ., . , ., ,. . .tHHHHHHHHHMMMMMMMMMMMMMMMMM~~~~|", 
    "+., ., ., ,. ., .  .,. ,. , ., ., . .,. ., ,. , ., ,.,. . ., ,tHHHHHHHHHHHHHMMMMMMMMMMMMMMMM~~+", 
    "|., ., . , . ., , ., . , ,.. , .,t t t t t t t  t t t tt t,. ,.,tHHHHHHHHHHHHHMMMMMMMMMMMMMMM~|", 
    "+ ,. , ., ., ,.  ., ., ,. ,..tttttHHHHHHHHHHHHHHHHHtttttHtt.,  ,tHHHHHHHHHHHHHHHMMMMMMMMMMMMMM+", 
    "|, ,. ., ,., ,.,. , . . ,ttttttHHHHHHHHHHHHHHHHHHHtttttttHt, ., .,tHHHHHHHHHHHHHHHMMMMMMMMMMMM|", 
    "+t t t t t  t t t t t t tHHHHHHHHHHHHHHHHHHHHHHHHHtttttttHHt., . .tHHHHHHHHHHHtttttMMMMMMMMMMM+", 
    "|HHHHHHHtttttHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHHtttttHHHt. ., ..ttttttHHHHtttttttHMMMMMMMMM|", 
    "+HMHHHHtttttttHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHt., ., .  .,,tttHtttttttHHMMMMMMMM+", 
    "|HHMHHHtttttttHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHt, ., .,, . ,. .,ttttttHHHHHMMMMMM|", 
    "+HHMMHHHtttttHHHHHHHHHHtttttHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHtt.., . ,. . , .,.tHHHHHHHHHMMMMM+", 
    "|HHHMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMHHHMttttttt, ., , ., .,.,tHHHHHHMMMM|", 
    "+HHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMHtttttHHMMMtttttt.., ,, . .ttHHHHMMM+", 
    "|MHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHtttttttHMMMMMMMMMMMMM### ###HHHHHHMM|", 
    "+MMHHHHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHtttttttHMMMMMMMMMMMMM#     #HHHHHHHM+", 
    "|MMMMMHHHHHHHHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMHtttttHMMMMMMMMM######     ######HHM|", 
    "+MMMMMMMMHHHHHHHHHHHMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMHHHHHMMMMMMMMMM#               #HHM+", 
    "|MMMMMMMMMMMMHHHHHHHHHHMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH#       X       #HHM|", 
    "+MMMMMMMMMMMMMMMMHHHHHHHMMMMMMMMMMHHHHHHHHHHHHHHHMMMMMHHHHHHHHHHHHHHHHHHHH#               #HHM+", 
    "|MMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH#               #HMM|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHH#################MMM+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHMMMM|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHMMMMMMM+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

//--------------------------------------------------------------------
void printMap()
{
    for(int rows=0;rows <= ROWS  ;rows++)
    {
        for (int columns=0; columns < COLUMNS; columns++)
        {  if ( MAP[rows][columns] == '~' )
                cout << ChangeToRed();
             else if ( MAP[rows][columns] == 't' )
                cout << ChangeToGreen();
             else if ( MAP[rows][columns] == '+' || MAP[rows][columns] == '|' || MAP[rows][columns] == '-' || MAP[rows][columns] == 'M' )
                cout << ChangeToBlue();
             else if ( MAP[rows][columns] == 'H' )
                cout << ChangeToYellow();
             else if ( MAP[rows][columns] == ',' || MAP[rows][columns] == '.') 
                cout << ChangeToBrightGreen();      
             else if ( MAP[rows][columns] == '#' || MAP[rows][columns] == 'X' || MAP[rows][columns] == 'w')
                cout << ChangeToWhite();
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



