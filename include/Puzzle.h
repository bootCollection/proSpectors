/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef PUZZLE_H
#define PUZZLE_H
#include "IObj.h"
#include <iostream>
#include <string>
#include "../include/Dialog.h"

/**
* Implements a puzzle. This is an item that the character can interact with.
*/
class Puzzle : public IObj {
 public:
  /**
  * Constructor
  * @param description the Puzzle description
  * @param name the Puzzle name
  */
  Puzzle(std::string, std::string);

  /**
  * Destructor
  */
  ~Puzzle();

  /**
  * This checks the game state for use in gameflow
  * @return bool true or false
  */
  bool checkpTypeSubCave1_2();

  /**
  * This checks the game state for use in gameflow
  * @return bool true or false
  */
  bool checkpTypeSubCave2_2();

  /**
  * This returns what type of Iobj this is
  * @return string type
  */
  std::string getType();

 private:
  std::string Name;
  std::string Description;
};
#endif
