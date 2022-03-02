#include <sstream>
#include "../include/IObj.h"
#include "gtest/gtest.h"

TEST(TestIObj, setDescriptionTest) {
  IObj* coolMoonOrb = new IObj("cool and blue", "coolMoonOrb");
  coolMoonOrb->setDescription("*hovering all cool like*");
EXPECT_EQ(coolMoonOrb->getDescription(), "*hovering all cool like*");
delete coolMoonOrb;
}

TEST(TestIObj, setNameTest) {
  IObj* coolMoonOrb = new IObj("cool and blue", "coolMoonOrb");
  coolMoonOrb->setName("*hovering all cool like*");
EXPECT_EQ(coolMoonOrb->getName(), "*hovering all cool like*");
delete coolMoonOrb;
}

TEST(TestIObj, setInteractableTest) {
  IObj* coolMoonOrb = new IObj("cool and blue", "coolMoonOrb");
  bool a = true;
  coolMoonOrb->setInteractable(a);
EXPECT_TRUE(coolMoonOrb->getInteractable());
delete coolMoonOrb;
}

TEST(TestIObj, getDialogTest) {
  IObj* coolMoonOrb = new IObj("cool and blue", "coolMoonOrb");
  Dialog* hover = new Dialog();
  hover->setName("Poppy");
  EXPECT_NO_THROW(coolMoonOrb->getDialog());
  delete coolMoonOrb;
  delete hover;
}
