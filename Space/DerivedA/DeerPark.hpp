//
//  DeerPark.hpp
//  Final Project
//
//  Created by Sean Lo on 3/14/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#ifndef DeerPark_hpp
#define DeerPark_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Character.hpp"
#include <vector>

class DeerPark : public Space
{
    protected:
    
    public:
        DeerPark();

        void feed(Character *person, std::vector<bool>&input);  //Feed deer, 3 Feed = key
        void getBiscuits(std::vector<bool>&input);   //Get feed
        void kick(Character *person);                           //Kick deer, -5 strength
        int deerMenu(Character *person, vector<bool>&input);
};

#endif /* DeerPark_hpp */
