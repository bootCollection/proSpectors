/**
* @author Team Big Brain (CPSC 2720 Team B)
* @author Elliot Etches <elliot.etches@uleth.ca>
* @author Cameron Nickle <c.nickle@uleth.ca>
* @author Vishnu Undhad <undhadv@uleth.ca>
* @author Nathan Stewart <nathan.stewart@uleth.ca>
* @date 2020-11-29\n\n
*/

#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <cctype>
#include <vector>

/**
* Implements an Parse object. This allows the program to interact with the
* player.
*/
class Parse {
 public:
  /**
  * Destructor
  */
  virtual ~Parse() {}

  /**
  * Parses an input/command string
  * @param string input
  * @param int size
  * @return bool
  */
  virtual bool parseString(std::string, int) = 0;
};

class ParseInt : public Parse {
 public:
  /**
  * Parses an input/command string
  * @param string input
  * @param int size
  * @return bool
  */
  bool parseString(std::string in, int n);

  /**
  * Returns a vector of integers as output
  * @return vector int
  */
  std::vector<int> getOutput();
 private:
  /**
  * Checks to see if the input is an integer
  * @param string input
  * @return bool if true
  */
  bool checkInt(std::string in);
  std::vector<int> output;
};

class ParseWord : public Parse {
 public:
  /**
  * Parses an input/command string
  * @param string input
  * @param int size
  * @return bool
  */
  bool parseString(std::string in, int n);

  /**
  * Returns a vector of integers as output
  * @return vector int
  */
  std::vector<std::string> getOutput();
 private:
   /**
   * Sets a string to all CAPS
   * @param string input
   * @return string output
   */
  std::string capital(std::string);
  std::vector<std::string> output;
};
#endif
