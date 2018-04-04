//
//  Space.hpp
//  Final Project
//
//  Created by Sean Lo on 3/14/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Character.hpp"
using namespace std;

class Space
{
    protected:
    
        Space *Directions[4];
        std::string name;
        int feedCounter;
        int potionCounter;
    public:
    
        Space();
    
        //Derived #1 - Deer Park
        virtual void feed(Character *person, std::vector<bool>&input);
        virtual int deerMenu(Character *person, vector<bool>&input);
        virtual void getBiscuits(std::vector<bool>&input);          //get food for deer - free, 3 servings;
        virtual void kick(Character *person);                       //kick the deer - minus 5 hp
    
        //Derived #2 - ETC
        virtual void explore(vector<bool>&input);
        virtual int derivedBMenu(Space *locationB, std::vector<bool>&input);
    
        //Derived #3 - MAIN
        virtual void attack(Character *user, Character *enemy);     //Go into  battle. Monsters then Boss
        virtual void upstair(std::vector<bool>&input);              //Go upstair to retrieve sword
    
        virtual int dayMenu(std::vector<bool>&input);
        virtual void nightMenu(Character *user, Character *enemyOne,Character *enemyTwo, Character *enemyThree, Character *enemyFour, std::vector<bool>&input);
    
        //Set Directions
        void setUp(Space *label);
        void setDown(Space *label);
        void setRight(Space *label);
        void setLeft(Space *label);
        int intRange(int min, int max, int input);
    
        //Other functions
        std::string getName();
        void setName(std::string nameInput);
    
};

#endif /* Space_hpp */
