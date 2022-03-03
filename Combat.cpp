#include "glue.h"
#include <iostream>
using namespace std;
//Currently has logic for player's turn, needs monster turn
void Combat_Loop(Hero &player,Monster enemy){
    bool chosen = false;
    int command = -1;
    int calculation = 0;
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
        //Player move
        while(!chosen){
            cout << "HP: " << player.Get_tmp_hp() << " MP: " << player.Get_tmp_mp() << endl;
            cout << "Choose a move: \n";
            for(int i = 0; i <= player.Get_Skill_Count(); i++){
                cout << i << " " << player.Get_Target_Skill(i).Get_Name() << endl;
            }
            cin >> command;
            if(command <= player.Get_Skill_Count() && command >= 0){
                if(player.Get_Target_Skill(command).Get_Type() == 0)
                {
                    cout << player.Get_Name()<<" "<<player.Get_Target_Skill(command).Get_Flavor() << endl;
                    calculation = player.Get_Attack()*player.Get_Target_Skill(command).Get_Modifier()-enemy.Get_Defense();
                    cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                    enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                    chosen = true;
                }
                else if(player.Get_Target_Skill(command).Get_Type() == 1){
                    if(player.Get_tmp_mp() >= player.Get_Target_Skill(command).Get_Cost()){
                        cout << player.Get_Name()<<" "<<player.Get_Target_Skill(command).Get_Flavor() << endl;
                        calculation = player.Get_Attack()*player.Get_Target_Skill(command).Get_Modifier()-enemy.Get_Defense();
                        cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                        enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                        player.Set_tmp_mp(player.Get_tmp_mp()-player.Get_Target_Skill(command).Get_Cost());
                        chosen = true;
                    }
                    else{
                        cout << "Not enough MP" << endl;
                    }
                }
                else if(player.Get_Target_Skill(command).Get_Type() == 2){
                    if(player.Get_tmp_mp() >= player.Get_Target_Skill(command).Get_Cost() && player.Get_tmp_hp() != player.Get_HP()){
                        cout << player.Get_Name() << " " << player.Get_Target_Skill(command).Get_Flavor()<< "\n" << player.Get_Target_Skill(command).Get_Modifier() << "HP recovered!";
                        player.Set_tmp_hp(player.Get_tmp_hp() + player.Get_Target_Skill(command).Get_Modifier());
                        if(player.Get_tmp_hp() > player.Get_HP()){
                            player.Set_tmp_hp(player.Get_HP());
                        }
                        chosen = true;
                    }
                    else if(player.Get_tmp_mp() <= player.Get_Target_Skill(command).Get_Cost()){
                        cout << "Not enough MP" << endl;
                    }
                    else{
                        cout << "Hp is full" << endl;
                    }
                }
            }
            else{
                cout << "Incorrect selection" << endl;
            }
        }
        //Monster Move
    }
    cout << enemy.Get_Name() << " has felled the " << enemy.Get_Name() << "!" << endl;
}