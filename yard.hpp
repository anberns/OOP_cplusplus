/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Yard class is a child of the abstact Space class. It has member
 ** variables to store two descriptions, a list of movement options, as well as action and
 ** item prompts to guide the user through the interactions they have with the space. It
 ** defines the virtual takeAction() and takeItem() functions for this space.
 *******************************************************************************************/

#ifndef yard_hpp
#define yard_hpp

#include "space.hpp"
#include <string>
#include <iostream>
#include "validate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Yard : public Space
{
private:
    string desc1;
    string desc2;
    string mOptions;
    string itemPrompt1;
    string itemPrompt2;
    string actionPrompt1;
    string actionPrompt2;
public:
    Yard();
    void takeAction();
    int takeItem();
    void setDescription2(string d) {desc2 = d; }
    void changeDescription() { description = desc2; }
    void setIP1(string p) { itemPrompt1 = p; }          // set unique item and action prompts for each instance
    void setIP2(string p) { itemPrompt2 = p; }
    void setAP1(string p) { actionPrompt1 = p; }
    void setAP2(string p) { actionPrompt2 = p; }
};

#endif /* yard_hpp */
