/**
* @author Team Big Brain
* @date 2020-11
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "../include/ParseInterface.h"

bool ParseInterface::intInterface(int n) {
  iO.clear();
  std::string input;
  std::cout << "> ";
  std::cin >> input;
  if (i.parseString(input, n)) {
    iO = i.getOutput();
    return true;
  }
  return false;
}

bool ParseInterface::wordInterface(int n) {
  wO.clear();
  std::string input;
  ParseWord p;
  valid = false;
  std::cout << "> ";
  std::cin >> input;
  if (i.parseString(input, n)) {
    wO = w.getOutput();
    return true;
  }
  return false;
}

bool ParseInterface::blankInterface() {
  std::cout << "Press <Enter> to continue";
  std::getchar();
  std::getchar();
  return true;
}

std::vector<int> ParseInterface::getIntOut() {
  return iO;
}

std::vector<std::string> ParseInterface::getWordOut() {
  return wO;
}
