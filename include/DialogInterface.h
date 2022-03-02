/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef DIALOG_INTERFACE_H
#define DIALOG_INTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Dialog.h"
#include "../include/ParseInterface.h"

/**
* Implements a DialogInterface.
*/
class DialogInterface {
 public:
  /**
  * Constructor
  * @param string name
  */
  DialogInterface(std::string);

  /**
  * Begin dialog starts a dialogName
  * @param pointer Dialog
  */
  void beginDialog(Dialog*);

  /**
  * Set name sets the dialog name.
  * @param string name
  */
  void setName(std::string);

 private:
  /**
  * Print out dialog options
  * @param pointer Dialog
  */
  void printOptions(Dialog*);

  /**
  * Select a dialog option
  * @param pointer Dialog
  * @return true
  */
  bool selectOption(Dialog*);
  /**
  * Displays helpful information
  */
  void help();
  ParseInterface p;
  std::string name;
  int selc;
};

#endif
