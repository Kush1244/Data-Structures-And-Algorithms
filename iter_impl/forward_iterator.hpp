#ifndef ITERATOR_HPP
#define ITERATOR_HPP 1

#include "../config.hpp"

NS_BEGIN(my)

template <class T>
class ForwardIterator {
 public:
  explicit ForwardIterator(T*& ptr);
  virtual ForwardIterator& operator++(int);
  virtual ForwardIterator& operator++();
  virtual bool operator==(ForwardIterator& otherIter);
  virtual bool operator!=(ForwardIterator& otherIter);
  T*& get_pointer() { return m_Ptr; }

 private:
  T* m_Ptr;
  inline static const bool is_forward = true;
  inline static const bool is_random = false;
  inline static const bool is_bidirectional = true;
};

NS_END(my)
/////////////////////////////////////////////
/////////////// IMPLEMENTATION //////////////
/////////////////////////////////////////////

template <class T>
my::ForwardIterator<T>::ForwardIterator(T*& ptr) : m_Ptr(ptr) {}

template <class T>
my::ForwardIterator<T>& my::ForwardIterator<T>::operator++(int) {
  m_Ptr++;
  return *this;
}

template <class T>
my::ForwardIterator<T>& my::ForwardIterator<T>::operator++() {
  m_Ptr++;
  return *this;
}

template <class T>
bool my::ForwardIterator<T>::operator==(ForwardIterator& otherIter) {
  return this->m_Ptr == otherIter.get_pointer();
}

template <class T>
bool my::ForwardIterator<T>::operator!=(ForwardIterator& otherIter) {
  return this->m_Ptr != otherIter.get_pointer();
}

#endif  // ITERATOR_HPP
