//
//  DeerPark.cpp
//  Final Project
//
//  Created by Sean Lo on 3/14/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#include "DeerPark.hpp"
#include "Space.hpp"
#include <vector>
#include "Game.hpp"

using namespace std;

DeerPark::DeerPark() : Space()
{
    feedCounter = 0;
    name = "Nara Park";
}
/**************************************************************************************
 *Description: Feed the deer, if feed reaches three times, user receive a key
**************************************************************************************/
void DeerPark::feed(Character *person, vector<bool>&input)
{
    if(input[0] == true)
    {
        if(feedCounter == 2)
        {
            cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "*Deer wagged it's tail and grazed it's nose against you." << endl;
            cout << "Suddenly, you noticed something shiny hovering in the deer's mouth." << endl;
            cout << "*You reach out and grabbed it*" << endl;
            cout << "You found a shiny golden key!" << endl;
 
            feedCounter = feedCounter + 1;
            input[1]= true;  //input[1] = key
        }
        else
        {
            cout << "*Happy deer noise :3*" << endl;
            feedCounter = feedCounter + 1;
        }
    }
    else
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "You don't have any biscuits to feed the deers!" << endl;
       
    }
}
/**************************************************************************************
 *Description: Function give user the food to feed the deers.
 **************************************************************************************/
void DeerPark::getBiscuits(vector<bool>&input)
{
    if(input[0] == true)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "You've already got some biscuits!" << endl;
    
    }
    else
    {
        input[0]= true;    // input[0] = feed/food for deer
        cout << "You got some special biscuits from the vending machine!" << endl;
        //Note to self: if vector<bool>*input, do (*input)[1]= true;
    }
}
/**************************************************************************************
 *Description: Function kicks the deer, minus five health for user.
 **************************************************************************************/
void DeerPark::kick(Character *person)    //kick the deer - minus 5 hp
{
    person->setStrength(5);
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "*angry deer noises*" << endl;
    cout << "*deer rammed you in the head*" << endl;
    cout << "You lost 5 strength, you now have " << person->getStrength() << "." << endl;
    cout << "*Whisper in the air* \"Doing a bamboozle on yourself i see. Jokes on you!\" "  << endl;
 
    if(person->getStrength() < 1)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl << "With a violent shake, you opened your eyes." << endl;
        cout << "*Looking around, you realized you are in your own bed*" << endl;
        cout << "*You look at the alarm clock and noticed that it's one o'clock in the afternoon*" << endl;
        cout << "\"But It's so dark out!\" You said, bewildered." << endl;
        cout << "*You wonder to yourself...if perhaps this wasn't all just a dream!?" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "GAME OVER : YOU LOSE" << endl;
        
        exit(0);
    }
}
/**************************************************************************************************
 * Description: Menu class for deerPark class, also run all of its function etc
 * ***********************************************************************************************/
int DeerPark::deerMenu(Character *person, vector<bool>&input)
{

    int choice;
    bool isOver = false;
    
    while(isOver != true)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Nara Park, located in the foot of Mount Wakakausa was established in 1300s and it is one of the oldest park in Japan." << endl;
        cout << "All these deers roaming around were once regarded as sacred. They are considered as god's messenger in Shinto religion. The legend claims that if you feed the deers with specialty crackers/biscuits, they will eventually return you with good fortune! Also they are hecking adorable" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Feed a deer biscuit." << endl;
        cout << "2. Get biscuits to feed deers." << endl;
        cout << "3. Kick a deer. At your own risk!" << endl;
        cout << "4. Move to another map." << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
        cin >> choice;
        choice = intRange(1,4,choice);

        if(choice == 1)
        {
            feed(person, input);
        }
        else if(choice == 2)
        {
            getBiscuits(input);
        }
        else if(choice == 3)
        {
            kick(person);
        }
        else if(choice == 4)
        {
            int mapChoice = 0;
            
            cout << "Which directions would you like to go?" << endl;
            cout << "1. Up    - Toda-ji" << endl;
            cout << "2. Right - Kasuga-taisha" << endl;
            cout << "3. Left  - Nara Natioanl Museum" << endl;
            cout << "4. Down  - Kofu-ji" << endl;
            
            cin >> mapChoice;
            mapChoice = intRange(1, 4, mapChoice);
            isOver = true;
            if(mapChoice ==  1)
            {
                return 1;
            }
            else if(mapChoice == 2)
            {
                return 2;
            }
            else if(mapChoice == 3)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
        
    }
    return 0;

}
