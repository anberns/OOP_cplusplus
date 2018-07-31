 /*******************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Space class implementation file.
 *******************************************************************************************/

#include "space.hpp"

/*******************************************************************************************
 ** setPointer is passed the pointer number and pointer to the Space derived object to link
 ** that pointer to, then performs the linking.
 *******************************************************************************************/
void Space::setPointer(int pNum, Space *target)
{
	if (pNum == 1)
	{
		this->p1 = target;
	}
	else if (pNum == 2)
	{
		this->p2 = target;
	}
	else if (pNum == 3)
	{
		this->p3 = target;
	}
	else if (pNum == 4)
	{
		this->p4 = target;
	}
	else
	{
		this->p5 = target;
	}  
}

/*******************************************************************************************
 ** Destructor unlinks all member pointers
 *******************************************************************************************/
Space::~Space()
{
    this->p1 = nullptr;
    this->p2 = nullptr;
    this->p3 = nullptr;
    this->p4 = nullptr;
    this->p5 = nullptr;
}
