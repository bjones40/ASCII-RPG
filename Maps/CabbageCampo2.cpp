/*------------------------------------
 *
 * Cabbage Campo (Area 2) - World Map
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
    "|MMMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~|",
    "+MMMHHHttttHHHHHHHHHHHHHHHHHtttttttttHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~+", 
    "|HHH, tttttt,. , . .. ., . ttttttttttt ., ., ., , . ,,.  HHHHHHHHHHHMMMMMMMMMMMMMMMMMMMMMMM~~~|",
    "+HH,.tttttttt ,. .., ., .,ttttttttttttt. , ., . , ., ., ,. ,. ,HHHHHHHHHHMMMMMMMMMMMMMMMMMMM~~+",
    "|,. .tttttttt., . ,. ,. ,.ttttttttttttt,, .ttttttt, ., , . .,  ., .HHHHHHHHHHHHHHHMMMMMMMMMMM~|",
    "+. ,.  ttttt,. , ., . , ., ttttttttttt . ,ttttttttt. , ., ., ., . ,. .HHHHHHHHHHHHHHHMMMMMM~~~+", 
    "|,. ., , t,. .. , ,. ., ., .tttttttt. , ttttttttttttt. , ., ., . , ., ., .HHHHHHHHHHHHHMMMMMM~|",
    "+., . . , .., ., .,., . ,.  ,.tttt . . ,ttttttttttttt , .,. ., ., ., ,. .,.,HHHHHHHHHHHHMMMMM~+",
    "|,. .,. ,. ,. tttttt., ., ,, . ,. ,. , . ttttttttttt, . . , . ,. , ., . HHHHHHHHHHHHHHHHHMMM~~|",
    "+. ., ., ., tttttttttt ., ., ., ,. ,. ,. . ttttttt. , ., . ,.  ., , , ., .HHHHHHHHHHHHHHHHMM~~+",
    "|,. . ,., ttttttttttttt . ., . ,. , . , ., . ,. , .. , .., . ,. ., ., ., ., .HHHHHHHHHHHHHHMM~|",
    "+,. ., ,.ttttttttttttttt. ,., ., ttt, , ,. ., .,,. ., ., .,,. ,. ,., ., .,,. . ,HHHHHHHHHHHMM~+",
    "|., . ,. ttttttttttttttt ,.. , .ttttt. ,. , ., . ,. ,.  ., . ,.ttt , . ,. ,. ,HHHHHHHHHHHHHHM~|",
    "+, ., ., ,tttttttttttt,. , .., . ttt, ., ., .,  tttt,. , .,   ttttt.. . .. HHHHHHHHHHHHHHHHHHM+",
    "|., ., ., ,tttttttttt ., . ., . , ., ., ., . , tttttt . ,. ,tttttttt., . , ,. ,. ,.HHHHHHHHHHM|",
    "+,. .  ,. . .ttttt., . ,. , ., . ,. ,. , . ,. ,.tttt. ,  , ttttttttttt  ., . ,. HHHHHHHHHHHHHH+",
    "|. ,. .,, . , , , ., ., ., . ,. ttt , . ,.  ., . tt  ,. , .ttttttttttttt , ., ., . ,. HHHHHHHH|",
    "+. , .., ., ., . , ., ., .  , .ttttt. , . ., . ,  , .,. , . tttttttttt, .,. ,. ., .HHHHHHHHHHH+",
    "|, ., . ,. . ,. ,. ,. , .,. ,.ttttttt . ,. .  . , . ,.  .. ,, ttttttt,. ,.  .HHHHHHHHHHHHHHHHH|",
    "+., .,.ttt ., . , ., ., . ,. ,ttttttt ., . . . , . ., .,   , ., ., . , .,  , ., .HHHHHHHHHHHHM+",
    "|,. .,ttttt ,. , ., ., . , ., .ttttt., .  . ,ttttttttttt, ., . ,. ,. . ,, . ,. ., . ,HHHHHHHHM|",
    "+,. ,. ttt, . ,. ,. ,. , ., ., .ttt., . ,tttttttttttttttttttt  ., .  ,. , ., . ,. HHHHHHHHHHHM+",
    "|., ., .,. ,. ,. , . ,. ,. , . , . ., tttttt.   .  .   , ttttttt ,. ,. ,. , . HHHHHHHHHHHHHHHM|",
    "+. ., ., ., . ,. . ttttttt,. , ., ttttttt.  , .   ,   .   ,tttttttt.,., ,. .,., ,.HHHHHHHHHHHM+",
    "|., ., .,. , . ,. ttttttttt., . ,tttttt      .### ### .     . ttttttt.  ., . . ., ,HHHHHHHHHM~|",
    "+., . ,. . , . ,.ttttttttttt, ttttttt   .  ,  #     #,     ,   ,tttttt , ., .HHHHHHHHHHHHHMM~~+",
    "|H., . ,., . , .,tttttttttt ttttttt.     ######     ###### .  .,  .tttttHHHHHHHHHHHHHHHHMMM~~~|",
    "+HH, tttt , .,. , tttttttt ttttttt .    ,#               #     ,  ,   tttttHHHHHHHHHHHMMMMMM~~+",
    "|MHHHtttttt. ,. ,. tttttt,ttttttt   ,  . #       X       #    ,   , .HHHHHHHHHHHHHHHHMMMMMMMM~|",
    "+~MMHHHttttt,.  ., ,. . .,ttttttt,       #               #,     , HHHHHHHHHHHHHHHHHMMMMMMMMMM~+",
    "|~~MMMMHtttt ,. , ., ., . ttttttt.  ,   .#               # ,  ,    . ,  HHHHHHHHHHMMMMMMMMM~~~|",
    "+~~~MMMMHHt ,. , . ,. , .ttttttt,    .  .#################     . ,. , HHHHHHHHHHHMMMMMMMMMMM~~+",
    "|~~~~MMMMMHH., . , .,. ,.ttttttt,        ,      .   ,     ,  .. .HHHHHHHHHHHHHMMMMMMMMMMMMMMM~|",
    "+~~~~~~~MMMHHH. ,. , ., .ttttttt, .  .      .  , .       ,. , HHHHHHHHHHHHHHMMMMMMMMMMMMMMM~~~+",
    "|~~~~~~~~~~MMHHHH.,. ,. ,ttttttt ., .   ,  . . ,   .  .HHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMMMMM~~|",
    "+~~~~~~~~~~~~MMMHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMMMMMMMMMMMMMM~~~~+",   
    "|~~~~~~~~~~~~~~~MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM~~~|",
    "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

//--------------------------------------------------------------------
void printMap()
{

    for(int rows=0;rows <= ROWS  ;rows++)
    {
        for (int columns=0;columns < COLUMNS;columns++)
        {  if ( MAP[rows][columns] == '~' )
                cout << ChangeToRed();
             else if ( MAP[rows][columns] == 't' )
                cout << ChangeToGreen();
             else if ( MAP[rows][columns] == '+' || MAP[rows][columns] == '|' || MAP[rows][columns] == '-' || MAP[rows][columns] == 'M' )
                cout << ChangeToBlue();
             else if ( MAP[rows][columns] == 'H' ) 
                cout << ChangeToYellow();      
             else if ( MAP[rows][columns] == '#' || MAP[rows][columns] == 'X')
                cout << ChangeToWhite();
             else if ( MAP[rows][columns] == ',' || MAP[rows][columns] == '.' )
                cout << ChangeToBrightGreen();
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


