/********************************************************************************************
 ** Author: Aaron Berns
 ** Date: 3/7/17
 ** Description: The Game class creates and manages the main character Prisoner object and
 ** the eight space objects of the game. It creates and manages the Space pointer location,
 ** introduces, runs and concludes the game by accessing and mutating its member objects.
 *******************************************************************************************/
#ifndef game_hpp
#define game_hpp

#include "utilities.hpp"
#include "validate.hpp"
#include "space.hpp"
#include "timesSquare.hpp"
#include "catwalk.hpp"
#include "yard.hpp" 
#include "tunnel.hpp"
#include "cell.hpp"
#include "prisoner.hpp"
#include <iostream>

class Game
{
private:
	Prisoner Gary;      // main character
	Space *ts;          // game areas
    Space *cw;
    Space *sw;
    Space *se;
    Space *ne;
    Space *nw;
    Space *tun;
    Space *cell;
    Space *location;    // tracks character's location
    int roundCount;     // number of moves
    bool inTunnel;      // true when character moves to tunnel
      
public:
    Game();
    void intro();
    void setInTunnel(bool i) { inTunnel = i; }
    bool getInTunnel() { return inTunnel; }
    void movePrisoner();
    void enterLocation();
    void performAction();
    void itemDecision();        // presents item and gives option of taking it
    bool actionTaken();
    bool itemTaken();
    void randomDeath();         // possible death after each move works as a clock
    void getFate();             // showdown to enter tunnel to safety
    bool isStillAlive();
    int getRoundCount() { return roundCount; }
    void setRoundCount(int c) { roundCount = c; }
    bool checkItem(string i) { return Gary.findItem(i); }
    void endGame();
    ~Game();
};

#endif /* game_hpp */

