/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Catwalk class is a child of the abstact Space class. It has member
 ** variables to store two descriptions, a list of movement options, as well as action and
 ** item prompts to guide the user through the interactions they have with the space. It
 ** defines the virtual takeAction() and takeItem() functions for this space.
 *******************************************************************************************/

#ifndef catwalk_hpp
#define catwalk_hpp

#include "space.hpp"
#include <string>
#include <iostream>
#include "validate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Catwalk : public Space
{
private:
    string desc1 = "It's not any safer here. J.R. from three cells down is slumped against "
    "the wall of D block. You look him over. What's left of his "
    "uniform is dark brown from four days of sleeping in the dirt "
    "and you think you see some red mixed in.\n";
    
    string desc2 = "Nothing here for you but your end. Move!\n";
    
    string mOptions = "(1) Drop 15 feet to the yard\n(2) Back across the catwalk\n";
    
    string itemPrompt = "J.R.'s ok but you don't know him that well. You do know that he'll "
    "slow you down. He'll surely die if he stays here. You may both die if "
    "you take him.\n";
    
    string itemPrompt2 = "(1) Try to save him\n(2) Leave him\n";
    
    string actionPrompt = "He's trying to say something. Press enter to kneel beside him.\n";
    
    string actionPrompt2 = "'Gary', he says. He shutters with every gunshot. 'What do we do?'\n";
    
public:
    Catwalk();
    void takeAction();
    int takeItem();
    void changeDescription() { description = desc2; }
};


#endif /* catwalk_hpp */
