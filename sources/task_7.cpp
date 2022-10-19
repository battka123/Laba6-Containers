//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>

void reverseNum(std::list<int> &nums) {
  auto i = nums.begin();
  if (!nums.empty()) {
    for (; i != nums.end(); i++) {
      if (*i != 0) nums.emplace(i, (-1) * (*i));
    }
  }
}
