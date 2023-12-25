#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../config.hpp"

NS_BEGIN(my)

template <typename T>
class bidirectional_iterator {
 public:
  explicit bidirectional_iterator(T*& ptr);
  virtual bidirectional_iterator& operator++();
  virtual bidirectional_iterator& operator++(int);
  virtual bidirectional_iterator& operator--();
  virtual bidirectional_iterator& operator--(int);
  bool operator==(bidirectional_iterator& otherIter);
  bool operator!=(bidirectional_iterator& otherIter);
  T*& get_pointer();
  inline static const bool is_bidirectional = true;
  inline static const bool is_forward = true;
  inline static const bool is_random = false;
 private:
  T* m_Ptr;
};

NS_END(my)

////////////////////////////////////////
/////////// IMPLEMENTATION /////////////
////////////////////////////////////////

template <typename T>
my::bidirectional_iterator<T>::bidirectional_iterator(T*& ptr)
    : m_Ptr(ptr) {}

template <typename T>
my::bidirectional_iterator<T>&
my::bidirectional_iterator<T>::operator++() {
  m_Ptr++;
  return *this;
}

template <typename T>
my::bidirectional_iterator<T>& my::bidirectional_iterator<T>::operator++(
    int) {
  m_Ptr++;
  return *this;
}

template <typename T>
my::bidirectional_iterator<T>&
my::bidirectional_iterator<T>::operator--() {
  m_Ptr--;
  return *this;
}

template <typename T>
my::bidirectional_iterator<T>& my::bidirectional_iterator<T>::operator--(
    int) {
  m_Ptr--;
  return *this;
}

template <typename T>
bool my::bidirectional_iterator<T>::operator==(
    my::bidirectional_iterator<T>& otherIter) {
  return this->m_Ptr == otherIter.get_pointer();
}

template <typename T>
bool my::bidirectional_iterator<T>::operator!=(
    my::bidirectional_iterator<T>& otherIter) {
  return this->m_Ptr != otherIter.get_pointer();
}

template <typename T>
T*& my::bidirectional_iterator<T>::get_pointer() {
  return m_Ptr;
}
#endif  // BIDIRECTIONAL_ITERATOR_HPP
