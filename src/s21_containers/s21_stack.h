
#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_STACK_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_STACK_H_
// сортировка, меняя узлы местами
#include "s21_list.h"
namespace s21 {
template <typename T>
class stack {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Functions

  stack() = default;
  stack(std::initializer_list<value_type> const &items) : l(items){};
  stack(const stack &other) : l(other.l){};
  stack(stack &&other) : l(std::move(other.l)){};
  stack &operator=(const stack &other) {
    if (this != &other) {
      l = other.l;
    }
    return *this;
  }
  stack &operator=(stack &&other) {
    if (this != &other) {
      l = std::move(other.l);
    }
    return *this;
  }
  ~stack() = default;

  // Element access

  const_reference top() { return l.back(); };

  // Capacity
  bool empty() { return l.empty(); };
  size_type size() { return l.size(); };

  // Modifiers
  void push(const_reference value) { l.insert(l.end(), value); };
  void pop() { l.pop_back(); };
  void swap(stack &other) { l.swap(other.l); };

  // inserts new elements into the container
  template <typename... Args>
  void insert_many_front(Args &&...args) {
    l.insert_many(l.end(), args...);
  }

 private:
  list<value_type> l;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_STACK_H_