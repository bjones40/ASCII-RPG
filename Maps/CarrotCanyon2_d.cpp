/*-----------------------------------
*
* Carrot Canyon - Dungeon (Floor 2) 
*
*------------------------------------
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
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+**#####################################################################**+",
   	"|**##                                                                 ##**|",
	"+**##  s                                                           T  ##**+",
   	"|**##                                                                 ##**|",
	"+**#####################################################################**+", 
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
	"+*************************************************************************+",
   	"|*************************************************************************|",
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
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
		{   
            //PositionCursor(rows,columns);
            if( MAP[rows][columns] == '+' || MAP[rows][columns] == '|' || MAP[rows][columns] == '-' || MAP[rows][columns] == 's' )
                cout << ChangeToBlue();
            else if( MAP[rows][columns] == '#' || MAP[rows][columns] == '*' )
                cout << ChangeToWhite();
            else if( MAP[rows][columns] == 'T' )
                cout << ChangeToYellow();
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




