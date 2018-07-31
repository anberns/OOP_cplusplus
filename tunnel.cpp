/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: Tunnel class implementation file.
 *******************************************************************************************/

#include "tunnel.hpp"
using namespace attica;

/********************************************************************************************
 ** Constructor that sets inherited variables.
 *******************************************************************************************/
Tunnel::Tunnel()
{
    setDescription(desc1);
    setmovementOptions(mOptions);
    setMoveChoices(1);
    setItem("pipe");
    setExposureLevel(LOW);
    setItemAvailable(1);
    setActionPerformed(false);
    
}

/*******************************************************************************************
 ** takeAction() displays action prompts and updates the actionPerformed variable.
 *******************************************************************************************/
void Tunnel::takeAction()
{
    cout << actionPrompt1 << endl;
    cin.get();
    
    // update description
    setActionPerformed(true);
}

/*******************************************************************************************
 ** takeItem() displays item prompts, reads an validates user choice and returns it.
 *******************************************************************************************/
int Tunnel::takeItem()
{
    int choice;
    
    cout << itemPrompt1 << endl;
    cout << itemPrompt2 << endl;
    cin >> choice;
    // validate
    while (!validEntry() || !isValid(choice, 1,2))
    {
        cout << "Take it or leave it. Make a choice!\n";
        cin >> choice;
    }
    return choice;
}