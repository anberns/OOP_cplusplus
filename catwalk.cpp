/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Catwalk class implementation file.
 *******************************************************************************************/

#include "catwalk.hpp"
using namespace attica;

/*******************************************************************************************
 ** Constructor that sets inherited variables
 *******************************************************************************************/
Catwalk::Catwalk()
{
    setDescription(desc1);
    setmovementOptions(mOptions);
    setMoveChoices(2);
    setItem("J.R.");
    setExposureLevel(HIGH);
    setItemAvailable(1);
    setActionPerformed(false);
    
}

/*******************************************************************************************
 ** takeAction() displays action prompts and updates description and actionPerformed
 ** variables.
 *******************************************************************************************/
void Catwalk::takeAction()
{
    cout << actionPrompt;
    cin.get();
    cout << actionPrompt2;
    
    // update description
    setDescription(desc2);
    setActionPerformed(true);
}

/*******************************************************************************************
 ** takeItem() displays item prompts, reads an validates user choice and returns it.
 *******************************************************************************************/
int Catwalk::takeItem()
{
    int choice;
    
    cout << itemPrompt << endl;
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