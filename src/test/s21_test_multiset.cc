#include <gtest/gtest.h>
// #include <multiset>
#include "../s21_containersplus.h"

TEST(MULTISET, ConstructorDefaultmultiset) {
  s21::multiset<char> my_empty_multiset;
  std::multiset<char> orig_empty_multiset;
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
}

TEST(MULTISET, InitializerMultiset) {
  s21::multiset<int> my_multiset = {};
  std::multiset<int> orig_multiset = {};
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, InitializerMultiset2) {
  s21::multiset<int> my_multiset = {8, 4,  6,  12, 10, 7, 11, 9,
                                    5, 14, 13, 2,  3,  1, 15};
  std::multiset<int> orig_multiset = {8, 4,  6,  12, 10, 7, 11, 9,
                                      5, 14, 13, 2,  3,  1, 15};
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, InitializerMultiset3) {
  s21::multiset<int> my_set = {1, 2, 3, 4, 5};
  std::multiset<int> orig_set = {1, 2, 3, 4, 5};
  EXPECT_EQ(my_set.size(), orig_set.size());
  auto my_it = my_set.begin();
  auto orig_it = orig_set.begin();
  for (; my_it != my_set.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, InitializerSet4) {
  s21::multiset<int> my_multiset = {3, 2, 3, 2};
  std::multiset<int> orig_multiset = {3, 2, 3, 2};
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, InitializerSet5) {
  s21::multiset<int> my_multiset = {3, 3, 3};
  std::multiset<int> orig_multiset = {3, 3, 3};
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, ConstructorInitializer2multiset) {
  s21::multiset<char> my_multiset = {};
  std::multiset<char> orig_multiset = {};
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, ConstructorCopymultiset) {
  s21::multiset<int> my_multiset = {1, 2, 3, 4, 5};
  std::multiset<int> orig_multiset = {1, 2, 3, 4, 5};
  s21::multiset<int> my_multiset_copy = my_multiset;
  std::multiset<int> orig_multiset_copy = orig_multiset;
  EXPECT_EQ(my_multiset_copy.size(), orig_multiset_copy.size());
  auto my_it = my_multiset_copy.begin();
  auto orig_it = orig_multiset_copy.begin();
  for (; my_it != my_multiset_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, ConstructorMovemultiset) {
  s21::multiset<int> my_multiset = {1, 2, 3, 4, 5};
  std::multiset<int> orig_multiset = {1, 2, 3, 4, 5};
  s21::multiset<int> my_multiset_copy = std::move(my_multiset);
  std::multiset<int> orig_multiset_copy = std::move(orig_multiset);
  EXPECT_EQ(my_multiset.size(), orig_multiset.size());
  EXPECT_EQ(my_multiset_copy.size(), orig_multiset_copy.size());
  auto my_it = my_multiset_copy.begin();
  auto orig_it = orig_multiset_copy.begin();
  for (; my_it != my_multiset_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, MultisetIteratorsmultiset) {
  s21::multiset<std::string> my_multiset = {"This", "is", "my", "multiset"};
  std::multiset<std::string> orig_multiset = {"This", "is", "my", "multiset"};
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  EXPECT_TRUE(*orig_it == *my_it);
  my_it = my_multiset.end();
  orig_it = orig_multiset.end();
  --my_it;
  --orig_it;
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(MULTISET, Capacitymultiset) {
  s21::multiset<char> my_empty_multiset;
  std::multiset<char> orig_empty_multiset;
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
  EXPECT_EQ(my_empty_multiset.size(), orig_empty_multiset.size());
  my_empty_multiset.insert('b');
  orig_empty_multiset.insert('c');
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
  EXPECT_EQ(my_empty_multiset.size(), orig_empty_multiset.size());
}

TEST(MULTISET, Clearmultiset) {
  s21::multiset<char> my_empty_multiset;
  std::multiset<char> orig_empty_multiset;
  my_empty_multiset.clear();
  orig_empty_multiset.clear();
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
  EXPECT_EQ(my_empty_multiset.size(), orig_empty_multiset.size());
  my_empty_multiset.insert('a');
  orig_empty_multiset.insert('b');
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
  EXPECT_EQ(my_empty_multiset.size(), orig_empty_multiset.size());
  my_empty_multiset.clear();
  orig_empty_multiset.clear();
  EXPECT_EQ(my_empty_multiset.empty(), orig_empty_multiset.empty());
  EXPECT_EQ(my_empty_multiset.size(), orig_empty_multiset.size());
}

TEST(MULTISET, Erasemultiset) {
  s21::multiset<int> my_multiset = {5, 4, 3, 2, 7, 8, 9};
  std::multiset<int> orig_multiset = {5, 4, 3, 2, 7, 8, 9};
  auto size = my_multiset.size();
  my_multiset.erase(my_multiset.end());
  auto new_size = my_multiset.size();
  EXPECT_EQ(size, new_size);
  my_multiset.erase(my_multiset.begin());
  orig_multiset.erase(orig_multiset.begin());
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(MULTISET, MultisetInsertMany) {
  s21::multiset<int> s21{10, 53, 35, 6, 15, 20};
  std::multiset<int> se{10, 53, 35, 6, 15, 20};
  s21.insert_many(11, 14, 22);
  se.insert(11);
  se.insert(14);
  se.insert(22);
  auto s21it = s21.begin();
  auto it = se.begin();
  for (; s21it != s21.end() && it != se.end(); ++it, ++s21it)
    EXPECT_EQ(*s21it, *it);
}

TEST(MULTISET, Swapmultiset) {
  s21::multiset<int> my_multiset = {1};
  s21::multiset<int> my_swap_multiset = {3, 4, 5};

  my_multiset.swap(my_swap_multiset);
  EXPECT_EQ(my_multiset.size(), 3);
  EXPECT_EQ(my_swap_multiset.size(), 1);
  EXPECT_EQ(*my_multiset.begin(), 3);
  EXPECT_EQ(*my_swap_multiset.begin(), 1);
}

TEST(MULTISET, multisetUtility) {
  s21::multiset<int> s21{10, 53, 35, 6, 6, 6, 7, 7};
  std::multiset<int> s{10, 53, 35, 6, 6, 6, 7, 7};
  auto s21it = s21.begin();
  auto it = s.begin();
  EXPECT_EQ(s21.size(), s.size());
  for (; s21it != s21.end() && it != s.end(); ++it, ++s21it)
    EXPECT_EQ(*s21it, *it);
  EXPECT_FALSE(s21.empty());
  EXPECT_NE(s21.max_size(), 0);
  EXPECT_EQ(s21.count(6), s.count(6));
  EXPECT_EQ(s21.count(10), s.count(10));
  EXPECT_EQ(s21.count(7), s.count(7));
  EXPECT_EQ(s21.count(8), s.count(8));
}

TEST(MULTISET, multisetRange) {
  s21::multiset<int> s21{10, 53, 35, 6, 6, 6, 7, 7};
  std::multiset<int> s{10, 53, 35, 6, 6, 6, 7, 7};
  auto range21 = s21.equal_range(6);
  auto range = s.equal_range(6);
  EXPECT_EQ(*range21.first, *range.first);
  EXPECT_EQ(*range21.second, *range.second);
  range21 = s21.equal_range(7);
  range = s.equal_range(7);
  EXPECT_EQ(*range21.first, *range.first);
  EXPECT_EQ(*range21.second, *range.second);
  range21 = s21.equal_range(53);
  range = s.equal_range(53);
  EXPECT_EQ(*range21.first, *range.first);
  EXPECT_EQ(range.second, s.end());
  EXPECT_EQ(range21.second, s21.end());
}

TEST(MULTISET, multisetBoundноs) {
  s21::multiset<int> s21{10, 53, 35, 6, 6, 6, 7, 7};
  std::multiset<int> s{10, 53, 35, 6, 6, 6, 7, 7};
  auto range21 = s21.lower_bound(6);
  auto range = s.lower_bound(6);
  EXPECT_EQ(*range21, *range);
  range21 = s21.lower_bound(7);
  range = s.lower_bound(7);
  EXPECT_EQ(*range21, *range);
  range21 = s21.lower_bound(5);
  range = s.lower_bound(5);
  EXPECT_EQ(*range21, *range);
  range21 = s21.lower_bound(53);
  range = s.lower_bound(53);
  EXPECT_EQ(*range21, *range);
  range21 = s21.upper_bound(6);
  range = s.upper_bound(6);
  EXPECT_EQ(*range21, *range);
  range21 = s21.upper_bound(7);
  range = s.upper_bound(7);
  EXPECT_EQ(*range21, *range);
  range21 = s21.upper_bound(9);
  range = s.upper_bound(9);
  EXPECT_EQ(*range21, *range);
  range21 = s21.upper_bound(53);
  range = s.upper_bound(53);
  EXPECT_EQ(range21, s21.end());
  EXPECT_EQ(range, s.end());
}

TEST(MULTISET, Mergemultiset) {
  s21::multiset<int> my_multiset = {1};
  s21::multiset<int> my_merge_multiset = {3, 4, 5};
  my_multiset.merge(my_merge_multiset);

  std::multiset<int> orig_multiset = {1};
  std::multiset<int> orig_merge_multiset = {3, 4, 5};
  orig_multiset.merge(orig_merge_multiset);
  auto my_it = my_multiset.begin();
  auto orig_it = orig_multiset.begin();
  for (; my_it != my_multiset.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
  EXPECT_EQ(orig_multiset.size(), my_multiset.size());
  EXPECT_EQ(my_merge_multiset.size(), orig_merge_multiset.size());
}

TEST(MULTISET, Findmultiset) {
  s21::multiset<double> my_multiset = {2.1, 2.4, 2.5, 2.6};
  std::multiset<double> orig_multiset = {2.1, 2.4, 2.5, 2.6};
  auto my_it = my_multiset.lower_bound(2.4);
  auto orig_it = orig_multiset.lower_bound(2.4);
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(MULTISET, Finduppermultiset) {
  s21::multiset<double> my_multiset = {2.1, 2.1, 2.1, 2.4, 2.5, 2.6};
  std::multiset<double> orig_multiset = {2.1, 2.1, 2.1, 2.4, 2.5, 2.6};
  my_multiset.insert(2.4);
  orig_multiset.insert(2.4);
  auto my_it = my_multiset.upper_bound(2.4);
  auto orig_it = orig_multiset.upper_bound(2.4);
  EXPECT_TRUE(*orig_it == *my_it);
}

TEST(MULTISET, Containsmultiset) {
  s21::multiset<double> my_multiset = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  s21::multiset<double> orig_multiset = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  EXPECT_EQ(my_multiset.contains(2), orig_multiset.contains(2));
  EXPECT_EQ(my_multiset.contains(2.1), orig_multiset.contains(2.1));
}

TEST(MULTISET, AssignmentOperatorConst) {
  s21::multiset<int> my_set = {1, 2, 3, 4, 5};
  s21::multiset<int> my_set_copy;
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

TEST(MULTISET, MoveAssignmentOperator) {
  s21::multiset<int> my_set = {1, 2, 3, 4, 5};
  s21::multiset<int> my_set_copy;
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