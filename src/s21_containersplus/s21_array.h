#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_S21_ARRAY_H_

// #include <initializer_list>

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  // внутриклассовые типы переопределений (типичные для включения библиотеки
  // STL), принятые для удобства восприятия класса кода:
  typedef T value_type;  // T определяет тип элемента (T — параметр шаблона)
  typedef T& reference;  // T& определяет тип ссылки на элемент
  typedef const T&
      const_reference;  // const T& определяет тип постоянной ссылки
  typedef T* iterator;  // T* определяет тип для перебора контейнера
  typedef const T* const_iterator;  // const T* определяет тип константы для
                                    // перебора контейнера
  typedef std::size_t size_type;  // size_t определяет тип размера контейнера
                                  // (стандартный тип — size_t)

  // публичные методы для взаимодействия с классом:
  array();  // default constructor, creates empty array
  array(std::initializer_list<value_type> const&
            items);           // initializer list constructor, creates array
                              // initizialized using std::initializer_list
  array(const array& a);      // copy constructor
  array(array&& a) noexcept;  // move constructor
  ~array() = default;         // destructor
  array& operator=(
      array&& a);  // assignment operator overload for moving object

  // // публичные методы для доступа к элементам класса:
  reference at(size_type pos);  // access specified element with bounds checking
  reference operator[](size_type pos);  // access specified element
  const_reference front();              // access the first element
  const_reference back();               // access the last element
  iterator data();  // прямой доступ к базовому массиву

  // // публичные методы для итерирования по элементам класса (доступ к
  // итераторам):
  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

  // // публичные методы для доступа к информации о наполнении контейнера:
  bool empty();          //  checks whether the container is empty
  size_type size();      // returns the number of elements
  size_type max_size();  //  returns the maximum possible number of elements

  // // публичные методы для изменения контейнера:
  void swap(array& other);           // swaps the contents
  void fill(const_reference value);  // assigns the given value value to all
                                     // elements in the container.

  T print(int n) { return arr_[n]; };

 private:
  size_type size_ = N;
  T arr_[N > 0 ? N : 1]{};
};
}  // namespace s21

template <typename T, size_t N>
s21::array<T, N>::array() : size_{N} {};

template <typename T, size_t N>
s21::array<T, N>::array(std::initializer_list<value_type> const& items)
    : array() {
  auto init_list_ptr = items.begin();
  for (size_t i = 0; i < items.size(); i++) {
    arr_[i] = *init_list_ptr;
    init_list_ptr++;
  }
};

template <typename T, size_t N>
s21::array<T, N>::array(const array& a) {
  // std::cout << "copy constr " << a.size_ << std::endl;
  for (size_type i = 0; i < size_; ++i) {
    arr_[i] = a.arr_[i];
  }
}

template <typename T, size_t N>
s21::array<T, N>::array(array&& a) noexcept {
  std::move(a.arr_, a.arr_ + N, arr_);
}

template <typename T, size_t N>
s21::array<T, N>& s21::array<T, N>::operator=(array&& a) {
  if (this != &a) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = a.arr_[i];
    }
  }
  return *this;
}

template <typename T, size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Index out of array range");
  return arr_[pos];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::front() {
  return arr_[0];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::back() {
  return arr_[size_ - 1];
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::data() {
  return arr_;
};

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::begin() {
  return arr_;
};

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::end() {
  return arr_ + size_;
};

template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::size() {
  return size_;
};
template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::max_size() {
  return size_;
};

template <typename T, size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::operator[](
    size_type pos) {
  return arr_[pos];
}

template <typename T, size_t N>
bool s21::array<T, N>::empty() {
  return this->begin() == this->end() ? true : false;  // this || arr_?
}

template <typename T, size_t N>
void s21::array<T, N>::swap(array& other) {
  array temp(other);
  other = std::move(*this);
  *this = std::move(temp);
  // for (auto c : temp) std::cout << " " << c;
  // std::cout << 't' << std::endl;
  // for (auto c : other) std::cout << " " << c;
  // std::cout << 'o' << std::endl;
  // other = std::move(*this);
  // *this = std::move(temp);

  // 2nd variant

  // value_type temp;
  // for (size_type i = 0; i < size_; ++i) {
  //     temp = other.arr_[i];
  //     other.arr_[i] = arr_[i];
  //     arr_[i] = temp;
  // }
}

template <typename T, size_t N>
void s21::array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < size_; ++i) {
    arr_[i] = value;
  }
}

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERSPLUS_S21_ARRAY_H_