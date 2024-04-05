//
// Created by Virgil Wilda on 11/16/23.
//

#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_TREE_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_TREE_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace s21 {
template <class Key, class Cmp = std::less<Key>>  // Шаблон, нужен для того что
                                                  // бы автамотически брать
                                                  // нужный тип переменной

class AVLTree {
 public:
  struct AVLTreeNode;
  // класс обычных итераторов
  struct AVLTreeIterator;
  // класс константных итераторов
  struct AVLTreeIteratorConst;

  // внутриклассовые переопределения типов (типичные для стандартной библиотеки
  // STL), принятые для удобства восприятия кода класса
  using tree_type = AVLTree;
  using iterator = AVLTreeIterator;
  using const_iterator = AVLTreeIterator;
  using tree_node = AVLTreeNode;
  using height_type = int;
  using reference = Key &;
  using const_reference = const Key &;
  using pointer = Key *;
  using const_pointer = const Key *;
  using size_type = std::size_t;

  // Основные публичные методы для взаимодействия с классом
  // Контруктор по умолчанию
  AVLTree() : root_(nullptr), count_(0U), end_(new tree_node) {
    if (end_ == nullptr) throw std::bad_alloc();
  };

  // Конструктор с инициализацией через список
  AVLTree(std::initializer_list<Key> const &items) : AVLTree() {
    for (const auto &item : items) {
      insert(item);
    }
  }

  // Конструктор копирования
  AVLTree(const tree_type &other) : AVLTree() {
    root_ = CopyTree(other.root_, nullptr);
    count_ = other.count_;
  }

  // Конструктор перемещения
  AVLTree(tree_type &&other) noexcept : AVLTree() { swap(other); }

  // Присваивание копированием
  tree_type &operator=(const tree_type &other) {
    if (this != &other) {
      clear();
      root_ = CopyTree(other.root_, nullptr);
      count_ = other.count_;
    }
    return *this;
  }

  // Перегрузка оператора присваивания перемещением
  tree_type &operator=(tree_type &&other) noexcept {
    if (this != &other) {
      swap(other);
    }
    return *this;
  }

  // Деструктор
  ~AVLTree() {
    clear();
    delete end_;
    end_ = nullptr;
  }

  // перегрузка insert, вставляет в контейнер ключевой элемент
  std::pair<iterator, bool> insert(const Key &key) {
    auto *new_node = new tree_node(key);
    if (new_node == nullptr) throw std::bad_alloc();
    bool flag = InsertNode(root_, new_node);
    std::pair<iterator, bool> result = {
        iterator(flag ? new_node : nullptr, this), flag};
    if (!flag) delete new_node;
    assert(assertBalance(root_) == true);
    return result;
  }

  // Публичные методы для итерирования по элементам класса:
  // возвращает итератор на начало контейнера
  iterator begin() noexcept {
    return (root_ ? iterator(FirstLeftNode(root_), this) : end());
  }

  const_iterator begin() const noexcept {
    return const_iterator(root_ ? iterator(FirstLeftNode(root_), this) : end());
  }

  // возвращает итератор на конец контейнера (после последнего элемента)
  iterator end() noexcept { return iterator(end_, this); };

  const_iterator end() const noexcept { return const_iterator(end_, this); }

  // Публичные методы для доступа к информации о наполнении контейнера:
  // проверяет, пустой ли контейнер
  [[nodiscard]] bool empty() const noexcept { return count_ == 0; }

  // возвращает количество элементов в контейнере
  [[nodiscard]] size_type size() const noexcept { return count_; }

  // возвращает максимальное допустимое количество элементов в контейнере
  [[nodiscard]] size_type max_size() const noexcept {
    size_type result = std::numeric_limits<size_type>::max() / 2;
    result -= sizeof(tree_type);
    result -= sizeof(tree_node);
    result /= sizeof(tree_node);
    return result;
  }

  // Публичные методы для изменения контейнера:
  // удаляет содержимое контейнера
  void clear() noexcept {
    Destroy(root_);
    root_ = nullptr;
    count_ = 0;
  }

  // удаляет элемент на определенной позиции
  void erase(iterator pos) noexcept { erase(*pos); }

  // обменивает содержимое одного конейнера на содержание контейнера other
  void swap(tree_type &other) noexcept {
    std::swap(root_, other.root_);
    std::swap(count_, other.count_);
  }

  // соединяет узлы из другого контейнера
  void merge(tree_type &other) {
    if (this != &other) {
      iterator pos = other.begin();
      while (pos != other.end()) {
        auto it = pos;
        ++pos;
        auto iter = find(*it);
        if (iter == end()) {
          other.removeNode(it.node);
          insert(*it);
        }
      }
    }
  }

  // Публичные методы, осуществляющие просмотр контейера
  // поиск элеменета контейнера с ключом key
  iterator find(const Key &key) noexcept {
    tree_node *node = SearchNode(root_, key);
    return iterator(node, this);
  }

  // Проверка наличия в контейнере элемента с ключом key
  bool contains(const Key &key) noexcept {
    return find(key) != iterator(end_, this);
  }

  // класс ноды дерева
  struct AVLTreeNode {
    AVLTreeNode *parent_{};
    Key key_{};
    AVLTreeNode *left_{};
    AVLTreeNode *right_{};
    size_t height_ = 1;

    AVLTreeNode() = default;

    explicit AVLTreeNode(const Key &key) : key_(key) {}

    explicit AVLTreeNode(Key &&key) : key_(std::move(key)) {}

    AVLTreeNode(tree_node &&node) noexcept = default;

    tree_node &operator=(tree_node &&node) noexcept = default;

    void swapNode(tree_node &other) noexcept {
      std::swap(left_, other.left_);
      std::swap(right_, other.right_);
      std::swap(parent_, other.parent_);
      std::swap(height_, other.height_);
    }
  };

  // Класс обычных итераторов
  struct AVLTreeIterator {
    AVLTreeIterator(tree_node *node, tree_type *tree) : node(node), T(tree) {}

    AVLTreeIterator() =
        delete;  // пустой итератор не нужен, дефолтный конструктор запрещен

    // получить ключевой элемент узла
    reference operator*() const noexcept { return node->key_; }

    // указатель
    pointer operator->() { return &node->key_; }

    // равенство двух итераторов
    bool operator==(const iterator &other) const noexcept {
      return node == other.node;
    }

    // неравенство двух итераторов
    bool operator!=(const iterator &other) const noexcept {
      return node != other.node;
    }

    // переход к следующему узлу (префиксный)
    iterator &operator++() noexcept {
      node = T->NextNode(node);
      return *this;
    }

    // переход к следующему узлу (постфиксный)
    iterator operator++(int) noexcept {
      iterator tmp{node, T};
      ++(*this);
      return tmp;
    }

    // переход к предыдущему узлу
    iterator operator--() noexcept {
      node = T->PrevNode(node);
      return *this;
    }

    // переход к предыдущему узлу (постфиксный)
    iterator operator--(int) noexcept {
      iterator tmp{node, T};
      --(*this);
      return tmp;
    }

    tree_node *node;  // узел итератора
    tree_type *T;     // дерево итератора
  };

  // Класс константных итераторов
  struct AVLTreeIteratorConst : AVLTreeIterator {
    AVLTreeIteratorConst(const tree_node *node, const tree_type *tree)
        : node_(node), T(tree) {}

    AVLTreeIteratorConst() = delete;

    explicit AVLTreeIteratorConst(const iterator &other)
        : iterator(other.node, other.T) {
      node_ = iterator::node;
      T = iterator::T;
    }

    const_reference operator*() const noexcept { return node_->key; }
    const_pointer operator->() const { return &node_->key; }

    const tree_node *node_;
    const tree_type *T;
  };

 private:
  tree_node *root_;  // указатель на корень дерева
  size_t count_{};   // количество узлов в дереве
  tree_node *end_;   // указатель на конец дерева

  // Вставка узла
  bool InsertNode(tree_node *cur_node, tree_node *new_node) noexcept {
    if (new_node == nullptr) return false;
    bool result = true;
    if (cur_node == nullptr) {
      root_ = new_node;
      ++count_;
    } else {
      if (Cmp{}(new_node->key_, cur_node->key_)) {
        if (cur_node->left_ == nullptr) {
          cur_node->left_ = new_node;
          new_node->parent_ = cur_node;
          ++count_;
        } else
          result = InsertNode(cur_node->left_, new_node);
      } else if (Cmp{}(cur_node->key_, new_node->key_)) {
        if (cur_node->right_ == nullptr) {
          cur_node->right_ = new_node;
          new_node->parent_ = cur_node;
          ++count_;
        } else
          result = InsertNode(cur_node->right_, new_node);
      } else
        result = false;
    }
    if (result) {
      UpdateHeight(cur_node);
      Balance(cur_node);
    }
    return result;
  }

  // Удаление узла
  void RemoveNodePart(tree_node *cur_node) noexcept {
    auto parent = cur_node->parent_;
    // в случае, если один ребенок
    tree_node *child =
        (cur_node->right_ == nullptr ? cur_node->left_ : cur_node->right_);
    if (child) {
      if (parent) {
        if (parent->right_ == cur_node) {
          parent->right_ = child;
        } else {
          parent->left_ = child;
        }
      } else {
        root_ = child;
      }
      child->parent_ = parent;
      // в случае, если 0 детей
    } else {
      if (parent && parent->left_ == cur_node) {
        parent->left_ = nullptr;
      }
      if (parent && parent->right_ == cur_node) {
        parent->right_ = nullptr;
      }
    }
    UpdateHeight(parent);
    Balance(parent);
  }

  void erase(Key key) noexcept {
    auto res = find(key);
    if (res == end()) return;
    removeNode(res.node);
    delete res.node;
  }

  void removeNode(tree_node *res) {
    if (res->left_ && res->right_) {
      res->swapNode(*LastRightNode(res->left_));
    }
    RemoveNodePart(res);
    --count_;
    assert(assertBalance(root_) == true);
  }

  // Рекурсивно удаляет все узлы и освобождает память
  void Destroy(tree_node *root) noexcept {
    if (root) {
      Destroy(root->left_);
      Destroy(root->right_);
      delete root;
    }
  }

  // Возвращает самый первый левый узел дерева (поиск min)
  tree_node *FirstLeftNode(tree_node *root) const noexcept {
    if (root == nullptr) return nullptr;
    if (root->left_ == nullptr) return root;
    return FirstLeftNode(root->left_);
  }

  // Возвращает самый последний правый узел дерева (поиск max)
  tree_node *LastRightNode(tree_node *root) const noexcept {
    if (root == nullptr) return nullptr;
    if (root->right_ == nullptr) return root;
    return LastRightNode(root->right_);
  }

  // Возвращает узел, следующий за текущим узлом
  tree_node *NextNode(tree_node *node) const noexcept {
    if (node == LastRightNode(root_)) return end_;
    if (node == end_) return FirstLeftNode(root_);
    if (node) {
      if (node->right_) {
        node = FirstLeftNode(node->right_);
      } else {
        tree_node *parent = node->parent_;
        while (parent && parent->right_ == node) {
          node = parent;
          parent = node->parent_;
        }
        node = parent;
      }
    }
    return (node ? node : end_);
  }

  // Возвращает предыдущий узел, относительно текущего узла
  tree_node *PrevNode(tree_node *node) const noexcept {
    if (node == FirstLeftNode(root_)) return end_;
    if (node == end_) return LastRightNode(root_);
    if (node) {
      if (node->right_) {
        node = LastRightNode(node->left_);
      } else {
        tree_node *parent = node->parent_;
        while (parent && parent->left_ == node) {
          node = parent;
          parent = node->parent_;
        }
        node = parent;
      }
    }
    return (node == nullptr ? FirstLeftNode(root_) : node);
  }

  // Копирование узлов из дугого дерева
  tree_node *CopyTree(const tree_node *root, tree_node *parent_) {
    tree_node *node = nullptr;
    if (root) {
      node = new tree_node(root->key_);
      node->height_ = root->height_;
      node->parent_ = parent_;
      try {
        if (root->left_) {
          node->left_ = CopyTree(root->left_, node);
        }
        if (root->right_) {
          node->right_ = CopyTree(root->right_, node);
        }
      } catch (...) {
        Destroy(node);
        throw std::bad_alloc();
      }
    }
    return node;
  }

  // Поиск узла
  tree_node *SearchNode(tree_node *cur_node, const Key &key) const noexcept {
    if (cur_node == nullptr) return end_;
    if (!Cmp{}(key, cur_node->key_) && !Cmp{}(cur_node->key_, key))
      return cur_node;
    return (Cmp{}(key, cur_node->key_) ? SearchNode(cur_node->left_, key)
                                       : SearchNode(cur_node->right_, key));
  }

  // Получение высоты узла
  height_type GetHeight(tree_node *node) const noexcept {
    return (node ? node->height_ : 0);
  }

  // Вычисление баланса узла
  height_type GetBalance(tree_node *node) const noexcept {
    return (node ? GetHeight(node->right_) - GetHeight(node->left_) : 0);
  }

  // Изменение высоты узла
  void UpdateHeight(tree_node *node) noexcept {
    if (node) {
      node->height_ = (GetHeight(node->left_) > GetHeight(node->right_)
                           ? GetHeight(node->left_)
                           : GetHeight(node->right_)) +
                      1;
    }
  }

  // левое малое вращение
  void LeftRotate(tree_node *pivotNode) {
    auto childNode = pivotNode->right_;
    FixParents(pivotNode, childNode);
    pivotNode->right_ = childNode->left_;
    if (childNode->left_) childNode->left_->parent_ = pivotNode;
    childNode->parent_ = pivotNode->parent_;
    childNode->left_ = pivotNode;
    pivotNode->parent_ = childNode;
    UpdateHeight(pivotNode->left_);
    UpdateHeight(pivotNode);
  }

  void FixParents(const tree_node *pivotNode, tree_node *childNode) {
    auto parent = pivotNode->parent_;
    if (!parent) {
      root_ = childNode;
    } else {
      if (parent->left_ == pivotNode) {
        parent->left_ = childNode;
      } else {
        parent->right_ = childNode;
      }
    }
  }

  // правое малое вращение
  void RightRotate(tree_node *pivotNode) {
    auto childNode = pivotNode->left_;
    FixParents(pivotNode, childNode);
    pivotNode->left_ = childNode->right_;
    if (childNode->right_) childNode->right_->parent_ = pivotNode;
    childNode->parent_ = pivotNode->parent_;
    childNode->right_ = pivotNode;
    pivotNode->parent_ = childNode;
    UpdateHeight(pivotNode->right_);
    UpdateHeight(pivotNode);
  }

  // Балансирование дерева
  void Balance(tree_node *node) noexcept {
    height_type balance = GetBalance(node);
    // левое дерево выше правого
    if (balance == -2) {
      if (GetHeight(node->left_->right_) > GetHeight(node->left_->left_)) {
        // большое правое вращение
        LeftRotate(node->left_);
      }
      // малое правое вращение
      RightRotate(node);
    } else if (balance == 2) {
      if (GetHeight(node->right_->left_) > GetHeight(node->right_->right_)) {
        // Большое левое вращение
        RightRotate(node->right_);
      }
      // малое левое вращение
      LeftRotate(node);
    }
  }

  // проверка балансировки
  bool assertBalance(tree_node *root) {
    if (!root) return true;
    height_type leftHeight = GetHeight(root->left_);
    height_type rightHeight = GetHeight(root->right_);
    return ((std::abs(leftHeight - rightHeight) <= 1) &&
            assertBalance(root->left_) && assertBalance(root->right_));
  }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_TREE_H_