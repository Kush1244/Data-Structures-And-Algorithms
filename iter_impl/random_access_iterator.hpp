#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP 1

#include "../config.hpp"

NS_BEGIN(my)

template <typename T>
class random_access_iterator {
 public:
  explicit random_access_iterator(T*& ptr);
  virtual random_access_iterator& operator++(int);
  virtual random_access_iterator& operator++();
  virtual random_access_iterator& operator--(int);
  virtual random_access_iterator& operator--();
  virtual random_access_iterator& operator+=(my::size_t offset);
  virtual random_access_iterator& operator-=(my::size_t offset);
  virtual bool operator==(random_access_iterator<T>& otherIter);
  virtual bool operator!=(random_access_iterator<T>& otherIter);
  virtual T*& get_pointer();
  inline static const bool is_random = true;
  inline static const bool is_forward = true;
  inline static const bool is_bidirectional = true;

 private:
  T* m_Ptr;
};
NS_END(my)

////////////////////////////////
/// IMPLEMENTATION /////////////
////////////////////////////////
template <typename T>
my::random_access_iterator<T>::random_access_iterator(T*& ptr) : m_Ptr(ptr) {}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator++(int) {
  m_Ptr++;
  return *this;
}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator++() {
  m_Ptr++;
  return *this;
}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator--() {
  m_Ptr--;
  return *this;
}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator--(int) {
  m_Ptr++;
  return *this;
}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator+=(
    my::size_t offset) {
  m_Ptr += offset;
  return *this;
}

template <typename T>
my::random_access_iterator<T>& my::random_access_iterator<T>::operator-=(
    my::size_t offset) {
  m_Ptr -= offset;
  return *this;
}

template <typename T>
bool my::random_access_iterator<T>::operator==(
    my::random_access_iterator<T>& otherIter) {
  return this->m_Ptr == otherIter.get_pointer();
}

template <typename T>
bool my::random_access_iterator<T>::operator!=(
    my::random_access_iterator<T>& otherIter) {
  return this->m_Ptr != otherIter.get_pointer();
}

template <typename T>
T*& my::random_access_iterator<T>::get_pointer() {
  return m_Ptr;
}

#endif  // RANDOM_ACCESS_ITERATOR_HPP
