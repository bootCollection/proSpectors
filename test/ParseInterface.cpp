#include "ParseInterface.h"
#include "gtest/gtest.h"

TEST(ParseInterfaceTest, blankInterfaceTest) {
  ParseInterface pi;
  EXPECT_NO_THROW(pi.blankInterface());
}

TEST(ParseInterfaceTest, getIntOutTest) {
  ParseInterface pi;
  EXPECT_NO_THROW(pi.getIntOut());
}

TEST(ParseInterfaceTest, getWordOutTest) {
  ParseInterface pi;
  EXPECT_NO_THROW(pi.getWordOut());
}
