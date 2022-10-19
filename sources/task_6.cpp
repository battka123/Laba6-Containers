//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>
#include <set>

int diffWordsCounter(const std::string& str) {
  std::set<std::string> count;
  std::string word;
  if ((str.empty()) || (str == ".") || (str == " ") || (str == ",")) {
    return 0;
  }
  for (auto i : str) {
    if ((i != ' ') && (i != '.') && (i != ',')) {
      word += i;
    } else {
      if (!word.empty()) {
        count.insert(word);
      }
      word = "";
    }
  }
  if (!word.empty()) {
    count.insert(word);
  }
  return static_cast<int>(count.size());
}
