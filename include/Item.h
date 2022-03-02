/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef ITEM_H
#define ITEM_H
#include "IObj.h"
#include <iostream>
#include <string>

/**
* Item provides a class for the creation of items that can (sometimes) be used
* by the character.
*/
class Item : public IObj {
 public:
   /**
   * Constructor
   * @param string pType
   * @param string name
   */
  Item(std::string, std::string);

  /**
  * Constructor (Legacy)
  * @param string pType
  * @param string name
  * @param string description
  */
//  Item(std::string, std::string, std::string);

  /**
  * Destructor
  */
  ~Item();

  /**
  * getType returns the item type
  * @return string Type
  */
  std::string getType();

 private:
  std::string pType;
  std::string iName;
  std::string iDescription;
  bool subCave1_3 = false;
  bool subCave2_3 = false;
  bool subCave3_3 = false;
};
#endif
