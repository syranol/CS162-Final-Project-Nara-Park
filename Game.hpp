/******************************************************************************
 * Author: Hsiang LO
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the framework for Menu.cpp
 * and the implementation of the menu function will be used too call upon
 * characters and operate the fight
 * ***************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"
#include "Character.hpp"
#include "DeerPark.hpp"
#include "SideMap.hpp"
#include "TodaJi.hpp"
#include "Player.hpp"
#include "Boss.hpp"
#include "Monster.hpp"

using namespace std;

class Game
{
	private:
        Space *Deer, *KasugaTaisha, *KofuJi, *NaraNP, *Toda, *NaraNPN;
        Space *CurrentMap;  //Pointer to user's current location;
        Character *User, *MobOne, *MobTwo, *MobThree, *Susanoo;
        std::vector<bool> items = std::vector<bool>(6);
		bool stillPlaying;
    
	public:
		int intRange(int min, int max, int input);
		void printMenu();
        void setCurrentMap(int dChoice);
        void setUp();

};
#endif
