/*********************************************************************
 ** Author: Aaron Berns
 ** Date: 1/14/17
 ** Description: utilities implementation file.
 *********************************************************************/

#include "utilities.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
using std::cout;
using std::endl;
using std::cin;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;


/*********************************************************************
 ** randomInt() is based on the random number generators in Gaddis
 ** et. al. It is passed the range of acceptable values, uses time()
 ** to set a unique seed and srand() to return a random value within
 ** the given range. The seed must be set inside of main() or when
 ** the class calling it is instantiated
 *********************************************************************/
int randomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/*********************************************************************
 ** clearScr() is passed a number of lines and prints that many blank
 ** lines on the screen, simulating a genuine clear screen function.
 *********************************************************************/
void clearScr(int lines)
{
    for (int count = 0; count < lines; count++)
    {
        cout <<endl;
    }
}

/*********************************************************************
 ** displaySleep() is based on a solution from:
 ** http://stackoverflow.com/questions/4184468/sleep-for-milliseconds
 ** The method sleep_for exists in the this_thread namespace of the 
 ** <thread> library. It pauses the execution of thread for the time 
 ** passed to it. The <chrono> library Duration object milliseconds 
 ** is passed as the time to pause the calling thread.
 *********************************************************************/
void displaySleep(int mil)
{
    sleep_for(milliseconds(mil));
}

/*********************************************************************
 ** randomDouble() is passed minimum and maximum double values and 
 ** calls the pre-seeded rand() function to assist in calculating
 ** a decimal value within the passed range and returns it.
 ** Based on random number solution from:
 ** http://stackoverflow.com/questions/33058848/generate-a-random-double-between-1-and-1
 *********************************************************************/
double randomDouble(double min, double max)
{
    return min + (rand() / (RAND_MAX / (max - min)));
}

