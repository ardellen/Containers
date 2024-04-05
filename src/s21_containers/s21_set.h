//
// Created by Aaron Arlene on 12/18/23.
//

#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_SET_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_SET_H_

// #include <iostream>
#include "s21_tree.h"

/* ----- ПРОСТРАНСТВА ИМЕН И КЛАССЫ ----- */
namespace s21 {
// Шаблон, нужен для того что бы автамотически братьнужный тип переменной
template <typename Key>

class set {
 public:
  /* ----- Set Member type ----- */
  /* В этой таблице перечислены внутриклассовые переопределения типов (типичные
   * для стандартной библиотеки STL), принятые для удобства восприятия  кода
   * класса:*/
  // Key the first template parameter (Key)
  using key_type = Key;
  // Key value type (the value itself is a key)
  using value_type = Key;

  // value_type & defines the type of the reference to an element
  using reference = value_type &;

  // const value_type & defines the type of the constant reference
  using const_reference = const value_type &;

  /* internal class SetIterator<T> or BinaryTree::iterator as the internal
   * iterator of tree subclass; defines the type for iterating through the
   * container*/
  using iterator = typename AVLTree<value_type>::iterator;

  /* internal class SetConstIterator<T> or BinaryTree::const_iterator as the
   * internal const iterator of tree subclass; defines the constant type for
   * iterating through the container*/
  using const_iterator = typename AVLTree<value_type>::const_iterator;

  // size_t defines the type of the container size (standard type is size_t)
  using size_type = std::size_t;

  /* -----  Set Member functions ----- */
  /* В этой таблице перечислены основные публичные методы для
   * взаимодействия с классом: */
  // default constructor, creates empty set
  set() = default;

  /* initializer list constructor, creates the set initizialized using
   * std::initializer_list */
  set(std::initializer_list<value_type> const &items) : tree(items){};

  // copy constructor
  set(const set &other) : tree(other.tree){};

  // move constructor
  set(set &&other) noexcept : tree(std::move(other.tree)){};

  // assignment operator overload for moving object
  set &operator=(const set &other) {
    if (this != &other) {
      tree = other.tree;
    }
    return *this;
  };

  // assignment operator overload for moving object
  set &operator=(set &&other) noexcept {
    if (this != &other) {
      tree = std::move(other.tree);
    }
    return *this;
  };

  // destructor
  ~set() = default;

  /* ----- Set Iterators ----- */
  /* В этой таблице перечислены публичные методы для итерирования по
   * элементам класса (доступ к итераторам):s */
  // returns an iterator to the beginning
  iterator begin() noexcept { return tree.begin(); };

  // returns an iterator to the end
  iterator end() noexcept { return tree.end(); };

  /* ----- Const Set Iterators ----- */
  // returns an iterator to the beginning
  const_iterator begin() const noexcept { return tree.begin(); };

  // returns an iterator to the end
  const_iterator end() const noexcept { return tree.end(); };

  /* ----- Set Capacity ----- */
  /* В этой таблице перечислены публичные методы для доступа к информации
   * о наполнении контейнера:  */
  // checks whether the container is empty
  bool empty() const noexcept { return tree.empty(); };

  // returns the number of elements
  size_type size() const noexcept { return tree.size(); };

  // returns the maximum possible number of elements
  size_type max_size() const noexcept { return tree.max_size(); };

  /* ----- Set Modifiers----- */
  /* В этой таблице перечислены публичные методы для изменения контейнера: */
  // clears the contents
  void clear() noexcept { tree.clear(); };

  /* inserts node and returns iterator to where the element is in the  container
   * and bool denoting whether the insertion took place */
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree.insert(value);
  }

  // erases element at pos
  void erase(iterator pos) noexcept { tree.erase(pos); }

  // swaps the contents
  void swap(set &other) noexcept { tree.swap(other.tree); }

  // splices nodes from another container
  void merge(set &other) { tree.merge(other.tree); }

  /* ----- Set Lookup ----- */
  /* В этой таблице перечислены публичные методы, осуществляющие просмотр
   * контейнера:*/
  // finds element with specific key
  iterator find(const Key &key) noexcept { return tree.find(key); };

  // checks if the container contains element with specific key
  bool contains(const Key &key) noexcept {
    value_type value(key);
    return tree.contains(value);
  }

  /* ----- БОНУСНЫЕ МЕТОДЫ ----- */
  // inserts new elements into the container
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::initializer_list<value_type> elements{args...};
    std::vector<std::pair<iterator, bool>> insert_result;
    for (auto elem : elements) insert_result.push_back(insert(elem));
    return insert_result;
  }

 private:
  /* ----- ПЕРЕМЕННЫЕ ----- */
  AVLTree<value_type> tree;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_SET_H_