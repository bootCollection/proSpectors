#include "../include/Dialog.h"
#include <iostream>
#include <string>
#include <vector>

Dialog::Dialog(Dialog* n) {
  available = new bool(true);
  previous = n;
  visited = new bool(false);
  size = 0;
}

void Dialog::setName(std::string s) {
  name = s;
}

std::string Dialog::getName() {
  return name;
}

void Dialog::changeOption(int n, std::string s) {
  options[n] = s;
}

Dialog::~Dialog() {
  while (!paths.empty()) delete paths.back(), paths.pop_back();
  paths.clear();
  delete available;
  delete visited;
}

void Dialog::setOutput(std::string in) {
  output = in;
}

void Dialog::setOptions(std::vector<std::string> in) {
  options = in;
  for (int i = 0; i < options.size(); i++)
    paths.push_back(new Dialog(this));
  size = in.size();
}

void Dialog::setEnabled(bool* n) {
  delete available;
  available = n;
}

void Dialog::setVisited() {
  *(visited) = true;
}

std::string Dialog::getOutput() {
  return output;
}

std::vector<std::string> Dialog::getOptions() {
  return options;
}

bool* Dialog::getEnabled() {
  return available;
}

bool* Dialog::getVisited() {
  return visited;
}

Dialog* Dialog::selectPath(int n) {
  return paths[n];
}

int Dialog::getSize() {
  return size;
}

Dialog* Dialog::getPrevious() {
  return previous;
}

void Dialog::setPrevious(Dialog* d) {
  delete previous;
  previous = d;
}

void Dialog::addOption(std::string s, Dialog* d) {
  options.push_back(s);
  paths.push_back(d);
  size++;
}

void Dialog::deletePrevious() {
  delete previous;
  previous = nullptr;
}
