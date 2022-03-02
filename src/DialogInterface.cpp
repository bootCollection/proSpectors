#include <iostream>
#include <string>
#include <vector>
#include "../include/DialogInterface.h"
#include "../include/ParseInterface.h"
DialogInterface::DialogInterface(std::string n) {
  name = n;
}

void DialogInterface::beginDialog(Dialog* dia) {
  if (system("CLS")) system("clear");
  std::cout << "-===" << dia->getName() << "===-" << std::endl;
  printOptions(dia);
  while (!selectOption(dia)) {
      //std::cout << "Invalid input, please try again!" << std::endl;
      //p.blankInterface();
    if (system("CLS")) system("clear");
    std::cout << "-===" << dia->getName() << "===-" << std::endl;
    printOptions(dia);
  }
  if (selc == dia->getSize()) {
    beginDialog(dia->getPrevious());
  }
  if (!(selc == 8)) {
    beginDialog(dia->selectPath(selc));
  }
}

void DialogInterface::printOptions(Dialog* d) {
  d->setVisited();
  int count = 1;
  std::vector<std::string> opt = d->getOptions();
  std::cout << d->getOutput() << std::endl;
  for (int i = 0; i < d->getSize(); i++) {
    if (*(d->selectPath(i)->getEnabled())) {
      std::cout << "[";
      if (*(d->selectPath(i)->getVisited())) {
        std::cout << "X";
      } else {
        std::cout << " ";
      }
      std::cout<< "]-" << count << " :: ";
      std::cout << opt[i] << std::endl;
    } else {
      std::cout << "[\\]-" << count << " :: " << std::endl;
    }
    count++;
  }
  if (d->getPrevious()!= nullptr) {
    std::cout << "[P]-" << count << " :: ";
    std::cout << "Return to previous options" << std::endl;
    count++;
  }
  std::cout << std::endl;
  std::cout << "[E]-9 :: " << "Exit" << std::endl;
  std::cout << "[H]-10 :: " << "Help" << std::endl;
  std::cout << std::endl;
}

bool DialogInterface::selectOption(Dialog* d) {
  int select;
  std::cout << "Please enter your selection:" << std::endl;
  if (!p.intInterface(1)) {
    return false;
  }
  select = ((p.getIntOut()).at(0));
  if (select == 10) {
    help();
  }
  if ((select == d->getSize() + 1) && (d->getPrevious()!= nullptr)) {
    selc = select - 1;
    return true;
  }
  if (select == 9) {
    selc =  8;
    return true;
  }
  if (select < 1 || (select > d->getSize() && select != 9)) {
    return false;
  }
  if (!(*((d->selectPath(select - 1))->getEnabled()))) {
    return false;
  }
  selc = select - 1;
  return true;
}

void DialogInterface::setName(std::string s) {
  name = s;
}

void DialogInterface::help() {
  if (system("CLS")) system("clear");
  std::cout << "+==[HELP]==+" << std::endl;
  std::cout << "Input valid numbers that corospond to the commands available."
  << std::endl << std::endl
  << "-Previously visited items will be marked with [X]."
  << std::endl << std::endl
  <<"-To return to the last list of options use the previous command marked [P]"
  << std::endl << std::endl
  << "-Exit at any time using the exit command marked [E]"
  << std::endl << std::endl
  << "-If the only option available to you is to exit, use the exit command."
  << std::endl << std::endl
  << "-If you become stuck consult with the characters."
  << std::endl
  << "Good luck!"
  << std::endl << std::endl;
  p.blankInterface();
}
