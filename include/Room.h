/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "NPC.h"
#include "Item.h"
#include "Puzzle.h"
#include "../include/IObj.h"
#include "../include/DialogInterface.h"

/**
* Implements a Room. This is an area where the use can interact with objects.
*/
class Room : public IObj {
 public:
    /**
    * Room Constructor
    * @param string Description the room description
    * @param string name the room name
    */
    Room(std::string description, std::string name);

    /**
    * Destructor
    */
    ~Room();

    /**
    * This function returns the room description
    * @return string Room description
    */
    //std::string getDescription();

    /**
    * This function displays the room contents
    */
    void display();

    /**
    * This function uses NPC class to add NPCs to the Room
    * @param pointer NPC to add for the room
    */
    void addNPC(NPC *);

    /**
    * This function returns the number of NPCs in the room
    * @return int number of NPCs
    */
    int numberofNPCs();

    /**
    * This function uses Puzzle class to add puzzles to the Room
    * @param pointer Puzzle to add for the room
    */
    void addPuzzle(IObj *);

    /**
    * This function returns the number of Puzzles in the room
    * @return int number of puzzles
    */
    int numberofPuzzles();

    /**
    * This function uses Item class to add items to the Room
    * @param pointer to Item to add for the room
    */
    void addItem(Item *);

    /**
    * This function returns the number of Items in the room
    * @return int number of Items in room
    */
    int numberofItems();

    /**
    * This function add Room
    * @param pointer to Room to add
    */
    void addRoom(Room*);

    /**
    * This function returns the number of Rooms.
    * @return int number of Rooms
    */
    int numberofRooms();

    /**
    * This function sets the direction for the north for the Room
    * @param string named North
    */
    void setNorth(std::string North);

    /**
    * This function sets the direction for the East for the Room
    * @param string named East
    */
    void setEast(std::string East);

    /**
    * This function sets the direction for the West for the Room
    * @param string named West
    */
    void setWest(std::string West);

    /**
    * This function sets the direction for the South for the Room
    * @param string named South
    */
    void setSouth(std::string South);

    /**
    * This function is no longer used.
    */
    void buildActionList(std::vector<Item*>);

    /**
    * This returns a pointer to the room Dialog
    * @return pointer to Dialog object
    */
    Dialog* roomDialog();

    /**
    * This sets the variable IsLighted
    * @param bool value
    */
    void setIsLighted(bool);

    /**
    * This gets the variable IsLighted
    * @return bool is lighted
    */
    bool getIsLighted();

 private:
  std::string Name;
  Dialog* d;
  DialogInterface* inter;
  std::vector<std::string> roomNames;
  //std::string Description;
  std::vector<NPC *> NPCs;
  std::vector<IObj *> Puzzles;
  std::vector<Item *> Items;
  std::vector<Room*> Rooms;
  //std::string Name;
  std::string North;
  std::string South;
  std::string East;
  std::string West;
  bool IsLighted;
};
#endif
