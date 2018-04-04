/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to create the vampire class as 
 * described by Vampire.hpp
 * ***************************************************************************/
#include "Boss.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
/**************************************
 * Description: THis function is the 
 * constructor and sets value for the
 * vampire object
 * ***********************************/
Boss::Boss() : Character()
{
	strength = 60;
	secondLife = true;
	type = 3;
	typeName = "Susanoo";
}
/**************************************
 * Attack function controls the attack
 * dies and set attack value
 * ***********************************/
int Boss::attack()
{
	int sum = 0;
	int rollOne = 0;

	rollOne = rand() % 25 + 1;

	sum = rollOne;
	return sum;
}

/**************************************************************************************************
 * Description:Get and set function for strength
 * ***********************************************************************************************/
int Boss::getStrength()
{
	return this->strength;
}
void Boss::setStrength(int change)
{
	strength = strength - change;
}
/**************************************************************************************************
 * Description: Reset strenth for Boss
 * ***********************************************************************************************/
void Boss::resetStrength()
{
    if(this->secondLife == true && this->strength < 1)
    {
        secondLife = false;
        this->strength = 50;
        cout << "Susanoo summoned the strength of the ocean, regains full health!" << endl;
    }
}
