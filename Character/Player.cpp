/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to create the barbarian class as 
 * described by Player.hpp
 * ***************************************************************************/
#include "Player.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

/**************************************
 * Descripton: Sets the value for Player
 * ***********************************/
Player::Player() : Character()
{
	strength = 80;
	secondLife = false;
	type = 1;
	typeName = "Player";
}

/**************************************
 * Description: Attack function for
 * the Player class
 * ***********************************/
int Player::attack()
{
	int sum = 0;
	int rollOne, rollTwo = 0;

	rollOne = rand() % 10 + 1;
	rollTwo = rand() % 10 + 1;

	sum = rollOne + rollTwo;
	return sum;
}
/**************************************
 * Description: The function will ret-
 * urn the strength of Player obj
 * ***********************************/
int Player::getStrength()
{
	return this->strength;
}
/**************************************
 * Description: Ths function will set
 * and change the strength of the 
 * Player obj
 * ***********************************/
void Player::setStrength(int change)
{
	strength = strength - change;
}
/**************************************************************************************************
 * Description: Reset strength for user
 * ***********************************************************************************************/
void Player::resetStrength()
{
    this->strength = 80;
    cout << "*You swishingly darted away and untwisted the bottle of potion.*" << endl;
    cout << "Hmm! Taste just watermelon juice!" << endl;
    cout << "You feel powerful, and your strength has restored to 100!" << endl;
}

