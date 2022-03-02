#include<iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "../include/Game.h"
#include "../include/Room.h"
#include "../include/NPC.h"
#include "../include/Dialog.h"

Game :: Game() {
}

Game :: ~Game() {
  while (!inventory.empty()) delete inventory.back(), inventory.pop_back();
  inventory.clear();
}

bool Game::surface() {
  std::vector<std::string> str;
  str.push_back("Illuminator");
  bool* A, *B, *C, *D, *E;
  Room t("The base camp Enterence", "Surface Camp");
  t.buildActionList(inventory);
  NPC* a = new NPC("Short and redheaded", "Alex Tanner");
  NPC* b = new NPC("Dirty coveralls and a beaming smile", "Beth Armstrong");
  NPC* c = new NPC("A long beard and worn boots", "Charlie Paul");
  NPC* d = new NPC("Young and blonde", "Dan Borne");
  IObj* e = new IObj("A crystal lattice encased in wrought iron",
  "Illuminator");
  Room* r = new Room("Head on to the depths bellow", "Mineshaft Elevator");
  Item* it = new Item("A crystal lattice encased in wrought iron",
  "Illuminator");
  inventory.push_back(it);
  //Alex
  t.addNPC(a);
  a->getDialog()->addOption("What's your role?",
  new Dialog(a->getDialog()));
  a->getDialog()->selectPath(0)->setOutput("I'm the teamleader of this crew.");
  a->getDialog()->addOption("Anything I need to do?",
  new Dialog(a->getDialog()));
  hold = "Go talk to beth, make sure the seismic checks out for today";
  a->getDialog()->selectPath(1)->setOutput(hold);
  //Beth
  t.addNPC(b);
  b->getDialog()->addOption("What's your role?",
  new Dialog(b->getDialog()));
  hold = "I'm a geologist by trade, I work the samples.";
  b->getDialog()->selectPath(0)->setOutput(hold);
  b->getDialog()->addOption("Anything I need to do?",
  new Dialog(b->getDialog()));
  hold = "Talk to to Mr. Paul and get your illuminator";
  b->getDialog()->selectPath(1)->setOutput(hold);
  //Charlie
  t.addNPC(c);
  c->getDialog()->addOption("What's your role?",
  new Dialog(c->getDialog()));
  hold = "I'm the teams engineer.";
  c->getDialog()->selectPath(0)->setOutput(hold);
  c->getDialog()->addOption("Anything I need to do?",
  new Dialog(c->getDialog()));
  hold = "Go grab your illuminator off the table top.";
  c->getDialog()->selectPath(1)->setOutput(hold);
  //Dan
  t.addNPC(d);
  d->getDialog()->addOption("What's your role?",
  new Dialog(c->getDialog()));
  hold = "I'm a labourer";
  d->getDialog()->selectPath(0)->setOutput(hold);
  t.addPuzzle(e);
  t.addRoom(r);
  t.addItem(it);
  t.roomDialog()->selectPath(2)->changeOption(0, "Illuminator");
  it->getDialog()->setEnabled(e->getDialog()->getVisited());
  A = a->getDialog()->getVisited();
  B = b->getDialog()->getVisited();
  b->getDialog()->setEnabled(A);
  C = c->getDialog()->getVisited();
  c->getDialog()->setEnabled(B);
  r->roomDialog()->setEnabled(C);
  E = e->getDialog()->getVisited();
  t.display();
  illum = *(e->getDialog()->getVisited());
  if (*(r->roomDialog()->getVisited())) {
    return caveIn();
  }
  return false;
}
bool Game::caveIn() {
  bool* A, *B, *C, *E;
  hold = "The roof of the passage collapes, trapping you inside.";
  Room t(hold, "The Cave In");
  t.buildActionList(inventory);
  NPC* a = new NPC("Shaken up, but still present", "Alex");
  NPC* b = new NPC("Completely calm", "Beth");
  NPC* c = new NPC("Completely hysterical", "Charlie");
  NPC* d = new NPC("Trapped beneath the rubble unresponsive and not breathing",
  "Dan Borne");
  Room* r = new Room("Leads to the abandoned survey camp", "Dark Passage");
  inventory[0]->getDialog()->addOption("Ignite the Illuminator",
  new Dialog(inventory[0]->getDialog()));
  inventory[0]->getDialog()->setEnabled(&illum);
  //Alex
  t.addNPC(a);
  a->getDialog()->addOption("What should we do?",
  new Dialog(a->getDialog()));
  hold = "Check on Dan, and keep an eye on whatever is moving in the shadows";
  a->getDialog()->selectPath(0)->setOutput(hold);
  //Beth
  t.addNPC(b);
  b->getDialog()->addOption("What should we do?",
  new Dialog(b->getDialog()));
  hold = "The map has a survey camp 300 yards to our west down the shaft.";
  b->getDialog()->selectPath(0)->setOutput(hold);

  //Charlie
  t.addNPC(c);
  c->getDialog()->addOption("What should we do?",
  new Dialog(c->getDialog()));
  hold = "They're in the shadows! They don't enter the light! Keep the light!";
  c->getDialog()->selectPath(0)->setOutput(hold);
  t.addNPC(d);
  t.addRoom(r);
  A = inventory[0]->getDialog()->selectPath(0)->getVisited();
  B = r->roomDialog()->getVisited();
  t.display();
  if (*A && *B) {
    return theCamp();
  } else if (!*A && *B) {
    std::cout << "The creatures of the dark pounce upon you" << std::endl;
    return false;
  }
  return false;
}

bool Game::theCamp() {
  bool* A, *B, *C, *E;
  Room t("An abandoned mining camp", "The Camp");
  t.buildActionList(inventory);
  //t.roomDialog()->selectPath(2)->changeOption(0, "Illuminator");
  NPC* a = new NPC("Searching for supplies", "Alex");
  NPC* b = new NPC("Pouring through the camps records", "Beth");
  NPC* c = new NPC("Signifigantly calmer then before", "Charlie");
  Room* r = new Room("A sturdy metal door controlled by the electric system",
  "The Door");
  IObj* e = new IObj("A broken generator, surounded by various parts",
  "Generator");
  IObj* book = new IObj("A botany field guide, still in the hands of its owner",
  "Botany Field Guide");
  Item* it = new Item("Useful in descerning between various flora and fauna",
  "Botany Field Guide");
  inventory.push_back(it);
  //Alex
  t.addNPC(a);
  a->getDialog()->addOption("How should we proceed?",
  new Dialog(a->getDialog()));
  hold = "Getting the generator running is the priority, will see from there.";
  a->getDialog()->selectPath(0)->setOutput(hold);
  //Beth
  t.addNPC(b);
  b->getDialog()->addOption("How's the state of the camp?",
  new Dialog(b->getDialog()));
  hold = "It seems that they where overrun, we haven't found a living soul";
  b->getDialog()->selectPath(0)->setOutput(hold);
  //Charlie
  t.addNPC(c);
  c->getDialog()->addOption("How should I get the generator running",
  new Dialog(c->getDialog()));
  hold = "Change the spark plugs, fuel it with gasoline and pull the cord.";
  c->getDialog()->selectPath(0)->setOutput(hold);
  t.addRoom(r);
  t.addPuzzle(e);
  t.addPuzzle(book);
  t.addItem(it);
  it->getDialog()->setEnabled(book->getDialog()->getVisited());
  e->getDialog()->addOption("Change the spark plugs",
  new Dialog(e->getDialog()));
  e->getDialog()->addOption("Pour in gasoline",
  new Dialog(e->getDialog()));
  e->getDialog()->addOption("Pour in diesel", new Dialog());
  e->getDialog()->addOption("Pull the starter cord",
  new Dialog(e->getDialog()));
  E = e->getDialog()->selectPath(3)->getVisited();
  r->roomDialog()->setEnabled(E);
  t.display();
  guide = *(book->getDialog()->getVisited());
  if (*(r->roomDialog()->getVisited())) {
    return lushCavern();
  }
  std::cout << "The generator was destroyed" << std::endl;
  return false;
}

bool Game::lushCavern() {
  bool* A, *B, *C, *E;
  hold = "A heavily vegetated cavery with an flooded and electrified passage";
  Room t(hold, "Lush Cavern");
  t.buildActionList(inventory);
  Room* r = new Room("A small passage flooded with electrified water",
   "Electrified Passage");
  Room* c = new Room("The doorway back to the abandoned camp",
  "The Camp");
  IObj* e = new IObj("A number of distinctively coloured mushrooms",
  "Mushrooms");
  t.addPuzzle(e);
  t.addRoom(r);
  t.addRoom(c);
  inventory[1]->getDialog()->addOption("Spotted Lecher",
  new Dialog(inventory[1]->getDialog()));
  hold = "Red with white spots - Highly poisonous";
  inventory[1]->getDialog()->selectPath(0)->setOutput(hold);
  inventory[1]->getDialog()->addOption("Brisben Lightning",
  new Dialog(inventory[1]->getDialog()));
  hold = "Red with blue stripes - Grants immunity to electricity";
  inventory[1]->getDialog()->selectPath(1)->setOutput(hold);
  inventory[1]->getDialog()->addOption("Townsman's Bane",
  new Dialog(inventory[1]->getDialog()));
  hold = "Blue with streaks of orange - Highly poisonous";
  inventory[1]->getDialog()->selectPath(2)->setOutput(hold);
  e->getDialog()->addOption("Mushroom A",
  new Dialog(e->getDialog()));
  hold = "Blue with streaks of orange.";
  e->getDialog()->selectPath(0)->setOutput(hold);
  e->getDialog()->selectPath(0)->addOption("Consume",
  new Dialog());
  e->getDialog()->addOption("Mushroom B",
  new Dialog(e->getDialog()));
  hold = "Red with white spots.";
  e->getDialog()->selectPath(1)->setOutput(hold);
  e->getDialog()->selectPath(1)->addOption("Consume",
  new Dialog());
  e->getDialog()->addOption("Mushroom C",
  new Dialog(e->getDialog()));
  hold = "Red with blue stripes.";
  e->getDialog()->selectPath(2)->setOutput(hold);
  e->getDialog()->selectPath(2)->addOption("Consume",
  new Dialog(e->getDialog()));
  E = e->getDialog()->selectPath(2)->selectPath(0)->getVisited();
  r->roomDialog()->setEnabled(E);
  inventory[1]->getDialog()->setEnabled(&guide);
  t.display();
  if (*(r->roomDialog()->getVisited())) {
    return explosivesCache();
  }
  if (*(c->roomDialog()->getVisited())) {
    return backCamp();
  }
  std::cout << "You have poisoned yourself with mushrooms" << std::endl;
  return false;
}

bool Game::backCamp() {
  Room t("An abandoned mining camp", "The Camp");
  t.buildActionList(inventory);
  NPC* a = new NPC("Sitting infront of the fire", "Alex");
  NPC* b = new NPC("Reading records", "Beth");
  NPC* c = new NPC("Eating the camp rations", "Charlie");
  Room* r = new Room("A sturdy metal door controlled by the electric system",
  "The Door");
  IObj* book = new IObj("A botany field guide, still in the hands of its owner",
  "Botany Field Guide");
  //Alex
  t.addNPC(a);
  //Beth
  t.addNPC(b);
  //Charlie
  t.addNPC(c);
  t.addRoom(r);
  if (!guide) {
    t.addPuzzle(book);
    inventory[1]->getDialog()->setEnabled(book->getDialog()->getVisited());
  }
  t.display();
  if (!guide)
    guide = *(book->getDialog()->getVisited());
  if (*(r->roomDialog()->getVisited())) {
    return lushCavern();
  }
  return false;
}

bool Game::explosivesCache() {
  bool* A, *B, *C, *E;
  Room t("Stockpiles of explosives used during mining operations",
   "Explosives Cache");
  t.buildActionList(inventory);
  Room* c = new Room("Confer with your peers",
  "Return to the Camp");
  IObj* e = new IObj("A collection of casings, filler, and blasting caps",
  "Explosives");
  t.addRoom(c);
  if (!explosives) {
    t.addPuzzle(e);
    e->getDialog()->addOption("Fill with 100g",
    new Dialog());
    e->getDialog()->selectPath(0)->addOption("Fill",
    new Dialog());
    e->getDialog()->addOption("Fill with 500g",
    new Dialog(e->getDialog()));
    e->getDialog()->selectPath(0)->addOption("Fill",
    new Dialog());
    e->getDialog()->addOption("Fill with 1000g",
    new Dialog());
  }
  t.display();
  if (!explosives)
    explosives = *(e->getDialog()->selectPath(1)->getVisited());
  if (*(c->roomDialog()->getVisited())) {
    return campEx();
  }
  std::cout << "The incorrect ammount of filler causes the explosive to ignite";
  return false;
}

bool Game::campEx() {
  Room t("An abandoned mining camp", "The Camp");
  t.buildActionList(inventory);
  NPC* a = new NPC("Sitting infront of the fire", "Alex");
  NPC* b = new NPC("Reading records", "Beth");
  NPC* c = new NPC("Eating the camp rations", "Charlie");
  Room* r = new Room("Return to the explosives cache",
  "The Cache");
  Room* cave = new Room("Return to the cave in",
  "The Cave In");
  if (explosives) {
    Item* it = new Item("Blasting explosives for clearing debris.",
    "Explosive");
    inventory.push_back(it);
  }
  //Alex
  t.addNPC(a);
  //Beth
  t.addNPC(b);
  //Charlie
  t.addNPC(c);
  c->getDialog()->addOption("How much filler should I add to the explosives?",
  new Dialog(c->getDialog()));
  hold = "Use exactly 500g, anything more or less and it could be dangerous.";
  c->getDialog()->selectPath(0)->setOutput(hold);
  t.addRoom(r);
  if (explosives) {
    t.addRoom(cave);
  }
  t.display();
  if (*(cave->roomDialog()->getVisited())) {
    return theEscape();
  }
  if (*(r->roomDialog()->getVisited())) {
    return explosivesCache();
  }
  return false;
}

bool Game::theEscape() {
  hold = "The rubble remains, the generator lights beat back the shadows.";
  Room t(hold, "The Cave In");
  t.buildActionList(inventory);
  NPC* d = new NPC("Partly devoured with long claw marks running across him.",
  "Dan Borne");
  t.addNPC(d);
  inventory[2]->getDialog()->addOption("Place and detonate the explosives",
  new Dialog());
  t.display();
  if (*(inventory[2]->getDialog()->selectPath(0)->getVisited())) {
    return true;
  }
  return false;
}

void Game :: initializeRooms() {
}

void Game :: initializedDialog() {}

void Game :: run() {
  if (system("CLS")) system("clear");
  std::cout << "It has been fifty years since man began exploring the wonders"
  << " of the world beneath." << std::endl << std::endl
  << "Creaking shafts driven through the earth brought out riches and horrors"
  << " beyond imagination." << std::endl << std::endl
  << "Allured by the temptation of riches you have set out to the eastern"
  << " mining camps in search of fortune." << std::endl << std::endl
  << "Only time will tell whether you will find fortune, or calamity."
  << std::endl << std::endl;
  std::cout << "Press <Enter> to begin:";
  std::getchar();
  if (surface()) {
    std::cout << "You have escape without fortune, but with your life."
    << std::endl;
    parse.blankInterface();
    if (system("CLS")) system("clear");
  } else {
    std::cout << "The mines have layed claim to you eternal." << std::endl;
    parse.blankInterface();
    if (system("CLS")) system("clear");
  }
}
