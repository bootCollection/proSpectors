#include"../include/IObj.h"
#include<iostream>
#include <string>

IObj :: IObj() {
}

IObj :: IObj(std::string des, std::string name1) {
  description = des;
  name = name1;
}

std::string IObj::getDescription() {
  return description;
}
std::string IObj::getName() {
  return name;
}
bool IObj::getInteractable() {
  return interactable;
}
Dialog* IObj::getDialog() {
  return dialog;
}
void IObj::setName(std::string n) {
  name = n;
}
void IObj::setDescription(std::string d) {
  description = d;
}
void IObj::setInteractable(bool i) {
  interactable = i;
}
void IObj::setDialog(Dialog* d) {
  dialog = new Dialog(d);
  dialog->setName(name);
  dialog->setOutput(description);
}
