#include"../include/Item.h"
#include<iostream>
#include <string>

Item :: Item(std::string pT, std::string name) {
  setDescription(pT);
  setName(name);
}

Item :: ~Item() {
}

std::string Item::getType() {
  return "item";
}
