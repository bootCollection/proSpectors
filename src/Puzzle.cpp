#include"../include/Puzzle.h"
#include<iostream>
#include<string>

Puzzle :: Puzzle(std::string disc, std::string n) {
  setDescription(disc);
  setName(n);
}

Puzzle :: ~Puzzle() {
}

std::string Puzzle::getType() {
  return "puzzle";
}
