/*************************************************************************************************
 * Author: Hsang Lo
 * Date: 02/12/2018
 * Description: This will be the crucial main file for the whole project. Not only will it print
 * the menu but will also run the game
 * **********:n*************************************************************************************/
#include "Game.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/**************************************************************************************************
 * Description: PrintMenu will be the main function of this file. For some reason i had trouble
 * making node a by reference value so I had combine my all other files into the same function
 * although i figured out a way around it, i honestly still wants to know how and why i fixed it
 * ***********************************************************************************************/
void Game::printMenu()
{
    int timer = 0;
    timer = 26;
    
    srand(time(NULL));
    
    setUp();
    
    cout << "You have been summoned by Amaterasu, goddess of the sun in your dream!" << endl;
    cout << "Having been ambushed by her brother, Susanoo, Amaterasu has hid away in Amano-Iwato, bringing the sun with her." << endl;
    cout << "Chosen as her champion, you must defeat her brother, Susanoo, and his armies of Funayurei." << endl;
    cout << "Be careful, but be fast! You must rescue her before you wake up!" << endl << endl;
    
    cout << "Amaterasu summoned you with an infinity mirror. Everytime you move to the a different map/space, the mirror cracks just a tad. The mirror can substain a total of 25 cracks before it completely shatters." << endl;
    
    //Insert About being summoned to deer park
    
    CurrentMap = Deer;  //Set initial map to DeerPark
    bool isOver = false;
    
    cout << endl << "WOAH? What was all that?? And where am i? " << endl;
    cout << "*You look around and finds yourself in the middle of Nara National Park in Nara, Japan.*" << endl;
    cout << "*As you crossed the Torii, a traditional Japanese gate symbolizing the mundane to sacred, you see numerous deers running around." << endl << endl;

    while(isOver != true)
    {
        timer = timer - 1;
        cout << "Remaining time " << timer << " seconds" << endl;
        
        if(timer == 0)
        {
            cout << endl << "With a violent shake, you opened your eyes." << endl;
            cout << "*Looking around, you realized you are in your own bed*" << endl;
            cout << "*You look at the alarm clock and noticed that it's one o'clock in the afternoon*" << endl;
            cout << "\"It's so dark out!\" You said, bewildered." << endl;
            cout << "*You wonder to yourself...if perhaps all of this wasn't just a dream!?" << endl;
            
            cout << "GAME OVER : YOU LOSE" << endl;
            
            exit(0);
        }
        int nextMap = 0;
        
        if(CurrentMap == Deer)
        {
            nextMap = Deer->deerMenu(User, items);
            setCurrentMap(nextMap);
        }
        else if(CurrentMap == KasugaTaisha)
        {
            nextMap = KasugaTaisha->derivedBMenu(CurrentMap, items);
            setCurrentMap(nextMap);
        }
        else if(CurrentMap == KofuJi)
        {
            nextMap = KofuJi->derivedBMenu(CurrentMap, items);
            setCurrentMap(nextMap);
        }
        else if(CurrentMap == NaraNP)
        {
            nextMap = NaraNP->derivedBMenu(CurrentMap, items);
            setCurrentMap(nextMap);
        }
        else if(CurrentMap == NaraNPN)
        {
            nextMap = NaraNP->derivedBMenu(CurrentMap, items);
            setCurrentMap(nextMap);
        }
        else if(CurrentMap == Toda)
        {
            if(items[5] == false)
            {
                //Explore Toda-Ji
                nextMap = Toda->dayMenu(items);
                setCurrentMap(nextMap);
            }
            else
            {
                Toda->nightMenu(User,MobOne,MobTwo,MobThree,Susanoo,items);
            }
        }
    }
}
/**************************************************************************************************
 * Description: set the next map the user is going to
 * ***********************************************************************************************/
void Game::setCurrentMap(int dChoice)
{
    if(dChoice == 42)
    {
        CurrentMap = Deer;
    }
    else if(dChoice == 444)
    {
        CurrentMap = Toda;
    }
    else if(dChoice == 38)
    {
        CurrentMap = NaraNPN;
    }
    else if(dChoice == 1)
    {
        CurrentMap = Toda;
    }
    else if(dChoice == 2)
    {
        CurrentMap = KasugaTaisha;
    }
    else if(dChoice == 3)
    {
        CurrentMap = NaraNP;
    }
    else
    {
        CurrentMap = KofuJi;
    }
}
/**************************************************************************************************
 * Description: setUp map information
 * ***********************************************************************************************/
void Game::setUp()
{
    items[0] = false;   //food
    items[1] = false;   //key
    items[2] = false;   //potion #1
    items[3] = false;   //potion #2
    items[4] = false;   //potion #3
    items[5] = false;   //sword
    
    Deer = new DeerPark;
    KasugaTaisha = new SideMap;
    NaraNPN = new SideMap;
    KofuJi = new SideMap;
    NaraNP = new SideMap;
    Toda = new TodaJi;
    
    User = new Player;
    MobOne = new Monster;
    MobTwo = new Monster;
    MobThree = new Monster;
    Susanoo = new Boss;
    
    Deer->setUp(Toda);
    Deer->setDown(KofuJi);
    Deer->setLeft(NaraNP);
    Deer->setRight(KasugaTaisha);
    
    KasugaTaisha->setLeft(Deer);
    
    KasugaTaisha->setRight(nullptr);
    KasugaTaisha->setDown(nullptr);
    KasugaTaisha->setUp(nullptr);
    
    KofuJi->setUp(Deer);
    
    KofuJi->setRight(nullptr);
    KofuJi->setDown(nullptr);
    KofuJi->setLeft(nullptr);
    
    NaraNP->setRight(Deer);
    NaraNP->setLeft(NaraNPN);
    NaraNP->setUp(nullptr);
    NaraNP->setDown(nullptr);
    
    NaraNPN->setRight(NaraNP);
    
    NaraNPN->setUp(nullptr);
    NaraNPN->setDown(nullptr);
    NaraNPN->setLeft(nullptr);
    
    KasugaTaisha->setName("Kasuga-taisha");
    KofuJi->setName("Kofu-ji");
    NaraNPN->setName("Nara National Museum New Wing");
    NaraNP->setName("Nara National Museum");
}
/**************************************************************************************************
 * Description: This function will check user input with given range
 * ***********************************************************************************************/

int Game::intRange(int min, int max, int input)
{
    while(input < min || input > max || cin.fail())
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cin >> input;
    }
    return input;
}
