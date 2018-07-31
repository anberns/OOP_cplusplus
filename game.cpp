/********************************************************************************************
** Author: Aaron Berns
** Date: 3/7/17
** Description: Game class implementation file.
********************************************************************************************/
#include "game.hpp"
using std::cout;
using std::cin;
using std::endl;
using namespace attica;

/********************************************************************************************
** Constructor sets member variables for Prisoner object, creates spaces from Space pointers,
** links the spaces to each other, set the variables for the four Yard objects and sets
** the names of all spaces.
********************************************************************************************/
Game::Game()
{
    // set Prisoner variables
    Gary.setName("Gary");
    Gary.setAlive(true);
    setRoundCount(0);
    setInTunnel(false);
    
	// create space-derived objects
	ts = new TimesSquare;
	cw = new Catwalk;
	se = new Yard;
	sw = new Yard;
	ne = new Yard;
	nw = new Yard;
	tun = new Tunnel;
	cell = new Cell;

	// link spaces
    ts->setPointer(2, cw);   // Times Square to Catwalk
    ts->setPointer(1, sw);  // Times Square down stairs to YardSW
    cw->setPointer(4, ts);  // Catwalk to Times Square
    cw->setPointer(1, se);  // Catwalk to YardSE
    sw->setPointer(1, nw);  // YardSW to YardNW
    sw->setPointer(2, ne);  // YardSW to YardNE
    sw->setPointer(3, se);  // YardSW to YardSE
    sw->setPointer(4, tun);  // YardSW to Tunnel
    sw->setPointer(5, ts);  // YardSW up stairs to Times Square
    se->setPointer(1, ne);  // YardSE to YardNE
    se->setPointer(4, nw);  // YardSE to YardNW
    se->setPointer(3, sw);  // YardSE to YardSW
    ne->setPointer(2, se);  // YardNE to YardSE
    ne->setPointer(3, sw);  // YardNE to YardSW
    ne->setPointer(4, nw);  // YardNE to YardNW
    nw->setPointer(2, ne);  // YardNW to YardNE
    nw->setPointer(3, se);  // YardNW to YardSE
    nw->setPointer(4, sw);  // YardNW to YardSW
    tun->setPointer(2, cell);  // Tunnel to Cell
    location = ts;  // start on roof of Times Square
    
    // set variables for yard objects
    string swOptions = "(1) Northwest corner\n(2) Northeast corner\n(3) Southeast corner\n(4) Enter"
                        " the tunnel\n(5) Climb back up to the roof of Times Square\n";
    string swDesc = "You look around. The stairs leading back to the roof. The entrance "
					"to the tunnel. There's troopers in masks standing around, looking as "
					"shocked as you feel. The steady percussion of rifle rounds and shotgun "
					"blasts remind you that you have to keep moving.\n";
    string swDesc2 = "Nothing's changed here. Every second that passes is a round of Russian roulette.\n";
    string swActionPrompt1 = "But wait. Part of the stair framing looks loose. Press enter "
                    "to pull it free.\n";
    string swActionPrompt2 = "The board comes off after you lean back and put your body weight "
                    "to work. ";
    string swItemPrompt1 = "It's about four feet long with two nails protruding from one end. Could "
                    "come in handy. Could also get you shot on sight.\n";
    string swItemPrompt2 = "(1) Take it\n(2) Leave it\n";

	sw->setDescription(swDesc);
    static_cast<Yard *>(sw)->setDescription2(swDesc2);
	sw->setmovementOptions(swOptions);
    sw->setMoveChoices(5);
    sw->setItem("2x4");
    sw->setItemAvailable(true);
    static_cast<Yard *>(sw)->setIP1(swItemPrompt1);
    static_cast<Yard *>(sw)->setIP2(swItemPrompt2);
    static_cast<Yard *>(sw)->setAP1(swActionPrompt1);
    static_cast<Yard *>(sw)->setAP2(swActionPrompt2);
    
    string seOptions = "(1) Northeast corner\n(2) Northwest corner\n(3) Southwest corner\n";
    string seDesc = "The gas is still thick down here. It sears your lungs every time you breathe. You "
					"can only see a few feet in any direction. There's a state trooper laying on the "
					"ground near the tunnel. You see his chest rise and fall and you see where his "
					"uniform has been shredded from the stray buck shot of another trooper's wild firing. "
					"He has a gas mask on.\n";
    string seDesc2 = "The trooper is still laying on the ground. He stares you down but makes no attempt "
                    "to engage.\n";
    string seActionPrompt1 = "Press enter to pull the gas mask off his face.\n";
    string seActionPrompt2 = "As soon as it's gone, the trooper starts coughing violently. "
                    "You start to put it back on but then you see the shotgun laying on the "
                    "ground to his right. Whatever momentary compassion you felt is gone.\n";
    string seItemPrompt1 = "You turn your attention back to the gas mask. When you hold it to your "
                    "face the air is less caustic. It's much harder to see though.\n";
    string seItemPrompt2 = "(1) Keep the mask\n(2) Not worth it\n";

	se->setDescription(seDesc);
    static_cast<Yard *>(se)->setDescription2(seDesc2);
    se->setmovementOptions(seOptions);
    se->setMoveChoices(3);
    se->setItem("gas mask");
    se->setItemAvailable(true);
    static_cast<Yard *>(se)->setIP1(seItemPrompt1);
    static_cast<Yard *>(se)->setIP2(seItemPrompt2);
    static_cast<Yard *>(se)->setAP1(seActionPrompt1);
    static_cast<Yard *>(se)->setAP2(seActionPrompt2);
    
    string neOptions = "(1) Southeast corner\n(2) Southwest corner\n(3) Northwest corner\n";
    string neDesc = "The wall of B block appears so suddenly that you almost run into it. "
					"By now you've seen enough of your fellow inmates and hostages lying "
					"around with gaping wounds that you should be unmoved by the lump "
					"of a man propped in the corner. It's not "
					"just another body though. This hostage, a CO by the name of Fitzpatrick, "
					"has been your partner in the contraband import export business that's kept "
					"you going in here. He's looked out for you. More than he was obliged to.\n";
    string neDesc2 = "Fitzpatrick is dead. There's nothing to do here.\n";
    string neActionPrompt1 = "Press enter to check for a pulse.\n";
    string neActionPrompt2 = "You feel a faint throbbing beneath his jaw. He's alive. You turn him "
                    "over. From the look of the wound in his torso he won't be for long.\n";
    string neItemPrompt1 = "In one of his hands is a folded piece of paper. Some of the "
                    "hostages were writing letters to their families on the third day, when "
                    "the hope of a peaceful resolution was fading.\n";
    string neItemPrompt2 = "(1) Take the letter. It may be ruined or lost.\n(2) Leave it. "
                    "There's a better chance it will be delivered if it's found on his body.\n";
	ne->setDescription(neDesc);
    static_cast<Yard *>(ne)->setDescription2(neDesc2);
    ne->setmovementOptions(neOptions);
    ne->setMoveChoices(3);
    ne->setItem("letter");
    ne->setItemAvailable(true);
    static_cast<Yard *>(ne)->setIP1(neItemPrompt1);
    static_cast<Yard *>(ne)->setIP2(neItemPrompt2);
    static_cast<Yard *>(ne)->setAP1(neActionPrompt1);
    static_cast<Yard *>(ne)->setAP2(neActionPrompt2);
    
    string nwOptions = "(1) Northeast corner\n(2) Southeast corner\n(3) Southwest corner\n";
    string nwDesc = "You pause to catch your breath. Running hunched over with the rain of bullet-chipped "
					"concrete on your head and back has you reeling. Something grabs your "
                    "leg. You jump back and look down. It's Lawrence. With a big hole in his "
                    "left thigh. The kind of wound that needs intervention. Lucky for Lawrence "
                    "he has a ripped t-shirt tied around his head for shade.\n";
    string nwDesc2 = "Nothing here but the brown stain of Lawrence's blood. Hopefully he'll\n"
                    "make it.\n";
    string nwActionPrompt1 = "Press enter to tie off the wound.\n";
    string nwActionPrompt2 = "Lawrence winces as you lift his leg and loop the twisted t-shirt "
                    "around his thigh above the wound. The bleeding lessens but it's no "
                    "guarantee. ";
    string nwItemPrompt1 = "You turn and look over your shoulder, looking for a break in the "
                    "gas cloud. Lawrence grabs your wrist and pulls you close so you can hear. "
                    "'Don't leave me Gary. They'll finish me for sure when they see me sittin' "
                    "here, lame like this.'\n";
    string nwItemPrompt2 = "(1) Take him with you despite the danger this puts you in.\n(2) "
                    "Now's not the time get soft. He'll most likely die anyway.\n";
	nw->setDescription(nwDesc);
    static_cast<Yard *>(nw)->setDescription2(nwDesc2);
    nw->setmovementOptions(nwOptions);
    nw->setMoveChoices(3);
    nw->setItem("Lawrence");
    nw->setItemAvailable(true);
    static_cast<Yard *>(nw)->setIP1(nwItemPrompt1);
    static_cast<Yard *>(nw)->setIP2(nwItemPrompt2);
    static_cast<Yard *>(nw)->setAP1(nwActionPrompt1);
    static_cast<Yard *>(nw)->setAP2(nwActionPrompt2);

	// set names
	ts->setName("Times Square");
	cw->setName("Catwalk");
	se->setName("Yard: Southeast Corner");
	sw->setName("Yard: Southwest Corner");
	ne->setName("Yard: Northeast Corner");
	nw->setName("Yard: Northwest Corner");
    tun->setName("Tunnel to Cell Block D");
    cell->setName("Cell Block D");
}

/********************************************************************************************
 ** intro() displays background information for the game
 ********************************************************************************************/
void Game::intro()
{
    cout << "In the summer of 1971 there were several prisoner uprisings in correctional facilities in "
            "New York State. By mid-September, tensions between politically-active prisoners and guards "
            "in Attica Prison were at a breaking point. Both sides anticipated that violence would break "
            "out at any moment. A miscommunication between guards led to a large group of inmates being "
            "locked in a tunnel connecting the cell blocks to the exercise yard. \n\nAs they were being turned "
            "around a guard was assaulted and a riot broke out. The prisoners eventually took control of "
            "part of the prison and collected a number of hostages in the process. They held the prison "
            "for four days, trying to negotiate a peaceful end to the standoff. On the morning of the fourth day, "
            "several prisoners took hostages to the roof of the central yard structure named Times "
            "Square. They held the prisoners at knife point, hoping to push prison authorities to meet "
            "their demands. It is believed that the prisoners were never planning on harming any of the "
            "hostages, but that fact was made irrelevant as hundreds of state troopers stormed the prison "
            "with every intention of killing any prisoner they came across.\n\n"
            "You are one of the prisoners standing on the roof of Times Square. You hold a hostage with a "
            "knife at his throat. There are troopers with rifles on the perimeter roof. The push to take back "
            "the prison has begun in the tunnels underneath you. Your only chance of survival is to somehow "
            "make your way back to the cell block through one of those very same tunnels. A helicopter has "
            "just dropped canisters of tear gas in the prison yard. At any moment you can "
            "be killed by a trooper firing from the roof or from the ground. Good luck.\n\nPress enter to begin.";
    cin.get();
}

/********************************************************************************************
 ** movePrisoner() gets a location's movement choices, displays them to the user, gets and
 ** validates their choice and uses the location pointer to move the prisoner to the 
 ** appropriate space.
 ********************************************************************************************/
void Game::movePrisoner()
{
    // prompt for and get choice
    int choice;
    cout << "Decide where to go next.\n" << location->getMovementOptions() << endl;
    cin >> choice;
    
    //validate
    while (!validEntry() || !isValid(choice, MIN_CHOICE, location->getMoveChoices()))
    {
        cout << "No time for mistakes! Where you going?\n";
        cin >> choice;
    }
    
    // make move depending on location
    if (location == ts)
    {
        if (choice == 1)
        {
            location = location->getp2();
        }
        else
        {
            location = location->getp1();
        }
    }
    else if (location == cw)
    {
        if (choice == 1)
        {
            location = location->getp1();
        }
        else
        {
            location = location->getp4();
        }
    }
    else if (location == sw)
    {
        if (choice == 1)
        {
            location = location->getp1();
        }
        else if (choice == 2)
        {
            location = location->getp2();
        }
        else if (choice == 3)
        {
            location = location->getp3();
        }
        else if (choice == 4)
        {
            location = location->getp4();
        }
        else if (choice == 5)
        {
            location = location->getp5();
        }
    }
    else if (location == se)
    {
        if (choice == 1)
        {
            location = location->getp1();
        }
        else if (choice == 2)
        {
            location = location->getp4();
        }
        else
        {
            location = location->getp3();
        }
    }
    else if (location == ne)
    {
        if (choice == 1)
        {
            location = location->getp2();
        }
        else if (choice == 2)
        {
            location = location->getp3();
        }
        else
        {
            location = location->getp4();
        }
    }
    else if (location == nw)
    {
        if (choice == 1)
        {
            location = location->getp2();
        }
        else if (choice == 2)
        {
            location = location->getp3();
        }
        else
        {
            location = location->getp4();
        }
    }
    else if (location == tun)
    {
        location = location->getp2();    // tunnel to cell
    }
    
    if (location == tun)
    {
        setInTunnel(true);
    }
}

/********************************************************************************************
 ** randomDeath() is called after each move if turned on in the beginning of the game. It
 ** gets a random integer between 0 and 100 and if it falls in the range between 0 and the 
 ** location's exposure level, one of three random prompts is displayed, ending the game.
 ********************************************************************************************/
void Game::randomDeath()
{
    // Possible random death
    int chance = randomInt(MIN_CHANCE, MAX_CHANCE);
    int deathPrompt = randomInt(MIN_DEATH_CHOICE, MAX_DEATH_CHOICE);
    
    if (chance <= location->getExposureLevel())
    {
        if (deathPrompt == 1)
        {
            cout << "A stray bullet nicks your right carotid artery. You press your hand against "
                    "it but it does little to slow the rapid blood loss. You drop to your knees. "
                    "Several inmates run past as your vision becomes blurry. None of them stop.\n\n";
        }
        else if (deathPrompt == 2)
        {
            cout << "You stop walking and try to get your bearings. The combination of fog and fear "
                    "makes it almost impossible to be certain of where you are. You feel something "
                    "burning against your back. It's a shotgun, hot from use. \n'Run', a voice behind you "
                    "says. \nYou've barely moved five feet when you're thrown to the ground from "
                    "the force of the slug. Lucky for you the wound is severe and you bleed out in minutes.\n\n";
        }
        else
        {
            cout << "Something catches your eye on the roof of B block. A flash like an orange lightening bug. "
                    "You keep looking in the direction it came from. There it is again. This time tiny pieces "
                    "of brick spray your left shoulder and neck. You don't feel it. You're lost in the memory "
                    "of a summer barbeque. The lightening bugs flicker on the periphery of your aunt June's "
                    "yard at dusk. Flicker. Flicker. Fli...\n\n";
        }
        Gary.setAlive(false);
    }
}

/********************************************************************************************
 ** enterLocation() gets and displays the name and description of a location and updates the
 ** roundCount.
 ********************************************************************************************/
void Game::enterLocation()
{
    cout << endl;
    cout << location->getName() << endl << endl;
    cout << location->getDescription() << endl << endl;
    setRoundCount(getRoundCount() + 1);
}

/********************************************************************************************
 ** performAction() clears the buffer and calls the location's takeAction function, unless
 ** the location is the beginning of the game.
 ********************************************************************************************/
void Game::performAction()
{
    if (getRoundCount() != 1)
    {
        cin.get();
    }
    location->takeAction();
}

/********************************************************************************************
 ** itemDecision() calls the location's takeItem function, which returns the user's choice.
 ** If the choice is to take the item, the Prisoner's addItem function is called. Either way
 ** the item becomes unavailable during future visits. The cell location has a unique
 ** situation and is excluded.
 ********************************************************************************************/
void Game::itemDecision()
{
    // get item choice
    int choice = location->takeItem();
    
    // if location is not cell, normal process
    if (location != cell)
    {
        // if take item, update Prisoner items and Space item availability
        if (choice == 1)
        {
            Gary.addItem(location->getItem());
        }
        location->setItemAvailable(false);
    }
    // cell choice
    else
    {
        if (choice == 1)
        {
            cout << "You hand the pipe to Big Chris. He nods. \n'Might catch you a bullet', you say.\n"
                    "'I'll take my chances.'\n";
        }
        else
        {
            cout << "'Naw', you say as you crouch down and slide it behind you. 'Just get you killed'.\n";
        }
    }
}

/********************************************************************************************
 ** itemTaken() gets and returns a location's item availability
 ********************************************************************************************/
bool Game::itemTaken()
{
    return location->getItemAvailable();
}

/********************************************************************************************
 ** actionTaken() gets and returns a location's action status
 ********************************************************************************************/
bool Game::actionTaken()
{
    return location->getActionPerfomed();
}

/********************************************************************************************
 ** getFate() is called as the prisoner tries to enter the tunnel to safety. It uses the
 ** Prisoner's findItem function to search for a knife, 2x4, two fellow inmates and the 
 ** absence of the hostage letter. Having each of these items triggers a unique death prompt.
 ** If the character has one or no fellow inmates and the letter with him, but no weapons,
 ** he is granted entry.
 *******************************************************************************************/
void Game::getFate()
{
    // search for items that lead to death by guards
    if (Gary.findItem("knife"))
    {
        cout << "As you approach one of the troopers looks at your right hand. You follow "
                "his gaze and see the knife, held loosely and pointing at the ground.\n"
                "'Knife! Take him out!' \nThe last thing you see is the upward pivot "
                "of all three shotguns.\n\n";
        Gary.setAlive(false);
    }
    else if (Gary.findItem("2x4"))
    {
        cout << "As you approach the troopers eyes grow wide. For the first time you feel the "
                "weight of the board in your left hand. You see yourself as they must see you. "
                "It's like you've left your body and are now a bystander witnessing your own "
                "death. It's better this way because the sight of three fingers pulling the "
                "triggers of their respective shotguns in low motion doesn't make you feel the "
                "least bit afraid.\n\n";
        Gary.setAlive(false);
    }
    else if (Gary.findItem("Lawrence") && Gary.findItem("J.R."))
    {
        cout << "You approach the troopers with Lawrence leaning against you, his arm draped "
                "over your shoulder. J.R. follows a few feet behind. One of the troopers elbows "
                "another in the side. The smile that settles on their faces is unmistakable, "
                "even through the cloud of white particulate. \n'Look at this group of militants. "
                "Just don't know when to quit', one of them shouts over the din. \n'You feel "
                "threatened Grepler?' \nThe one beside him nods. Lawrence's blood feels warm on "
                "your face. That's the last thought you'll ever have.\n\n";
        Gary.setAlive(false);
    }
    else if (!Gary.findItem("letter"))
    {
        cout << "You approach the troopers, slowly raising your empty hands, trying your "
        "best to appear non-threatening. It doesn't matter. These racist hillbillies "
        "might as well be out deer-hunting. The last thing you see is the corner of "
        "one of their mouths begin to shape itself into a grin.\n\n";
        Gary.setAlive(false);
    }
    // make it through
    else
    {
        cout << "As you approach the troopers they raise their shotguns. You can see the animal fear "
                "in their eyes. You raise your hands in surrender. \n'Drop him', one of "
                "trooper shouts. \nYou see the muscles in their arms begin to tense, anticipating the "
                "recoil. \n'Wait!', shouts another. 'What's he got in his hand?' \nHe's looking at the "
                "letter resting in your right hand. \n'What's that?', he shouts. \n'Fitzpatrick wrote "
                "a letter', you say. \n'Who the hell's Fitzpatrick?' \n'A hostage. A guard.' \n'Stay "
                "right there. If I see so much as a muscle twitch...' \nThe trooper walks over slowly. "
                "He stops in front of you, just out of reach. \n'Drop the letter on the "
                "ground and walk backwards three steps.' \nHe rests the barrel of his gun on his forearm "
                "as he bends down to pluck the letter from the mud. The other two troopers move up "
                "beside him, never taking their eyes or their guns off of you. He drops his gun and "
                "unfolds the paper. \n'What are you doing with this?', he asks. \n'He looked out for me.'\n"
                "'What the hell does that mean?' \n'I'm just saying he was a good man.' \n'Uh huh...'\n"
                "'Look, I'm just trying to get back to my cell. I didn't want none of this. I only "
                "got nineteen months left'. \nYou can see him wrestling with what you've said. \n'Fine', "
                "he says. 'But if I see you out here again ain't no letter going to save you.' \nThe "
                "troopers step back. One of them keeps the business end of his shotgun trained on your head "
                "as you walk between them and into the D block tunnel.\n\n";
    }
}

/********************************************************************************************
 ** isStillAlive() gets and returns the Prisoner's life status.
 ********************************************************************************************/
bool Game::isStillAlive()
{
    return Gary.getAlive();
}

/********************************************************************************************
 ** endGame() displays the ending prompt.
 ********************************************************************************************/
void Game::endGame()
{
    cout << "\nYou've done everything you can. It's out of your hands now. You and your "
    "fellow inmates hunker down in the cell block, knowing that the future holds only shades "
    "of the same color, which is suffering.\n\n";
}

/********************************************************************************************
 ** Destructor deletes Space derived objects created in constructor.
 ********************************************************************************************/
Game::~Game()
{
    // free allocated memory
    delete ts;
    ts = nullptr;
    delete cw;
    cw = nullptr;
    delete sw;
    sw = nullptr;
    delete se;
    se = nullptr;
    delete sw;
    sw = nullptr;
    delete ne;
    ne = nullptr;
    delete nw;
    nw = nullptr;
    delete tun;
    tun = nullptr;
    delete cell;
    cell = nullptr;
}