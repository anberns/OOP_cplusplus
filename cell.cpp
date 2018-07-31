/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Cell class implementation file.
 *******************************************************************************************/

#include "cell.hpp"
using namespace attica;

/********************************************************************************************
 ** Constructor that sets inherited variables.
 *******************************************************************************************/
Cell::Cell()
{
    setDescription(desc1);
    setMoveChoices(1);
    setItem("");
    setExposureLevel(LOW);
    setItemAvailable(0);
}

/*******************************************************************************************
 ** takeAction() displays action prompts and updates the actionPerformed variable.
 *******************************************************************************************/
void Cell::takeAction()
{
    cout << actionPrompt1 << endl;
    cin.get();
    
    // update description
    setActionPerformed(true);
}

/*******************************************************************************************
 ** takeItem() displays item prompts, reads an validates user choice and returns it.
 *******************************************************************************************/
int Cell::takeItem()
{
    int choice;
    
    cout << itemPrompt1 << endl;
    cout << itemPrompt2 << endl;
    cin >> choice;
    
    // validate
    while (!validEntry() || !isValid(choice, 1,2))
    {
        cout << "Make a choice!\n";
        cin >> choice;
    }	
    return choice;
}