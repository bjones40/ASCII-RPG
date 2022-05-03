#include <iostream>
#include "glue.h"
using namespace std;

int main() {
    string test = "Hello Friend\nWelcome to your eternal life of sweet servitude\nBe sure to visit the healing fountain!\n";
    NPC Uther = NPC("Uther",0,0,Item("Burrito",key));
    Uther.Add_Dialogue(0,test);
    cout << Uther.Get_Name() << ": " << Uther.Get_Dialogues(0);

    Hero player = Hero("man",1,0,5,5,5,5,0,0,0);
    Monster enemy = Parse_Monster_Tables(player,normal_enemy);
    cout << player.Show_Info()<<endl<<endl;
    Item taco = Item("Taco",1,1,consumable);
    Item burrito = Item("Burrito",2,2,consumable);
    Item sword = Item("Sword",10,10,weapon);
    Item clothing = Item("Clothing",5,5,armor);
    player.Gain_Item(taco);
    player.Gain_Item(burrito);
    player.Gain_Item(sword);
    player.Gain_Item(sword);
    player.Gain_Item(sword);
    player.Gain_Item(burrito);
    player.Gain_Item(clothing);
    Combat_Loop(player,enemy);
    Combat_Loop(player,enemy);
    Combat_Loop(player,enemy);



    // cout << "Inventory Demonstration\n\n";
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";
    // cout << player.Inventory_Menu();
    // cout << player.Use_Item(3);


    // // cout << player.Show_Inventory_Item(0).Get_Name();
    // // cout << player.Show_Inventory_Item(1).Get_Name();
    // // cout << player.Show_Inventory_Item(2).Get_Name();
    //     cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";
    // cout << player.Inventory_Menu()<<endl;
    // player.Gain_Item(burrito);
    // player.Gain_Item(taco);
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";
    // cout << player.Inventory_Menu()<<endl;
    // cout << player.Use_Item(4);
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";

    // cout << player.Inventory_Menu()<<endl;
    // player.Set_tmp_hp(player.Get_HP() -4);
    // cout << player.Use_Item(0);
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";

    // cout << player.Use_Item(2);
    // cout << player.Inventory_Menu()<<endl;
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";

    // cout << player.Inventory_Menu()<<endl;
    // cout << player.Use_Item(0);
    // cout << "inv_count = "<<to_string(player.Get_Inventory_Count())<<"\n";

    // cout << player.Inventory_Menu()<<endl;
 
    // //Monster enemy = Monster("slime",1,1,1,50,100,1,taco);
    // Combat_Loop(player,enemy);
    // cout << player.Show_Info();
    Item store_tester[20] = {burrito,sword};
    player.Set_tmp_hp(2);
    Store s_test("Test Store",Dessert_Desert_Town,"Random Junk!",store_tester);
    player.Set_Gold_Count(0);
    cout << "current gold: " << player.Get_Gold_Count() << "\n\n";
    cout << s_test.Show_Store_Inventory() << endl;
    cout << s_test.Buy_Item(player,0)<< endl;
    cout << "current gold: " <<player.Get_Gold_Count()<< endl;
    cout << player.Inventory_Menu()<< endl;
    cout << s_test.Sell_Item(player,1)<< endl;
    cout << "current gold: " <<player.Get_Gold_Count() << endl << player.Inventory_Menu();
    cout << s_test.Sell_Item(player,0)<< endl;
    cout << "current gold: " <<player.Get_Gold_Count() << endl << player.Inventory_Menu();
    cout << player.Use_Item(0);
    cout << player.Inventory_Menu() << endl;
    return 0;
}