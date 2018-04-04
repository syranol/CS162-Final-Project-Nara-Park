/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the framework 4 monster
 * and upon the completion of this file, i will be testing whether the creation
 * of such object works as desired through testing. Monster.hpp serves as
 * the framework for the Monster.cpp
 * ***************************************************************************/
#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include <string>
#include <iostream>

using namespace std;

class Monster : public Character
{
	protected:

	public:
		Monster();
		
		int attack();
		int defense();
		void setStrength(int change);
		int getStrength();
		void resetStrength();
};

#endif
