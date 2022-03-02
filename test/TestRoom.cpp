#include <sstream>
#include "../include/Room.h"
#include "Puzzle.h"
#include "../include/NPC.h"
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestRoom, constructorTest) {
  Room r("Room of Doom", "DeathRoom1");
  EXPECT_EQ("Room of Doom", r.getDescription());
}

TEST(TestRoom, addNPCTest) {
  Room* r1 = new Room("Just a room", "Room1");
  NPC* guard1 = new NPC("A dim looking spark", "Burny");
  r1->buildActionList(guard1->getInventory());
  EXPECT_NO_THROW(r1->addNPC(guard1));
  EXPECT_EQ(1, r1->numberofNPCs());
  //delete guard1;
  delete r1;
}

TEST(TestRoom, addItemTest) {
  Room* r1 = new Room("Just a room", "Room1");
  Item* it = new Item("yo", "Smells like genocide");
  NPC* guard1 = new NPC("A dim looking spark", "Burny");
  r1->buildActionList(guard1->getInventory());
  // r1->addItem(it);
  EXPECT_NO_THROW(r1->addItem(it));
  EXPECT_EQ(r1->numberofItems(), 1);
//  EXPECT_NO_THROW(r1->display());
  //delete it;
  delete guard1;
  delete r1;
  delete it;
}

TEST(TestRoom, addPuzzleTest) {
  Room* r1 = new Room("Just a room", "Room1");
  Puzzle* pz = new Puzzle("spooky", "eyye");
  NPC* guard1 = new NPC("A dim looking spark", "Burny");
  r1->buildActionList(guard1->getInventory());
//  r1->addPuzzle(pz);
  EXPECT_NO_THROW(r1->addPuzzle(pz));
  EXPECT_EQ(r1->numberofPuzzles(), 1);
//dd  EXPECT_NO_THROW(r1->display());
// delete pz;
delete guard1;
delete r1;
}

TEST(TestRoom, addRoomTest) {
  Room* r1 = new Room("Just a room", "Room1");
//  Room* r2 = new Room("Just a room, sorta", "Room2");
  Item* it = new Item("NapSack", "Smells like genocide");
  NPC* guard1 = new NPC("A dim looking spark", "Burny");
  r1->buildActionList(guard1->getInventory());
// EXPECT_NO_THROW(r1->addRoom(r1));
  EXPECT_EQ(0, r1->numberofRooms());
// delete r2;
  delete r1;
//  delete r2;
  delete it;
  delete guard1;
}

TEST(TestRoom, getIsLightedTest) {
    Room* r1 = new Room("Just a room", "Room1");
    EXPECT_NO_THROW(r1->getIsLighted());
    delete r1;
}
/*
TEST(TestRoom, displayTest) {
  Room* r1 = new Room("Just a room", "Room1");
  Item* it = new Item("t1", "NapSack", "Smells like genocide");
  NPC* guard1 = new NPC("A dim looking spark", "Burny");
  r1->buildActionList(guard1->getInventory());
  EXPECT_NO_THROW(r1->display());
}
*/
TEST(TestRoom, setIsLightedTest) {
  Room* r1 = new Room("Just a room", "Room1");
  bool a = true;
  r1->setIsLighted(a);
  EXPECT_TRUE(r1->getIsLighted());
  delete r1;
}
