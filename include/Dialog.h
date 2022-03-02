/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef DIALOG_H
#define DIALOG_H
#include <iostream>
#include <string>
#include <vector>

/**
* Implements a Dialog. This is an interaction with an object or character.
*/
class Dialog {
 public:
  /**
  * Constructor
  * @param pointer Dialog
  */
  Dialog(Dialog* n = nullptr);

  /**
  * Destructor
  */
  ~Dialog();

  /**
  * This function sets the name of the Dialog
  * @param string name
  */
  void setName(std::string);

  /**
  * This function gets the name of the Dialog
  * @return string name
  */
  std::string getName();

  /**
  * This function sets the Dialog output
  * @param string output
  */
  void setOutput(std::string);

  /**
  * This function sets the Dialog options
  * @param vector string output
  */
  void setOptions(std::vector<std::string>);

  /**
  * This function sets the Dialog to enabled
  * @param pointer bool
  */
  void setEnabled(bool*);

  /**
  * This function sets the Dialog to Visited
  */
  void setVisited();

  /**
  * This function gets the Dialog output
  * @return string output
  */
  std::string getOutput();

  /**
  * This function gets the Dialog options
  * @return vector string options
  */
  std::vector<std::string> getOptions();

  /**
  * This function gets the Dialog enabled
  * @return pointer bool enabled
  */
  bool* getEnabled();

  /**
  * This function gets the Dialog visited
  * @return pointer bool visited
  */
  bool* getVisited();

  /**
  * This function gets the Dialog size
  * @return int size
  */
  int getSize();

  /**
  * This function gets the previous Dialog
  * @return pointer Dialog
  */
  Dialog* getPrevious();

  /**
  * This function gets the Dialog path
  * @param int
  * @return pointer Dialog
  */
  Dialog* selectPath(int);

  /**
  * This function adds an option to the dialog
  * @param string
  * @param pointer Dialog
  */
  void addOption(std::string, Dialog*);

  void setPrevious(Dialog* d);

  void changeOption(int, std::string);

  void deletePrevious();

 private:
  std::string name;
  std::string output;
  std::vector<std::string> options;
  std::vector<Dialog*> paths;
  Dialog* previous;
  bool* available;
  bool* visited;
  int size;
};
#endif
