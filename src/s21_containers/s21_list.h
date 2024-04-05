#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {

template <class T>
class list {
 private:
  struct FakeListNode;
  struct ListNode;
  class ListIterator;
  class ListConstIterator;

 public:
  // List Member type

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  // internal class ListIterator<T> defines the type for iterating through the
  // container
  using const_iterator = ListConstIterator;
  // internal class ListConstIterator<T> defines the constant type for iterating
  // through the container
  using size_type = std::size_t;

  // List Functions

  // default constructor, creates empty list
  list() {}

  // parameterized constructor, creates the list of size n
  explicit list(size_type n) : list() {
    for (; n > 0; --n) {
      push_back(value_type{});
    }
  }

  // initializer list constructor, creates list initizialized using
  // std::initializer_list
  list(std::initializer_list<value_type> const& items) : list() {
    for (const auto& item : items) {
      push_back(item);
    }
  }

  // copy constructor
  list(const list& l) : list() {
    for (const auto& item : l) {
      push_back(item);
    }
  }

  list& operator=(const list& l) {
    if (this != &l) {
      clear();
      for (auto& item : l) {
        push_back(item);
      }
    }
    return *this;
  }

  // move constructor
  list(list&& l) noexcept { swap(l); }

  // assignment operator overload for moving object
  list& operator=(list&& l) noexcept {
    if (this != &l) {
      swap(l);
    }
    return *this;
  }

  // destructor
  ~list() {
    clear();
    delete head_;
  }

  // List Element access

  // access the first element
  const_reference front() const noexcept {
    return static_cast<const ListNode*>(head_->next_)->data_;
  }

  // access the last element
  const_reference back() const noexcept {
    return static_cast<const ListNode*>(head_->prev_)->data_;
  }

  // List Iterators

  // returns an iterator to the beginning
  iterator begin() noexcept { return iterator(head_->next_); }
  const_iterator begin() const { return const_iterator(head_->next_); }

  // returns an iterator to the end
  iterator end() noexcept { return iterator(head_); }
  const_iterator end() const { return const_iterator(head_); }

  // List Capacity

  // checks whether the container is empty
  bool empty() const noexcept { return !size_; }

  // returns the number of elements
  size_type size() const noexcept { return size_; }

  // returns the maximum possible number of elements
  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(ListNode) / 2U;
  }

  // List Modifiers

  // clears the contents
  void clear() {
    while (size_ > 0) {
      pop_back();
    }
  }

  // inserts element into concrete pos and returns the iterator that points to
  // the new element
  iterator insert(iterator pos, const_reference value) {
    ListNode* new_node = new ListNode(value);
    pos.current->insertBefore(new_node);
    ++size_;
    return iterator(new_node);
  }

  iterator insert(const_iterator pos, const_reference value) {
    ListNode* new_node = new ListNode(value);
    ListNode* modifiable_node =
        const_cast<ListNode*>(static_cast<const ListNode*>(pos.current));
    modifiable_node->insertBefore(new_node);
    ++size_;
    return iterator(new_node);
  }

  template <class... Args>
  void insert_many(const_iterator pos, Args&&... args) {
    list other{args...};
    splice(pos, other);
  }

  // erases element at pos
  void erase(iterator pos) {
    ListNode* nodeToDelete = static_cast<ListNode*>(pos.current);
    unbind(nodeToDelete);
    delete nodeToDelete;
    --size_;
  }

  // adds an element to the end
  void push_back(const_reference value) {
    ListNode* newNode = new ListNode(value);
    newNode->prev_ = head_->prev_;
    newNode->next_ = head_;
    head_->prev_->next_ = newNode;
    head_->prev_ = newNode;
    ++size_;
  }

  // removes the last element
  void pop_back() {
    if (size_ > 0) {
      ListNode* lastNode = static_cast<ListNode*>(head_->prev_);
      unbind(lastNode);
      delete lastNode;
      --size_;
    }
  }

  // adds an element to the head
  void push_front(const_reference value) {
    ListNode* newNode = new ListNode(value);
    newNode->prev_ = head_;
    newNode->next_ = head_->next_;
    head_->next_->prev_ = newNode;
    head_->next_ = newNode;
    ++size_;
  }

  // removes the first element
  void pop_front() {
    if (size_ > 0) {
      ListNode* removeNode = static_cast<ListNode*>(head_->next_);
      // ListNode* removeNode = head_->next_;
      head_->next_ = removeNode->next_;
      removeNode->next_->prev_ = head_;
      delete removeNode;
      --size_;
    }
  }

  // swaps the contents
  void swap(list& other) {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
  }

  // transfers elements from list other starting from pos
  void splice(const_iterator pos, list& other) {
    // Приведение типа const_iterator к ListNode*
    ListNode* thisCur =
        const_cast<ListNode*>(static_cast<const ListNode*>(pos.current));
    ListNode* thisPrev = static_cast<ListNode*>(thisCur->prev_);

    ListNode* otherFirst = static_cast<ListNode*>(other.head_->next_);
    ListNode* otherLast = static_cast<ListNode*>(other.head_->prev_);

    other.head_->next_ = other.head_;
    other.head_->prev_ = other.head_;

    thisPrev->next_ = otherFirst;
    otherFirst->prev_ = thisPrev;
    thisCur->prev_ = otherLast;
    otherLast->next_ = thisCur;

    size_ += other.size_;
    other.size_ = 0;
  }

  // reverses the order of the elements
  void reverse() {
    FakeListNode* current = head_;
    do {
      std::swap(current->next_, current->prev_);
      current = current->prev_;
    } while (current != head_);
  }

  // removes consecutive duplicate elements
  void unique() {
    ListNode* current = static_cast<ListNode*>(head_->next_);
    while (current != head_ && current->next_ != head_) {
      ListNode* nextNode = static_cast<ListNode*>(current->next_);
      if (nextNode->data_ == current->data_) {
        current->next_ = nextNode->next_;
        nextNode->next_->prev_ = current;
        delete nextNode;
        --size_;
      } else {
        current = nextNode;
      }
    }
  }

  void merge(list& other) {
    iterator iter = begin();
    while (iter != end() && other.size_) {
      if (*iter > *(other.begin())) {
        ListNode* inserted = static_cast<ListNode*>(other.begin().current);
        ListNode* newBegin = static_cast<ListNode*>(inserted->next_);

        other.head_->next_ = newBegin;
        newBegin->prev_ = other.head_;

        ListNode* prevNode = static_cast<ListNode*>(iter.current->prev_);
        prevNode->next_ = inserted;
        inserted->prev_ = prevNode;

        inserted->next_ = iter.current;
        iter.current->prev_ = inserted;

        other.size_ -= 1;
        size_ += 1;
      } else {
        ++iter;
      }
    }
    if (!other.empty()) {
      splice(end(), other);
    }
  }

  void sortMerge() {
    if (size_ <= 1) return;

    for (size_t step = 1; step < size_; step *= 2) {
      ListNode* curr = static_cast<ListNode*>(head_->next_);
      ListNode dummyHead;
      ListNode* tail = &dummyHead;

      while (curr != head_) {
        ListNode* left = curr;
        ListNode* right = split(left, step);
        curr = split(right, step);
        tail = mergeLists(left, right, tail, head_);
      }

      head_->next_ = dummyHead.next_;
      dummyHead.next_->prev_ = head_;
      head_->prev_ = tail;
      tail->next_ = head_;
    }
  }

  ListNode* split(ListNode* start, size_t size) {
    for (size_t i = 0; i < size && start != head_; ++i) {
      start = static_cast<ListNode*>(start->next_);
    }
    if (start != head_) {
      start->prev_->next_ = head_;
      head_->prev_ = start->prev_;
      start->prev_ = nullptr;
    }
    return start;
  }

  ListNode* mergeLists(ListNode* left, ListNode* right, ListNode* tail,
                       FakeListNode* head) {
    while (left != head && right != head && right != nullptr) {
      if (left->data_ < right->data_) {
        tail->next_ = left;
        left->prev_ = tail;
        left = static_cast<ListNode*>(left->next_);
      } else {
        tail->next_ = right;
        right->prev_ = tail;
        right = static_cast<ListNode*>(right->next_);
      }
      tail = static_cast<ListNode*>(tail->next_);
    }

    tail->next_ = (left != head) ? left : right;
    if (tail->next_ != head) {
      tail->next_->prev_ = tail;
      while (tail->next_ != head) {
        tail = static_cast<ListNode*>(tail->next_);
      }
    }
    return tail;
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    insert_many(end(), args...);
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    insert_many(begin(), args...);
  }

  void compareLists(const list& other) {
    auto s21_it = this->begin();
    auto another_it = other.begin();
    for (; s21_it != this->end(); ++s21_it, ++another_it) {
      EXPECT_EQ(*s21_it, *another_it);
    }
    EXPECT_EQ(this->size(), other.size());
  }

  // void compareWithStdList(const std::list<T>& stdList) const {
  //   auto s21_it = this->begin();
  //   auto std_it = stdList.begin();
  //   for (; s21_it != this->end() && std_it != stdList.end();
  //        ++s21_it, ++std_it) {
  //     EXPECT_EQ(*s21_it, *std_it);
  //   }
  //   EXPECT_EQ(this->size(), stdList.size());
  // }

 private:
  struct FakeListNode {
    FakeListNode* prev_;
    FakeListNode* next_;

    FakeListNode() : prev_(this), next_(this) {}

    void insertBefore(ListNode* new_node) noexcept {
      new_node->next_ = this;
      new_node->prev_ = this->prev_;
      this->prev_->next_ = new_node;
      this->prev_ = new_node;
    }
  };

  struct ListNode : public FakeListNode {
    explicit ListNode() noexcept {}
    explicit ListNode(const_reference value) noexcept : data_(value) {}

    value_type data_;
  };

  class ListIterator {
   public:
    ListIterator(FakeListNode* node) : current(node) {}

    T& operator*() { return static_cast<ListNode*>(current)->data_; }

    const T& operator*() const {
      return static_cast<const ListNode*>(current)->data_;
    }

    value_type* operator->() {
      return &(static_cast<ListNode*>(current)->data_);
    }

    const T* operator->() const {
      return &(static_cast<const ListNode*>(current)->data_);
    }

    ListIterator& operator++() {
      current = current->next_;
      return *this;
    }

    ListIterator& operator--() {
      current = current->prev_;
      return *this;
    }

    bool operator==(const ListIterator& other) const {
      return current == other.current;
    }

    bool operator!=(const ListIterator& other) const {
      return !(*this == other);
    }

    FakeListNode* current;
  };

  class ListConstIterator {
   public:
    ListConstIterator(const FakeListNode* node) : current(node) {}

    ListConstIterator(const ListIterator& iter) : current(iter.current) {}

    const T& operator*() const {
      return static_cast<const ListNode*>(current)->data_;
    }

    const T* operator->() const {
      return &(static_cast<const ListNode*>(current)->data_);
    }

    ListConstIterator& operator++() {
      if (current) {
        current = current->next_;
      }
      return *this;
    }

    ListConstIterator& operator--() {
      if (current) {
        current = current->prev_;
      }
      return *this;
    }

    bool operator==(const ListConstIterator& other) const {
      return current == other.current;
    }

    bool operator!=(const ListConstIterator& other) const {
      return !(*this == other);
    }

    const FakeListNode* current;
  };

  void resetHead() {
    head_->next_ = head_;
    head_->prev_ = head_;
  }

  void setNext(ListNode* node, ListNode* next) {
    node->next_ = next;
    next->prev_ = node;
  }

  void setPrev(ListNode* node, ListNode* prev) {
    node->prev_ = prev;
    prev->next_ = node;
  }

  void bind(ListNode* node, ListNode* prev_node, ListNode* next_node) noexcept {
    node->prev_ = prev_node;
    node->next_ = next_node;
    prev_node->next_ = node;
    next_node->prev_ = node;
  }

  void unbind(ListNode* node) noexcept {
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    node->prev_ = nullptr;
    node->next_ = nullptr;
  }

  void swapNode(ListNode* node, ListNode* other) {
    std::swap(node->prev_, other->prev_);
    std::swap(node->next_, other->next_);
    node->prev_->next_ = node;
    node->next_->prev_ = node;
    other->prev_->next_ = other;
    other->next_->prev_ = other;
  }

  void swapHead(FakeListNode* head, FakeListNode* other) {
    std::swap(head->prev_, other->prev_);
    std::swap(head->next_, other->next_);
    head->prev_->next_ = head;
    head->next_->prev_ = head;
    other->prev_->next_ = other;
    other->next_->prev_ = other;
  }

  FakeListNode* head_{new FakeListNode{}};
  size_type size_{};
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_