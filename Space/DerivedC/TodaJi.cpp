//
//  TodaJi.cpp
//  Final Project
//
//  Created by Sean Lo on 3/17/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#include "TodaJi.hpp"
#include "Space.hpp"
#include <vector>
#include "Game.hpp"

using namespace std;

/**************************************************************************************
 *Description: Default Constructor for Derived C
 **************************************************************************************/
TodaJi::TodaJi() : Space() // Default Constructor
{
    name = "Toda-ji";
    potionCounter = 0;
}

/**************************************************************************************
 *Description: Attack function takes in user, a monster. In order for the user to win,
 *the user must defeat 5 monsters and a boss. Game.cpp will pass in each monster one by
 one until the game is over. Inside the attack function, user attacks first, then the
 monster attacks. user can then choose to attack again or defend, which runs around and
 heal
 **************************************************************************************/
void TodaJi::attack(Character *user, Character *enemy)
{
    bool stillPlaying = true;
    
    while(stillPlaying == true)
    {
        int battleChoice = 0;
        
        cout << "Your current strength: " << user->getStrength() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Drink potion (" << potionCounter << " left)" << endl;
        
        cin >> battleChoice;
        battleChoice = intRange(1,2,battleChoice);
        
        if(battleChoice == 1)
        {
            int p1Attack, damage = 0;
            
            p1Attack = user->attack();
            damage = p1Attack;
            
            if(damage < 0)
            {
                damage = 0;
            }
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Swish! You dealt " << damage << "!" << endl;
            enemy->setStrength(damage);
            enemy->resetStrength();
            
            cout << "Enemy currently have " << enemy->getStrength() << endl;
            
            bool keepGoing = true;
            
            if(enemy->getStrength() < 1)
            {
                cout << enemy->getTypeName() << " has been defeated." << endl;
                
                stillPlaying = false;
                keepGoing = false;
            }
            if(keepGoing == true)
            {
                int p2Attack, damage = 0;
                
                p2Attack = enemy->attack();
                damage = p2Attack;
                
                if(damage < 0)
                {
                    damage = 0;
                }
               cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Ahh, the enemy dealt " << damage << "!" << endl;
                user->setStrength(damage);
        
                if(user->getStrength() < 1)
                {
                    cout << endl << "With a violent shake, you opened your eyes." << endl;
                    cout << "*Looking around, you realized you are in your own bed*" << endl;
                    cout << "*You look at the alarm clock and noticed that it's one o'clock in the afternoon*" << endl;
                    cout << "\"It's so dark out!\" You said, bewildered." << endl;
                    cout << "*You wonder to yourself...if perhaps all of this wasn't just a dream!?" << endl;
                    
                    cout << "GAME OVER : YOU LOSE" << endl;
                    
                    exit(0);
                }
            }
        }
        else
        {
            if(potionCounter < 1)
            {
                cout << "You don't have any potions left" << endl;
            }
            else
            {
                user->resetStrength();
                potionCounter = potionCounter - 1;
            }
        }
    }
}

/**************************************************************************************
 *Description: GO upstair, and if the user have a key, then receive sword
 **************************************************************************************/
void TodaJi::upstair(std::vector<bool>&input)
{
    cout << "*The staircase creaks as you walk up*" << endl;

    if(input[1] == true)
    {
        input[5] = true;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Laying in the corner of the second floor is a chest..." << endl;
        cout << "*The thick layer of dust seems to indicate that it hasn't been walked on for years...if not decades." << endl;
        cout << "*The whisper seems to be getting louder... it is almost if the chest is calling... to me?" << endl;
        
        cout << "*And of course, it would be locked... But then you remembered!"<< endl;
        cout << "You reach into your pocket and took out the golden key the deer gave you earlier." << endl;
        cout << "*You insert the golden key and twisted*" << endl;
        
        cout << "And it worked....!!!??" << endl;
        cout <<"With a shaking hand... you open the golden box." << endl;
        cout <<"Inside it, you find a sword.... a sword unlike any other." << endl;
        cout <<"You reached out and took the sword" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}
/**************************************************************************************************
 * Description: This is the battle menu that sets the user into battle/last act of the game
 *calls the attakc and ehal function dirtectly through here
 * ***********************************************************************************************/
void TodaJi::nightMenu(Character *user, Character *enemyOne,Character *enemyTwo, Character *enemyThree, Character *enemyFour, std::vector<bool>&input)
{
    if(input[2] == true)
    {
        potionCounter = potionCounter + 1;
    }
    if(input[3] == true)
    {
        potionCounter = potionCounter + 1;
    }
    if(input[4] == true)
    {
        potionCounter = potionCounter + 1;
    }
    
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " \"WHAT IS GOING ON?\" You screamed as you walked out the temple." << endl;
    cout << "Suddenly the sky was dark and an omnious vibration can be felt through the very fabric of time." << endl;
    cout << "*A crack suddenly begins to grow in the middle of the courtyard, and suddenly a giant head begins to float out the crack." << endl;
    cout << "*Suddenly the sky begin to rain, and within seconds, the sound of crashing thunder vibrated through your eardrums" << endl;
    cout << "*lightning strikes everywhere around you*" << endl;
    cout << "\" YOU! \" A thundering voice brought your attention back to the crack, and there stood a giant man... But he's much bigger and scarier." << endl;
    cout << " \"I AM SUSANOO, GOD OF THE OCEAN AND STORM. I BELIEVE YOU HAVE SOMETHING OF MINE. \" " << endl;
    cout << " \"I DON'T UNDERSTAND....\" You screamed in the pouring rain with your leg shaking..." << endl << endl;
    cout << "\" YOUR SWORD! ITS NAME IS KUSANAGI-NO-TSURRUGI. AND IT BELONGS TO ME!" << endl << endl;
    
    cout << "*Amaterasu whispers to you* \"No champion, that sword was won by me when i defeated my brother in the battle when he ambushed me. It holds special power. It is made of virtue and courage of the all the ones that comes before you. It have the power to control the wind. Use it to defeat my brother and banish him back to the ocean! \n " << endl;
    
    cout << " \" NO IT BELONGS TO AMATERASU AND I AM GOING TO USE IT TO DEFEAT YOU \" " << endl;
    cout << " \n Fine then so be it!" << endl;
    
    cout << "*Emerging from the fountain comes crawling out three Funayurei, ghosts of victims drawn in sea*" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    attack(user,enemyOne);
    cout << "1 died" << endl;
    attack(user, enemyTwo);
    cout << "2nd died" << endl;
    attack(user,enemyThree);
    cout << "3rd died" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n FINE ILL DEAL WITH YOU MYSELF\n " << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    attack(user,enemyFour);
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\"AHH... HOW COULD YOU..IMPOSSIBLE \" Susanoo screams" << endl;
    cout << "*You lift the sword, andr drew a large circle above your head and directed it towards the ocean*" << endl;
    cout << " \"Back to where you belong! \" You yelled. " << endl;
    
    cout << "Suddenly the sun reappears in the sky. Decending from above... was a woman who seems to be glowing..." << endl;
    cout << "*With a big smile on her face* \"Thank you champion... you have freed me and defeated my brother. I thank you. " << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "GAME OVER. YOU WIN!" << endl;
    
    exit(1);

    
}


/**************************************************************************************************
 * Description: Regular day menu for when sword hasnt been found
 * ***********************************************************************************************/
int TodaJi::dayMenu(std::vector<bool>&input)
{
    cout << "You are now at Todai-ji" << endl;
    
    int choice;
    bool isOver = false;
    
    while(isOver != true)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Explore the temple." << endl;
        cout << "2. Move to another map." << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cin >> choice;
        choice = intRange(1,2,choice);
        
        if(choice == 1)
        {
            bool isSOver = false;
            while(isSOver != true)
            {
                int iChoice = 0;
                cout << "You walk inside the courtyard of Toda-Ji" << endl;
                cout << "While Toda-ji is now a Buddhist temple complex, it was once of the Seven Great Temples." << endl;
                cout << "Legend has it that it was once Amaterasu, the sun godddess's temple. It is believe that she still show herself aroudn to the worth once in a thousand years." << endl;
            
                if(input[1] == true && input[5] == false)
                {
                    cout << " \"Come find me... \" "  << endl;
                    cout << " *The whisper gets louder" << endl;
                }
                cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "What would you like to do?" << endl;
                cout << "1. Explore the temple" << endl;
                cout << "2. Leave the temple" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
                if(input[1] == true && input[5] == false)
                {
                    cout << "3. Go upstairs" << endl;
                }
                
                cin >> iChoice;
                
                if(input[1] == true)
                {
                    iChoice = intRange(1,3,iChoice);
                }
                else
                {
                    iChoice = intRange(1,2,iChoice);
                }
                
                if(iChoice == 1)    //Explore
                {
                    cout << "As you walk inside the temple, you find a giant bronze buddist temple staring right back at you. " << endl;
                }
                else if(iChoice == 2 && input[5] == false)   //Leave the temple
                {
                    isSOver = true;
                }
                else if(iChoice == 2 && input[5] == true)
                {
                    return 444;
                }
                else            //GoUpStair
                {
                    upstair(input);
                    cout << "As you walk down the stairs... you look back..." << endl;
                    cout << "!!!!!" << endl;
                    cout << "The staircase has disappeared!?" << endl;
                }
            }
                
        }
        else
        {
            int mapChoice = 0;
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Which directions would you like to go?" << endl;
            cout << "1. Down    - Deer Park" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            cin >> mapChoice;
            mapChoice = intRange(1, 1, mapChoice);
            
            if(mapChoice == 1)
            {
                return 42;
            }
            isOver = true;
        }
    }
    return 0;
}
    
