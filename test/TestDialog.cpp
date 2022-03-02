#include <sstream>
#include <string>
#include <vector>
#include "../include/Dialog.h"
#include "gtest/gtest.h"

TEST(TestDialog, constructorTest) {
  Dialog *lad1 = new Dialog();
  lad1->setOutput("hi");
EXPECT_EQ(lad1->getOutput(), "hi");
delete lad1;
}

TEST(TestDialog, setNameTest) {
  Dialog *lad1 = new Dialog();
  lad1->setName("Poppy");
EXPECT_EQ(lad1->getName(), "Poppy");
delete lad1;
}

TEST(TestDialog, setOutputTest) {
  Dialog *lad1 = new Dialog();
  Dialog *lad2 = new Dialog();
  lad1->setOutput("hi");
  lad2->setOutput("hello");
EXPECT_NO_THROW(lad1->setOutput("hi"));
EXPECT_NE(lad1->getOutput(), "hello");
delete lad1;
delete lad2;
}

TEST(TestDialog, setOptionsTest) {
  Dialog *lad1 = new Dialog();
  std::vector<std::string> a;
  // a = lad1->getOptions();
  EXPECT_EQ(lad1->getSize(), 0);
  EXPECT_NO_THROW(lad1->setOptions(lad1->getOptions()));
  delete lad1;
}

TEST(TestDialog, setVisitedTest) {
  Dialog *lad1 = new Dialog();
  lad1->setVisited();
  EXPECT_TRUE(lad1->getVisited());
  delete lad1;
}


TEST(TestDialog, setEnabledTest) {
  Dialog *lad1 = new Dialog();
  bool* temp = new bool;
  EXPECT_NO_THROW(lad1->setEnabled(temp));
  EXPECT_NO_THROW(lad1->getEnabled());
  delete lad1;
}


TEST(TestDialog, addOptionTest) {
  Dialog *pleb = new Dialog();
  Dialog *lad1 = new Dialog();
  std::string ball = "PLAY BALL!";
  pleb->addOption(ball, lad1);
  // original
  // EXPECT_NO_THROW(pleb->selectPath(10));
  EXPECT_NO_THROW(pleb->selectPath(0));
  EXPECT_NO_THROW(pleb->getPrevious());
  EXPECT_EQ(pleb->getSize(), 1);
//  delete lad1;
  delete pleb;
}

TEST(TestDialog, setPreviousTest) {
  Dialog *lad1 = new Dialog();
  Dialog *lad2 = new Dialog();
  EXPECT_NO_THROW(lad1->setPrevious(lad2));
  // lad1->setPrevious(lad2);
  // EXPECT_NO_THROW(lad1->deletePrevious());
  delete lad1;
  delete lad2;
}
