//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>

std::map<std::string, int> wordsMapCounter(const std::string& str) {
  std::map<std::string, int> cot;
  std::string word;
  if ((str.empty()) || (str == ".") || (str == " ") || (str == ",")) {
    return cot;
  }
  for (auto i : str) {
    if ((i != ' ') && (i != '.') && (i != ',')) {
      word += static_cast<char>(tolower(i));
    } else {
      if (!word.empty()) {
        if (cot.count(word) != 0) {
          cot[word]++;
        } else {
          cot.insert(make_pair(word, 1));
        }
      }
      word = "";
    }
  }
  if (!word.empty()) {
    if (cot.count(word) != 0) {
      cot[word]++;
    } else {
      cot.insert(make_pair(word, 1));
    }
  }
  return cot;
}
