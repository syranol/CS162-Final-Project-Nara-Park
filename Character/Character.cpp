/******************************************************************************
 * Author: Hsiang Lo
 * Date: 02/12/2018
 * Description: The purpose of this file is to build the base class for vampire,
 * barbarians, blue man, medusa, and harry potter. Upon completion of the based
 * class, the derived class will have access to it and copy over memeber funct
 * and other data field as desire.
 * ***************************************************************************/
#include "Character.hpp"
#include <iostream>

using namespace std;
/**************************************************************************************************
 * Description: Default constructor
 * ***********************************************************************************************/
Character::Character()
{
}
/**************************************************************************************************
 * Description:everything is implemented  later on
 * ***********************************************************************************************/
int Character::getStrength()
{
	return this->strength;
}
void Character::setName(std::string userName)
{
	this->name = userName; 
}
int Character::getType()
{
	return this->type;
}
std::string Character::getName()
{
	return this->name;
}
std::string Character::getTypeName()
{
	return this->typeName;
}
void Character::resetStrength()
{
}
