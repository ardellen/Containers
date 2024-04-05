#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

TEST(list, ConstructorDefaultlist) {
  s21::list<char> my_empty_list;
  std::list<char> orig_empty_list;
  EXPECT_EQ(my_empty_list.empty(), orig_empty_list.empty());
}

TEST(list, Initializerlist) {
  s21::list<int> my_list = {};
  std::list<int> orig_list = {};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, Initializerlist2) {
  s21::list<int> my_list = {8, 4, 6, 12, 10, 7, 11, 9, 5, 14, 13, 2, 3, 1, 15};
  std::list<int> orig_list = {8, 4,  6,  12, 10, 7, 11, 9,
                              5, 14, 13, 2,  3,  1, 15};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, Initializerlist3) {
  s21::list<int> my_list = {0, 1, 2, 3, 4, 5};
  std::list<int> orig_list = {0, 1, 2, 3, 4, 5};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, Initializerlist4) {
  s21::list<int> my_list = {0, 0, 0, 0};
  std::list<int> orig_list = {0, 0, 0, 0};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, Initializerlist5) {
  s21::list<char> my_list = {'h', 'e', 'l', 'l', 'o', '0'};
  std::list<char> orig_list = {'h', 'e', 'l', 'l', 'o', '0'};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, Initializerlist6) {
  std::string arr[] = {"hello", "world", "test", "string"};
  s21::list<std::string> my_list;
  std::list<std::string> orig_list;
  for (const auto& str : arr) {
    my_list.push_back(str);
    orig_list.push_back(str);
  }
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, ConstructorInitializer2list) {
  s21::list<char> my_list = {};
  std::list<char> orig_list = {};
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

// copy

TEST(list, CopyConstructorElements) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list(original_list);
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyOperatorElements) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list = original_list;
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyConstructorElements1) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  s21::list<float> copied_list(original_list);
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyOperatorElements1) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  s21::list<float> copied_list = original_list;
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyOperatorElements2) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  s21::list<float> copied_list = {1.81, 2};
  copied_list = original_list;
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyConstructorEmptyList) {
  s21::list<int> original_list;
  s21::list<int> copied_list(original_list);
  EXPECT_EQ(copied_list.size(), 0u);
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyOperatorElements0) {
  s21::list<int> original_list;
  s21::list<int> copied_list = original_list;
  EXPECT_EQ(copied_list.size(), 0u);
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyConstructorSelfCopy) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list(original_list);
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

TEST(list, CopyOperatorSelfCopy) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list = original_list;
  original_list = original_list;
  auto orig_it = original_list.begin();
  auto copy_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++copy_it) {
    EXPECT_EQ(*orig_it, *copy_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

// Move

TEST(list, MoveConstructorElements) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list = original_list;
  s21::list<int> moved_list(std::move(original_list));
  auto copy_it = copied_list.begin();
  auto move_it = moved_list.begin();
  for (; copy_it != copied_list.end(); ++copy_it, ++move_it) {
    EXPECT_EQ(*copy_it, *move_it);
  }
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, MoveOperatorElements) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list = original_list;
  s21::list<int> moved_list = std::move(original_list);
  auto copy_it = copied_list.begin();
  auto move_it = moved_list.begin();
  for (; copy_it != copied_list.end(); ++copy_it, ++move_it) {
    EXPECT_EQ(*copy_it, *move_it);
  }
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, MoveConstructorElements1) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  s21::list<float> copied_list = original_list;
  s21::list<float> moved_list(std::move(original_list));
  auto copy_it = copied_list.begin();
  auto move_it = moved_list.begin();
  for (; copy_it != copied_list.end(); ++copy_it, ++move_it) {
    EXPECT_EQ(*copy_it, *move_it);
  }
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, MoveOperatorElements1) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  s21::list<float> copied_list = original_list;
  s21::list<float> moved_list = std::move(original_list);
  auto copy_it = copied_list.begin();
  auto move_it = moved_list.begin();
  for (; copy_it != copied_list.end(); ++copy_it, ++move_it) {
    EXPECT_EQ(*copy_it, *move_it);
  }
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, MoveConstructorEmptyList) {
  s21::list<int> original_list;
  s21::list<int> copied_list = original_list;
  s21::list<int> moved_list(std::move(original_list));
  EXPECT_EQ(moved_list.size(), 0u);
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, MoveOperatorEmptyList) {
  s21::list<int> original_list;
  s21::list<int> copied_list = original_list;
  s21::list<int> moved_list = std::move(original_list);
  EXPECT_EQ(moved_list.size(), 0u);
  EXPECT_EQ(copied_list.size(), moved_list.size());
}

TEST(list, ConstructorMovelist2) {
  s21::list<int> my_list = {1, 2, 3, 4, 5};
  std::list<int> orig_list = {1, 2, 3, 4, 5};
  s21::list<int> my_list_copy = std::move(my_list);
  std::list<int> orig_list_copy = std::move(orig_list);
  EXPECT_EQ(my_list.size(), orig_list.size());
  EXPECT_EQ(my_list_copy.size(), orig_list_copy.size());
  auto my_it = my_list_copy.begin();
  auto orig_it = orig_list_copy.begin();
  for (; my_it != my_list_copy.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, MoveConstructorSelfCopy) {
  s21::list<int> original_list = {1, 2, 3, 4, 5};
  s21::list<int> copied_list = original_list;
  original_list = std::move(original_list);
  auto orig_it = original_list.begin();
  auto move_it = copied_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++move_it) {
    EXPECT_EQ(*orig_it, *move_it);
  }
  EXPECT_EQ(original_list.size(), copied_list.size());
}

// const_reference

TEST(list, ConstReferenceList1) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  auto orig_it = original_list.begin();
  float next = original_list.front();
  float origin_next = *orig_it;
  EXPECT_FLOAT_EQ(origin_next, next);
}

TEST(list, ConstReferenceList2) {
  s21::list<float> original_list;
  auto orig_it = original_list.begin();
  auto orig_it2 = original_list.end();
  EXPECT_EQ(orig_it, orig_it2);
}

TEST(list, ConstReferenceList3) {
  s21::list<float> original_list = {1.8901, 2, 3.7777, 0.4, 555.5};
  auto orig_it = original_list.end();
  --orig_it;
  float prev = original_list.back();
  float origin_prev = *orig_it;
  EXPECT_FLOAT_EQ(origin_prev, prev);
}

// Clear/Capacity/Modifiers

TEST(list, ClearList) {
  s21::list<char> my_empty_list;
  std::list<char> orig_empty_list;
  my_empty_list.clear();
  orig_empty_list.clear();
  EXPECT_EQ(my_empty_list.empty(), orig_empty_list.empty());
  EXPECT_EQ(my_empty_list.size(), orig_empty_list.size());
  my_empty_list.push_front('a');
  orig_empty_list.push_front('b');
  EXPECT_EQ(my_empty_list.empty(), orig_empty_list.empty());
  EXPECT_EQ(my_empty_list.size(), orig_empty_list.size());
  my_empty_list.clear();
  orig_empty_list.clear();
  EXPECT_EQ(my_empty_list.empty(), orig_empty_list.empty());
  EXPECT_EQ(my_empty_list.size(), orig_empty_list.size());
  EXPECT_EQ(my_empty_list.max_size(), orig_empty_list.max_size());
}

TEST(list, insertList) {
  s21::list<int> original_list;
  original_list.insert(original_list.begin(), 1);
  std::list<int> another_list;
  another_list.insert(another_list.begin(), 1);
  ASSERT_EQ(*original_list.begin(), *another_list.begin());
}

TEST(list, insertList2) {
  s21::list<int> original_list(1);
  original_list.insert(original_list.begin(), 1);
  std::list<int> another_list(1);
  another_list.insert(another_list.begin(), 1);
  ASSERT_EQ(*original_list.begin(), *another_list.begin());
}

TEST(list, insertList3) {
  s21::list<int> original_list(3);
  original_list.insert(original_list.end(), 1);
  std::list<int> another_list(3);
  another_list.insert(another_list.end(), 1);
  ASSERT_EQ(original_list.back(), another_list.back());
  ASSERT_EQ(original_list.size(), another_list.size());
}

TEST(list, insertList4) {
  s21::list<int> original_list(3);
  original_list.insert(original_list.begin(), 1);
  std::list<int> another_list(3);
  another_list.insert(another_list.begin(), 1);
  ASSERT_EQ(original_list.front(), another_list.front());
}

TEST(list, insertList5) {
  s21::list<int> original_list(3);
  original_list.insert(original_list.begin(), 2);
  std::list<int> another_list(3);
  another_list.insert(another_list.begin(), 2);
  auto orig_it = original_list.begin();
  auto another_it = another_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++another_it) {
    EXPECT_EQ(*orig_it, *another_it);
  }
}

TEST(list, eraseList) {
  s21::list<double> original_list;
  original_list.push_back(1.678);
  original_list.push_back(3.3333);
  original_list.erase(original_list.begin());
  std::list<double> another_list;
  another_list.push_back(1.678);
  another_list.push_back(3.3333);
  another_list.erase(another_list.begin());
  ASSERT_EQ(original_list.front(), another_list.front());
  ASSERT_EQ(original_list.size(), another_list.size());
}

TEST(list, eraseList2) {
  s21::list<double> original_list;
  original_list.push_back(1.678);
  original_list.push_back(6.66666);
  original_list.erase(original_list.begin());
  std::list<double> another_list;
  another_list.push_back(1.678);
  another_list.push_back(6.66666);
  another_list.erase(another_list.begin());
  ASSERT_EQ(original_list.size(), another_list.size());
  auto orig_it = original_list.begin();
  auto another_it = another_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++another_it) {
    EXPECT_EQ(*orig_it, *another_it);
  }
}

TEST(list, uniqueList) {
  s21::list<int> original_list{1, 2, 3, 4, 5, 6, 6, 6};
  s21::list<int> another_list{1, 2, 3, 4, 5, 6};
  original_list.unique();
  auto orig_it = original_list.begin();
  auto another_it = another_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++another_it) {
    EXPECT_EQ(*orig_it, *another_it);
  }
}

TEST(list, uniqueList2) {
  s21::list<int> my_list = {1, 2, 2, 2, 3, 4, 4, 5};
  std::list<int> orig_list = {1, 2, 2, 2, 3, 4, 4, 5};
  my_list.unique();
  orig_list.unique();
  EXPECT_EQ(my_list.size(), orig_list.size());
  auto my_it = my_list.begin();
  auto orig_it = orig_list.begin();
  for (; my_it != my_list.end(); ++my_it, ++orig_it) {
    EXPECT_TRUE(*orig_it == *my_it);
  }
}

TEST(list, uniqueList3) {
  s21::list<int> original_list{1, 2, 3, 4, 5, 6};
  s21::list<int> another_list{1, 2, 3, 4, 5, 6};
  original_list.unique();
  auto orig_it = original_list.begin();
  auto another_it = another_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++another_it) {
    EXPECT_EQ(*orig_it, *another_it);
  }
}

TEST(list, popList) {
  s21::list<char> original_list;
  std::list<char> another_list;
  EXPECT_EQ(original_list.size(), another_list.size());
  original_list.push_front('a');
  another_list.push_front('a');
  original_list.push_front('b');
  another_list.push_front('b');
  EXPECT_EQ(original_list.empty(), another_list.empty());
  EXPECT_EQ(original_list.size(), another_list.size());
  original_list.pop_back();
  another_list.pop_back();
  auto orig_it = original_list.begin();
  auto another_it = another_list.begin();
  for (; orig_it != original_list.end(); ++orig_it, ++another_it) {
    EXPECT_EQ(*orig_it, *another_it);
  }
  EXPECT_EQ(original_list.size(), another_list.size());
  original_list.push_front('b');
  another_list.push_front('a');
  original_list.pop_front();
  another_list.pop_front();
  auto orig_it2 = original_list.begin();
  auto another_it2 = another_list.begin();
  for (; orig_it2 != original_list.end(); ++orig_it2, ++another_it2) {
    EXPECT_EQ(*orig_it2, *another_it2);
  }
  EXPECT_EQ(original_list.size(), another_list.size());
}

TEST(list, swapList) {
  s21::list<int> my_list = {1};
  s21::list<int> my_swap_list = {3, 4, 5};
  my_list.swap(my_swap_list);
  EXPECT_EQ(my_list.size(), 3u);
  EXPECT_EQ(my_swap_list.size(), 1u);
  EXPECT_EQ(*my_list.begin(), 3);
  EXPECT_EQ(*my_swap_list.begin(), 1);
}

TEST(list, swapList2) {
  s21::list<int> my_list;
  s21::list<int> my_swap_list = {3, 4, 5};
  my_list.swap(my_swap_list);
  EXPECT_EQ(my_list.size(), 3u);
  EXPECT_EQ(my_swap_list.size(), 0u);
  EXPECT_EQ(*my_list.begin(), 3);
}

TEST(list, spliceList) {
  s21::list<int> right = {3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> original_list;
  original_list.push_front(10);
  original_list.push_front(9);
  original_list.push_front(8);
  original_list.push_front(7);
  s21::list<int> another_list;
  another_list.push_front(6);
  another_list.push_front(5);
  another_list.push_front(4);
  another_list.push_front(3);
  original_list.splice(original_list.begin(), another_list);
  std::list<int> list3;
  list3.push_front(10);
  list3.push_front(9);
  list3.push_front(8);
  list3.push_front(7);
  std::list<int> another_list2;
  another_list2.push_front(6);
  another_list2.push_front(5);
  another_list2.push_front(4);
  another_list2.push_front(3);
  list3.splice(list3.begin(), another_list2);
  auto orig_it = right.begin();
  auto list3_it = list3.begin();
  for (; orig_it != right.end(); ++orig_it, ++list3_it) {
    EXPECT_EQ(*orig_it, *list3_it);
  }
  EXPECT_EQ(right.size(), list3.size());
}

TEST(list, reverseList) {
  s21::list<int> original_list;
  original_list.push_front(1);
  original_list.push_front(2);
  original_list.push_front(3);
  original_list.reverse();
  std::list<int> another_list;
  another_list.push_front(1);
  another_list.push_front(2);
  another_list.push_front(3);
  another_list.reverse();
  auto orig_it2 = original_list.begin();
  auto another_it2 = another_list.begin();
  for (; orig_it2 != original_list.end(); ++orig_it2, ++another_it2) {
    EXPECT_EQ(*orig_it2, *another_it2);
  }
  EXPECT_EQ(original_list.size(), another_list.size());
}

TEST(list, mergeList) {
  s21::list<int> original_list;
  original_list.push_front(10);
  original_list.push_front(7);
  s21::list<int> another_list;
  another_list.push_front(6);
  another_list.push_front(3);
  original_list.merge(another_list);
  std::list<int> test;
  test.push_front(10);
  test.push_front(7);
  std::list<int> testOne;
  testOne.push_front(6);
  testOne.push_front(3);
  test.merge(testOne);
  ASSERT_EQ(original_list.front(), test.front());
}

TEST(list, mergeList2) {
  s21::list<int> original_list;
  original_list.push_front(10);
  original_list.push_front(1);
  s21::list<int> another_list;
  another_list.push_front(11);
  another_list.push_front(3);
  original_list.merge(another_list);
  std::list<int> test;
  test.push_front(10);
  test.push_front(1);
  std::list<int> testOne;
  testOne.push_front(11);
  testOne.push_front(3);
  test.merge(testOne);
  ASSERT_EQ(original_list.front(), test.front());
}

TEST(list, mergeList3) {
  s21::list<int> original_list;
  original_list.push_front(10);
  original_list.push_front(7);
  original_list.push_front(5);
  original_list.push_front(1);
  s21::list<int> another_list;
  original_list.merge(another_list);
  std::list<int> test;
  test.push_front(10);
  test.push_front(7);
  test.push_front(5);
  test.push_front(1);
  std::list<int> another_list2;
  test.merge(another_list2);
  ASSERT_EQ(original_list.front(), test.front());
}

TEST(list, sortList) {
  s21::list<int> original_list(0);
  original_list.push_front(9);
  original_list.push_front(3);
  original_list.push_front(2);
  original_list.push_front(1);
  s21::list<int> another_list(0);
  another_list.push_front(1);
  another_list.push_front(2);
  another_list.push_front(3);
  another_list.push_front(9);
  another_list.sortMerge();
  original_list.compareLists(another_list);
}

TEST(list, sortList2) {
  s21::list<int> original_list(0);
  original_list.push_front(7);
  original_list.push_front(6);
  original_list.push_front(5);
  original_list.push_front(4);
  original_list.push_front(3);
  original_list.push_front(2);
  original_list.push_front(1);
  s21::list<int> another_list(0);
  another_list.push_front(7);
  another_list.push_front(6);
  another_list.push_front(3);
  another_list.push_front(5);
  another_list.push_front(2);
  another_list.push_front(1);
  another_list.push_front(4);
  another_list.sortMerge();
  original_list.compareLists(another_list);
}

TEST(list, ListConstIterator) {
  s21::list<int> test_list = {1, 2, 3, 4, 5};
  s21::list<int>::const_iterator it = test_list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);
  auto it_begin = test_list.begin();
  EXPECT_TRUE(it == it_begin);
  ++it_begin;
  EXPECT_TRUE(it != it_begin);
  ++it;
  ++it;
  EXPECT_EQ(*it, 3);
  while (it != test_list.end()) {
    ++it;
  }
  --it;
  EXPECT_EQ(*it, 5);
}

TEST(list, ListIterator) {
  s21::list<int> test_list = {1, 2, 3, 4, 5};
  s21::list<int>::const_iterator it = test_list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);
  auto it_begin = test_list.begin();
  EXPECT_TRUE(it == it_begin);
  ++it_begin;
  EXPECT_TRUE(it != it_begin);
  ++it;
  ++it;
  EXPECT_EQ(*it, 3);
  while (it != test_list.end()) {
    ++it;
  }
  --it;
  EXPECT_EQ(*it, 5);
}

TEST(insert_many, test0) {
  s21::list<int> test;
  test.insert_many(test.begin(), 1, 2, 3, 4, 5);
  auto it = test.begin();
  ASSERT_EQ(test.size(), 5u);
  ASSERT_EQ(*it, 1);
}

TEST(insert_many, test1) {
  s21::list<int> test;
  s21::list<int> test2 = {1, 2, 1, 2, 3, 4, 5, 3, 4, 5};
  test.insert_many(test.begin(), 1, 2, 3, 4, 5);
  ASSERT_EQ(test.size(), 5u);
  auto it = test.begin();
  ++it;
  ++it;
  test.insert_many(it, 1, 2, 3, 4, 5);
  ASSERT_EQ(test.size(), 10u);
  test.compareLists(test2);
}

TEST(insert_many, test2) {
  s21::list<int> test;
  test.insert_many_back(6, 7, 8, 9, 0);
  ASSERT_EQ(test.size(), 5);
  ASSERT_EQ(test.back(), 0);
}

TEST(insert_many, test3) {
  s21::list<int> test;
  test.insert_many_front(22, 23, 24, 25, 26);
  ASSERT_EQ(test.size(), 5);
  ASSERT_EQ(test.front(), 22);
}
