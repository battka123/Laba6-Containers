//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>
#include <set>

std::vector<std::string> uniqueWords(const std::string& str) {
  std::set<std::string> words;
  std::string word;
  std::vector<std::string> unique;
  if ((str.empty()) || (str == ".") || (str == " ") || (str == ",")) {
    return unique;
  }
  for (auto i : str) {
    if ((i != ' ') && (i != '.') && (i != ',')) {
      word += i;
    } else {
      if (!word.empty()) {
        words.insert(word);
      }
      word = "";
    }
  }
  if (!word.empty()) {
    words.insert(word);
  }
  auto it = words.begin();
  while (it != words.end()) {
    unique.push_back(*it);
    ++it;
  }
  return unique;
}
