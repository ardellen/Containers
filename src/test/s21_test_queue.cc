#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

TEST(QUEUE, DefaultConstructor) {
  s21::queue<int> q1;
  std::queue<int> q2;
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
}

TEST(QUEUE, InitializerListConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  std::queue<int> q2;
  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(4);
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(QUEUE, InitializerListConstructor2) {
  s21::queue<int> q1{1, 3, 4, 2};
  std::queue<int> q2;
  q2.push(1);
  q2.push(3);
  q2.push(4);
  q2.push(2);
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(QUEUE, InitializerListConstructor3) {
  s21::queue<int> q1{3, 3, 3};
  std::queue<int> q2;
  q2.push(3);
  q2.push(3);
  q2.push(3);
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(QUEUE, CopyConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(q1);
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4(q3);
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QUEUE, MoveConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(std::move(q1));
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4(std::move(q3));
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QUEUE, Push) {
  s21::queue<int> q;
  std::queue<int> std_q;

  q.push(1);
  std_q.push(1);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());

  q.push(2);
  std_q.push(2);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());

  q.push(3);
  std_q.push(3);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());
}

TEST(QUEUE, MoveAssignmentOperator) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2;
  q2 = std::move(q1);
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4;
  q4 = std::move(q3);
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QUEUE, AssignmentOperatorConst) {
  s21::queue<int> q1 = {1, 2, 3, 4};
  s21::queue<int> q2;
  q2 = q1;
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4;
  q4 = q3;
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QUEUE, SwapTest) {
  s21::queue<int> q1{1, 2, 3};
  s21::queue<int> q2{4, 5, 6};
  s21::queue<int> q1_copy{q1};
  s21::queue<int> q2_copy{q2};

  q1.swap(q2);

  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.front(), 4);
  EXPECT_EQ(q1.back(), 6);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);

  q2.swap(q1);

  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.front(), 4);
  EXPECT_EQ(q2.back(), 6);
  EXPECT_EQ(q1.front(), 1);
  EXPECT_EQ(q1.back(), 3);
}

TEST(QUEUE, FrontTest) {
  s21::queue<int> test;
  test.push(1);
  test.push(2);
  std::queue<int> testS;
  testS.push(1);
  testS.push(2);
  ASSERT_EQ(test.front(), testS.front());
}

TEST(QUEUE, BackTest) {
  s21::queue<int> test;
  test.push(1);
  test.push(2);
  std::queue<int> testS;
  testS.push(1);
  testS.push(2);
  ASSERT_EQ(test.back(), testS.back());
}

TEST(QUEUE, EmptyTest1) {
  s21::queue<int> test;
  test.push(1);
  test.pop();
  std::queue<int> testS;
  testS.push(1);
  testS.pop();
  ASSERT_EQ(test.empty(), testS.empty());
}

TEST(QUEUE, EmptyTest2) {
  s21::queue<int> test;
  std::queue<int> testS;
  ASSERT_EQ(test.empty(), testS.empty());
}

TEST(QUEUE, SizeTest) {
  s21::queue<int> test;
  std::queue<int> testS;
  ASSERT_EQ(test.size(), testS.size());
}

TEST(QUEUE, ctors) {
  s21::queue<int> st{1, 2, 3, 4, 5};
  s21::queue<int> cpy(st);
  EXPECT_EQ(st.front(), cpy.front());
  EXPECT_EQ(st.back(), cpy.back());
  s21::queue<int> mv(std::move(st));
  EXPECT_EQ(mv.front(), cpy.front());
  EXPECT_EQ(mv.back(), cpy.back());
}

TEST(QUEUE, insert_many_back) {
  s21::queue<int> test;
  test.insert_many_back(1, 2, 3, 4, 5);
  ASSERT_EQ(test.size(), 5);
  ASSERT_EQ(test.back(), 5);
  test.insert_many_back(6, 7, 8, 9, 0);
  ASSERT_EQ(test.size(), 10);
  ASSERT_EQ(test.back(), 0);
  test.insert_many_back(22, 23, 24, 25, 26);
  ASSERT_EQ(test.size(), 15);
}