/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Tunnel class is a child of the abstact Space class. It has member
 ** variables to store one description, a list of movement options, as well as one action and
 ** two item prompts to guide the user through the interactions they have with the space. It
 ** defines the virtual takeAction() and takeItem() functions for this space.
 *******************************************************************************************/

#ifndef tunnel_hpp
#define tunnel_hpp

#include "space.hpp"
#include <string>
#include <iostream>
#include "validate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Tunnel : public Space
{
private:
    string desc1 = "All around you is carnage. If you can make it "
                "to your cell, you might get away with just a beating. Unfortunately there are three "
                "troopers with shotguns standing guard over the entrance. Their guns "
                "are aimed at the ground, but that doesn't mean they won't fill you with "
                "double-aught as soon as they notice you.\n";
    string actionPrompt1 = "There's no other way. Press enter to slowly approach the troopers.\n";
    string itemPrompt1 = "As you enter the tunnel you start running towards the cell block. You "
                "have to hurtle over the bodies of several inmates but you don't slow. A glint "
                "of steel catches your eye. A length of pipe is laying next to a crumpled body.\n";
    string itemPrompt2 = "(1) Can't hurt to have it.\n(2) Not worth the risk.\n";
    string mOptions = "(1) No going back now. Enter the cell block.\n";
public:
    Tunnel();
    void takeAction();
    int takeItem();
};

#endif /* tunnel_hpp */

