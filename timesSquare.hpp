 /*******************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The TimesSquare class is a child of the abstact Space class. It has member
 ** variables to store two descriptions, a list of movement options, as well as action and
 ** item prompts to guide the user through the interactions they have with the space. It
 ** defines the virtual takeAction() and takeItem() functions for this space.
 *******************************************************************************************/

#ifndef timesSquare_hpp
#define timesSquare_hpp

#include "space.hpp"
#include <string>
#include <iostream>
#include "validate.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;

class TimesSquare : public Space
{
private:
    string desc1 = "The gunfire is deafening. It seems to be coming from all around. The yard below "
    "is a haze of white powder. The makeshift steps that your fellow inmates built, "
    "and that you climbed not that long ago, descend into the chemical fog. You realize that you still have your "
    "knife, really just a piece of sharpened metal with one side wrapped in tape, "
    "pressed up again the hostage CO's neck. Even though parading him in front of the state "
    "police was only a power play, a trickle "
    "of blood begins to stain his collar. Must have pressed a little too hard.\n";
    
    string desc2 = "Back here again! There's no cover. No chance of surviving. Head down "
    "to the yard if you know what's good for you.\n";
    
    string mOptions = "(1) Across the catwalk\n(2) Down the stairs to the yard\n";
    
    string actionPrompt = "Press enter to let him go.\n";
    
    string actionPrompt2 = "You move him to the side and moments later his abdomen is ripped open by "
    "a round from a state trooper. Jesus, they don't "
    "even care about their own you think. Time to split.\n";
    
    string itemPrompt = "The knife is still in your hand. If you drop it you may be seen as less "
    "of a threat. On the other hand without it you will only be able to protect yourself with your bare hands.\n";
    
    string itemPrompt2 = "(1) Take it\n(2) Drop it\n";
    
public:
    TimesSquare();
    void takeAction();
    int takeItem();
    void changeDescription() { description = desc2; }   // change after space has been entered once
};

#endif /* timesSquare_hpp */
