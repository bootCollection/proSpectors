/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef IOBJ_H
#define IOBJ_H
#include <iostream>
#include <string>
#include "../include/Dialog.h"

/**
* This is an abstract class to be used for Items, NPCs, and puzzles.
*/
class IObj {
 public:
  /**
  * Constructor
  */
  IObj();

  /**
  * Constructor
  * @param string Description
  * @param string name
  */
  IObj(std::string, std::string);

  /**
  * Destructor
  */
  virtual ~IObj() {
  }

  /**
  * This function returns description
  * @return string description
  */
  std::string getDescription();

  /**
  * This function returns name
  * @return string name
  */
  std::string getName();

  /**
  * This function returns the type of object, NPC, item, puzzle
  * @return string type
  */
  std::string getType();

  /**
  * This function returns returns true if the object is interactable
  * @return bool interactable
  */
  bool getInteractable();

  /**
  * This function returns a dialog object if there is dialog available
  * @return pointer Dialog
  */
  Dialog* getDialog();

  /**
  * This function sets the name
  * @param string name
  */
  void setName(std::string);

  /**
  * This function sets the description
  * @param string description
  */
  void setDescription(std::string);

  /**
  * This function sets the interactibility
  * @param bool interactable
  */
  void setInteractable(bool);

  /**
  * This function sets the dialog
  * @param pointer Dialog
  */
  void setDialog(Dialog* = nullptr);

 private:
  std::string description;
  std::string name;
  Dialog* dialog;
  bool interactable;
};
#endif
