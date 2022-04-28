/*------------------------------------
 *
 * Carrot Canyon (Area 1) - World Map
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
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|",     
    "+MMMMMMMMMMMMMMMMM, .. ,MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH+",
    "|MMMMMMMMMMMMMM.. ,., ., , . .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHH|",
    "+MMMMMMMMMMMM, .,.MMMMMMMMM.  . .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHH+",
    "|MMMMMMMMMMM. ,.,MMMMMMMMMMMMMM,  ., ,HHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHH|",
    "+MMMMMMMMMM### ###MMMMMMMMMMMMMMHHHH, ., ,HHHHHHHHHHMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHH+",
    "|MMMMMMMMMM#     #MMMMMMMMMMMMMMMMMMHHHHH. ,. . .,,HHHMMMMMMMMMMMMMMMMHHHHHHHHHHHHHHHHHHHHHHHH|", 
    "+MMMMM######     ######MMMMMMMMMMMMMMMMMMHHHH. ,. .,,HHHHMMMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH+",    
    "|MMMMM#               #MMMMMMMMMMMMMMMMMMMMMHHHH. ,, ..HHHMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|", 
    "+MMMMM#       X       #MMMMMMMMMMMMMMMMMMMMMMMMHHHH, ., ,HHMMHHHHHHHHHHHHHHHHHHHHHHHHH. ., ., +", 
    "|MMMMM#               #MMMMMMMMMMMMMMMMMMMMMMMMMMMMHHH. ,..HHHHHHHHHHHHHHHH,,. . , ., ., ., .,|", 
    "+MMMMM#               #MMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHH, . ,HHHHH. ttttt ., ,. ., ., ., ,. .,+", 
    "|MMMMM#################MMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHH, ., , . ,ttttttt., ., ,. ., ., ,. ,.|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHHH.. , ., .,ttttttt, ., . , .,., ., ,. +", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHHH,,. . , . ,..ttttt,. ., ,. ,. ,. . ,. ,|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH. ,. ., ., ., ., , .,., ., ,. .,  ., ., .+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH. ttttt ., ,.,. .,., ., ,. ., . ,ttttt. ., ,.|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHH, .,ttttttt ,. ., .,,. ., ,. ., ., ttttttt,, . .+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHH. ., .,ttttttt.,., ., ., ., . , , . , ttttttt., ..,|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHHH, ,. ., ., ttttt. ,.,  .,., ., ., ,. ., .,ttttt. ..HHH+", 
    "|MMMMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHHH, ., ., ., .,., .,  ., ., . ., ., ., ., ,. ,. ,. ,.,HHHHM|", 
    "+MMMMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH., . ,. , .,. , . , .. , ., ., ,. .,. ,. , ., ., ,..,HHHHHMM+", 
    "|MMMMMMMMMMMMMMMMMMMMMHHHHHHHHHH., ttttt , ., ,, . , ., ,. .,.,. , .,. , ., .,.,  .,.HHHHHMMMM|", 
    "+MMMMMMMMMMMMMMMMMMMMHHHHHHHHHH,  ttttttt, , . ,. .,, ., ., ttttt,. ,. , ., ., . ,HHHHHHHMMMMM+", 
    "|MMMMMMMMMMMMMMMMMHHHHHHHHHHHH.., ttttttt , ,. . , ,., . ,.ttttttt,., ., ., ..HHHHHHHHMMMMMMMM|", 
    "+MMMMMMMMMMMMMMHHHHHHHHHHHHHHH, ., ttttt., ., ,. ., ., ., ,ttttttt .,,  ..HHHHHHHHHHHMMMMMMMMM+", 
    "|MMMMMMMMMMHHHHHHHHHHHHHHHHHHH ,., ., ., . , , ., ,. ,. ., .ttttt,.HHHHHHHHHHHHHHHHMMMMMMMMMMM|", 
    "+MMMMMMMMHHHHHHHHHHHHHHHHHHHHH.., , ., .,., ,. . ,. ,, ., ,HHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMM+", 
    "|MMMMMMMHHHHHHHHHHHHHHHHHHHH,., ,. ., ., ,. , ., ., .HHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMM|", 
    "+MMMMMMHHHHHHHHHHHHHHHHHH.., ., .,. , . ., . ,,HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMM+", 
    "|MMMMMHHHHHHHHHHHHHHHHH,.,  ,.. , .. , ..HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+MMMMMHHHHHHHHHHHHH. ., ,. ,.,. . ,. ,HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMM+", 
    "|MMMMHHHHHHHHHHH,., ., ,. .,.,  .,.HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+MMMHHHHHHHHHH. ., ., . , . ,. ..HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+", 
    "|MMMHHHHHHHHHH., ., ., ., ,.. .HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+MMHHHHHHHHHHH, .,. ,. ,. , .HHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+", 
    "|MHHHHHHHHHH. , ., , .,  .,,HHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+HHHHHHHHHH. .,, .  , ., .,HHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+", 
    "|HHHHHHHH, ,. .,, ., ,. .,HHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|", 
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

//--------------------------------------------------------------------
void printMap()
{
    for(int rows=0;rows <= ROWS  ;rows++)
    {
        for (int columns=0; columns < COLUMNS; columns++)
        {  if ( MAP[rows][columns] == 'N' )
                cout << ChangeToRed();
             else if ( MAP[rows][columns] == 't' )
                cout << ChangeToGreen();
             else if ( MAP[rows][columns] == '+' || MAP[rows][columns] == '|' || MAP[rows][columns] == '-' || MAP[rows][columns] == 'M' )
                cout << ChangeToBlue();
             else if ( MAP[rows][columns] == 'H' )
                cout << ChangeToYellow();
             else if ( MAP[rows][columns] == ',' || MAP[rows][columns] == '.') 
                cout << ChangeToBrightGreen();      
             else if ( MAP[rows][columns] == '#' || MAP[rows][columns] == 'X')
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



