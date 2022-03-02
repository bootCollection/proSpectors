#include <sstream>
#include "../include/Puzzle.h"
#include "gtest/gtest.h"

TEST(TestPuzzle, constructorTest) {
  Puzzle *woodenBox1 = new Puzzle("big lump of potatoes", "magicMike");
EXPECT_EQ(woodenBox1->getType(), "puzzle");
delete woodenBox1;
}
