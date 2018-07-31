 /*******************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: TimesSquare class implementation file.
 *******************************************************************************************/

#include "timesSquare.hpp"
using namespace attica;

/*******************************************************************************************
 ** Constructor that sets inherited variables
 *******************************************************************************************/
TimesSquare::TimesSquare()
{
    
    setDescription(desc1);
    setmovementOptions(mOptions);
    setMoveChoices(2);
    setItem("knife");
    setExposureLevel(HIGH);
    setItemAvailable(1);
    setActionPerformed(false);
    
}

/*******************************************************************************************
 ** takeAction() displays action prompts and updates description and actionPerformed 
 ** variables.
 *******************************************************************************************/
void TimesSquare::takeAction()
{
    
    cout << actionPrompt << endl;
    cin.get();
    cout << actionPrompt2 << endl;
    
    // update description
    setDescription(desc2);
    setActionPerformed(true);

}

/*******************************************************************************************
 ** takeItem() displays item prompts, reads an validates user choice and returns it.
 *******************************************************************************************/
int TimesSquare::takeItem()
{
    int choice;
    
    cout << itemPrompt << endl;
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