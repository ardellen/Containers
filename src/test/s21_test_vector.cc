#include <gtest/gtest.h>

#include "../s21_containers.h"

TEST(BaseConstructor, vector_test_1) {
  s21::vector<int> s21v;
  std::vector<int> v;
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
}

TEST(ParamConstructor, vector_test_1) {
  s21::vector<int> s21v(3);
  std::vector<int> v(3);
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
}

TEST(CopyConstructor, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2(s21v_1);
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2(v_1);
  EXPECT_EQ(v_2.capacity(), s21v_2.capacity());
  EXPECT_EQ(v_2.size(), s21v_2.size());
  for (size_t i = 0; i < v_2.size(); i++) EXPECT_EQ(v_2[i], s21v_2[i]);
}
/*[----------] 1 test from MoveConstructor
[ RUN      ] MoveConstructor.vector_test_1
is3
Distr
tets(28303,0x10d037e00) malloc: *** error for object 0x7fbc94614db0: pointer
being freed was not allocated tets(28303,0x10d037e00) malloc: *** set a
breakpoint in malloc_error_break to debug /bin/sh: line 1: 28303 Abort trap: 6
./tets
*/
TEST(MoveConstructor, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2(std::move(s21v_1));
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2(std::move(v_1));
  EXPECT_EQ(v_2.capacity(), s21v_2.capacity());
  EXPECT_EQ(v_2.size(), s21v_2.size());
  for (size_t i = 0; i < v_2.size(); i++) EXPECT_EQ(v_2[i], s21v_2[i]);
}

/*
s21_test_vector.cc: In member function 'virtual void
EqOperator_vector_test_1_Test::TestBody()': s21_test_vector.cc:48:12: error: use
of deleted function 'constexpr s21::vector<int>&
s21::vector<int>::operator=(const s21::vector<int>&)' 48 |   s21v_1 = s21v_2; |
^~~~~~ In file included from ../s21_containers.h:9, from s21_test_vector.cc:2:
../s21_containers/s21_vector.h:13:7: note: 'constexpr s21::vector<int>&
s21::vector<int>::operator=(const s21::vector<int>&)' is implicitly declared as
deleted because 's21::vector<int>' declares a move constructor or move
assignment operator 13 | class vector {
*/
TEST(EqOperator, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {4, 5, 6};
  s21v_1 = s21v_2;
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2 = {4, 5, 6};
  v_1 = v_2;
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
}

/*
tets(30054,0x10c7a1e00) malloc: *** error for object 0x7f8abf408590: pointer
being freed was not allocated tets(30054,0x10c7a1e00) malloc: *** set a
breakpoint in malloc_error_break to debug /bin/sh: line 1: 30054 Abort trap: 6
./tets
*/
TEST(EqOperator, vector_test_2_move) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {4, 5, 6, 5};
  s21v_1 = std::move(s21v_2);
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2 = {4, 5, 6, 5};
  v_1 = std::move(v_2);
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
}

/*
ets -lgtest  -lgmock -pthread -g
s21_test_vector.cc: In member function 'virtual void
EqOperator_vector_test_2_Test::TestBody()': s21_test_vector.cc:90:12: error: use
of deleted function 'constexpr s21::vector<int>&
s21::vector<int>::operator=(const s21::vector<int>&)' 90 |   s21v_1 = s21v_2; |
^~~~~~ In file included from ../s21_containers.h:9, from s21_test_vector.cc:2:
../s21_containers/s21_vector.h:13:7: note: 'constexpr s21::vector<int>&
s21::vector<int>::operator=(const s21::vector<int>&)' is implicitly declared as
deleted because 's21::vector<int>' declares a move constructor or move
assignment operator 13 | class vector {
*/
TEST(EqOperator, vector_test_2) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {4, 5, 6, 5};
  s21v_1 = s21v_2;
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2 = {4, 5, 6, 5};
  v_1 = v_2;
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
}

TEST(At, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<double> s21v_2 = {4.45645, 5.97709, -6.34, 9.8};
  EXPECT_EQ(s21v_1.at(2), 3);
  EXPECT_EQ(s21v_2.at(3), 9.8);
}

TEST(At, vector_test_2) {
  s21::vector<double> s21v_2 = {4.45645, 5.97709, -6.34, 9.8};
  EXPECT_ANY_THROW(s21v_2.at(8));
}

TEST(BracketOperator, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<double> s21v_2 = {4.45645, 5.97709, -6.34, 9.8};
  EXPECT_EQ(s21v_1[2], 3);
  EXPECT_EQ(s21v_2[3], 9.8);
}

TEST(Front, vector_test_1) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  EXPECT_EQ(v.front(), s21v.front());
}

TEST(Back, vector_test_1) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  EXPECT_EQ(v.back(), s21v.back());
}

TEST(Data, vector_test_1) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  EXPECT_EQ(*v.data(), *s21v.data());
}

TEST(Empty, vector_test_1) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Empty, vector_test_2) {
  s21::vector<int> s21v;
  std::vector<int> v;
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Empty, vector_test_3) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  for (size_t i = 0; i < v.size(); i++) {
    s21v.pop_back();
    v.pop_back();
  }
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Empty, vector_test_4) {
  s21::vector<int> s21v = {5, 8, 9, 112, 56, 7779};
  std::vector<int> v = {5, 8, 9, 112};
  v.clear();
  s21v.clear();
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Reserve, vector_test_1) {
  s21::vector<double> s21v(4);
  std::vector<double> v(4);
  EXPECT_ANY_THROW(v.reserve(v.max_size() + 23));
  EXPECT_ANY_THROW(s21v.reserve(s21v.max_size() + 23));
}

TEST(Reserve, vector_test_2) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.reserve(23);
  s21v.reserve(23);
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(ShrinkToFit, vector_test_1) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.reserve(23);
  s21v.reserve(23);
  v.shrink_to_fit();
  s21v.shrink_to_fit();
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(Clear, vector_test_2) {
  s21::vector<double> s21v;
  std::vector<double> v;
  v.clear();
  s21v.clear();
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Clear, vector_test_1) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.clear();
  s21v.clear();
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  EXPECT_EQ(v.empty(), s21v.empty());
}

TEST(Insert, vector_test_1) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};

  EXPECT_EQ(*v.insert(v.begin() + 2, 23.345),
            *s21v.insert(s21v.begin() + 2, 23.345));

  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(Insert, vector_test_2) {
  s21::vector<double> s21v;
  std::vector<double> v;

  EXPECT_EQ(*v.insert(v.begin(), 23.345), *s21v.insert(s21v.begin(), 23.345));

  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(Erase, vector_test_1) {
  s21::vector<double> s21v_1 = {1, 23, 54, 56};
  std::vector<double> v_1 = {1, 23, 54, 56};

  v_1.erase(v_1.begin() + 2);
  s21v_1.erase(s21v_1.begin() + 2);
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
}

TEST(Erase, vector_test_2) {
  s21::vector<double> s21v_1 = {1, 23, 54};
  std::vector<double> v_1 = {1, 23, 54};

  v_1.erase(v_1.begin() + 2);
  s21v_1.erase(s21v_1.begin() + 2);
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
}

TEST(PushBack, vector_test_1) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};

  v.push_back(2.678);
  s21v.push_back(2.678);
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(PushBack, vector_test_2) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.reserve(8);
  s21v.reserve(8);
  v.push_back(2.678);
  s21v.push_back(2.678);
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(PushBack, vector_test_3) {
  s21::vector<double> s21v;
  std::vector<double> v;

  v.push_back(2.678);
  s21v.push_back(2.678);
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(PopBack, vector_test_1) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.pop_back();
  s21v.pop_back();
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(PopBack, vector_test_2) {
  s21::vector<double> s21v = {1, 23, 54, 56};
  std::vector<double> v = {1, 23, 54, 56};
  v.reserve(23);
  s21v.reserve(23);
  v.pop_back();
  s21v.pop_back();
  EXPECT_EQ(v.capacity(), s21v.capacity());
  EXPECT_EQ(v.size(), s21v.size());
  for (size_t i = 0; i < v.size(); i++) EXPECT_EQ(v[i], s21v[i]);
}

TEST(Swap, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {4, 5, 6};
  std::vector<int> v_1 = {1, 2, 3};
  std::vector<int> v_2 = {4, 5, 6};
  v_1.swap(v_2);
  s21v_1.swap(s21v_2);
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_2.capacity(), s21v_2.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  EXPECT_EQ(v_2.size(), s21v_2.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
  for (size_t i = 0; i < v_2.size(); i++) EXPECT_EQ(v_2[i], s21v_2[i]);
}

TEST(Swap, vector_test_2) {
  s21::vector<int> s21v_1 = {1, 2, 3, 4};
  s21::vector<int> s21v_2 = {4, 5, 6};
  std::vector<int> v_1 = {1, 2, 3, 4};
  std::vector<int> v_2 = {4, 5, 6};
  v_1.swap(v_2);
  s21v_1.swap(s21v_2);
  EXPECT_EQ(v_1.capacity(), s21v_1.capacity());
  EXPECT_EQ(v_2.capacity(), s21v_2.capacity());
  EXPECT_EQ(v_1.size(), s21v_1.size());
  EXPECT_EQ(v_2.size(), s21v_2.size());
  for (size_t i = 0; i < v_1.size(); i++) EXPECT_EQ(v_1[i], s21v_1[i]);
  for (size_t i = 0; i < v_2.size(); i++) EXPECT_EQ(v_2[i], s21v_2[i]);
}

TEST(Begin, vector_test_1) {
  s21::vector<int> s21v = {5, 8, 9, 112};
  std::vector<int> v = {5, 8, 9, 112};
  EXPECT_EQ(*v.begin(), *s21v.begin());
}

TEST(End, vector_test_1) {
  s21::vector<int> s21v;
  std::vector<int> v;
  EXPECT_EQ(v.end() - v.begin(), s21v.end() - s21v.begin());
}
/*
is3
is5
insert_many_1 cap 3
Distr
insert_many_2 2  5  0x7fac128041c0  0x7fac128041cc  0x7fac12804190
0x7fac128041c0
to_end_1 3  5  3
t_e 1  3
t_e 2  3
t_e 3  3
to_end_2 5  0
s21_test_vector.cc:369: Failure
Expected equality of these values:
  *s21v_1.insert_many(s21v_1.begin(), 4, 5)
    Which is: 1
  4
Distr
Distr
*/
TEST(ManyInsert, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {4, 5, 1, 2, 3};
  EXPECT_EQ(*s21v_1.insert_many(s21v_1.begin(), 4, 5), 4);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}
/*
is2
insert_many_1 cap 0
Distr
insert_many_2 2  2  0x7f97c941a190  0x7f97c941a190  0
0x7f97c941a190
to_end_1 0  2  0
to_end_2 2  0
s21_test_vector.cc:395: Failure
Expected equality of these values:
  *s21v_1.insert_many(s21v_1.begin(), 4, 5)
    Which is: 0
  4
Distr
Distr
*/
TEST(ManyInsert, vector_test_2) {
  s21::vector<int> s21v_1;
  s21::vector<int> s21v_2 = {4, 5};
  EXPECT_EQ(*s21v_1.insert_many(s21v_1.begin(), 4, 5), 4);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}
/*
 Segmentation fault: 11  ./tets
*/
TEST(ManyInsert, vector_test_3) {
  s21::vector<int> s21v_1;
  s21::vector<int> s21v_2 = {4, 5};
  s21v_1.insert_many(s21v_1.begin() + 88, 4, 5);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}

TEST(ManyInsert, vector_test_4) {
  s21::vector<int> s21v_1;
  s21::vector<int> s21v_2 = {4, 5};
  s21v_1.insert_many(s21v_1.begin() + 88, -4, 5);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}

TEST(ManyInsertBack, vector_test_1) {
  s21::vector<int> s21v_1 = {1, 2, 3};
  s21::vector<int> s21v_2 = {1, 2, 3, 4, 5};
  s21v_1.insert_many_back(4, 5);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}

TEST(ManyInsertBack, vector_test_2) {
  s21::vector<int> s21v_1;
  s21::vector<int> s21v_2 = {4, 5};
  s21v_1.insert_many_back(4, 5);
  for (size_t i = 0; i < s21v_2.size(); i++) EXPECT_EQ(s21v_2[i], s21v_1[i]);
}
