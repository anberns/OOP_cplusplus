/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Cell class is a child of the abstact Space class. It has member
 ** variables to store one description, an action prompt and item prompts to guide the user 
 ** through the interactions they have with the space. It defines the virtual takeAction() 
 ** and takeItem() functions for this space.
 *******************************************************************************************/

#ifndef cell_hpp
#define cell_hpp

#include "space.hpp"
#include <string>
#include <iostream>
#include "validate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Cell : public Space
{
private:
    string desc1 = "You scan the row of cells. Sweetlips' cell is filled with inmates. No room "
                "for you. Doesn't make sense to group together like that anyway. Several cells "
                "down you see Big Chris. He's squatting down with his back pressed up against a cell wall, checking "
                "over his shoulder every few seconds.\n";
    string actionPrompt1 = "Big Chris ain't dumb. He's your best bet. Press enter to join him in his cell.\n";
    string itemPrompt1 = "As you squat across from him, he eyes the pipe. \n'I got nothing to protect myself', "
                "Chris says, opening the palms of his hands. 'Help a brother out.' "
                "\nDespite his name he's rail thin. You've got a good five inches and sixty pounds on him.\n";
    string itemPrompt2 = "(1) Give him the pipe.\n(2) Survival of the fittest.\n";
public:
    Cell();
    void takeAction();
    int takeItem();
};

#endif /* cell_hpp */
