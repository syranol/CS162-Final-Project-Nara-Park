/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the base class for vampire
 * barbarian, blue man, medusa and harry potter. Upon completion of the base
 * class, the derived class will have access to it and copy over member funct
 * and data field
 * ***************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

using namespace std;

class Character
{
	protected:
			int strength;
			int type;
			bool secondLife;
			std::string name;
			std::string typeName;
	public:
			Character();
	
            virtual void resetStrength();
			virtual int attack() = 0;
			virtual void setStrength(int change) = 0;
			virtual int getStrength() = 0;
			void setName(std::string);
			int getType();
			std::string getName();		
			std::string getTypeName();
};


#endif
