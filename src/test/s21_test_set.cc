
#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

TEST(SET, DefoltSet) {
  s21::set<int> my_set;
  std::set<int> orig_set;
  EXPECT_EQ(my_set.empty(), orig_set.empty());
}

TEST(SET, InitializerSet) {
  s21::set<int> my_set = {};
  std::set<int> orig_set = {};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, InitializerSet2) {
  s21::set<int> my_set = {8, 4, 6, 12, 10, 7, 11, 9, 5, 14, 13, 2, 3, 1, 15};
  std::set<int> orig_set = {8, 4, 6, 12, 10, 7, 11, 9, 5, 14, 13, 2, 3, 1, 15};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, InitializerSet3) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  std::set<int> orig_set = {1, 2, 3, 4, 5};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, InitializerSet4) {
  s21::set<int> my_set = {3, 3, 3};
  std::set<int> orig_set = {3, 3, 3};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, InitializerSet5) {
  s21::set<int> my_set = {3, 2, 3, 2};
  std::set<int> orig_set = {3, 2, 3, 2};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, InsertSet) {
  s21::set<int> my_set;
  std::set<int> orig_set;
  my_set.insert(1);
  my_set.insert(2);
  orig_set.insert(1);
  orig_set.insert(2);
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, ConstructorCopySet) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  std::set<int> orig_set = {1, 2, 3, 4, 5};
  s21::set<int> my_set_copy = my_set;
  std::set<int> orig_set_copy = orig_set;
  EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
  auto my_it = my_set_copy.begin();
  auto orig_it = orig_set_copy.begin();
  for (; my_it != my_set_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, ConstructorMoveSet) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  std::set<int> orig_set = {1, 2, 3, 4, 5};
  s21::set<int> my_set_copy = std::move(my_set);
  std::set<int> orig_set_copy = std::move(orig_set);
  EXPECT_EQ(my_set.size(), orig_set.size());
  EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
  auto my_it = my_set_copy.begin();
  auto orig_it = orig_set_copy.begin();
  for (; my_it != my_set_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, CapacitySet) {
  s21::set<char> my_empty_set;
  std::set<char> orig_empty_set;
  EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
  EXPECT_NEAR(my_empty_set.max_size(), orig_empty_set.max_size(), 0);
  my_empty_set.insert('b');
  orig_empty_set.insert('c');
  EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
  EXPECT_NEAR(my_empty_set.max_size(), orig_empty_set.max_size(), 0);
}

TEST(SET, ClearSet) {
  s21::set<char> my_empty_set;
  std::set<char> orig_empty_set;
  my_empty_set.clear();
  orig_empty_set.clear();
  EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
  my_empty_set.insert('a');
  orig_empty_set.insert('b');
  EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
  my_empty_set.clear();
  orig_empty_set.clear();
  EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
  EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
}

TEST(SET, SwapSet) {
  s21::set<int> my_set = {1};
  s21::set<int> my_swap_set = {3, 4, 5};

  my_set.swap(my_swap_set);
  EXPECT_EQ(my_set.size(), 3);
  EXPECT_EQ(my_swap_set.size(), 1);
  EXPECT_EQ(*my_set.begin(), 3);
  EXPECT_EQ(*my_swap_set.begin(), 1);
}

TEST(SET, ContainsSet) {
  s21::set<double> my_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  s21::set<double> orig_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  EXPECT_EQ(my_set.contains(2), orig_set.contains(2));
  EXPECT_EQ(my_set.contains(2.1), orig_set.contains(2.1));
}

TEST(SET, FindSet) {
  s21::set<double> my_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  s21::set<double> orig_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  auto my_it = my_set.find(2.4);
  auto orig_it = orig_set.find(2.4);
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(SET, SetMerge) {
  s21::set<int> s21{10, 53, 35, 6, 15, 20};
  s21::set<int> merges21{11, 14, 6, 6, 6};
  std::set<int> se{10, 53, 35, 6, 15, 20};
  std::set<int> merges{11, 14, 6, 6, 6};
  s21.merge(merges21);
  se.merge(merges);
  EXPECT_EQ(s21.size(), se.size());
  EXPECT_EQ(merges21.size(), merges.size());
  auto s21it = s21.begin();
  auto it = se.begin();
  for (; s21it != s21.end() && it != se.end(); ++it, ++s21it)
    EXPECT_EQ(*s21it, *it);
}

TEST(SET, SetIteratorsSet) {
  s21::set<std::string> my_set = {"This", "is", "my", "set"};
  std::set<std::string> orig_set = {"This", "is", "my", "set"};
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  EXPECT_TRUE(*orig_it == *my_it);
  my_it = my_set.end();
  orig_it = orig_set.end();
  --my_it;
  --orig_it;
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(SET, SetIteratorsSet2) {
  s21::set<std::string> my_set = {"set", "This", "is", "my"};
  std::set<std::string> orig_set = {"set", "This", "is", "my"};
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  EXPECT_TRUE(*orig_it == *my_it);
  my_it = my_set.end();
  orig_it = orig_set.end();
  --my_it;
  --orig_it;
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(SET, SetInsertMan) {
  s21::set<int> s21{10, 53, 35, 6, 15, 20};
  std::set<int> se{10, 53, 35, 6, 15, 20};
  s21.insert_many(11, 14, 22);
  se.insert(11);
  se.insert(14);
  se.insert(22);
  auto s21it = s21.begin();
  auto it = se.begin();
  for (; s21it != s21.end() && it != se.end(); ++it, ++s21it)
    EXPECT_EQ(*s21it, *it);
}

TEST(SET, AssignmentOperatorConst) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  s21::set<int> my_set_copy;
  my_set_copy = my_set;
  std::set<int> orig_set = {1, 2, 3, 4, 5};
  std::set<int> orig_set_copy;
  orig_set_copy = orig_set;
  EXPECT_EQ(my_set.size(), orig_set.size());
  EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
  auto my_it = my_set_copy.begin();
  auto orig_it = orig_set_copy.begin();
  for (; my_it != my_set_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, MoveAssignmentOperator) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  s21::set<int> my_set_copy;
  my_set_copy = std::move(my_set);
  std::set<int> orig_set = {1, 2, 3, 4, 5};
  std::set<int> orig_set_copy;
  orig_set_copy = std::move(orig_set);
  EXPECT_EQ(my_set.size(), orig_set.size());
  EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
  auto my_it = my_set_copy.begin();
  auto orig_it = orig_set_copy.begin();
  for (; my_it != my_set_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(SET, SetErase) {
  s21::set<int> s21 = {10, 53, 35, 6, 15, 20};
  std::set<int> s = {10, 53, 35, 6, 15, 20};
  auto s21it = s21.begin();
  auto it = s.begin();
  s21.erase(s21it);
  s.erase(it);
  EXPECT_EQ(s21.size(), s.size());
  s21it = s21.begin();
  it = s.begin();
  for (; s21it != s21.end() && it != s.end(); ++it, ++s21it)
    EXPECT_EQ(*s21it, *it);
}