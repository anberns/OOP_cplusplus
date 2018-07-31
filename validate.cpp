/*********************************************************************
 ** Author: Aaron Berns
 ** Date: 1/25/17
 ** Description: Validate function implementation file.
 *********************************************************************/

#include "validate.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace {
    const int MAX_CHAR = 500;
}

/*********************************************************************
 ** validEntry(), uses cin.good() to check if the constant last 
 ** extracted is compatible with the target variable.
 ** Idea and cin functions from
 ** http://stackoverflow.com/questions/16934183/integer-validation-for-input
 ** explanation of cin functions and parameters from
 ** http://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
 ** and
 ** http://stackoverflow.com/questions/22588747/struggling-with-cin-function-c
 *********************************************************************/
bool validEntry()
{
    // set return variable
    bool valid = false;
    
    // validate that input matches target variable type
    
    // if cin extracted a literal that matches entry, return true
    if (cin.good())
    {
        valid = true;
    }
    
    // if literal is not a match
    else
    {
        // reset cin to good
        cin.clear();
        
        // move extraction operator past invalid entry
        
        // ignore() is passed the const MAX_CHAR to allow
        // for a large input to be passed over.
        // It is also passed the endline character, which halts
        // the ignore process after it is reached
        cin.ignore(MAX_CHAR,'\n');
    }
    return valid;
    
}

/*********************************************************************
 ** isValid() is passed an integer to test as well as the range of
 ** acceptable values. Returns true if integer is in range, false
 ** otherwise.
 *********************************************************************/
bool isValid(int input, int min, int max)
{
    if (input >= min && input <= max)
        return true;
    else
        return false;
}