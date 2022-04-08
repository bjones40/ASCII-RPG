/*------------------------------
 *
 * Dessert Desert - World Map
 * 
 *------------------------------
*/
#include <iostream>


#include <stdlib.h>
#include <string.h>
#include "ColorLib.h"


using namespace std;

#define  ROWS 40 
#define  COLUMNS 125


char MAP[][COLUMNS] =	
{
	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
	"|~~~~~~~~~~~~MMMMttttttttttttttt, ., . ,.,., ., ., ., ., ., .ttttttttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
        "+~~~~~~~~~~~MMMttttttttttttttttttt., ., ., ,. , tttttttttttttttttttttttttMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
        "|~~~~~~~~~MMMtttttttttttttttttttt,,, .. , . , ttttttttttttttttttttHHHHHHHHHMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
	"+~~~~~~~~~~MMMHHHHHHHHHttttHHHHHt, ., ., . ,. ttttttttttttttttttttttttHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
        "|~~~~~~~~~MMMMMMMHHtttttttttHHHtt. ., .,., ., .tttttttttttttttttttttttttHHHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
        "+~~~~~~~~MMHHHHHHHHHHHttttHHHttt., . ,. , .,. ,tttttt., ., ., ., . ,..ttHMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
        "|~~~~~~~MMMMMHHHHHHHHHHHHHMMMMMt.,. ., . ,.. ,tMttttttt., . , . ,. , tHHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~MMMHHHHHHHHHHHHHHHHHHMMMM.. ., ., , tttMMMHHHttt. ., ., ., ., tHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",	
    	"|~~~~~MMMMMMMHHHHHHHHHHHHHHMMMMt, ., ., .,. tttMMMMHHHtt. ., , ,., ,ttMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~MMMMMMHHHHHHHHHHHHMMMMtt, ., ., ., .,,tMMMMMHHHHtt., ., ,. ,.ttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~MMMMMMMMMMMMMMMMMttt., ., .,,. . ,, ttMMMMHHHttttt##   ##ttMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
	"+~~~~~~~~~~MMMMMMMMMMMMMMtt., ., .,., ,. ,,.ttMMMMMMHtttttt#     #tMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~MMMMMMMMMMtt,., ., ,. , ., , .,tMMMMMMMMMMtttt#  X  #tttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~MMMMMMMMMMttt,. ., ,. ,. ., ,. , ttMMMMMMMMMMMttt#     #ttttMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~MMMMMMMMttt, ., ., ,. ., ., ,. ,.,ttMMMMMMMMMMMtt#######tttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",   
    	"+~~~~~~~~~~MMMMMttt., . ., ,. .,, . ,. ,.., ,ttttMMMMMMMMMtttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",   
    	"|~~~~~~~~~~~MMMtt, ., . . ,. , ., .,., ,. , ,.. tttMMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~MMMt.,. ., ., ,. .,., . .,. ,., ., . ,ttttMMMMMMMMMMMMMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~MMMM., ., .,., ., ., ,. . , .,,. ,. , ,. tttMMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
	"+~~~~~~~~~~MMMMtttt. ,., ., , . , . ,. ,. ,. ,. , .,  ,,ttMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~MMMMtt., . . , ., ., ,. , . ,. ,. ,.,. ,ttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
	"+~~~~~~~~~~~~~~~~Mt. ,., ,. ., ., ., ., ., . ,. , .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~Mtttt., . , ., . . , ., . ,.,. ,. ,ttttttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
	"+~~~~~~~~~~~~~MMHHtt., ., ,. ,. ,. ., ,. ,. ,. . .,tttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~MMMHtttttt., ., ., ., ., ., ., ., ,.ttttttM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~MMHtttttttttttt., ., , . ., ., ., tttttttMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
	"|~~~~~~~~~~~~~~~~MHHttttttttttttt,. , ., ., ., ,,.ttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~MMMHHHHHHttttttt.,. ., ., .,ttttttttttHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~MMMHHHHtttttttttt##   ##tttttttttttttHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~~~~~MMHHttttttttttt#     #tttttttttHHHHHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~~MMMHHttttttttttt#  X  #ttttttttttttHHHHM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~~~~~MMHHHHHHHtttttt#     #tttttttttttHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~~~~~MMMMMHHHHHttt#######ttttttttttttHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~~~~~~~~~~~~MMMHHHtttttttttttttttttttttHHHHMMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHttttttttttttttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMMMMMMMMMMttHHHHHHHMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMMMHHHMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MMMM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    	"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
    	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
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
           else if ( MAP[rows][columns] == '.' || MAP[rows][columns] == ',' ) 
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


