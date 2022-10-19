//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>

int wordsCounter(const std::string& str) {
  short k = 1;
  size_t len = str.size();
  if ((len != size_t(1)) && (len != size_t(0))) {
    for (size_t i = 0; i < len; i++) {
      if (((str[i] == ' ') || (str[i] == ',') || (str[i] == '.')) &&
          ((str[i + 1] != ' ') && (str[i + 1] != ',') && (str[i + 1] != '.'))) {
        k++;
      }
    }
    return k;
  } else
    return 0;
}
