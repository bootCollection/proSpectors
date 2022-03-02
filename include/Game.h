/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef GAME_H
#define GAME_H
#include <Item.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../include/Room.h"
#include "../include/Dialog.h"
#include "../include/ParseInterface.h"

/**
* Implements a game. This is the main game configuration and run loop.
*/
class Game {
 public:
   /**
   * Constructor
   */
  Game();

  /**
  * Destructor
  */
  ~Game();

  /**
  * Initialize all the rooms for the game along with all the NPCs and
  */
  bool surface();

  bool caveIn();

  bool theCamp();

  bool lushCavern();

  bool backCamp();

  bool explosivesCache();

  bool campEx();

  bool theEscape();

  void initializeRooms();

  /**
  * Initilizes all the dialog to be spoken by the NPCs and the room
  * descriptions
  */
  void initializedDialog();

  /**
  * Runs the source code for the game
  */
  void run();

  /**
  * Takes in the players input
  * @param string input
  * @return string ouput
  */
  std::string CheckUserInput(std::string);

 private:
  std::string hold;
  ParseInterface parse;
  std::vector<Item*> inventory;
  bool illum = false;
  bool guide = false;
  bool explosives = false;
};
#endif
