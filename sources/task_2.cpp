//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first,
                                        std::vector<int>::iterator last,
                                        int el) {
  if (first != last) {
    while (first != last) {
      if (*first == el) return first;
      ++first;
    }
    return last;
  } else
    return last;
}
