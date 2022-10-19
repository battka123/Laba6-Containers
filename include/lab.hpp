//
// Created by Ivan on 13.10.2022.
//
#ifndef INCLUDE_LAB_HPP_
#define INCLUDE_LAB_HPP_

#include <list>
#include <map>
#include <string>
#include <vector>
// Task_1
std::vector<int>::iterator Find(std::vector<int>::iterator first,
                                std::vector<int>::iterator last, int el);
// Task_2
std::vector<int>::iterator findInSorted(std::vector<int>::iterator first,
                                        std::vector<int>::iterator last,
                                        int el);
// Task_3
int wordsCounter(const std::string& str);
// Task_4
std::map<std::string, int> wordsMapCounter(const std::string& str);
// Task_5
std::vector<std::string> uniqueWords(const std::string& str);
// Task_6
int diffWordsCounter(const std::string& str);
// Task_7
void reverseNum(std::list<int>& nums);
// Task_8
void plusesDeleter(std::vector<int>& v);
// Task_9
void Sort(std::list<int>& nums);
#endif  // INCLUDE_LAB_HPP_