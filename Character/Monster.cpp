/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to create the monster class as
 * described by Monster.hpp
 * ***************************************************************************/
#include "Monster.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

/**************************************
 * Default constructor that sets the
 * value for the monster obj
 * ***********************************/
Monster::Monster() : Character()
{
	strength = 25;
	secondLife = false;
	type = 2;
	typeName = "Funayurei";
}
/**************************************
 * Attack dice roll will set the attack
 * dice roll and set the attack for 
 * monster obj
 * ***********************************/
int Monster::attack()
{
	int sum = 0;
	int rollOne, rollTwo = 0;

	rollOne = rand() % 8 + 1;
	rollTwo = rand() % 8 + 1;

	sum = rollOne + rollTwo;

	return sum;
}

//Set and get functions for monster class
int Monster::getStrength()
{
	return this->strength;
}

void Monster::setStrength(int change)
{
	strength = strength - change;
}

void Monster::resetStrength()
{
}
