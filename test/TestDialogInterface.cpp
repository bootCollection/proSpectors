#include <sstream>
#include <string>
#include <vector>
#include "../include/DialogInterface.h"
#include "gtest/gtest.h"

TEST(TestDialogInterface, constructorTest) {
  DialogInterface* radio = new DialogInterface("buzz");
  radio->setName("radio :)");
EXPECT_NO_THROW(radio->setName("radio :)"));
delete radio;
}
/*
TEST(TestDialogInterface, beginDialogTest) {
  DialogInterface* radio = new DialogInterface("buzz");
  Dialog *lad1 = new Dialog();
  //radio->beginDialog(lad1);
  EXPECT_NO_THROW(radio->beginDialog(lad1));
  delete radio;
}
*/
