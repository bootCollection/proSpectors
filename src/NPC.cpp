#include <iostream>
#include <string>
#include <vector>
#include "../include/NPC.h"
#include "../include/DialogInterface.h"

NPC :: NPC(std::string disc, std::string n) {
  setDescription(disc);
  setName(n);
  Inventory.clear();
}

NPC::~NPC() {}

std::string NPC::getType() {
  return "npc";
}

bool NPC :: addItem(Item* i) {
  int count = 0;
  if (Inventory.size() == 0) {
    Inventory.push_back(i);
    return true;
  }
  std::vector<Item*>::iterator it;
  for (it = Inventory.begin(); it != Inventory.end(); it++) {
    if (*it != i) {
      count++;
    }
  }
  if (Inventory.size() == count) {
    Inventory.push_back(i);
    return true;
  }
  if (Inventory.size() != count) {
    std::cout << "This item already exist" << std::endl;
    return false;
  }
  return true;
}

std::vector<Item*> NPC :: getInventory() {
  return Inventory;
}
