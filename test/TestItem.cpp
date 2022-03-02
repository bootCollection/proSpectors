#include <sstream>
#include "../include/Item.h"
#include "gtest/gtest.h"

TEST(TestItem, constructorTest) {
  Item *coolMoonOrb = new Item("cool and blue", "coolMoonOrb");
  EXPECT_EQ(coolMoonOrb->getName(), "coolMoonOrb");
  delete coolMoonOrb;
}

TEST(TestItem, getTypeTest) {
  Item *coolMoonOrb = new Item("cool and blue", "coolMoonOrb");
  EXPECT_EQ(coolMoonOrb->getType(), "item");
  delete coolMoonOrb;
}
