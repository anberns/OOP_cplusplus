 /*******************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Space class in an abstract class that has variables for a space's name,
 ** description, item name, movement options, Space pointers to link to up to five other
 ** spaces, the number of move choices, level of exposure (chance of being randomly shot),
 ** and variables to hold the availability of the space's item and action. It has get and 
 ** set functions for member variables and two pure virtual functions to allow each child
 ** class to have an appropriate item and action mechanism.
 *******************************************************************************************/

#ifndef space_hpp
#define space_hpp

#include <iostream>
#include <string>
using std::string;

namespace attica
{
    const int HIGH = 20;
    const int MED = 10;
    const int LOW = 5;
    const int MIN_CHANCE = 0;
    const int MAX_CHANCE = 100;
    const int MAX_ITEMS = 5;
    const int MIN_CHOICE = 1;
    const int MIN_DEATH_CHOICE = 1;
    const int MAX_DEATH_CHOICE = 3;
}

class Space
{
protected:
    string name;
    string description;
    string item;
    string movementOptions;
    Space *p1 = nullptr;
    Space *p2 = nullptr;
    Space *p3 = nullptr;
    Space *p4 = nullptr;
    Space *p5 = nullptr;
    int moveChoices;
    int exposureLevel;
    bool itemAvailable;
    bool actionPerformed;
public:
    Space *getp1() { return p1; }           // allow outside functions to locate linked spaces
	Space *getp2() { return p2; }
	Space *getp3() { return p3; }
	Space *getp4() { return p4; }
	Space *getp5() { return p5; }
	void setPointer(int, Space*);           // allow Game constructor to link spaces
    void setName(string n) { name = n; }
    void setDescription(string s) { description = s; }
    void setmovementOptions(string o) { movementOptions = o; }
    void setMoveChoices(int c) { moveChoices = c; }
    void setItem(string i) { item = i; }
    void setExposureLevel(int l) { exposureLevel = l; }
    void setItemAvailable(bool b) { itemAvailable = b; }
    void setActionPerformed(bool b) { actionPerformed = b; }
    string getDescription() { return description; }
    string getMovementOptions() { return movementOptions; }
    int getMoveChoices() { return moveChoices; }
    string getItem() { return item; }
    string getName() { return name; }
    int getExposureLevel() { return exposureLevel; }
    bool getItemAvailable() { return itemAvailable; }
    bool getActionPerfomed() { return actionPerformed; }
    virtual void takeAction() = 0;
    virtual int takeItem() = 0;
    virtual ~Space();
};

#endif /* space_hpp */
