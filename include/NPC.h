/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef NPC_H
#define NPC_H

#include "IObj.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include "../include/Dialog.h"

/**
* Implements an NPC. This is a non-player character that is used for story
* purposes.
*/
class NPC : public IObj {
 public:
  /**
  * Constructor
  * @param description the NPC description
  * @param name the NPC name
  */
  NPC(std::string, std::string);

  /**
  * Destructor
  */
  ~NPC();

  /**
  * Adds an item to inventory
  * @param item pointer
  * @return true if successful, false if unsuccessful
  */
  bool addItem(Item* i);

  /**
  * Removes an item to inventory
  * @param item pointer
  * @return true if successful, false if unsuccessful
  */
  bool removeItem(Item* i);

  /**
  * Returns the type of object
  * @return string in this case "npc"
  */
  std::string getType();

  /**
  * Returns a vector of items
  * @return Inventory
  */
  std::vector<Item*> getInventory();

  /**
  * Outputs an NPCs inventory
  */
  void listInventory();

 private:
  std::vector<Item*> Inventory;
};
#endif
