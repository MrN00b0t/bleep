#include <iostream>
#include <string>
#include "functions.hpp"

//print comments included for debugging

void bleep(std::string word, std::string &text){

  //temporary storage string as we work through text
  std::string temp;
  //punc defines some basic punctuation
  std::string punc = " ,.!?";
  //start and end will be pointers to indexes of text
  int start = 0;
  int end = 0;
  //puncflag toggles when punctuation is detected to format temp
  bool puncflag = false;
  //outer for loop iterates over each character of text, adding it to temp
  for (int i = 0; i < text.size(); i++){
    //inner for loop iterates over the punctuation
    for (int k = 0; k < punc.size(); k++){
    //if punctuation detected, there is a word break. Need to check preceding word.
    if (text[i] == punc[k]) {
 //     std::cout << "Punctuation detected!\n";
 //     std::cout << temp << "\n";
 //   boolean function call to check if temp is the target word
      if (check(temp, word)){
 //       std::cout << "Word detected!\n";
 //     logic to replace characters in text using start and end index pointers
        end = i - 1;
 //       std::cout << start << "\n";
 //       std::cout << end << "\n";
        for (int j = start; j <= end; j++){
          text[j] = '*';
        }
        }
  //    flush temp, set new start pointer, and flag a punctuation detection
        temp = "";
        start = i + 1;
        puncflag = true;
        continue;     
  //    check for edge case where target word is at end of text and unpunctuated
    } else if (i == (text.size() - 1)) {
  //    std::cout << "End of text detected!\n";
      if (check(temp,word)){
// logic similar to above, only end pointer is different
        end = i;
        for (int j = start; j > end; j++){
        text[j] = '*';
        }
        continue;
      }
    }
  }
//  if current character is word break punctuation, don't want it added to temp
  if (puncflag){
    puncflag = false;
    continue;
    
  } else {
// if it is just a normal character, add to temp
    temp += text[i];

  }
}
}

//simple logic to check each word parsed against target word
bool check(std::string const &string1, std::string const &string2){

  if (string1 == string2){

    return true;

  } 
  return false;
}