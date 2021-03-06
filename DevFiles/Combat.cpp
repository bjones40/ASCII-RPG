#include "glue.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
Item taco = Item("Taco",1,1,0);

Monster Monster_Table[10][5] = {{Monster("slime",1,1,1,50,100,1,taco),Monster("slime2",1,1,1,50,100,1,taco)}};
Monster Rare_Monster_Table[10];
Monster Boss_Monster_Table[10];

Skill Levelup_Skills[10] = {Skill(),Skill(),Skill("Throw Rock","picks up a small rock and hurls it, it's apparently very effective.",2,10,magic_attack),
Skill(),Skill("Dia","using their inner calories, heals their wounds a bit",3,15,healing),Skill(),Skill(),Skill(),Skill(),Skill()};

//Usable on overworld to call up a monster to pass to the combat screen, use the enums to specify "table" in call!
Monster Parse_Monster_Tables(Hero player,int table){
    srand(time(NULL));
    Monster output;
    int choice = 0;
    int location = player.Get_Current_Map();
    switch(table){
        case normal_enemy:
            choice = rand()% 2;
            output = Monster_Table[location][choice];
            break;
        case rare_enemy:
            output = Rare_Monster_Table[location];
            break;
        case boss:
            output = Boss_Monster_Table[location];             
            break;
    }
    return output;
}
void Level_Up(Hero & player){
    if(player.Get_Exp() >= floor(10*(pow(player.Get_Level(),1.5)))){
        string skillget = "";
        int HPUP = rand() % 2 + 3;
        int MPUP = rand() % 2 + 3;
        int AttackUP = rand() % 3+1;
        player.Set_Level(player.Get_Level() + 1);
        player.Set_HP(player.Get_HP()+HPUP);
        player.Set_MP(player.Get_MP()+MPUP);
        player.Set_Attack(player.Get_Attack()+AttackUP);
        player.Set_Defense(player.Get_Defense()+1);
        if(Levelup_Skills[player.Get_Level()].Get_Name() != "Null"){
            player.Gain_Skill(Levelup_Skills[player.Get_Level()]);
            skillget = "\n"+player.Get_Name()+" learns: "+Levelup_Skills[player.Get_Level()].Get_Name()+"\n";
        }
        string level_up_text = "LEVEL UP!\n"+player.Get_Name()+" has obtained level "+to_string(player.Get_Level())+" and gains:\nHP: "
        +to_string(HPUP)+"\nMP: "+to_string(MPUP)+"\nAttack: "+to_string(AttackUP)+"\nDef: 1"+skillget+"\nHP/MP restored.\n";
        player.Set_tmp_hp(player.Get_HP());
        player.Set_tmp_mp(player.Get_MP());
        //cout << level_up_text;
    }
}
void Rewards(Hero & player,Monster & enemy){
    player.Set_Gold_Count(player.Get_Gold_Count() + enemy.Get_Gold());
    player.Set_Exp(player.Get_Exp() + enemy.Get_Exp_Drop());
    string reward_string = player.Get_Name() +" receives:\n"+to_string(enemy.Get_Exp_Drop())+"exp\n"+to_string(enemy.Get_Gold())+"gold\n";
    //cout << player.Get_Name() <<" receives:\n"<<to_string(enemy.Get_Exp_Drop())<<"exp\n"<<to_string(enemy.Get_Gold())<<"gold\n";
    if((rand() % 100) == 0){
        player.Gain_Item(enemy.Get_Drop());
        reward_string += player.Get_Name()+"found a: "+enemy.Get_Drop().Get_Name();
    }
    Level_Up(player);
    //impliment random chance for item drops
}
void Combat_Loop(Hero &player,Monster enemy){
    //Flags and utility data declarations
    srand(time(NULL));
    bool chosen = false;
    bool proper_input = false;
    int command = -1;
    int calculation = 0;
    int move = 0;
    string player_move = "";
    string monster_move = "";
    string move_menu = "";

    //Test skills
    // Item taco = Item("taco",10,1,0);
    // Item tacosword = Item("tacosword",10,534543,1);
    // Skill fireball = Skill("Fireball","You shoot a fireball",1,1.2,1);
    // Skill heal = Skill("Heal","wounds begin to close",2,5,2);
    // Skill bullshit = Skill("Diarahan"," is a cheating jerk.",0,enemy.Get_HP(),2);
    // Skill ded = Skill("Murderodyne"," blows you to pieces.",0,1000000,1);
    // player.Gain_Item(taco);
    // player.Gain_Item(tacosword);
    // player.Gain_Skill(fireball);
    // player.Gain_Skill(heal);
    // enemy.Gain_Skill(bullshit);
    // enemy.Gain_Skill(ded);

    player_move = enemy.Get_Name() + " draws near!\n";
    //cout << enemy.Get_Name() << " draws near!"  << endl;
    while(player.Get_tmp_hp() > 0 && enemy.Get_tmp_hp() > 0){
        chosen = false;
        //Player move <all cut out //player_move strings are for n-curses implimentation later
        while(!chosen){
            //Reject all but ints, can change later depending on n-curses menu design
            while(!proper_input){
                player_move = "HP: "+to_string(player.Get_tmp_hp())+" MP: "+to_string(player.Get_tmp_mp())+"\n";
                //cout << "HP: " << player.Get_tmp_hp() << " MP: " << player.Get_tmp_mp() << endl;
                player_move = "Choose a move: \n";
                //cout << "Choose a move: \n";

                //Show all skills, add item skill to end for inventory?
                for(int i = 0; i < player.Get_Skill_Count(); i++){
                    move_menu = to_string(i)+ " " + player.Get_Target_Skill(i).Get_Name() + "\n";
                    //cout << i << " " << player.Get_Target_Skill(i).Get_Name() << endl;
                }

                cin >> command;
                if(!cin){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    //cout << "Improper input, numbers only.\n";
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
                        player_move = player.Get_Name()+" "+choice.Get_Flavor()+"\n";
                        //cout << player.Get_Name()<<" "<<choice.Get_Flavor() << endl;
                        calculation = max(int(player.Get_Attack()*choice.Get_Modifier()-enemy.Get_Defense()),0);
                        player_move = enemy.Get_Name()+ " receives "+to_string(calculation)+" damage!\n";
                        //cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                        enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                        chosen = true;
                        break;
                
                    case magic_attack:
                        if(player.Get_tmp_mp() >= choice.Get_Cost()){
                            player_move = player.Get_Name()+" "+choice.Get_Flavor()+"\n";
                            //cout << player.Get_Name()<<" "<<choice.Get_Flavor() << endl;
                            calculation = player.Get_Attack()*choice.Get_Modifier()-enemy.Get_Defense();
                            player_move = enemy.Get_Name()+" receives "+to_string(calculation)+" damage!\n";
                            //cout << enemy.Get_Name() << " receives " << calculation << " damage!" << endl;
                            enemy.Set_tmp_hp(enemy.Get_tmp_hp() - calculation);
                            player.Set_tmp_mp(player.Get_tmp_mp()-choice.Get_Cost());
                            chosen = true;
                        }
                        else{
                            player_move = "Not enough MP\n";
                            //cout << "Not enough MP" << endl;
                        }
                        break;
                
                    case healing:
                        if(player.Get_tmp_mp() >= choice.Get_Cost() && player.Get_tmp_hp() != player.Get_HP()){ 
                            calculation = min((player.Get_HP()-player.Get_tmp_hp()),int(choice.Get_Modifier()));
                            player_move = player.Get_Name()+" "+choice.Get_Flavor()+"\n"+to_string(calculation)+"HP recovered!\n";
                            //cout << player.Get_Name() << " " << choice.Get_Flavor()<< "\n" << calculation << "HP recovered!\n";
                            player.Set_tmp_hp(player.Get_tmp_hp()+calculation);
                            chosen = true;
                        }
                        else if(player.Get_tmp_mp() <= choice.Get_Cost()){
                            player_move = "Not enough MP\n";
                            //cout << "Not enough MP" << endl;
                        }
                        else{
                            player_move = "Hp is full\n";
                            //cout << "Hp is full" << endl;
                        }
                        break;                
                }
            }
            else{
                //cout << "Incorrect selection" << endl;
            }
        }
        if(enemy.Get_tmp_hp() > 0){
            move = rand()% enemy.Get_Monster_Skill_Count();
            Skill monster_choice = enemy.Get_Monster_Skill(move);
            switch(monster_choice.Get_Type()){
                case phys_attack:
                    monster_move = enemy.Get_Name() + " " + monster_choice.Get_Flavor() + "\n";
                    //cout << enemy.Get_Name() << " " << monster_choice.Get_Flavor() + "\n";
                    calculation = max(int(enemy.Get_Attack()*monster_choice.Get_Modifier() - player.Get_Defense()),0);
                    monster_move = player.Get_Name() + " receives "+to_string(calculation)+ " damage!\n";
                    //cout << player.Get_Name() << " receives "<<to_string(calculation)<< " damage!\n";
                    player.Set_tmp_hp(player.Get_tmp_hp()-calculation);
                break;
                case magic_attack:
                    monster_move = enemy.Get_Name() + " " + monster_choice.Get_Flavor() + "\n";
                    //cout << enemy.Get_Name() + " " << monster_choice.Get_Flavor() << "\n";
                    monster_move = player.Get_Name() + " receives " + to_string(monster_choice.Get_Modifier())+" damage!\n";
                    //cout << player.Get_Name() << " receives " << to_string(monster_choice.Get_Modifier())<<" damage!\n";
                    player.Set_tmp_hp(player.Get_tmp_hp()-monster_choice.Get_Modifier());
                break;
                case healing:
                    calculation = min((enemy.Get_HP()-enemy.Get_tmp_hp()),int(monster_choice.Get_Modifier()));
                    monster_move = enemy.Get_Name()+" "+monster_choice.Get_Flavor()+"\n"+to_string(calculation)+"HP recovered!\n";
                    //cout << enemy.Get_Name() << " " << monster_choice.Get_Flavor()<< "\n" << calculation << "HP recovered!\n";
                    enemy.Set_tmp_hp(enemy.Get_tmp_hp()+calculation);
                break;
            }
        }
    }
    //Impliment level_up function?
    if(player.Get_tmp_hp() > 0){
        player_move = player.Get_Name() + " has felled the " + enemy.Get_Name() + "!\n";
        //cout << player.Get_Name() << " has felled the " << enemy.Get_Name() << "!" << endl;
        Rewards(player,enemy);
    }
    else{
        player_move = "Thou art dead";
        //cout << "Thou art dead";
    }
}
