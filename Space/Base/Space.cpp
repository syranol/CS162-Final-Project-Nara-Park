//
//  Space.cpp
//  Final Project
//
//  Created by Sean Lo on 3/14/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#include "Space.hpp"
#include <vector>
#include "Character.hpp"
/**************************************************************************************************
 * Description: Default constructor for space
 * ***********************************************************************************************/
Space::Space()
{
}

//Derived #1 - Deer Park
/**************************************************************************************************
 * Description: everything is implemented in derived cpp/hpp
 * ***********************************************************************************************/
void Space::feed(Character *person, std::vector<bool>&input)//feed the deer - three times to get a golden key
{
}
void Space::getBiscuits(std::vector<bool>&input)     //get food for deer - free, 3 servings;
{
}
void Space::kick(Character *person)    //kick the deer - minus 5 hp
{
}

int Space::deerMenu(Character *person, vector<bool>&input)
{
    return 0;
}
//Derived #2 - ETC
void Space::explore(vector<bool>&input)   //walk around but finds nothing
{
}
int Space::derivedBMenu(Space *locationB, std::vector<bool>&input)
{
    return 0;
}

//Derived #3 - MAIN(The most important one)

void Space::attack(Character *user, Character *enemy)    //Attack function
{
}
void Space::upstair(std::vector<bool>&input) //Upstair
{
}
int Space::dayMenu(std::vector<bool>&input)
{
    return 0;
}
/**************************************************************************************************
 * Description: This function will check user input with given range
 * ***********************************************************************************************/

int Space::intRange(int min, int max, int input)
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
void Space::nightMenu(Character *user, Character *enemyOne,Character *enemyTwo, Character *enemyThree, Character *enemyFour, std::vector<bool>&input)
{
}
//Directional interchanges
/**************************************************************************************************
 * Description: These set the directions for the space poitner to another space pointer and set get name
 * ***********************************************************************************************/
void Space::setUp(Space *label)
{
    this->Directions[0] = label;
}
void Space::setDown(Space *label)
{
    this->Directions[2] = label;
}
void Space::setRight(Space *label)
{
    this->Directions[1] = label;
}
void Space::setLeft(Space *label)
{
    this->Directions[3] = label;
}

std::string Space::getName()
{
    return this->name;
}

void Space::setName(std::string nameInput)
{
    this->name = nameInput;
}


