CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17

TEST_FLAGS =  -lgtest  -lgmock -pthread -g
TEST_FILE =  s21_main_test.cc s21_test_set.cc s21_test_multiset.cc s21_test_map.cc s21_test_list.cc s21_test_queue.cc s21_test_stack.cc s21_test_array.cc s21_test_vector.cc
TEST_NAME = tets

.PHONY: test

all: clean test

test: clean
	cd test && $(CC) $(FLAGS) $(TEST_FILE) -o $(TEST_NAME) $(TEST_FLAGS) 
	cd test && ./$(TEST_NAME)


gcov_report: add_coverage rebuild
	lcov  -t "tests" -o test.info  -c -d . --no-external --ignore-errors mismatch
	genhtml -o report test.info
	open report/index.html
	cd test && rm -rf *.gcda *.gcno *.out

add_coverage:
	$(eval FLAGS += --coverage)

rebuild: clean test

clean:
	cd test && rm -rf $(TEST_NAME)
	cd test && rm -rf tets.dSYM
	cd test && rm -rf *.gcda
	cd test && rm -rf *.gcno
	rm -rf *.info
	rm -rf report

