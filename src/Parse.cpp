#include "../include/Parse.h"
#include <string>
#include <vector>

std::vector<int> ParseInt::getOutput() {
  return output;
}

std::vector<std::string> ParseWord::getOutput() {
  return output;
}

bool ParseInt::parseString(std::string in, int n) {
  output.clear();
  int counter = 0;
  std::vector<int> intList;
  std::string temp;
  std::stringstream ssInput;
  ssInput << in;
  while (!ssInput.eof()) {
    ssInput >> temp;
    if (std::stringstream(temp) >> temp) {
      if (checkInt(temp)) {
        intList.push_back(stoi(temp));
        counter++;
      }
    }
    if (counter == n + 1) {
      return false;
    }
  }
  if (counter < 1) {
    return false;
  }
  output = intList;
  return true;
}

bool ParseInt::checkInt(std::string in) {
  char* c;
  strtol(in.c_str(), &c, 10);
  return(*c == 0);
}

bool ParseWord::parseString(std::string in, int n) {
  output.clear();
  int counter = 0;
  std::vector<std::string> stringList;
  std::string temp;
  std::stringstream ssInput;
  ssInput << in;
  while (!ssInput.eof()) {
    ssInput >> temp;
    if (std::stringstream(temp) >> temp) {
      for (int i = 0; i < temp.size(); i++)
        if (temp.at(i) < 'a' || temp.at(i) > 'Z')
          return false;
        stringList.push_back(capital(temp));
        counter++;
      }
    }
    if (counter == n + 1) {
      return false;
    }
  if (counter < 1) {
    return false;
  }
  output = stringList;
  return true;
}

std::string ParseWord::capital(std::string in) {
  std::string capital;
  for (int i = 0; i < in.size(); i++)
    capital.push_back(toupper(in[i]));
  return capital;
}
