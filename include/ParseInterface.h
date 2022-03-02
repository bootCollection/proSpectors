/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef PARSE_INTERFACE_H
#define PARSE_INTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Parse.h"

/**
* Implements a ParseInterface object. This allows the program to interact with
* the player.
*/
class ParseInterface {
 public:
  /**
  * Checks the integer provided with intInterface
  * @param int opt
  * @return bool true if a valid option. false otherwise
  */
  bool intInterface(int);

  /**
  * Checks the integer provided with intInterface
  * @param int opt
  * @return bool true if a valid option. false otherwise
  */
  bool wordInterface(int);

  /**
  * Blank interface
  */
  bool blankInterface();

  /**
  * Get the word out of the Parse Interface
  * @return vector strings of output
  */
  std::vector<std::string> getWordOut();

  /**
  * Get the integer out of the Parse Interface
  * @return vector integers of output
  */
  std::vector<int> getIntOut();

 private:
  ParseWord w;
  ParseInt i;
  std::vector<std::string> wO;
  std::vector<int> iO;
  bool valid = false;
};

#endif
