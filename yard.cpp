/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Yard class implementation file.
 *******************************************************************************************/

#include "yard.hpp"
using namespace attica;

/********************************************************************************************
 ** Constructor that sets inherited variables that are not unique to each instance
 *******************************************************************************************/
Yard::Yard()
{
    setActionPerformed(false);
    setExposureLevel(MED);
}

/*******************************************************************************************
 ** takeItem() displays item prompts, reads an validates user choice and returns it.
 *******************************************************************************************/
int Yard::takeItem()
{
    int choice;
    
    cout << itemPrompt1 << endl;
    cout << itemPrompt2 << endl;
    cin >> choice;
    
    // validate
    while (!validEntry() || !isValid(choice, 1,2))
    {
        cout << "Stay focused! Your life depends on it!\n";
        cin >> choice;
    }
    return choice;
}

/*******************************************************************************************
 ** takeAction() displays action prompts and updates description and actionPerformed
 ** variables.
 *******************************************************************************************/
void Yard::takeAction()
{
    cout << actionPrompt1;
    cin.get();
    cout << actionPrompt2;
    setActionPerformed(true);
    changeDescription();
}
