/*------------------------------------
 *
 * Cabbage Campo (Area 1) - World Map
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
    "|~~~~~~~~~~~MMMMMMMHHHHH,. ., . ,. , . , . . ., .ttttttt. ,. , ,. , .  ,.  ,. .tttttttttttHHMM|",
    "+~~~~~~~~~~MMMMMMMHHHH, ., . , .,., . , ., .. ,.ttttttttt., ., . ### ###. ,. ,. ttttttttttttHM+", 
    "|~~~~~~~MMMMMMMMHHHH,. ., ., ,. ., . ,. , ,,. ,ttttttttttt., ,.  #     # . ,, ,ttttttttttttttH|",
    "+~~~~~MMMMMMMMMHHHH, . ,. ,. ., ,. ., ,, ., ., ttttttttttt.,######     ######, .,tttttttttttHH+",
    "|~~~MMMMMMMMMHHHHHH,. ., . ,. ,. , ., . , . ,, ttttttttttt,,#               #., .ttttttt. , . |",
    "+~~MMMMMMMHHHHHHtttttt,. ., . ,, .tttttt., . . .ttttttttt, ,#       X       # ., ,.ttttt,. ,. +", 
    "|~MMMMMHHHHHHHHttttttttt, , .  .ttttttttt,. , . , ttttt., ,.#               # .,. tttt. .. ., |",
    "+MMMMMMHHHHHHtttttttttt,. ., .ttttttttttttt,. .,.  ..ttt. ..#               #, ,. .ttttttt,. ,+",
    "|MMMMMMMHHHHHHHtttttttt, .,, ..ttttttttttt., ., .,.tttttt.,,#################.,.ttttttttt,.. ,|",
    "+~MMMMMMHHHHHHHHHHtttt,. ., . .ttttttttttt.,, . . .tttttt., . ,. ,., . ,. , ,ttttttttttt,. , .+",
    "|~~MMMMMMMHHH,. ., . ,. ,.  . ,. ttttttt., ., ,., .,ttt.,. ., ., ., ., ., . .ttttttttttt,., . |",
    "+~~MMMMMMHHHHHHH,. ., . ,.  .,,. ,. ,. . . , . ,  .,. , . .ttttttt,, ., . . ,ttttttttttt., ., +",
    "|~MMMMMMMHHHHHHHHH, ., . ,., .,  ., . , ., . , . ,. ,. ,.ttttttttttt., , , ,. ttttttttt, ., . |",
    "+~MMMMMMMHHHHHHH,., ,. ,. ,.  , . ..,  ., . ,. , ., . .,ttttttttttttt, ., . ,..ttttttt. ,,. .,+",
    "|~~MMMMMMMMHHHHHHHHH,. ., . ,, ., ,. , .,. , . ,,  , .,.ttttttttttttt, ., . ,. ., . ,. ,. , . |",
    "+~~~MMMMMMMMHHHHHH,. ., . ., ., . , ., ,. , ., . . , ., ttttttttttttt,. ., ., ., . , ., . ,. .+",
    "|~~~MMMMMMMHHHHHHHHHHHHHH,,. ., . , . , , ., ., . ,. , . ttttttttttt.,. ,. . , ., . ,.. ,..  ,|",
    "+~~~MMMMMMMMHHHHHHH,.. ., ., . ,. ,. . , .  ., . ,. , .. ,. ttttt,. ., ., . , ., , ., ., , .. +",
    "|~~MMMMMMMMHHHHHHHHHHH,. ., ., ,., .., , . ,. , ., . , .,., ., , ., . ,. ,. ,. ,., . ., ,. . ,|",
    "+~MMMMMMMMMMHHHHHHHH,., ., . ,. ,, .., . , ,. ,. ,. ,, .,.., , .., ,. ,. , . ,.  . , . ,. , ..+",
    "|~MMMMMMMMMMHHHHHHH, ,. .,, ., ., ., ., ., . .,. ,.,. , ,.. , . ,. ., ,. ., . ,. ., .. , ., . |",
    "+~~MMMMMMMMHHHHHHHHHHH,. ., . .,tttttttttt,. ., . ,. , . ,. , . ,, ., ., ,, , . . ,. .,. ,. ,.+",
    "|~~~MMMMMMHHHHHHHHHHHH, ., ., .tttttttttttt. ,., ., ,. ., , , ,. , . ,. , ., ., .,., ., ., . .|",
    "+~~~MMMMMMMHHHHHHHH.,. ., . ,tttttttttttttttt,., . ,. ,. ,., . ,tttttttttttttttttt,., ., .,. ,+",
    "|~~~MMMMMMMHHHHHHHHHHH, ., .,tttttttttttttttt., . , ., . , .,ttttttttttttttttttttttttt,, ., . |",
    "+~~~~MMMMMHHHHHHHH,. ,.  ,. ,tttttttttttttttt. .,  ., , . .ttttttttttttttttttttttttttttt., ., +",
    "|~~MMMMMMMHHHHHHHHHHHHH, ,. ., tttttttttttt,. . ,, ., . ttttttttttttttttttttttttttttttttttt. .|",
    "+~MMMMMMMHHHHHHHHHHH., ., . ,.,  tttttttt. .,  ., ., ,.ttttttttttttttttttttttttttttttttttttt.,+",
    "|~MMMMMHHHHHHH,. ., . , ., ., ., ., .., ., ., . ,. , .,ttttttttttttttttttttttttttttttttttttt ,|",
    "+MMMMMMHHHHHHHHHHHHH, ., ., ,. ., , . , ., ., . ,., ., ttttttttttttttttttttttttttttttttttttt. +",
    "|~MMMMMMHHHHHHHH., ., . ,,. ., ,. ,  ., ., ., ., . ,. , ,ttttttttttttttttttttttttttttttHHMMMMM|",
    "+~~MMMMMMHHHHHHHHH, . ,. . ,. ,. ,, .tttttttt., ., . ,, ,.tttttttttttttttttttttttttHHHMMMMMM~~+",
    "|~~~MMMMMMHHHHHHHHH,. ., ,. , . ,.,ttttttttttt,. ., ., ., ,.tttttttttttttttttHHHHMMMMMMMM~~~~~|",
    "+~~~~~MMMMMHHHHHHHHHHH,., ., ., ., .ttttttttttt, ., . , , ., .,ttttttttttHHHHMMMMMMMMM~~~~~~~~+",
    "|~~~~~MMMMMHHHH,.,. ., . ,. , . . . ,ttttttttt., . ., .  . , ., ,tttttttttHHHMMMMMMM~~~~~~~~~~|",
    "+~~~~~~MMMMMMHHHHHH., . ,. ., ., ,. ., ,ttttt ., . ,. , .,. ., ., ,.,. ., HHHMMMMMM~~~~~~~~~~~+",
    "|~~~~~~MMMMMHHHHHHHHHH., . , , . ,. ,. ,.ttt. ,. , ., . , ,. ,. ., ., .HHHHMMMMMM~~~~~~~~~~~~~|",
    "+~~~~~~~MMMMMHHHH, ., . ,.  ., . , . ., ,. .,., ., ., , ,..,., ., .HHHHHMMMMMM~~~~~~~~~~~~~~~~+",   
    "|~~~~~~~MMMMHHHHHHHH,. ., . ,. , . ,. ,, .,., . ,. ,. ., ,.HHHMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~|",
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


