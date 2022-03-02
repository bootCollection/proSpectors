#include <sstream>
#include "../include/NPC.h"
#include "gtest/gtest.h"

TEST(TestNPC, constructorTest) {
  NPC *cook1 = new NPC("big lump of potatoes", "magicMike");
EXPECT_EQ(cook1->getType(), "npc");
delete cook1;
}

TEST(TestNPC, addItemTest) {
  NPC *cook1 = new NPC("big lump of potatoes", "magicMike");
  Item *item1 = new Item("stick", "wooden");
  Item *item2 = new Item("stick2", "wooden2");
  Item *item3 = new Item("stick3", "wooden3");
EXPECT_TRUE(cook1->addItem(item1));
EXPECT_TRUE(cook1->addItem(item2));
EXPECT_FALSE(cook1->addItem(item2));
delete cook1;
delete item1;
delete item2;
delete item3;
}
