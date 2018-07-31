/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Prisoner class implementation file.
 *******************************************************************************************/

#include "prisoner.hpp"
#include <iostream>
using std::iterator;
using std::cout;
using std::endl;

const int MAX_ITEMS = 5;

/********************************************************************************************
 ** addItem() is passed an item name in the form of a string, checks to see if the Prisoner
 ** has room to carry the item and adds it if there is room.
 *******************************************************************************************/
void Prisoner::addItem(string item)
{
    if (items.size() < MAX_ITEMS)
    {
        items.push_front(item);
        cout << "Taking " << item << " with you." << endl;
    }
    else
    {
        cout << "You cannot carry anything else.\n";
    }
}

/********************************************************************************************
 ** removeItem() is passed an item name in the form of a string, checks to see if the Prisoner
 ** is carrying anything, if so checks to see if the Prisoner is carrying the specific item
 ** and if so, removes it from the items list.
 *******************************************************************************************/
void Prisoner::removeItem(string item)
{
    if (items.empty())
    {
        string e1 = "You aren't carrying anything.\n";
        throw e1;
    }
    else if (!findItem(item))
    {
        string e2 = "You don't have that item.\n";
        throw e2;
    }
    else
    {
        items.remove(item);
        cout << "Removed " << item << endl;
    }
    
}

/********************************************************************************************
 ** findItem() is pass an item name in the form or a string, iterates through the items
 ** list checking for the existence of the item and returns true if it is found, false
 ** otherwise.
 *******************************************************************************************/
bool Prisoner::findItem(string item)
{
    bool found = false;
    auto iter = items.begin();
    while (iter != items.end())
    {
        if (*iter == item)
        {
            found = true;
        }
        iter++;
    }
    return found;
}
