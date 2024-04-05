#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_QUEUE_H_
// сортировка, меняя узлы местами
#include "s21_list.h"
namespace s21 {
//, class C = list<T>
template <typename T>
class queue {
 public:
  // Member type

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Functions

  queue() = default;
  queue(std::initializer_list<value_type> const &items) : l(items){};
  queue(const queue &other) : l(other.l){};
  queue(queue &&other) : l(std::move(other.l)){};
  queue &operator=(const queue &other) {
    if (this != &other) {
      l = other.l;
    }
    return *this;
  }
  queue &operator=(queue &&other) {
    if (this != &other) {
      l = std::move(other.l);
    }
    return *this;
  }
  ~queue() = default;

  // Element access

  const_reference front() { return l.front(); };
  const_reference back() { return l.back(); };

  // Capacity

  bool empty() { return l.empty(); };
  size_type size() { return l.size(); };

  // Modifiers

  void push(const_reference value) { l.insert(l.end(), value); };
  void pop() { l.erase(l.begin()); };
  void swap(queue &other) { l.swap(other.l); };

  // inserts new elements into the container
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    l.insert_many(l.end(), args...);
  }

 private:
  list<value_type> l;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_QUEUE_H_