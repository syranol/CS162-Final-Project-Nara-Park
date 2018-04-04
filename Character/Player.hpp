/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the framework 4 player
 * and upon the completion of this file, i will be testing whether the creation
 * of such object works as desired through testing. Player.hpp serves as
 * the framework for the Player.cpp 
 * ***************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

#include <iostream>
#include <string>

using namespace std;

class Player : public Character
{
	protected:

	public:
		Player();
		
		int attack();
		void setStrength(int change);
		int getStrength();
		void resetStrength();
};

#endif
