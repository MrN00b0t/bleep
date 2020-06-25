#include <iostream>
#include <string>
#include "functions.hpp"

int main() {

  std::string word = "broccoli";
  std::string text = "Tonight's meal, broccoli bake, consists mostly of broccoli florets basted in a rich broccoli sauce.";
  //call our bleep function
  bleep(word, text);
  //display our censored text
  std::cout << text + "\n";
  
}