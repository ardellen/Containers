//
// Created by Virgil Wilda on 12/25/23.
//

#include "s21_test_map.h"

namespace {

TEST_F(MapTest, default_constructor) {
  EXPECT_EQ(int_map.empty(), orig_int_map.empty());
  EXPECT_EQ(char_map.empty(), orig_char_map.empty());
  EXPECT_EQ(string_map.empty(), orig_string_map.empty());
  EXPECT_EQ(true, int_map.empty());
  EXPECT_EQ(true, char_map.empty());
  EXPECT_EQ(true, string_map.empty());
}

TEST_F(MapTest, initializer_list) {
  EXPECT_EQ(false, m.empty());
  EXPECT_EQ(false, m1.empty());
  EXPECT_EQ(false, m2.empty());
  EXPECT_EQ(false, m3.empty());
}

TEST_F(MapTest, initializer_list_2) {
  s21::map<int, int> myMap = {};
  std::map<int, int> origMap = {};
  EXPECT_EQ(myMap.size(), origMap.size());
  auto myIt = myMap.begin();
  auto origIt = origMap.begin();
  for (; myIt != myMap.end(); ++myIt, ++origIt) {
    EXPECT_TRUE((*myIt).first == (*origIt).first);
    EXPECT_TRUE((*myIt).second == (*origIt).second);
  }
}

TEST_F(MapTest, destructor) {
  m.~map();
  m1.~map();
  m2.~map();
  m3.~map();
  EXPECT_EQ(true, m.empty());
  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ(true, m2.empty());
  EXPECT_EQ(true, m3.empty());
}

TEST_F(MapTest, copy_constructor) {
  s21::map<int, int> map_cpy(m);
  s21::map<int, std::string> int_map_cpy(m1);
  s21::map<char, std::string> char_map_cpy = m2;
  s21::map<std::string, std::string> string_map_cpy = m3;
  EXPECT_EQ(false, map_cpy.empty());
  EXPECT_EQ(false, int_map_cpy.empty());
  EXPECT_EQ(false, char_map_cpy.empty());
  EXPECT_EQ(false, string_map_cpy.empty());
}

TEST_F(MapTest, copy_constructor_int) {
  const s21::map<int, int> myMap({{1, 2}, {3, 4}, {5, 6}});
  const std::map<int, int> origMap({{1, 2}, {3, 4}, {5, 6}});
  s21::map<int, int> myMapCopy = myMap;
  std::map<int, int> origMapCopy = origMap;
  EXPECT_EQ(myMapCopy.size(), origMapCopy.size());
  auto myIt = myMapCopy.begin();
  auto origIt = origMapCopy.begin();
  for (; myIt != myMapCopy.end(); ++myIt, ++origIt) {
    EXPECT_TRUE((*myIt).first == (*origIt).first);
    EXPECT_TRUE((*myIt).second == (*origIt).second);
  }
}

TEST_F(MapTest, move_constructor_int) {
  s21::map<int, int> myMap({{1, 2}, {3, 4}, {5, 6}});
  std::map<int, int> origMap({{1, 2}, {3, 4}, {5, 6}});
  s21::map<int, int> myMapCopy = std::move(myMap);
  std::map<int, int> origMapCopy = std::move(origMap);
  EXPECT_EQ(myMap.size(), origMap.size());
  EXPECT_EQ(myMapCopy.size(), origMapCopy.size());
  auto myIt = myMapCopy.begin();
  auto origIt = origMapCopy.begin();
  for (; myIt != myMapCopy.end(); ++myIt, ++origIt) {
    EXPECT_TRUE((*myIt).first == (*origIt).first);
    EXPECT_TRUE((*myIt).second == (*origIt).second);
  }
}

TEST_F(MapTest, move_constructor_int_string) {
  std::map<int, std::string> origMap({{4, "pas"}, {5, "pis"}, {6, "pos"}});
  s21::map<int, std::string> myMapCopy = std::move(m1);
  std::map<int, std::string> origMapCopy = std::move(origMap);
  EXPECT_EQ(m1.size(), origMap.size());
  EXPECT_EQ(myMapCopy.size(), origMapCopy.size());
  auto myIt = myMapCopy.begin();
  auto origIt = origMapCopy.begin();
  for (; myIt != myMapCopy.end(); ++myIt, ++origIt) {
    EXPECT_TRUE((*myIt).first == (*origIt).first);
    EXPECT_TRUE((*myIt).second == (*origIt).second);
  }
}

TEST_F(MapTest, move_constructor) {
  string_map =
      std::move(s21::map<std::string, std::string>{{"hello world", "friends"}});
  char_map = std::move(m2);
  int_map = std::move(m1);

  EXPECT_EQ(false, string_map.empty());
  EXPECT_EQ(false, char_map.empty());
  EXPECT_EQ(false, int_map.empty());
}

TEST_F(MapTest, assign_constuctor) {
  s21::map<int, std::string> int_map2{{{7, "the"}, {8, "zi"}, {9, "oi"}}};
  std::map<int, std::string> intmap1{{4, "pas"}, {5, "pis"}, {6, "pos"}};
  std::map<int, std::string> intmap2{{{7, "the"}, {8, "zi"}, {9, "oi"}}};
  m1 = int_map2;
  intmap1 = intmap2;
  auto iter = intmap1.begin();
  for (auto &it : m1) {
    EXPECT_EQ(it.first, (*iter).first);
    EXPECT_EQ(it.second, (*iter).second);
    ++iter;
  }
}

TEST_F(MapTest, map_operator) {
  s21::map<int, int> myMap({{10, 1}, {20, 2}, {30, 3}});
  std::map<int, int> origMap({{10, 1}, {20, 2}, {30, 3}});
  myMap[10] = 11;
  origMap[10] = 11;
  origMap[20] = 22;
  EXPECT_TRUE(myMap[10] == origMap[10]);
  EXPECT_FALSE(myMap[20] == origMap[20]);
  EXPECT_TRUE(myMap[30] == origMap[30]);
}

TEST_F(MapTest, at_operator) {
  s21::map<int, int> myMap({{10, 1}, {20, 2}, {30, 3}});
  std::map<int, int> origMap({{10, 1}, {20, 2}, {30, 3}});

  //  for (auto const &ln : myMap) {
  //    std::cout << ln.second << " ";
  //  }
  myMap.at(10) = 11;
  origMap.at(10) = 11;
  origMap.at(20) = 22;

  EXPECT_TRUE(myMap[10] == origMap[10]);
  EXPECT_FALSE(myMap[20] == origMap[20]);
  EXPECT_TRUE(myMap[30] == origMap[30]);
}

TEST_F(MapTest, at_exception) {
  s21::map<int, int> myMap({{20, 1}, {10, 1}, {30, 56}, {80, 1}, {5, 1}});
  EXPECT_THROW(myMap.at('g') = 1, std::out_of_range);
}

TEST_F(MapTest, at) {
  s21::map<int, int> tree = {{20, 1}, {10, 1}, {30, 56}, {80, 1}, {5, 1}};
  std::map<int, int> tree1 = {{20, 1}, {10, 1}, {30, 56}, {80, 1}, {5, 1}};

  //  for (auto const &ln : tree1) {
  //    std::cout << ln.second << " ";
  //  }
  EXPECT_EQ(tree.at(30), tree1.at(30));
  EXPECT_EQ(tree[10], tree1[10]);
  EXPECT_EQ(tree[30], tree1[30]);
}

TEST_F(MapTest, begin_end) {
  std::map<int, std::string> origMap =
      std::map<int, std::string>{{4, "pas"}, {5, "pis"}, {6, "pos"}};
  auto iter = origMap.begin();

  for (auto &it : m1) {
    EXPECT_EQ(it.first, (*iter).first);
    EXPECT_EQ(it.second, (*iter).second);
    ++iter;
  }
  iter = --origMap.end();
  for (auto it = --m1.end(); it != m1.end(); --it) {
    EXPECT_EQ((*it).first, (*iter).first);
    EXPECT_EQ((*it).second, (*iter).second);
    --iter;
  }

  s21::map<int, std::string>::const_iterator const_it = m1.begin();
  auto const_it_orig = origMap.begin();
  EXPECT_EQ((*const_it).first, (*const_it_orig).first);
  EXPECT_EQ((*const_it).second, (*const_it_orig).second);
}

TEST_F(MapTest, size_empty) {
  std::map<int, std::string> intmap = {{4, "pas"}, {5, "pis"}, {6, "pos"}};

  std::map<char, std::string> charmap = {
      {'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
  std::map<std::string, std::string> stringmap{
      {"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};

  EXPECT_EQ(false, m1.empty());
  EXPECT_EQ(false, m2.empty());
  EXPECT_EQ(false, m3.empty());
  EXPECT_EQ(intmap.size(), m1.size());
  EXPECT_EQ(charmap.size(), m2.size());
  EXPECT_EQ(stringmap.size(), m3.size());
  EXPECT_NEAR(m1.max_size(), intmap.max_size(), 0);
  EXPECT_NEAR(m2.max_size(), charmap.max_size(), 0);
  EXPECT_NEAR(m3.max_size(), stringmap.max_size(), 0);
}

TEST_F(MapTest, capacity) {
  s21::map<int, int> myMap;
  std::map<int, int> origMap;
  EXPECT_TRUE(myMap.empty() == origMap.empty());
  myMap.insert(10, 1);
  EXPECT_FALSE(myMap.empty() == origMap.empty());
  EXPECT_EQ(myMap.size(), 1);
}

TEST_F(MapTest, merge) {
  s21::map<int, int> myMap({{1, 1}, {4, 4}, {2, 2}});
  s21::map<int, int> myMapMerge({{3, 3}, {4, 4}});

  std::map<int, int> origMap({{1, 1}, {4, 4}, {2, 2}});
  std::map<int, int> origMapMerge({{3, 3}, {4, 4}});

  //  for (auto const &ln : myMap) {
  //    std::cout << ln.second << " ";
  //  }
  //
  //  for (auto const &ln : origMap) {
  //    std::cout << ln.second << " ";
  //  }

  myMap.merge(myMapMerge);
  origMap.merge(origMapMerge);

  //  for (auto const &ln : myMap) {
  //    std::cout << ln.second << " ";
  //  }

  //  for (auto const &ln : origMap) {
  //    std::cout << ln.second << " ";
  //  }

  EXPECT_EQ(myMap.size(), origMap.size());
  EXPECT_EQ(myMapMerge.size(), origMapMerge.size());

  auto myIt = myMap.begin();
  auto origIt = origMap.begin();
  for (; myIt != myMap.end(); ++myIt, ++origIt) {
    EXPECT_TRUE((*myIt).first == (*origIt).first);
    EXPECT_TRUE((*myIt).second == (*origIt).second);
  }
  EXPECT_TRUE(myMapMerge.contains(4));
  EXPECT_FALSE(myMapMerge.contains(3));
}

TEST_F(MapTest, merge_1) {
  s21::map<int, std::string> int_map1{{3, "arr"}, {9, "say"}};
  std::map<int, std::string> intmap{{4, "pas"}, {5, "pis"}, {6, "pos"}};
  std::map<int, std::string> intmap1{{3, "arr"}, {9, "say"}};

  s21::map<char, std::string> char_map1 = {{'w', "wou"}, {'t', "time"}};
  std::map<char, std::string> charmap = {
      {'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
  std::map<char, std::string> charmap1 = {{'w', "wou"}, {'t', "time"}};

  s21::map<std::string, std::string> string_map1{{"wine", "wah?"},
                                                 {"hello", "prise"},
                                                 {"till", "tram"},
                                                 {"scorge", " monster"}};
  std::map<std::string, std::string> stringmap{
      {"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};
  std::map<std::string, std::string> stringmap1{{"wine", "wah?"},
                                                {"hello", "prise"},
                                                {"till", "tram"},
                                                {"scorge", " monster"}};

  m1.merge(int_map1);
  intmap.merge(intmap1);
  //  for (auto const &ln : m1) {
  //    std::cout << ln.second << " ";
  //  }
  //
  //  for (auto const &ln : intmap) {
  //    std::cout << ln.second << " ";
  //  }

  char_map1.merge(m2);
  charmap1.merge(charmap);

  //      for (auto const &ln : char_map1) {
  //        std::cout << ln.second << " ";
  //      }
  //
  //      for (auto const &ln : charmap1) {
  //        std::cout << ln.second << " ";
  //      }

  m3.merge(string_map1);
  stringmap.merge(stringmap1);

  //      for (auto const &ln : m3) {
  //        std::cout << ln.second << " ";
  //      }
  //
  //      for (auto const &ln : stringmap) {
  //        std::cout << ln.second << " ";
  //      }

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), m1.size());
  for (auto &it : m1) {
    EXPECT_EQ(it.first, (*it1).first);
    EXPECT_EQ(it.second, (*it1).second);
    ++it1;
  }
  auto it2 = charmap1.begin();
  EXPECT_EQ(charmap1.size(), char_map1.size());
  for (auto &it : char_map1) {
    EXPECT_EQ(it.first, (*it2).first);
    EXPECT_EQ(it.second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), m3.size());
  for (auto &it : m3) {
    EXPECT_EQ(it.first, (*it3).first);
    EXPECT_EQ(it.second, (*it3).second);
    ++it3;
  }
}

TEST_F(MapTest, erase) {
  std::map<int, std::string> intmap = {{4, "pas"}, {5, "pis"}, {6, "pos"}};
  std::map<char, std::string> charmap = {
      {'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
  std::map<std::string, std::string> stringmap{
      {"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};

  m1.erase(m1.begin());
  intmap.erase(intmap.begin());

  //  for (auto const &ln : m1) {
  //    std::cout << ln.second << " ";
  //  }
  //
  //  for (auto const &ln : intmap) {
  //    std::cout << ln.second << " ";
  //  }

  m2.erase(m2.begin());
  charmap.erase(charmap.begin());

  m3.erase(m3.begin());
  stringmap.erase(stringmap.begin());

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), m1.size());
  for (auto &it : m1) {
    EXPECT_EQ(it.first, (*it1).first);
    EXPECT_EQ(it.second, (*it1).second);
    ++it1;
  }

  auto it2 = charmap.begin();
  EXPECT_EQ(charmap.size(), m2.size());
  for (auto &it : m2) {
    EXPECT_EQ(it.first, (*it2).first);
    EXPECT_EQ(it.second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), m3.size());
  for (auto &it : m3) {
    EXPECT_EQ(it.first, (*it3).first);
    EXPECT_EQ(it.second, (*it3).second);
    ++it3;
  }
}

TEST_F(MapTest, contains) {
  EXPECT_EQ(m1.contains(6), true);
  EXPECT_EQ(m2.contains('c'), true);
  EXPECT_EQ(m3.contains("it's hard"), true);

  EXPECT_EQ(m1.contains(777), false);
  EXPECT_EQ(m2.contains('H'), false);
  EXPECT_EQ(m3.contains("dummy"), false);
}

TEST_F(MapTest, assign) {
  s21::map<int, int> tree = {{20, 1},  {10, 1},  {30, 1},  {80, 1},  {5, 1},
                             {16, 1},  {108, 1}, {110, 1}, {120, 1}, {130, 1},
                             {107, 1}, {106, 1}, {105, 1}, {17, 1},  {18, 1},
                             {19, 1},  {21, 1},  {22, 1},  {34, 1},  {35, 1},
                             {36, 1},  {40, 1},  {50, 1},  {60, 1}};
  tree.insert_or_assign(999, 22);
  std::map<int, int> tree1 = {{20, 1},  {10, 1},  {30, 1},  {80, 1},  {5, 1},
                              {16, 1},  {108, 1}, {110, 1}, {120, 1}, {130, 1},
                              {107, 1}, {106, 1}, {105, 1}, {17, 1},  {18, 1},
                              {19, 1},  {21, 1},  {22, 1},  {34, 1},  {35, 1},
                              {36, 1},  {40, 1},  {50, 1},  {60, 1}};
  tree1.insert_or_assign(999, 22);

  EXPECT_EQ(tree.at(19), tree1.at(19));
  tree.insert_or_assign(999, 36);
  tree1.insert_or_assign(999, 36);
  EXPECT_EQ(tree.at(999), tree1.at(999));
}

TEST_F(MapTest, swap) {
  s21::map<int, int> myMap({{1, 1}});
  s21::map<int, int> mySwapMap({{3, 3}, {4, 4}});

  myMap.swap(mySwapMap);
  EXPECT_EQ(myMap.size(), 2);
  EXPECT_EQ(mySwapMap.size(), 1);
  auto x = myMap.begin();
  auto y = mySwapMap.begin();
  EXPECT_EQ((*x).first, 3);
  EXPECT_EQ((*y).first, 1);
}

TEST_F(MapTest, swap_1) {
  s21::map<int, std::string> int_map1{{3, "arr"}, {9, "say"}};
  std::map<int, std::string> intmap = {{4, "pas"}, {5, "pis"}, {6, "pos"}};
  std::map<int, std::string> intmap1 = {{3, "arr"}, {9, "say"}};

  s21::map<char, std::string> char_map1 = {{'w', "wou"}, {'t', "time"}};
  std::map<char, std::string> charmap = {
      {'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
  std::map<char, std::string> charmap1 = {{'w', "wou"}, {'t', "time"}};

  s21::map<std::string, std::string> string_map1{{"wine", "wah?"},
                                                 {"hello", "prise"},
                                                 {"till", "tram"},
                                                 {"scorge", " monster"}};
  std::map<std::string, std::string> stringmap{
      {"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};
  std::map<std::string, std::string> stringmap1{{"wine", "wah?"},
                                                {"hello", "prise"},
                                                {"till", "tram"},
                                                {"scorge", " monster"}};

  m1.swap(int_map1);
  intmap.swap(intmap1);

  m2.swap(char_map1);
  charmap.swap(charmap1);

  m3.swap(string_map1);
  stringmap.swap(stringmap1);

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), m1.size());
  for (auto &it : m1) {
    EXPECT_EQ(it.first, (*it1).first);
    EXPECT_EQ(it.second, (*it1).second);
    ++it1;
  }
  auto it2 = charmap.begin();
  EXPECT_EQ(charmap.size(), m2.size());
  for (auto &it : m2) {
    EXPECT_EQ(it.first, (*it2).first);
    EXPECT_EQ(it.second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), m3.size());
  for (auto &it : m3) {
    EXPECT_EQ(it.first, (*it3).first);
    EXPECT_EQ(it.second, (*it3).second);
    ++it3;
  }
}

TEST_F(MapTest, insert_clear) {
  std::map<int, std::string> intmap = {{4, "pas"}, {5, "pis"}, {6, "pos"}};
  std::map<char, std::string> charmap = {
      {'s', "school"}, {'c', "cool"}, {'a', "akademy"}};
  std::map<std::string, std::string> stringmap{
      {"word", "world"}, {"hello", "world"}, {"it's hard", "not easy"}};

  auto pair_int_map = m1.insert({8, "mine"});
  auto pairintmap = intmap.insert({8, "mine"});
  auto pair_char_map = m2.insert({'t', "life"});
  auto paircharmap = charmap.insert({'t', "life"});
  auto pair_string_map = m3.insert({"angle", "stable"});
  auto pairstringmap = stringmap.insert({"angle", "stable"});
  EXPECT_EQ((*(pair_int_map.first)).first, (*(pairintmap.first)).first);
  EXPECT_EQ((*(pair_char_map.first)).first, (*(paircharmap.first)).first);
  EXPECT_EQ((*(pair_string_map.first)).first, (*(pairstringmap.first)).first);
  EXPECT_EQ((*(pair_int_map.first)).second, (*(pairintmap.first)).second);
  EXPECT_EQ((*(pair_char_map.first)).second, (*(paircharmap.first)).second);
  EXPECT_EQ((*(pair_string_map.first)).second, (*(pairstringmap.first)).second);
  auto pair_int_map1 = m1.insert({8, "hw"});
  auto pairintmap1 = intmap.insert({8, "hw"});
  auto pair_char_map1 = m2.insert({'t', "flag"});
  auto paircharmap1 = charmap.insert({'t', "flag"});
  auto pair_string_map1 = m3.insert({"angle", "wiget"});
  auto pairstringmap1 = stringmap.insert({"angle", "wiget"});

  EXPECT_EQ(pair_int_map1.second, pairintmap1.second);
  EXPECT_EQ(pair_char_map1.second, paircharmap1.second);
  EXPECT_EQ(pair_string_map1.second, pairstringmap1.second);

  EXPECT_EQ(false, m1.empty());
  EXPECT_EQ(false, m2.empty());
  EXPECT_EQ(false, m3.empty());
  m1.clear();
  intmap.clear();
  m2.clear();
  charmap.clear();
  m3.clear();
  stringmap.clear();
  EXPECT_EQ(intmap.empty(), m1.empty());
  EXPECT_EQ(charmap.empty(), m2.empty());
  EXPECT_EQ(stringmap.empty(), m3.empty());
}

TEST_F(MapTest, insert_many) {
  m.insert_many(std::make_pair(2, 20), std::make_pair(4, 40));
  m1.insert_many(std::make_pair(6, "abc"), std::make_pair(9, "abc"));
  m2.insert_many(std::make_pair('w', "wou"), std::make_pair('t', "time"));
  m3.insert_many(std::make_pair("wine", "wah?"),
                 std::make_pair("hello", "prise"),
                 std::make_pair("till", "tram"));
  EXPECT_EQ(m.contains(2), true);
  EXPECT_EQ(m.contains(4), true);
  EXPECT_EQ(m1.contains(3), false);
  EXPECT_EQ(m1.contains(9), true);
  EXPECT_EQ(m2.contains('w'), true);
  EXPECT_EQ(m2.contains('t'), true);
  EXPECT_EQ(m3.contains("wine"), true);
  EXPECT_EQ(m3.contains("hello"), true);
  EXPECT_EQ(m3.contains("till"), true);
  EXPECT_EQ(m3.contains("flag"), false);
}

TEST_F(MapTest, insert_many_1) {
  s21::map<char, int> myMap{{'a', 10}, {'b', 53}, {'c', 35},
                            {'v', 6},  {'g', 15}, {'k', 20}};
  std::map<char, int> origMap{{'a', 10}, {'b', 53}, {'c', 35},
                              {'v', 6},  {'g', 15}, {'k', 20}};
  myMap.insert_many(std::make_pair('z', 11), std::make_pair('x', 14),
                    std::make_pair('c', 11), std::make_pair('z', 11));
  origMap.insert(std::make_pair('z', 11));
  origMap.insert(std::make_pair('x', 14));
  origMap.insert(std::make_pair('c', 11));
  origMap.insert(std::make_pair('z', 11));

  auto iter = origMap.begin();
  for (auto &it : myMap) {
    EXPECT_EQ(it.first, (*iter).first);
    EXPECT_EQ(it.second, (*iter).second);
    ++iter;
  }
}

}  // namespace