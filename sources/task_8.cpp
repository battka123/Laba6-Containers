//
// Created by Ivan on 13.10.2022.
//

#include <lab.hpp>

void plusesDeleter(std::vector<int>& v) {
  auto it = v.begin();
  for (; it != v.end();) {
    if (*it > 0) {
      v.erase(it);
    } else
      it++;
  }
}
