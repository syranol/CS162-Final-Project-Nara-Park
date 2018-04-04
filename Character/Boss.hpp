/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the framework 4 vampire
 * and upon the completion of this file, i will be testing whether the creation
 * of such object works as desired through testing. Vampire.hpp serves as
 * the framework for the Vampire.cpp 
 * ***************************************************************************/
#ifndef BOSS_HPP
#define BOSS_HPP

#include "Character.hpp"
#include <string>
#include <iostream>

using namespace std;

class Boss : public Character
{
	protected:
	
	public:
		Boss();
		
		int attack();
		int defense();
		void setStrength(int change);
		int getStrength();
		void resetStrength();
};

#endif
