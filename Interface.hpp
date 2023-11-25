#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

namespace chess {

class Interface {
 public:
  Interface() = delete;
  Interface(const Interface&) = delete;
  Interface(Interface&&) = delete;
  Interface& operator=(const Interface&) = delete;
  Interface& operator=(Interface&&) = delete;

  static std::string greetings();
  static std::string getUserCommand();

  static void help();
  static void farewell();
  static void clearScreen();
};

}  // namespace chess

#endif