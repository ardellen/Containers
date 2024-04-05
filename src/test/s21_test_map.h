//
// Created by Virgil Wilda on 12/25/23.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_TEST_S21_TEST_MAP_H
#define CPP2_S21_CONTAINERS_1_SRC_TEST_S21_TEST_MAP_H

#include <gtest/gtest.h>

#include <map>
#include <vector>

#include "../s21_containers.h"

class MapTest : public ::testing::Test {
 public:
  //  using pii = std::pair<int, int>;
  //  using pis = std::pair<int, std::string>;
  //  using pcs = std::pair<char, std::string>;
  //  using pss = std::pair<std::string, std::string>;

  s21::map<int, int> m;
  s21::map<int, std::string> m1;
  s21::map<char, std::string> m2;
  s21::map<std::string, std::string> m3;

  void SetUp() override {
    m = s21::map<int, int>({{1, 'a'}, {3, 'b'}, {5, 'c'}});
    m1 = {{4, "pas"}, {5, "pis"}, {6, "pos"}};
    m2 = {{'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
    m3 = {{"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};
  };

  void TearDown() override {}

  // protected:

  s21::map<int, std::string> int_map;
  s21::map<char, std::string> char_map;
  s21::map<std::string, std::string> string_map;
  std::map<int, std::string> orig_int_map;
  std::map<char, std::string> orig_char_map;
  std::map<std::string, std::string> orig_string_map;
};

#endif  // CPP2_S21_CONTAINERS_1_SRC_TEST_S21_TEST_MAP_H
