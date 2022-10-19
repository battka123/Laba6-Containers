// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include <lab.hpp>

TEST(Test1, Find) {
  std::vector<int> v = {10, 17, 23, 4, 56, 79, 83, 11, 2, -3};
  // базовый случай
  std::vector<int>::iterator it = Find(v.begin(), v.end(), 17);
  EXPECT_EQ(*it, 17);
  // нет такого элемента в векторе
  it = Find(v.begin(), v.end(), 1023);
  EXPECT_EQ(it, v.end());
  // вектор одинаковых элементов
  v = {2, 2, 2};
  it = Find(v.begin(), v.end(), 2);
  EXPECT_EQ(*it, 2);
  // пустой вектор
  v = {};
  it = Find(v.begin(), v.end(), 2);
  EXPECT_EQ(it, v.end());
}

TEST(Test2, findInSorted) {
  // базовый случай
  std::vector<int> v = {16, 17, 23, 56, 78, 90};
  std::vector<int>::iterator it = findInSorted(v.begin(), v.end(), 17);
  EXPECT_EQ(*it, 17);
  // нет такого элемента
  it = findInSorted(v.begin(), v.end(), 11);
  EXPECT_EQ(it, v.end());
  // вектор одинаковых элементов
  v = {2, 2, 2};
  it = findInSorted(v.begin(), v.end(), 2);
  EXPECT_EQ(*it, 2);
  // пустой вектор
  v = {};
  it = Find(v.begin(), v.end(), 2);
  EXPECT_EQ(it, v.end());
}

TEST(Test3, wordsCounter) {
  // базовый сценарий
  int words = wordsCounter("can you can");
  EXPECT_EQ(3, words);
  // разделяем точками
  words = wordsCounter("hello.good. world");
  EXPECT_EQ(3, words);
  // совместное разделение
  words = wordsCounter("hi,dear how.dear");
  EXPECT_EQ(4, words);
  // раздеяем запятыми
  words = wordsCounter("hi,dear,how,dear");
  EXPECT_EQ(4, words);
  // одно слово
  words = wordsCounter("hello");
  EXPECT_EQ(1, words);
  // пустая строка
  words = wordsCounter("");
  EXPECT_EQ(0, words);
  // строка с пробелом
  words = wordsCounter(" ");
  EXPECT_EQ(0, words);
  // строка с точкой
  words = wordsCounter(".");
  EXPECT_EQ(0, words);
}

TEST(Test4, wordsMapCounter) {
  // базовый сценарий
  std::map<std::string, int> words = wordsMapCounter("can you can");
  EXPECT_EQ(2, words["can"]);
  EXPECT_EQ(1, words["you"]);
  EXPECT_EQ(2, words.size());
  // с точками
  words = wordsMapCounter("hello.good. world");
  EXPECT_EQ(1, words["hello"]);
  EXPECT_EQ(1, words["good"]);
  EXPECT_EQ(1, words["world"]);
  EXPECT_EQ(3, words.size());
  // c разными знаками
  words = wordsMapCounter("hi,dear how.dear.");
  EXPECT_EQ(2, words["dear"]);
  EXPECT_EQ(1, words["hi"]);
  EXPECT_EQ(1, words["how"]);
  EXPECT_EQ(3, words.size());
  // c запятыми
  words = wordsMapCounter("hi,dear,how,dear");
  EXPECT_EQ(2, words["dear"]);
  EXPECT_EQ(1, words["hi"]);
  EXPECT_EQ(1, words["how"]);
  // c заглавной буквой
  words = wordsMapCounter("Can you can");
  EXPECT_EQ(2, words["can"]);
  EXPECT_EQ(1, words["you"]);
  EXPECT_EQ(2, words.size());
  // одно слово
  words = wordsMapCounter("hello");
  EXPECT_EQ(1, words["hello"]);
  EXPECT_EQ(1, words.size());
  // пустая строка
  words = wordsMapCounter("");
  EXPECT_EQ(true, words.empty());
  // строка с пробелом
  words = wordsMapCounter(" ");
  EXPECT_EQ(true, words.empty());
  // строка с точкой
  words = wordsMapCounter(".");
  EXPECT_EQ(true, words.empty());
}

TEST(Test5, uniqueWords) {
  // базовый сценарий
  std::vector<std::string> unique = uniqueWords("Can you can");
  std::vector<std::string> result = {"Can", "can", "you"};
  EXPECT_EQ(unique, result);
  // с запятой
  unique = uniqueWords("Can,you, can,a,can");
  result = {"Can", "a", "can", "you"};
  EXPECT_EQ(unique, result);
  // c точкой
  unique = uniqueWords("Can.you. can.a.can.now");
  result = {"Can", "a", "can", "now", "you"};
  EXPECT_EQ(unique, result);
  // c разными знаками
  unique = uniqueWords("Can you,can. a.can now.");
  result = {"Can", "a", "can", "now", "you"};
  EXPECT_EQ(unique, result);
  // одно слово
  unique = uniqueWords("hi");
  result = {"hi"};
  EXPECT_EQ(unique, result);
  // пустая строка
  unique = uniqueWords("");
  result = {};
  EXPECT_EQ(unique, result);
  // пробел
  unique = uniqueWords(" ");
  result = {};
  EXPECT_EQ(unique, result);
  // запятая
  unique = uniqueWords(",");
  result = {};
  EXPECT_EQ(unique, result);
}

TEST(Test6, diffWordsCounter) {
  // базовый сценарий
  int words = diffWordsCounter("can you can a can");
  EXPECT_EQ(3, words);
  // запятые
  words = diffWordsCounter("can,you, can");
  EXPECT_EQ(2, words);
  // точки
  words = diffWordsCounter("can.you. can.a.can.now");
  EXPECT_EQ(4, words);
  // разные знаки
  words = diffWordsCounter("can you,can. a can.now,");
  EXPECT_EQ(4, words);
  // заглавная буква
  words = diffWordsCounter("Can you can a can");
  EXPECT_EQ(4, words);
  // одно слово
  words = diffWordsCounter("can");
  EXPECT_EQ(1, words);
  // пустая строка
  words = diffWordsCounter("");
  EXPECT_EQ(0, words);
  // точка
  words = diffWordsCounter(".");
  EXPECT_EQ(0, words);
  // пробел
  words = diffWordsCounter(" ");
  EXPECT_EQ(0, words);
}

TEST(Test7, reverseNum) {
  // базовый сценарий
  std::list<int> nums = {1, 5, 4, -3};
  reverseNum(nums);
  std::list<int>result = {-1, 1, -5, 5, -4, 4, 3, -3};
  EXPECT_EQ(nums, result);
  // только отрицательные
  nums = {-1, -5, -4, -3};
  reverseNum(nums);
  result = {1, -1, 5, -5, 4, -4, 3, -3};
  EXPECT_EQ(nums, result);
  // только положительные
  nums = {1, 5, 4, 3};
  reverseNum(nums);
  result = {-1, 1, -5, 5, -4, 4, -3, 3};
  EXPECT_EQ(nums, result);
  // c нулем
  nums = {-1, -5, 4, 0};
  reverseNum(nums);
  result = {1, -1, 5, -5, -4, 4, 0};
  EXPECT_EQ(nums, result);
  // один элемент
  nums = {1};
  reverseNum(nums);
  result = {-1, 1};
  EXPECT_EQ(nums, result);
  // пустой список
  std::list<int> empt;
  reverseNum(empt);
  EXPECT_EQ(true, empt.empty());
}

TEST(Test8, plusesDeleter) {
  // базовый сценарий
  std::vector<int> v = {1, 0, -8, -9, 0, 10, 23, -7};
  plusesDeleter(v);
  std::vector<int> result = {0, -8, -9, 0, -7};
  EXPECT_EQ(v, result);
  // без положительных
  v = {0, -8, -9, 0, -7};
  plusesDeleter(v);
  result = {0, -8, -9, 0, -7};
  EXPECT_EQ(v, result);
  // без отрицательных
  v = {0, 8, 9, 0, 7};
  plusesDeleter(v);
  result = {0, 0};
  EXPECT_EQ(v, result);
  // без отрицательных и 0
  v = {8, 9, 7};
  plusesDeleter(v);
  result = {};
  EXPECT_EQ(v, result);
  // пустой
  v = {};
  plusesDeleter(v);
  result = {};
  EXPECT_EQ(v, result);
}

TEST(Test9, Sort) {
  // базовый сценарий
  std::list<int> nums = {1, 5, 1, 4, -3};
  Sort(nums);
  std::list<int> result = {5, 4, 1, 1, -3};
  EXPECT_EQ(nums, result);
  // с нулем
  nums = {1, 5, 4, -3, 0};
  Sort(nums);
  result = {5, 4, 1, 0, -3};
  EXPECT_EQ(nums, result);
  // без положительных
  nums = {-1, -5, -4, -3, 0};
  Sort(nums);
  result = {0, -1, -3, -4, -5};
  EXPECT_EQ(nums, result);
  // без отрицательных
  nums = {1, 5, 4, 3, 0};
  Sort(nums);
  result = {5, 4, 3, 1, 0};
  EXPECT_EQ(nums, result);
  // пустой
  nums = {};
  Sort(nums);
  result = {};
  EXPECT_EQ(nums, result);
}
