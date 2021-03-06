/*---------------------------
*
* Carrot Canyon - Village 
*
*----------------------------
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ColorLib.h"


using namespace std;

#define  ROWS 50 
#define  COLUMNS 130


//#define StartingX 1
//#define StartingY 1


char MAP[][COLUMNS] =	
{
	"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+",
	"|., ., . ,. , ., ., ., . , ., .,. ,. , ., ., . ., ., . ,., . , ., ., ., ., . ,. , ., ., ., ., ., . , ., ., . ., . ,. ,. , ., .|",
	"+. ,., . ,. , ., ., ., ., ,. ., . . , ., ., . , ., ., .,., ., ,. ., ., .,. ,. , ., ., ., ., ., ., . ,. , ., ., ., . ,. ., . . +",
   	"|., ., ., ., , .. , ., ,..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ., ., ., . , ., ., . , .|",
	"+. , ,. .,. , ., ., . , .,x                                                                         x., , ., ., ., ., . ,, .  +",
   	"|., ., ., ,. ., . , ,. ., x                                                                         x. ,,. . , . , ., ., . ,. |",
	"+. ,. ,, . , ., ., . ,. .,x                                                                         x ., ,. ,. . ,. , ., ,. .,+",
   	"|., ., ,. . ,, .. , ., . ,x         xxxxxxxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxxxxxxxxxxxx         x. ,,. . , . ,. ., ,. ,.. |",
	"+, . , ., . , ,. , ., ., ,x         x., ,. . ,. , ., , . , .x     x,. ., ,. ., ., . . , .,x         x ., ., ., ,. ., . , .,  .+",
   	"|., ,. . ,,.  ., ., ,. ., x         x., ., ,. . , ,. ,. .,. x     x., ,. ,. ,. ,. .,  . ,.x         x., ., ., ., ,. ., . , ., |",
	"+., ,. ., . , . ,. , .,. ,x         x., ,. ., ,. ., ., ,. ,.x     x., ., ., ., . ,. ., . ,x         x., , ., ,. ., ., ., ., . +",
   	"|., ., . ,. ,, ., . , ., .x         x., ., ., ., ., ,. ., ..x     x. , ., ., ., ,  ., .,.,x         x. ,., ,. ., ,. ., ,. ,. .|",
	"+. ,. , ., ., ., ., . , .,x         x., ,. ., ,. ,. , .,.  .x     x,.., ,. ,. ,. ,. .,  .,x         x., . ,,. ., ., ,. ., .,. +",
   	"|. ,. ,. ,. , ., ,. ., ,. x         x., ., .,  ,. ., . . , .x     x., ., ,. ,. ,. ,. .,  .x         x. ,. ,,. ., . , ., ., .,.|",
	"+., . ,,. ., ,. . ,. , ., x         x., ., ., ., ., ,. ,. .,x     x., ,. ., ., ,. ., ,.. ,x         x., ., . ,. ,. , ., ,. ,. +", 
   	"|., . , ., . , ., .,,.  .,x         x. ,,.  , . ,. .,,. ,., x     x,. ., ., ,. ,. ., ,.  ,x         x., ,. ., ., ., ., ,. ., .|",
	"+., ., ., . , ., ., ., . ,x         x,. ,. ,. ., ,. ,. ., . x     x., ,. ,. ., ,. ,. .,  .x         x. , ., . , ., ., ,.. , .,+",
   	"|., . ,. , ., ., ., ,. ,. x         x., ,. ,. ,.  ,. ,. ,.. x     x., , ., ,. ., . , .,,..x         x., ,. . ,. , ,. ., ,. .,.|",
	"+., . ,. ,., . ,. , ., ,..x         x., ., ,. ,. ., ,. ######## ########., ,. ., , . ,. . x         x., , ., , ., . , . ,. , ,+",
   	"|., . , ,. , ., ,. , ., . x         x,. ,. ., ., . ., ,#000000000000000#., ,. . , ., .,.. x         x., , ., ., ., ., . , ,.. |",
	"+. ,. ,., . ,. , ., , . ,.x         x., ,. , , ., ,. .,#000000000000000#., ., , . , ., . ,x         x., ., ., ., ,. .,, . ,,. +",
   	"|., ., ., . , ., ,. , ., .x         x., ,. . , ., ,. .,#000000000000000#., ,. . , .  ,.  .x         x., ., ., ., . , ., ., .,.|",
	"+., ., , . , ., .,.  ., .,x         x., ,. . , .,.######000000000000000######., , . ,. , ,x         x., .,., .,. , ., ., ., .,+",
   	"|., ., ., . ,. , . ,. , ..x         x., ,. ., ,. .#0000000000000000000000000#. , ., ,. ., x         x ., ., ., ., ., . . ,. . |",
	"+xxxxxxxxxxxxxxxxxxxxxxxxxx         x., ., ,. . , #0000000000000000000000000#., ., , . ,. x         xxxxxxxxxxxxxxxxxxxxxxxxxx+",
   	"|                                   x., ,. ,. ., .#0000000000000000000000000#. ,. ,. ., . x                                   |",
	"+                                   x .,. , ,.. .,#0000000000000000000000000#., ., ,. ., .x                                   +",
   	"|                                   x. ,,. ,. . . #0000000000000000000000000#., ., .,  .,.x                                   |",
	"+xxxxxxxxxxxxxxxxxxxxxxxxxx         x., ,. ., .,  #0000000000000000000000000#., ., ., . ,.x         xxxxxxxxxxxxxxxxxxxxxxxxxx+",
   	"|., ,. , . ,, . , ,.. , .,x         x. , .,. . ,,.#0000000000000000000000000#,. ,. ., . ,.x         x. , ., ,. ., ., ., ., ,..|",
	"+. , .,,. . ,, . ,. ,. ,.,x         x. ,,.  ., ,. ###########################. ,,. ., ,. .x         x. , ,.. , ,. ., , .,  ., +",
   	"| ., ., ., ., . ,. ,. , ..x         x., ,. . ,, . , ., .,  ., ., ,. ,. ,. ,. ,. ,. ,. ,. .x         x ., ,. ., , ,. ,. ., ,.. |",
	"+ ., ., , . , . ,. , ., .,x         x., ,. ., ., ,. , .  ,., . ., ,. ., ., ,. ,. ,. ,. ,. x         x ,.,  ,. ,. ,. ,. ,. .,. +",
   	"|., ., ,. . ,. , ., . ,. ,x         x. ,,.  ., , ., . ,. ., .,  ., ,. ., ,. ., ,. ., . , .x         x. , , ,. ,.., , ., ., ,..|",
	"+., ., ., ., ,. . , ., , .x         x., ,. . ,. ., ., . , . , .,.  , ., ., .,., .,. ,.,  .x         x ,. ., ,. ., ., ., ., ,. +",
   	"|,. , ., ,. ., ., ., , .. x         x .,., . , ., ., ., , . , ., , . ,,. ,  ,.. , .,, .. ,x         x., , . , ., ,. ,. ,. ,. ,|",
	"+., ., . ,. , ., ., ., ,. x         x., ,. ., ., . ., ., ., . ,, . ,,. ., . , . ,. ,. ,. .x         x,. .,,. ,. ,. ., ., ., . +",
   	"|., ., . ,. , ., ,. ., .,.x         x. ,,  .,,. ., ,. .,, ., ,. ., ., ,. ., , .., ., . ,. x         x., ,. , ,. ., , .,., ., ,|",
	"+., , . ,. , ., ., ,. ., .x         x., , . , ., ,. ,. ., ,.., , .,  ,.,  ,.,. ,. ,. ., . x         x ,.,. . , ., ,. ., . , .,+",
   	"|. ,.,  ., ., ., ., ., ., x         x., ,. . , , .,,. ., ,.., ., ., ., ., ., ., ., ., ,. ,x         x., ,. . , ., , .,  , ,. ,|",
	"+. ,. , ., ., ., ., . , . x         x ., ., ,. ., ., ., ., .,. , .,. ., ., ., . ,., , .., x         x,. ,. ,. ., ,. ., , ., , +",
   	"|., ,. ,. ,. . . , ., ... x         x. ,., ., ., ., . , ., ., ., ., ., ., ., ., ,. ., ., .x         x., ,. ,. ,. ,. ,. ,. ,. ,|",
	"+., ,. ., ., ., . , ., ., x         x,. ., ,. ,. ,. ,. ., ,., . , . ,.. , ,.. , ,.. , ., .x         x,. . ., . , ., , ., ,. . +",
   	"|., ., , ., , . , ,. .,. ,x         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         x, . , . , ,.  ,., . ., . |",
	"+., , . , ., ,. ,. ,. ., ,x                                                                         x., ,. ., ,. , . ,. . ,. .+",
   	"|., ,. , . , ., ,. ,. ,. ,x                                                                         x., ,. ., ,. . , ., ., ,. |",
	"+., ,.  ., ., ., ., ., ., x                                                                         x, ., ., ., ., ., ., ,. ,.+",
   	"|., ., ., . , ., ., ., . ,xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ., ., ,. ,. ,. ., ,. ,. |",
	"+ ., ,. ., ,. ., ., ,. ,. ,. ., ,. ,. ,. ., . , . , ., ., .,., ., ., ., ,. ., ,. ., ., ., . ,. ., ,. ., ,. ,. , ,.. , ,.. ,,. +",
    "|. ., ., .. , . ,. ., ,. ,. ,. ., ., , ., , ,. ,. ,.  ., ., . , , ., ., ., . ,., . ,.,  ., . ., ., ,. ,. ,. ,. ., . ,. ,. ,, .|", 
    "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
};

//--------------------------------------------------------------------
void printMap()
{
	for(int rows=0;rows <= ROWS  ;rows++)
	{
		for (int columns=0;columns < COLUMNS;columns++)
		{   
            if( MAP[rows][columns] == '+' || MAP[rows][columns] == '-' || MAP[rows][columns] == '|' )
                cout << ChangeToBlue();   
            else if( MAP[rows][columns] == '#' || MAP[rows][columns] == 'x' )
                cout << ChangeToWhite();
            else if( MAP[rows][columns] == '0' )
                cout << ChangeToLightPurple();
            else if( MAP[rows][columns] == '.' || MAP[rows][columns] == ',' )
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




