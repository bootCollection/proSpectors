#include"../include/Room.h"
#include<iostream>
#include <string>
#include <vector>

Room :: Room(std::string description, std::string name) {
  setDescription(description);
  setName(name);
  Name = name;
  d = new Dialog();
  inter = new DialogInterface(getName());
}

Room :: ~Room() {
  delete d;
  delete inter;
  while (!NPCs.empty()) delete NPCs.back(), NPCs.pop_back();
  NPCs.clear();
  while (!Puzzles.empty()) delete Puzzles.back(), Puzzles.pop_back();
  Puzzles.clear();
}

void Room :: addNPC(NPC* newNPC) {
  NPCs.push_back(newNPC);
  newNPC->setDialog(d->selectPath(1));
  (d->selectPath(1))->addOption(newNPC->getName(), newNPC->getDialog());
}

int Room :: numberofNPCs() {
  return NPCs.size();
}
void Room::addRoom(Room* newRoom) {
  Rooms.push_back(newRoom);
  newRoom->setDialog(d->selectPath(3));
  (d->selectPath(3))->addOption(newRoom->getName(), newRoom->roomDialog());
}
void Room :: addItem(Item* newItem) {
  Items.push_back(newItem);
  newItem->setDialog(d->selectPath(2));
  (d->selectPath(2))->addOption(newItem->getName(), newItem->getDialog());
}

int Room :: numberofItems() {
  return Items.size();
}

void Room :: addPuzzle(IObj* newPuzzle) {
  Puzzles.push_back(newPuzzle);
  newPuzzle->setDialog(d->selectPath(0));
  (d->selectPath(0))->addOption(newPuzzle->getName(), newPuzzle->getDialog());
}

int Room :: numberofPuzzles() {
  return Puzzles.size();
}

int Room :: numberofRooms() {
  return Rooms.size();
}

void Room::buildActionList(std::vector<Item*> Inventory) {
  delete d;
  d = new Dialog();
  std::vector<std::string> options;
  d->setName(Name);
  options.push_back("Interactions");
  options.push_back("Characters");
  options.push_back("Items");
  options.push_back("Rooms");
  d->setOutput(getDescription());
  d->setOptions(options);
  (d->selectPath(0))->setName("Interactions");
  (d->selectPath(1))->setName("Characters");
  (d->selectPath(2))->setName("Items");
  (d->selectPath(3))->setName("Rooms");
  for (int i = 0; i < Inventory.size(); i++)
    addItem(Inventory[i]);
  delete inter;
  inter = new DialogInterface(getName());
}

Dialog* Room::roomDialog() {
  return d;
}

void Room :: display() {
  inter->beginDialog(d);
}

void Room::setIsLighted(bool value) {
  IsLighted = value;
}

bool Room::getIsLighted() {
  return IsLighted;
}
