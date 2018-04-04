//
//  SideMap.cpp
//  Final Project
//
//  Created by Sean Lo on 3/17/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#include "SideMap.hpp"

#include "Space.hpp"
#include <vector>
#include "Game.hpp"

using namespace std;

/**************************************************************************************
 *Description: Default Constructor
 **************************************************************************************/
SideMap::SideMap() : Space()
{

}
/**************************************************************************************
 *Description: Explore the map but finds nothing
 **************************************************************************************/
void SideMap::explore(vector<bool>&input)
{
    if(input[2] == false)
    {
        input[2] = true;
        cout << "You found a potion!" << endl;
    }
    else if(input[3] == false)
    {
        input[3] = true;
        cout << "You found a potion!" << endl;
    }
    else if(input[4] == false)
    {
        input[4] = true;
        cout << "You found a potion!" << endl;
    }
    else
    {
        cout << "You don't have anymore spaces for potions!" << endl;
    }
}
/**************************************************************************************************
 * Description: Menu for all the sidemap class cpp files and run them as needed
 
 * ***********************************************************************************************/
int SideMap::derivedBMenu(Space *locationB, std::vector<bool>&input)
{
    cout << "You are now at " << locationB->getName() << endl;
    
    if(locationB->getName()== "Kasuga-taisha")
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Kasuga-taisha also known as Kasuga Grand Shrine is shrine established in 768 CE of the Fujiwara family" << endl;
        cout << "*Looking around, you see a bunch of bronze lanterns, as well as many stone lanterns as well!*" << endl;

        
    }
    else if(locationB->getName() == "Kofu-ji")
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Kofuku-ji is a Buddhist temple that was once one of the powerful Seven Great Temples!" << endl;
        cout << "it is reknown by it's Architectural design as well as it's numerous treasures." << endl;
  
        
    }
    else if(locationB->getName() == "Nara National Museum New Wing")
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "It's not very interesting, just an extension of the Nara National Museum" << endl;

    }
    else
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Nara National Museum or Nara Kokuritsu Hakubutsukan is one of the promiment national art museums in Japan!" << endl;
        cout << "The museum is noted for its collection of Buddhist art. Established in 1889, the museum was first established as an imperitial museum for the royal family." << endl;

    }
    
    int choice;
    bool isOver = false;
    
    while(isOver != true)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Explore the shrine." << endl;
        cout << "2. Move to another map." << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cin >> choice;
        choice = intRange(1,2,choice);
        
        if(choice == 1)
        {
            explore(input);
        }
        else if(choice == 2)
        {
            int mapChoice = 0;
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Which directions would you like to go?" << endl;
            
            cout <<"1. ";
            
            if(locationB->getName()== "Kasuga-taisha")
            {
                cout << "Left";
            }
            else if(locationB->getName() == "Kofu-ji")
            {
                cout << "Up";
            }
            else
            {

                cout << "Right";
            }
            if(locationB->getName() == "Nara National Museum New Wing")
            {
                cout << "    - Nara Natioanl Museum" << endl;
            }
            else
            {
                cout << "    - Deer Park" << endl;
            }
            
            if(locationB->getName() == "Nara National Museum")
            {
                   cout << "2. Left     - Nara Natioanl Museum New Wings" << endl;
                
            }
            cin >> mapChoice;
            mapChoice = intRange(1, 2, mapChoice);
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            if(locationB->getName() == "Nara National Museum New Wing" && mapChoice == 1)
            {
                return 3;
            }
            else if(mapChoice == 1)
            {
                return 42;
            }
            else
            {
                return 38;
            }
        }
    }
    return 0;
}
