#include "glue.h"
#include <iostream>
#include <algorithm>
using namespace std;
//Currently has logic for player's turn, needs monster turn
void Combat_Loop(Hero &player,Monster enemy){
    //Flags and utility data declarations
    bool chosen = false;
    bool proper_input = false;
    int command = -1;
    int calculation = 0;
    string player_move = "";

    //Test skills
    Item taco = Item("taco",10,1,0);
    Item tacosword = Item("tacosword",10,534543,1);
    Skill fireball = Skill("Fireball","You shoot a fireball",1,1.2,1);
    Skill heal = Skill("Heal","wounds begin to close",2,5,2);
    player.Gain_Item(taco);
    player.Gain_Item(tacosword);
    player.Gain_Skill(fireball);
    player.Gain_Skill(heal);

    while(player.Get_tmp_hp() > 0 && enemy.Get_tmp_hp() > 0){
        chosen = false;
        //Player move <all cut out player_move strings are for n-curses implimentation later
        while(!chosen){
            //Reject all but ints, can change later depending on n-curses menu design
            while(!proper_input){
                //player_move = "HP: "+to_string(player.Get_tmp_hp())+" MP: "+to_string(player.Get_tmp_mp())+"\n";
                cout << "HP: " << player.Get_tmp_hp() << " MP: " << player.Get_tmp_mp() << endl;
                //player_move = "Choose a move: \n";
                cout << "Choose a move: \n";

                //Show all skills, add item skill to end for inventory?
                for(int i = 0; i <= player.Get_Skill_Count(); i++){
                    cout << i << " " << player.Get_Target_Skill(i).Get_Name() << endl;
                }

                cin >> command;
                if(!cin){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    cout << "Improper input, numbers only.\n";
                }
                else{
                    proper_input = true;
                }
            }
            proper_input = false;
            if(command <= player.Get_Skill_Count() && command >= 0){
                Skill & choice = player.Get_Target_Skill(command);
                switch(choice.Get_Type()){
                    case phys_attack:
                        //player_move = player.Get_Name+" "+choice.Get_Flavor()+"\n";
                        cout << player.Get_Name()<<" "<<choice.Get_Flavor() << endl;
                        calculation = player.Get_Attack()*choice.Get_Modifier()-enemy.Get_Defense();
                        //player_move = enemy.Get_Name()+ " receives "+to_string(calculation)+" damage!\n";
                        cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                        enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                        chosen = true;
                        break;
                
                    case magic_attack:
                        if(player.Get_tmp_mp() >= choice.Get_Cost()){
                            //player_move = player.Get_Name()+" "+choice.Get_Flavor()+"\n";
                            cout << player.Get_Name()<<" "<<choice.Get_Flavor() << endl;
                            calculation = player.Get_Attack()*choice.Get_Modifier()-enemy.Get_Defense();
                            //player_move = enemy.Get_Name()+" receives "+to_string(calculation)+" damage!\n";
                            cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                            enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                            player.Set_tmp_mp(player.Get_tmp_mp()-choice.Get_Cost());
                            chosen = true;
                        }
                        else{
                            //player_move = "Not enough MP\n";
                            cout << "Not enough MP" << endl;
                        }
                        break;
                
                    case healing:
                        if(player.Get_tmp_mp() >= choice.Get_Cost() && player.Get_tmp_hp() != player.Get_HP()){ 
                            calculation = min((player.Get_HP()-player.Get_tmp_hp()),int(choice.Get_Modifier()));
                            //player_move = player.Get_Name()+" "+choice.Get_Flavor()+"\n"+to_string(calculation)+"HP recovered!\n";
                            cout << player.Get_Name() << " " << choice.Get_Flavor()<< "\n" << calculation << "HP recovered!\n";
                            player.Set_tmp_hp(player.Get_tmp_hp()+calculation);
                            chosen = true;
                        }
                        else if(player.Get_tmp_mp() <= choice.Get_Cost()){
                            //player_move = "Not enough MP\n";
                            cout << "Not enough MP" << endl;
                        }
                        else{
                            //player_move = "Hp is full\n";
                            cout << "Hp is full" << endl;
                        }
                        break;                
                }
            }
            else{
                cout << "Incorrect selection" << endl;
            }
        }
        //Monster Move, impliment
    }
    //Impliment level_up function?
    cout << player.Get_Name() << " has felled the " << enemy.Get_Name() << "!" << endl;
}