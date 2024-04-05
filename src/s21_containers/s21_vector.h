#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_VECTOR_H_

#include <initializer_list>
#include <limits>
// #include <iterator>
// #include <vector>
// #include <memory>

namespace s21 {
template <class T>
class vector {
 public:
  // внутриклассовые типы переопределений (типичные для включения библиотеки
  // STL), принятые для удобства восприятия класса кода:
  typedef T value_type;  // T определяет тип элемента (T — параметр шаблона)
  typedef T &reference;  // T& определяет тип ссылки на элемент
  typedef const T
      &const_reference;  // const T& определяет тип постоянной ссылки
  typedef T *iterator;  // T* определяет тип для перебора контейнера
  typedef const T *const_iterator;  // const T* определяет тип константы для
                                    // перебора контейнера
  typedef std::size_t size_type;  // size_t определяет тип размера контейнера
                                  // (стандартный тип — size_t)

  // typedef A allocator_type;   // потом удылить

  // методы взаимодействия с классом:
  vector();  // конструктор по умолчанию, создает пустой вектор
  explicit vector(
      size_type n);  // параметризованный конструктор, создает вектор размера n
  vector(
      std::initializer_list<value_type> const
          &items);  // конструктор списка инициализаторов, создает вектор,
                    // инициализированный с использованием std::initializer_list
  vector(const vector &v);      // copy конструктор
  vector(vector &&v) noexcept;  // move конструктор
  ~vector();                    // деструктор
  vector<T> &operator=(
      vector &&v);  // Перегрузка оператора присваивания для move объекта
  vector<T> &operator=(const vector &v);

  // методы доступа к элементам класса:
  reference at(
      size_type pos);  // доступ к указанному элементу с проверкой границ
  reference operator[](size_type pos);  // доступ к указанному элементу
  const_reference front();  // доступ к первому элементу
  const_reference back();  // доступ к последнему элементу
  T *data();  // прямой доступ к базовому массиву

  // методы итерирования по элементам классов (доступ к итераторам):
  iterator begin();  // возвращает итератор в начало
  iterator end();    // возвращает итератор до конца

  // методы доступа к информации о заполненном контейнере:
  bool empty();      // проверяет, пуст ли контейнер
  size_type size();  // возвращает количество элементов
  size_type
  max_size();  // возвращает максимально возможное количество элементов
  void reserve(
      size_type size);  // выделяет хранилище элементов размера и копирует
                        // текущие элементы массива в вновь выделенный массив
  size_type capacity();  // возвращает количество элементов, которые могут
                         // храниться в выделенном на данный момент хранилище
  void shrink_to_fit();  // уменьшает использование памяти за счет освобождения
                         // неиспользуемой памяти

  // методы для изменения контейнера:
  void clear() noexcept;  // очищает содержимое
  iterator insert(iterator pos,
                  const_reference value);  // вставляет элементы в конкретную
                                           // позицию и возвращает итератор,
                                           // указывающий на новый элемент
  void erase(iterator pos);  // стирает элемент в позиции
  void push_back(const_reference value);  // добавляет элемент в конец
  void pop_back();           // удаляет последний элемент
  void swap(vector &other);  // меняет содержимое

  void get_new_capacity();  //
  void move_range_to_end(size_t pos);
  // + 2 допа
  template <typename... Args>
  void insert_many_back(
      Args &&...args);  // добавляет новые элементы в конец контейнера
  template <typename... Args>
  iterator insert_many(const_iterator pos,
                       Args &&...args);  // вставляет новые элементы в контейнер
                                         // непосредственно перед pos

  // T print(int n) {return arr_[n];};

 private:
  size_type capacity_;
  size_type size_;
  iterator data_;
};

template <typename T>
vector<T>::vector() : capacity_{0}, size_{0}, data_{nullptr} {};

template <typename T>
vector<T>::vector(size_type n)
    : /*vector(),*/ capacity_{n}, size_{n}, data_{nullptr} {
  // exeption выкидывает oper new
  // проверка n на ноль data_ = nullptr
  if (n != 0) {
    data_ =
        reinterpret_cast<value_type *>(operator new(n * sizeof(value_type)));
    for (size_t i = 0; i < size_; i++) {
      new (data_ + i) value_type;
      // *(data_ + i) = 22 + i*i;
    }
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  // std::cout << "is" << items.size() << std::endl;
  // size_t i = 0;
  for (size_t i = 0; i < size_; i++) {
    data_[i] = *(items.begin() + i);
  }
}

template <typename T>
vector<T>::vector(const vector &v) : vector(v.size_) {
  if (size_ != 0) {
    for (size_t i = 0; i < size_; i++) {
      data_[i] = v.data_[i];
    }
  }
}

template <typename T>
vector<T>::vector(vector &&v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = std::move(v.data_);
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename T>
vector<T>::~vector() {
  for (size_t i = 0; i < size_; i++) {
    (data_ + i)->~T();
  }
  // operator delete(data_);
  // std::cout << "Distr" << std::endl;
}

template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &other) {
  vector copy(other);
  *this = std::move(copy);
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&other) {
  // if (&v == this) return *this;
  // size_ = v.size_;
  // capacity_ = v.capacity_;
  // data_ = std::move(v.data_);
  // v.size_ = 0;
  // v.capacity_ = 0;
  // return *this;
  swap(other);
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size()) throw std::out_of_range("Index out range");
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  // return data_[pos];
  return *(this->begin() + pos);
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return *begin();
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return *(end() - 1);
}

template <typename T>
typename vector<T>::value_type *vector<T>::data() {
  return begin();
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  // std::cout << "it_b ";
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  // std::cout << "it_e ";
  return data_ + size_;
}

template <typename T>
bool vector<T>::empty() {
  return begin() == end();
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return end() - begin();
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  // return (2 ^ nativePointerBitWidth) / sizeof(value_type) - 1;
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

// !!!!! Думаем тут

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > max_size()) throw std::length_error("Can't allocate memory");
  // if(size <= capacity_) return;///ЧТО ЭТО
  vector<T> tmp;

  tmp.data_ =
      reinterpret_cast<value_type *>(operator new(size * sizeof(value_type)));

  for (size_t i = 0; i < size; i++) {
    new (tmp.data_ + i) value_type;
  }

  for (size_t i = 0; i < size_; i++) {
    // std::cout << "?!!? " << sizeof(value_type) << std::endl;
    // new (tmp.data_ + i) value_type(data_[i]);
    tmp.data_[i] = data_[i];
  }

  std::swap(data_, tmp.data_);
  this->capacity_ = size;
  // operator delete(tmp .data_);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size() == capacity()) return;
  vector<T> tmp;
  tmp.data_ =
      reinterpret_cast<value_type *>(operator new(size() * sizeof(value_type)));
  for (size_t i = 0; i < size_; i++) {
    tmp.data_[i] = data_[i];
  }
  std::swap(data_, tmp.data_);
  this->capacity_ = size();
}

template <typename T>
void vector<T>::clear() noexcept {
  for (size_t i = 0; i < size_; i++) {
    (data_ + i)->~T();
    // std::cout << i << " ";
  }
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type rev_indx = end() - pos - 1;
  size_type insert_indx = pos - begin();
  if (insert_indx > size_) {
    throw std::out_of_range(
        "InsertError: The insertion position is out of range of the vector ");
  }
  push_back(value);
  // std::cout << "insert " << rev_indx << " "<< insert_indx << " " << size() <<
  // std::endl;

  size_type i = 1;
  for (; rev_indx + 1 != 0; rev_indx--) {
    data_[size() - i] = data_[size() - i - 1];
    i++;
  }
  data_[insert_indx] = value;

  // второй вариант

  // size_type new_capacity = size_ + 1;
  // if(new_capacity > capacity()) {
  //     reserve(new_capacity * 2)
  // };

  //  end of второй вариант

  return data_ + insert_indx;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  if (empty()) throw std::length_error("vector::erase called for empty vector");
  //  проверка на size = 0

  size_type position = pos - begin();
  // std::cout << "eras " << pos - begin() << "size " << size_ - position <<
  // std::endl; (data_ + position)->~T();

  // std::cout << "eras [] " << data_[position + 0] << std::endl;

  for (size_type i = 0; i < size_ - position - 1; i++) {
    //  std::cout << i << " " << std::endl;
    // *(data_ + (position + i)) = *(data_ + position + i + 1);
    data_[position + i] = data_[position + i + 1];
    //  std::cout << i << "_" << std::endl;
  }

  (data_ + (size_ - 1))->~T();
  size_--;
  // std::cout << "ers " << size_ << std::endl;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size() == capacity()) get_new_capacity();
  new (end()) T(value);
  size_++;
}

template <typename T>
void vector<T>::pop_back() {
  if (empty())
    throw std::length_error("vector::pop_back called for empty vector");
  (data_ + size() - 1)->~T();  // ????
  size_--;
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(data_, other.data_);

  // value_type *tmp_data_ = data_;
  // size_type tmp_size = size_;
  // size_type tmp_capacity = capacity_;
  // data_ = other.data_;
  // size_ = other.size_;
  // capacity_ = other.capacity_;
  // other.data_ = tmp_data_;
  // other.size_ = tmp_size;
  // other.capacity_ = tmp_capacity;
}

template <typename T>
void vector<T>::get_new_capacity() {
  size_t new_capacity = capacity_;
  // std::cout << "\n in push 0  " << new_capacity << "  " << capacity_ << "  "
  // << size_ << std::endl;

  if (empty()) {
    new_capacity = 1;
  } else {
    new_capacity = capacity_ * 2;
  }
  // std::cout << "\n in push 1  " << new_capacity << std::endl;
  reserve(new_capacity);
  // std::cout << "in push 2" << std::endl;
  capacity_ = new_capacity;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  for (T val : std::initializer_list<T>{args...}) push_back(val);
}

// !!!!! Думаем тут

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  // std::cout << "insert_many_1 cap " << capacity() << std::endl

  size_t args_qnt = sizeof...(args);
  size_t insert_indx = pos - begin();

  if (size() + args_qnt >= capacity()) {
    size_t new_capacity = size_ + args_qnt;
    reserve(new_capacity);
    // std::cout << "insert_many_2 " << args_qnt << "  " << capacity() << "  "
    // << begin() << "  " << end() << "  " << pos << std::endl; std::cout <<
    // begin() + insert_indx << std::endl;
  }

  move_range_to_end(insert_indx);

  for (T val : std::initializer_list<T>{args...}) {
    data_[insert_indx] = val;
    insert_indx++;
    size_++;
  }
  // size_ += args_qnt;
  return begin();
}
//ТУТ СЕГА!

template <typename T>
void vector<T>::move_range_to_end(size_t pos) {
  size_t range_size = 0;
  if (size())
    range_size = size() - pos;
  else
    range_size = pos;
  // std::cout << "to_end_1 " << range_size << "  " << capacity() << "  "<<
  // size()  << std::endl;
  for (size_t i = 1; i <= range_size; i++) {
    new (&data_[capacity() - i]) value_type(data_[size() - i]);
    data_[capacity() - i] = data_[size() - i];
    // std::cout << "t_e " << i << "  " << range_size << std::endl;
  }
  // std::cout << "to_end_2 " << capacity() << "  " << pos << std::endl;
}

};      // namespace s21
#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_S21_VECTOR_H_