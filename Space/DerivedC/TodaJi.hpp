//
//  TodaJi.hpp
//  Final Project
//
//  Created by Sean Lo on 3/17/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#ifndef TodaJi_hpp
#define TodaJi_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Character.hpp"
#include <vector>

class TodaJi: public Space
{
    protected:
    
    public:
        TodaJi(); // Default Constructor
    
        void attack(Character *user, Character *enemy); //Go into  battle. Monsters then Boss
        void defend(Character *user);  //Defend and Heal
        void upstair(std::vector<bool>&input); //Go upstair to retrieve
        int dayMenu(std::vector<bool>&input);
        void nightMenu(Character *user, Character *enemyOne,Character *enemyTwo, Character *enemyThree, Character *enemyFour, std::vector<bool>&input);
};

#endif /* TodaJi_hpp */
