//
//  SideMap.hpp
//  Final Project
//
//  Created by Sean Lo on 3/17/18.
//  Copyright © 2018 Sean Lo. All rights reserved.
//

#ifndef SideMap_hpp
#define SideMap_hpp

#include <stdio.h>

#include <stdio.h>
#include "Space.hpp"

class SideMap : public Space
{
    protected:
            int feedCounter;
    public:
        SideMap();
        void explore(vector<bool>&input);
        int derivedBMenu(Space *locationB, std::vector<bool>&input);
};

#endif /* SideMap_hpp */
