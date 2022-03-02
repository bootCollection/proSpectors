#include <sstream>
#include <string>
#include <vector>
#include "../include/Parse.h"
#include "gtest/gtest.h"

TEST(TestParse, ParseIntTest) {
  std::string test;
  std::vector<int> out;
  ParseInt t;
  //Testing no inputs
  test = "";
  EXPECT_FALSE(t.parseString(test, 3));
  //Testing one input
  test = "1";
  EXPECT_TRUE(t.parseString(test, 1));
  out = t.getOutput();
  EXPECT_EQ(1, out[0]);
  //Testing two inputs
  test = "-11 32";
  EXPECT_TRUE(t.parseString(test, 2));
  out = t.getOutput();
  EXPECT_EQ(-11, out[0]);
  EXPECT_EQ(32, out[1]);
  //Testing three inputs
  test = "0 34 545";
  EXPECT_TRUE(t.parseString(test, 3));
  out = t.getOutput();
  EXPECT_EQ(0, out[0]);
  EXPECT_EQ(34, out[1]);
  EXPECT_EQ(545, out[2]);
  //Invalid input 1
  test = "F";
  EXPECT_FALSE(t.parseString(test, 1));
  //Invalid input 2
  test = "Falling down the stairs slow";
  EXPECT_FALSE(t.parseString(test, 3));
  //Intertwined parser
  test = "Falling 32 down -2 stairs slow 2";
  EXPECT_TRUE(t.parseString(test, 3));
  out = t.getOutput();
  EXPECT_EQ(32, out[0]);
  EXPECT_EQ(-2, out[1]);
  EXPECT_EQ(2, out[2]);
}

/*
TEST(TestParse, ParseWordTest) {
  std::string test;
  std::vector<std::string> out;
  ParseWord t;
  test = "test";
  EXPECT_TRUE(t.parseString(test, 1));
//  out = t.getOutput();
//  EXPECT_EQ("TEST", out[0]);
}
*/
