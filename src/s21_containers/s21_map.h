#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_MAP_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_MAP_H_

#include <iostream>

#include "s21_tree.h"

namespace s21 {
template <class Key, class T, class Cmp = std::less<Key>>

class map {
 public:
  // внутриклассовые переопределения типов
  // the first template parameter (Key)
  using key_type = Key;
  // the second template parameter (T)
  using mapped_type = T;
  // Key-value pair
  using value_type = std::pair<const key_type, mapped_type>;

  class Comparator {
   public:
    bool operator()(const value_type &lhs, const value_type &rhs) {
      return Cmp{}(lhs.first, rhs.first);
    }
  };

  using tree_type = AVLTree<value_type, Comparator>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree_type::iterator;
  using const_iterator = typename tree_type::const_iterator;
  using size_type = std::size_t;

  //  основные публичные методы для взаимодействия с классом
  //   default constructor, creates empty map
  map() = default;

  //   initializer list constructor, creates the map initizialized using
  //   std::initializer_list
  map(std::initializer_list<value_type> const &items) : tree_(items) {}

  // конструктор копирования
  map(const map &other) = default;

  // конструктор переноса
  map(map &&other) noexcept { tree_ = std::move(other.tree_); }

  // destructor
  ~map() = default;

  // присваивание копированием
  map &operator=(const map &other) {
    if (this != &other) {
      tree_ = other.tree_;
    }
    return *this;
  }

  // присваивание переносом
  map &operator=(map &&other) noexcept {
    if (this != &other) {
      tree_ = std::move(other.tree_);
    }
    return *this;
  }

  // публичные методы для доступа к элементам классa
  // доступ к указанному элементу с проверкой границ
  T &at(const Key &key) {
    value_type value(key, mapped_type{});
    iterator it = tree_.find(value);
    if (it == tree_.end()) {
      throw std::out_of_range("No elements with key");
    } else
      return (*it).second;
  }

  // получить доступ или вставить указанный элемент
  T &operator[](const Key &key) { return at(key); }

  // возвращает итератор в начало
  iterator begin() noexcept { return tree_.begin(); }

  const_iterator begin() const noexcept {
    return const_iterator(tree_.begin());
  }

  // возвращает итератор в конец
  iterator end() noexcept { return tree_.end(); }

  const_iterator end() const noexcept { return const_iterator(tree_.end()); }

  // публичные методы для доступа к информации о наполнении контейнера
  // проверяет, пуст ли контейнер
  bool empty() const noexcept { return tree_.empty(); }

  // возвращает количество элементов
  size_type size() const noexcept { return tree_.size(); }

  // возвращает максимально возможное количество элементов
  size_type max_size() const noexcept { return tree_.max_size(); }

  // публичные методы для изменения контейнера
  // очищает содержимое
  void clear() noexcept { tree_.clear(); }

  // вставляет узел и возвращает итератор туда, где находится элемент в
  // контейнере, и логическое значение, обозначающее, имела ли место вставка.
  std::pair<iterator, bool> insert(const_reference value) {
    return tree_.insert(value);
  }

  // вставляет значение по ключу и возвращает итератор туда, где находится
  // элемент в контейнере, и логическое значение, обозначающее, имела ли место
  // вставка
  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return tree_.insert(value_type{key, obj});
  }

  // вставляет новые элементы в контейнер
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.emplace_back(insert(std::forward<Args>(args))), ...);
    return result;
  }

  // вставляет элемент или присваивает его текущему элементу, если ключ уже
  // существует
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    iterator it = tree_.find(value_type{key, obj});
    if (it != tree_.end()) {
      (*it).second = obj;
      return {it, false};
    } else
      return tree_.insert(value_type{key, obj});
  }

  // стирает элемент в позиции
  void erase(iterator pos) noexcept { tree_.erase(pos); }

  // меняет содержимое
  void swap(map &other) noexcept { tree_.swap(other.tree_); }

  // соединяет узлы из другого контейнера
  void merge(map &other) { tree_.merge(other.tree_); }

  // публичные методы, осуществляющие просмотр контейнера
  // проверяет, есть ли в контейнере элемент с ключом, эквивалентным ключу
  bool contains(const Key &key) noexcept {
    value_type value(key, mapped_type{});
    return tree_.contains(value);
  }

 private:
  tree_type tree_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_MAP_H_