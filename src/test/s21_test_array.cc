#include <gtest/gtest.h>

#include "../s21_containersplus.h"

TEST(EqOperator, array_test_1) {
  s21::array<int, 4> a21_1{1, 2, 3, 4};
  std::array<int, 4> a_1{1, 2, 3, 4};
  std::array<int, 4> a_2 = a_1;
  s21::array<int, 4> a21_2 = a21_1;
  for (size_t i = 0; i < a_2.size(); i++) EXPECT_EQ(a_2[i], a21_2[i]);
}

TEST(EqOperator, array_test_2) {
  s21::array<int, 4> a21{1, 2, 3, 4};
  std::array<int, 4> a{1, 2, 3, 4};
  a21[2] = 4;
  a[2] = 4;
  for (size_t i = 0; i < a.size(); i++) EXPECT_EQ(a[i], a21[i]);
}

TEST(At, array_test_1) {
  s21::array<int, 3> s21a_1 = {1, 2, 3};
  s21::array<double, 4> s21a_2 = {4.45645, 5.97709, -6.34, 9.8};
  EXPECT_EQ(s21a_1.at(1), 2);
  EXPECT_EQ(s21a_2.at(3), 9.8);
}

TEST(At, array_test_2) {
  s21::array<int, 3> s21a_1 = {1, 2, 3};
  EXPECT_ANY_THROW(s21a_1.at(9));
}
TEST(BracketOperator, array_test_1) {
  s21::array<int, 3> s21a_1 = {1, 2, 3, 6};
  s21::array<double, 4> s21a_2 = {4.45645, 5.97709, -6.34, 9.8};
  EXPECT_EQ(s21a_1[2], 3);
  EXPECT_EQ(s21a_2[3], 9.8);
}

TEST(Front, array_test_1) {
  s21::array<int, 4> s21a = {5, 8, 9, 112};
  std::array<int, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(a.front(), s21a.front());
}

TEST(Back, array_test_1) {
  s21::array<int, 4> s21a = {5, 8, 9, 112};
  std::array<int, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(a.back(), s21a.back());
}

TEST(Data, array_test_1) {
  s21::array<int, 4> s21a = {5, 8, 9, 112};
  std::array<int, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(*a.data(), *s21a.data());
}

TEST(Empty, array_test_1) {
  s21::array<int, 4> s21a = {5, 8, 9, 112};
  std::array<int, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(a.empty(), s21a.empty());
}

TEST(Empty, array_test_2) {
  s21::array<int, 0> s21a;
  std::array<int, 0> a;
  EXPECT_EQ(a.empty(), s21a.empty());
}

TEST(MaxSize, array_test_2) {
  s21::array<int, 4> s21a = {1, 2};
  std::array<int, 4> a = {1, 2};
  EXPECT_EQ(a.max_size(), s21a.max_size());
}

TEST(Swap, array_test_1) {
  s21::array<int, 4> a21_1 = {1, 2, 3, 4};
  std::array<int, 4> a_1 = {1, 2, 3, 4};
  std::array<int, 4> a_2 = {8, 9, 10, 11};
  s21::array<int, 4> a21_2 = {8, 9, 10, 11};
  a_1.swap(a_2);
  a21_1.swap(a21_2);
  for (size_t i = 0; i < a_1.size(); i++) EXPECT_EQ(a_1[i], a21_1[i]);
  for (size_t i = 0; i < a_2.size(); i++) EXPECT_EQ(a_2[i], a21_2[i]);
}

TEST(Fill, array_test_2) {
  s21::array<int, 0> a21;
  std::array<int, 0> a;
  a21.fill(6);
  a.fill(6);
  for (size_t i = 0; i < a.size(); i++) EXPECT_EQ(a[i], a21[i]);
}

TEST(Fill, array_test_1) {
  s21::array<int, 4> a21{1, 2, 3, 4};
  std::array<int, 4> a{1, 2, 3, 4};
  a21.fill(6);
  a.fill(6);
  for (size_t i = 0; i < a.size(); i++) EXPECT_EQ(a[i], a21[i]);
}

TEST(Begin, array_test_1) {
  s21::array<double, 4> s21a = {5, 8, 9, 112};
  std::array<double, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(*a.begin(), *s21a.begin());
}
TEST(End, array_test_1) {
  s21::array<double, 4> s21a = {5, 8, 9, 112};
  std::array<double, 4> a = {5, 8, 9, 112};
  EXPECT_EQ(a.end() - a.begin(), s21a.end() - s21a.begin());
}