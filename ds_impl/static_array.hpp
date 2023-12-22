#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP 1

#include <cstdlib>
#include <iostream>

#include "../config.hpp"
NS_BEGIN(my)

template <typename T>
class iterator {
 public:
  explicit iterator(T *ptr) : m_Ptr(ptr) {}

  iterator &operator++(int) {
    m_Ptr++;
    return *this;
  }

  iterator &operator++() {
    m_Ptr++;
    return *this;
  }

  T &operator*() { return *m_Ptr; }
  T *&get_pointer() { return m_Ptr; }

 private:
  T *m_Ptr;
};

template <typename T>
bool operator!=(iterator<T> &first, iterator<T> &second) {
  return first.get_pointer() != second.get_pointer();
}

/**
 * @brief Fixed Length Array
 *
 * @tparam T Data Type
 * @tparam N Fix Size Length (Known at compile Time)
 */
template <class T, my::size_t N>
class static_array {
 public:
  static_array();
  explicit static_array(T t_initVal);
  my::size_t size();
  T &operator[](my::size_t index);
  T &at(my::size_t index);
  T *&data();
  bool is_empty();
  void fill(T fillValue);
  iterator<T> begin();
  iterator<T> end();

 private:
  T mArr[N];
};

NS_END(my)

template <class T, my::size_t N>
std::ostream &operator<<(std::ostream &os, my::static_array<T, N> &arr);

/////////// IMPLEMENTATION ///////////////

template <class T, my::size_t N>
my::static_array<T, N>::static_array() = default;

template <class T, my::size_t N>
my::static_array<T, N>::static_array(T t_initVal) {
  for (my::size_t i = 0; i < N; i++) {
    mArr[i] = t_initVal;
  }
}

/**
 * @return size of the array
 */
template <class T, my::size_t N>
my::size_t my::static_array<T, N>::size() {
  return N;
}

/**
 * @brief Doesn't checks for out of bounds
 *
 * @param index index
 *
 * @return  data at provided index
 */
template <class T, my::size_t N>
T &my::static_array<T, N>::operator[](my::size_t index) {
  return mArr[index];
}

/**
 * @brief Checks for out of bounds
 *
 * @param index index
 *
 * @return  data at provided index
 */
template <class T, my::size_t N>
T &my::static_array<T, N>::at(my::size_t index) {
  if (index >= N) {
    std::cout << "Index out of range" << std::endl;  // TO REMOVE
    exit(1);  // TODO assertion "access out of range"
  }
  return mArr[index];
}

/**
 * @return pointer to the first element to the array
 */
template <class T, my::size_t N>
T *&my::static_array<T, N>::data() {
  return mArr;
}

/**
 * @brief checks whether array is empty or not
 *
 * @return array size != 0
 */
template <class T, my::size_t N>
bool my::static_array<T, N>::is_empty() {
  return N == 0;
}

/**
 * @brief fill the whole container with a particular value
 *
 * @param fillValue value to filled with
 */
template <class T, my::size_t N>
void my::static_array<T, N>::fill(T fillValue) {
  for (my::size_t i = 0; i < N; i++) {
    mArr[i] = fillValue;
  }
}

//////////////////////////// std::ostream overloading ///////////////
/**
 * @brief prints my::static_array using std::cout. In case of custom data type T
 * overload the std::ostream for T
 *
 * @tparam T data type
 * @tparam N size of the static_array
 * @param os std::cout
 * @param arr static_array
 *
 * @return std::cout
 */
template <class T, my::size_t N>
std::ostream &operator<<(std::ostream &os, my::static_array<T, N> &arr) {
  for (my::size_t i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }
  return os;
}

//////////////////////////////// Iterator Implementation ////////////////////
template <class T, my::size_t N>
my::iterator<T> my::static_array<T, N>::begin() {
  return my::iterator<T>(mArr);
}

/**
 * @brief Iterator pointing to the end of the array
 *
 * @return iterator pointing to the end of array
 */
template <class T, my::size_t N>
my::iterator<T> my::static_array<T, N>::end() {
  return my::iterator<T>(mArr + N);
}

#endif  // STATIC_ARRAY_HPP
