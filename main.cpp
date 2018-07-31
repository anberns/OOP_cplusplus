/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: main() seeds srand, creates a Game object, gets the timer choice and
 ** starts the game. It loops through Game's enterLocation, and movePrisoner functions
 ** until the Prisoner is killed or tries to enter the tunnel to safety. As the Prisoner
 ** attempts to enter the tunnel, Game's getFate function is called and the Prisoner
 ** is killed or admitted based on which items he has or doesn't have. If the Prisoner gains 
 ** entry, they make one more item decision and progress to the end of the game.
 *******************************************************************************************/

#include <iostream>
#include <string>
#include "space.hpp"
#include "timesSquare.hpp"
#include "catwalk.hpp"
#include "yard.hpp"
#include "cell.hpp"
#include "prisoner.hpp"
#include "game.hpp"
#include "utilities.hpp"
#include "validate.hpp"
using std::cout;
using std::endl;
using std::cin;
const int TIMER_CHOICE_1 = 1;   // on
const int TIMER_CHOICE_2 = 2;   // off

int main()
{
	// seed srand
    unsigned seed = time(0);
    srand(seed);
    int choice;
    
    // create game object
	Game gtest;
    
    // Title and random death (timer) choice
    cout << "Welcome to Survival in Attica\n" << endl;
    cout << "Do you want to engage the random death timer?\n(1) Yes\n(2) No\n";
    cin >> choice;
    while (!validEntry() || !isValid(choice, TIMER_CHOICE_1, TIMER_CHOICE_2))
    {
        cout << "Invalid choice.\n";
        cin >> choice;
    }
    
    // background info
    gtest.intro();
    
    // while prisoner is still alive and not in cell
    while (gtest.isStillAlive() && !gtest.getInTunnel())
    {
        gtest.enterLocation();
        if (!gtest.actionTaken())
        {
            gtest.performAction();
        }
        if (gtest.itemTaken())
        {
            gtest.itemDecision();
        }
        gtest.movePrisoner();
        
        // engage timer if on
        if (choice == TIMER_CHOICE_1)
        {
            gtest.randomDeath();
        }
    }
    
    // Prisoner has survived in exposed areas
    if (gtest.isStillAlive())
    {
        // tunnel encounter
        gtest.enterLocation();
        gtest.performAction();
        gtest.getFate();
        if (gtest.isStillAlive())
        {
            if (gtest.itemTaken())
            {
                gtest.itemDecision();
            }
            gtest.movePrisoner();
            
            // cell / ending
            gtest.enterLocation();
            gtest.performAction();
            if (gtest.checkItem("pipe"))
            {
                gtest.itemDecision();
            }
            gtest.endGame();
        }
    }
    cout << "Thanks for playing!\n";
	
	return 0;
}
