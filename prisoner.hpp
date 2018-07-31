/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Prisoner class acts as the main character of the test-based game. It 
 ** accepts a name when created and has a list<string> to hold the names of up to five items
 ** that the character can hold. It has member functions to add, remove and check to see if
 ** the character has a specific item.
 *******************************************************************************************/

#ifndef prisoner_hpp
#define prisoner_hpp

//#include "space.hpp"
#include <string>
#include <list>
#include <iterator>
using std::list;
using std::string;

class Prisoner
{
private:
    string name;
    list<string> items;
    bool alive;
public:
    void setAlive(bool a) { alive = a; }
    void setName(string n) { name = n; }
    string getName() { return name; }
    void addItem(string);
    void removeItem(string);        // not used in this version
    bool findItem(string);
    bool getAlive() { return alive; }
};

#endif /* prisoner_hpp */
