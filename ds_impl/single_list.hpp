#ifndef SINGLE_LIST_HPP
#define SINGLE_LIST_HPP

#include <initializer_list>
#include <iostream>
#include <ostream>

#include "../config.hpp"
#include "../iter_impl/forward_iterator.hpp"
#include "./node_structure/node_structure.hpp"

NS_BEGIN(my)

template <typename T>
class single_list_iterator : public my::ForwardIterator<node::singleNode<T>> {
 public:
  explicit single_list_iterator(node::singleNode<T>*& ptr);
  T& operator*();
  single_list_iterator<T>& operator++(int);
  single_list_iterator<T>& operator++();
  bool operator==(single_list_iterator<T>& otherIter);
  bool operator!=(single_list_iterator<T>& otherIter);

 private:
};

template <class T>
class single_list {
 public:
  single_list();
  single_list(std::initializer_list<T> initMe);
  single_list(const single_list<T>& otherSingleList);
  void push_front(T data);
  void push_back(T data);
  void push(T data, my::size_t index);
  void pop_front();
  T& front();
  T& back();
  my::size_t size();
  bool is_empty();
  single_list_iterator<T> begin();
  single_list_iterator<T> end();
  ~single_list();

 private:
  node::singleNode<T>* m_Head;
  node::singleNode<T>* m_Tail;
  node::singleNode<T>* m_null;
  my::size_t m_Size{0};
};

NS_END(my)
template <typename T>
std::ostream& operator<<(std::ostream& os, my::single_list<T>& list);

///////////////////////////////
/// Implementation ////////////
/// single list iterator //////
///////////////////////////////

template <typename T>
my::single_list_iterator<T>::single_list_iterator(node::singleNode<T>*& ptr)
    : my::ForwardIterator<node::singleNode<T>>(ptr) {}

template <typename T>
T& my::single_list_iterator<T>::operator*() {
  return this->get_pointer()->data;
}

template <typename T>
my::single_list_iterator<T>& my::single_list_iterator<T>::operator++(int) {
  this->get_pointer() = this->get_pointer()->next;
  return *this;
}

template <typename T>
my::single_list_iterator<T>& my::single_list_iterator<T>::operator++() {
  this->get_pointer() = this->get_pointer()->next;
  return *this;
}

template <typename T>
bool my::single_list_iterator<T>::operator==(
    my::single_list_iterator<T>& otherIter) {
  return this->get_pointer() == otherIter.get_pointer();
}

template <typename T>
bool my::single_list_iterator<T>::operator!=(
    my::single_list_iterator<T>& otherIter) {
  return this->get_pointer() != otherIter.get_pointer();
}

///////////////////////////////
/// Implementation ////////////
/// single list ///////////////
///////////////////////////////

template <typename T>
my::single_list<T>::single_list()
    : m_Head(nullptr), m_Tail(nullptr), m_null(nullptr) {}

template <typename T>
my::single_list<T>::single_list(std::initializer_list<T> initMe) {
  for (auto& i : initMe) {
    this->push_back(i);
  }
}

template <typename T>
void my::single_list<T>::push_front(T data) {
  auto* temp = new node::singleNode<T>(data, m_Head);
  m_Head = temp;
  if (m_Tail == nullptr) {
    m_Tail = m_Head;
  }
  m_Size++;
}

template <typename T>
void my::single_list<T>::push_back(T data) {
  if (m_Tail == nullptr) {
    return this->push_front(data);
  }
  auto* temp = new node::singleNode<T>(data);
  m_Tail->next = temp;
  m_Tail = temp;
  m_Size++;
}

template <typename T>
void my::single_list<T>::pop_front() {
  if (m_Head != nullptr) {
    auto temp = m_Head->next;
    delete m_Head;
    m_Head = temp;
    m_Size--;
    if (m_Size == 0) {
      m_Tail = nullptr;
    }
  }
}
template <typename T>
T& my::single_list<T>::front() {
  return m_Head->data;
}

template <typename T>
T& my::single_list<T>::back() {
  return m_Tail->data;
}

template <typename T>
my::size_t my::single_list<T>::size() {
  return m_Size;
}

template <typename T>
bool my::single_list<T>::is_empty() {
  return m_Size == 0;
}

template <typename T>
my::single_list_iterator<T> my::single_list<T>::begin() {
  return my::single_list_iterator<T>(m_Head);
}

template <typename T>
my::single_list_iterator<T> my::single_list<T>::end() {
  return my::single_list_iterator<T>(m_null);
}

template <typename T>
my::single_list<T>::~single_list() {
  auto* temp = m_Head;
  while (m_Head != nullptr) {
    temp = m_Head->next;
    delete m_Head;
    m_Head = temp;
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, my::single_list<T>& list) {
  for (auto& i : list) {
    os << i << " ";
  }
  return os;
}

#endif  // SINGLE_LIST_HPP
