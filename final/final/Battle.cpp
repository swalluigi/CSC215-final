#include "Battle.h"//includes the battle header
#include <iostream>//includes the iostram library
#include<cstring>//includes the cstring library
#include<string>// includes the string library
#include <stdlib.h>// indcludes the stdlib.h
#include<ctime> // includes the ctime library
using namespace std;//includes the std namespace








hero fight(hero player1, enemy player2) {
    player2.setHobby("why would a mindless enemy in a video game have a hobby"); //initializes the enemy's hobby
   
    int usrin;//integer user input
    bool TurnEnd = false;
    int grappleDmg;// value for grapple damage
    int burnDmg;// value for how much damage you take from the burning status effect
    int mpDrain;//value for how much MP you lose from MP drain
    int savingThrow;//values for freeing yourself from the grapple state
    int EattkRoll;//value for determining what attack the enemy uses
    int critRoll;//values for critical chance
    int StatusRoll;// value for being affected by status effect


    cout << "a " << player2.element << " " << player2.name << " stands in " << player1.name << "'s way" << endl;

    while (player1.health > 0 && player2.health > 0) { //while both creatures are alives
        cout << " " << endl;
        TurnEnd = false;//resets the TurnEnd value to false
        while (TurnEnd == false) {//if the turn is not over. This is the hero's turn
            if (player1.StatusEffect != "Freezing" && player1.StatusEffect != "Grappled") {//if the hero is not freezing or grappled
                cout << "you have " << player1.health << " HP and " << player1.magic << " MP" << endl;
                printf("what do you do? press 1 for a phyical attack, 2 for magic, or press 3 for potions. you could also press 4 to learn the enemy's hobby \n");
                cin >> usrin;//asks player to attack or use magic
                if (usrin == 1) {//if the player chooses to attack
                    cout << "you attack for " << player1.physicalDmg << " damage" << endl;
                    player2.health = player2.health - player1.physicalDmg;//the player deals physical damage to the enemy
                    TurnEnd = true;// end the player's turn
                }
                else if (usrin == 2 && player1.magic >= 0) {// if the player has magic and chooses to use it
                    printf("what will you cast? press 1 for FireBall (8 mp) or 2 for WaterBall (6 mp) \n");
                    cin >> usrin;
                    if (usrin == 1 && player1.magic >= 8) { // if the player has enough magic to use fire ball
                        cout << "you casted FireBall for for 8 MP" << endl;
                        player1.magic = player1.magic - 8;// subtracts 8 from the player's MP

                        if (player2.element == "ice") {// if the enemy element is week to fireball
                            cout << "Critical Hit! " << player2.element << " " << player2.name << " takes " << (player1.MAB1dmg + (player1.MAB1dmg * 0.5)) << " damage!" << endl;
                            player2.health = player2.health - (player1.MAB1dmg + (player1.MAB1dmg * 0.5)); //subtracts the enemy's health by fire ball damage with a critical modifier
                            TurnEnd = true;// end the player's turn
                        }
                        else if (player2.element == "fire") {// if the enemy is the same element type to fireball
                            cout << "you stoked the enemy's flames. They took no damage and are stronger" << endl;
                            player2.physicalDamage = player2.physicalDamage + 3; //increases the enemy's physical damage
                            player2.magicDamage = player2.magicDamage + 3;//increases the enemy's magic damage
                            TurnEnd = true; // end the player's turn
                        }

                        else // if the enemy is neither strong or week against fireball
                        {
                            cout << "the " << player2.element << " " << player2.name << " takes " << player1.MAB1dmg << " damage" << endl;
                            player2.health = player2.health - player1.MAB1dmg;//subtracts the enemy's health by fire ball damage 
                            TurnEnd = true;// end the player's turn
                        }


                    }
                    else if (usrin == 2 && player1.magic >= 6) {//if the player has enough magic to cast waterBall
                        cout << "You cast Water Ball for 6 MP" << endl;
                        player1.magic = player1.magic - 6;//subtracts 6 from the player's MP

                        if (player2.element == "fire") {//if the enemy element is weak to waterBall
                            cout << "Critical Hit! " << player2.element << " " << player2.name << " takes " << (player1.MAB2dmg + (player1.MAB2dmg * 0.5)) << " damage!" << endl;
                            player2.health = player2.health - (player1.MAB2dmg + (player1.MAB2dmg * 0.5));//subtracts the enemy's health by water ball damage with a critical modifier
                            TurnEnd = true;// end the player's turn
                        }

                        else if (player2.element == "ice") { // if the enemy element is strong against waterball
                            cout << "The enemy converts all of the water into ice, strenghthening itself" << endl;
                            player2.physicalDamage = player2.physicalDamage + 3;//increases the enemy's physical damage
                            player2.magicDamage = player2.magicDamage + 3;//increases the enemy's magic damage
                            TurnEnd = true; // end the player's turn

                        }

                        else // if the enemy is neither strong or week against waterball
                        {
                            cout << "the " << player2.element << " " << player2.name << " takes " << player1.MAB2dmg << " damage" << endl;
                            player2.health = player2.health - player1.MAB2dmg; //subtracts the enemy's health by water ball damage
                            TurnEnd = true; // end the player's turn
                        }

                    }
                    else {// if the hero doesn't have enough MP
                        cout << "not enough MP" << endl;
                    }

                }
                else if (usrin == 3) { // if hte player wants to use potions
                    cout << "you have " << player1.HealthPotion << " Health potions and " << player1.MagicPotion << " magic potions" << endl;
                    cout << "press 1 to use a health potion or 2 to use a magic potion " << endl;
                    cin >> usrin;
                    if (usrin == 1 && player1.HealthPotion > 0) {// if you want to use a health potion and you have any available
                        cout << "you chugged down the health potion and feel your life force returning" << endl;
                        player1.health = player1.maxHP;//fully restore player HP
                        player1.HealthPotion = player1.HealthPotion - 1;// remove one HP potion
                        TurnEnd = true;// end the player's turn
                    }
                    else if (usrin == 1 && player1.HealthPotion <= 0) {// if you want to use a health potion and have none left
                        cout << "you are out of potions" << endl;
                    }
                    else if (usrin == 2 && player1.MagicPotion > 0) {// if you want to use a magic potion and you have any available
                        cout << "you downed the magic potion and feel your energy returning" << endl;
                        player1.magic = player1.maxMP;//fully restor the player's MP
                        player1.MagicPotion = player1.MagicPotion - 1;//remove one MP potion
                        TurnEnd = true;//end the player's turn
                    }
                    else if (usrin == 2 && player1.MagicPotion <= 0) {// if you want to use a magic potion and have none left
                        cout << "you are out of potions" << endl;
                    }
                }
                else if (usrin == 4) { // if the user wants to get the enemy's hobby
                    cout << player2.gethobby() << endl;
                }
                else if (usrin == 2 && player1.magic >= 0) {// if you try to use magic with no MP
                    cout << "you have no mana. Try using a physical attack" << endl;
                }

            }

            else if (player1.StatusEffect == "Grappled") { // if the player is grappled by a slime
                cout << "You struggle to free yourself from the slime's grip and ";
                savingThrow = rand() % 2;
                if (savingThrow == 2|| savingThrow == 1) {// if the player succeeds in escaping the slime
                    cout << "you succeed" << endl;
                    player1.StatusEffect = "none";
                }
                else {// if the player fails in escaping the slime
                    grappleDmg = player2.physicalDamage + rand() % 3;// adds a random number between 0 and 3 to the enemy's physical damage
                    cout << "you fail and take " << grappleDmg << " damage" << endl;
                    player1.health = player1.health - grappleDmg; //subtracts teh player's health by the grappleDmg value
                    TurnEnd = true;// end the player's turn

                }
            }
            else if (player1.StatusEffect == "Freezing") {//if the player is frozen
                cout << "your so cold that you cant move!" << endl;
                TurnEnd = true;// end the player's turn
                player1.StatusEffect = "none";//resets player's status
            }
            if (player1.StatusEffect == "Burning") {// if the player is burning
                burnDmg = player2.BurnDamage + (rand() % 5);//adds a random number between 0 and 5 to the burn damage value
                cout << "you took " << burnDmg << " burn damage!" << endl;
                player1.health = player1.health - burnDmg;//subtract the player's health by teh burnDmg value
                player1.StatusEffect = "none";//resets player's status
            }

            if (player1.StatusEffect == "MP Drain") {// if the player is under the MP Drain effect
                mpDrain = 3 + rand() % 3;
                cout << "you lost " << mpDrain << " MP!" << endl;
                player1.magic = player1.magic - mpDrain;//subtracts the player's MP by the mpDrain value
                player1.StatusEffect = "none";//resets player's status
            }
        }
        TurnEnd = false;//sets the turn end to false to start the enemy's turn

        if (player2.health > 0) {// if player2's health is above 0
            while (TurnEnd == false) {//while the turn is not over. this is the enemy's turn
                EattkRoll = rand() % 5 + 1; //picks a random number between 1 and 5
                if (EattkRoll == 4) {// attack with the elemental ability
                    if (player2.elementalAbility == "Freeze") { // if the enemy is an Ice elemental
                        cout << "the enemy attacks you with ice magic" << endl;
                        player1.health = player1.health - player2.magicDamage; //subtracts the player's health by the enemy's magic damage
                        cout << "you take " << player2.magicDamage << " damage";
                        StatusRoll = rand() % 2 + 1; //picks a number between 1 and 2, determining if the status is applied
                        if (StatusRoll == 2) {//if the status is applied
                            player1.StatusEffect = "Freezing"; //applys the "Freezing" effect
                            cout << "...and you're frozen" << endl;
                            TurnEnd = true; // end the enemy's turn
                        }
                        else {
                            cout << endl;
                            TurnEnd = true;// end the enemy's turn
                        }

                    }
                    else if (player2.elementalAbility == "Burn") {// if the enemy is a fire elemental
                        cout << "the enemy attacks you with fire magic" << endl;
                        player1.health = player1.health - player2.magicDamage; //subtracts the player's health by the enemy's magic damage
                        cout << "you take " << player2.magicDamage << " damage";
                        StatusRoll = rand() % 2 + 1; //picks a number between 1 and 2, determining if the status is applied
                        if (StatusRoll == 2) {//if the status is applied
                            player1.StatusEffect = "Burning";//applys the "Burning" effect
                            cout << "...and you're buring" << endl;
                            TurnEnd = true;// end the enemy's turn
                        }
                        else {
                            cout << endl;
                            TurnEnd = true;// end the enemy's turn

                        }
                    }
                    else {// if there is no elemental ability
                        cout << "the enemy uses a physical attack and deals " << player2.physicalDamage << " damage!" << endl;
                        player1.health = player1.health - player2.physicalDamage; // subtracts the player's health by the enemy's physical damage
                        TurnEnd = true;// end the enemy's turn

                    }
                }

                else if (EattkRoll == 5) {// if the monster rolls a 5, it can use it's ability
                    cout << "the enemy uses the " << player2.monsterAbility << " ability" << endl;
                    if (player2.monsterAbility == "Grapple") {// if the monster has the grapple ability
                        cout << "the " << player2.element << " slime jumps at you and grabs a hold of you, dealing " << player2.physicalDamage << " damage! You are now grappled" << endl;
                        player1.health = player1.health - player2.physicalDamage;// subtracts the player's health by the enemy's physical damage
                        player1.StatusEffect = "Grappled";
                        TurnEnd = true;// end the enemy's turn

                    }
                    else if (player2.monsterAbility == "MP Drain") {// if the monster has the mp drain ability
                        cout << "the " << player2.name << " casts a spell and you feel your energy draining" << endl;
                        player1.StatusEffect = "MP Drain";//applys the "MP Drain" Status Effect
                        TurnEnd = true;// end the enemy's turn


                    }
                    else if (player2.monsterAbility == "Weaken") {// if the monster has the weaken ability
                        cout << "the " << player2.name << " gives you a death stare and you suddenly feel weak. Your physical damage has been reduced" << endl;
                        player1.physicalDmg = player1.physicalDmg - (player1.physicalDmg * 0.3); // weakens the player's physical attack by 3%
                        TurnEnd = true;// end the enemy's turn
                    }

                    else {// if there is no monster ability
                        cout << "the enemy uses a physical attack and deals " << player2.physicalDamage << " damage!" << endl;
                        player1.health = player1.health - player2.physicalDamage;// subtracts the player's health by the enemy's physical damage
                        TurnEnd = true;// end the enemy's turn
                    }



                }
                else {// any other roll and the monster uses a physical attack
                    cout << "the enemy uses a physical attack and deals " << player2.physicalDamage << " damage!" << endl;
                    player1.health = player1.health - player2.physicalDamage;// subtracts the player's health by the enemy's physical damage
                    TurnEnd = true;// end the enemy's turn
                }




            }

        }
        else {
            cout << player2.element << " " << player2.name << " has been defeated" << endl;
        }
        



    }
    return player1;
}
    