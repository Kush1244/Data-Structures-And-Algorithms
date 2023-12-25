#ifndef DOUBLE_LIST_HPP
#define DOUBLE_LIST_HPP
#include <fstream>
#include <initializer_list>
#include <ostream>

#include "../config.hpp"
#include "../iter_impl/bidirectional_iterator.hpp"
#include "./node_structure/node_structure.hpp"
NS_BEGIN(my)

template <typename T>
class double_list_iterator : my::bidirectional_iterator<node::doubleNode<T>> {
 public:
  explicit double_list_iterator(node::doubleNode<T>*& ptr);
  double_list_iterator<T>& operator++(int);
  double_list_iterator<T>& operator++();
  double_list_iterator<T>& operator--(int);
  double_list_iterator<T>& operator--();
  bool operator==(double_list_iterator<T>& otherIter);
  bool operator!=(double_list_iterator<T>& otherIter);
  T& operator*();
  inline static constexpr bool is_forward = true;
  inline static constexpr bool is_bidirectional = true;
  inline static constexpr bool is_random = false;

 private:
  T* m_Ptr;
};

template <typename T>
class double_list {
 public:
  double_list();
  double_list(std::initializer_list<T> initMe);
  void push_back(T data);
  void push_front(T data);
  void pop_back();
  void pop_front();
  T& back();
  T& front();
  my::size_t size();
  bool is_empty();
  double_list_iterator<T> begin();
  double_list_iterator<T> end();
  ~double_list();

 private:
  node::doubleNode<T>* m_Head{nullptr};
  node::doubleNode<T>* m_Tail{nullptr};
  node::doubleNode<T>* m_null{nullptr};
  my::size_t m_Size{0};
};

NS_END(my)

template <typename T>
std::ostream& operator<<(std::ofstream& os, my::double_list<T>& list);

//////////////////////////////////
/// Implementation ///////////////
/// double list iterator /////////
//////////////////////////////////

template <typename T>
my::double_list_iterator<T>::double_list_iterator(node::doubleNode<T>*& ptr)
    : my::bidirectional_iterator<node::doubleNode<T>>(ptr) {}

template <typename T>
my::double_list_iterator<T>& my::double_list_iterator<T>::operator++(int) {
  this->get_pointer() = this->get_pointer()->next;
  return *this;
}

template <typename T>
my::double_list_iterator<T>& my::double_list_iterator<T>::operator++() {
  this->get_pointer() = this->get_pointer()->next;
  return *this;
}

template <typename T>
my::double_list_iterator<T>& my::double_list_iterator<T>::operator--(int) {
  this->get_pointer() = this->get_pointer()->prev;
  return *this;
}

template <typename T>
my::double_list_iterator<T>& my::double_list_iterator<T>::operator--() {
  this->get_pointer() = this->get_pointer()->prev;
  return *this;
}

template <typename T>
bool my::double_list_iterator<T>::operator==(
    double_list_iterator<T>& otherIter) {
  return this->get_pointer() == otherIter.get_pointer();
}

template <typename T>
bool my::double_list_iterator<T>::operator!=(
    double_list_iterator<T>& otherIter) {
  return this->get_pointer() != otherIter.get_pointer();
}

template <typename T>
T& my::double_list_iterator<T>::operator*() {
  return this->get_pointer()->data;
}

//////////////////////////////////
/// Implementation ///////////////
/// double list //////////////////
//////////////////////////////////
template <typename T>
my::double_list<T>::double_list() = default;

template <typename T>
my::double_list<T>::double_list(std::initializer_list<T> initMe) {
  for (auto& i : initMe) {
    this->push_back(i);
  }
}

template <typename T>
void my::double_list<T>::push_back(T data) {
  if (m_Tail == nullptr) {
    return this->push_front(data);
  }
  auto* temp = new node::doubleNode<T>(data, nullptr, m_Tail);
  m_Tail->next = temp;
  m_Tail = temp;
}

template <typename T>
void my::double_list<T>::push_front(T data) {
  auto* temp = new node::doubleNode<T>(data, m_Head, nullptr);
  if (m_Head != nullptr) {
    m_Head->prev = temp;
  }
  m_Head = temp;
  if (m_Tail == nullptr) {
    m_Tail = m_Head;
  }
  m_Size++;
}

template <typename T>
void my::double_list<T>::pop_back() {
  if (m_Tail != nullptr) {
    auto* temp = m_Tail->prev;
    delete m_Tail;
    m_Tail = temp;
    if (m_Tail != nullptr) {
      m_Tail->next = nullptr;
    }
    m_Size--;
    if (m_Size == 0) {
      m_Head = nullptr;
    }
  }
}

template <typename T>
void my::double_list<T>::pop_front() {
  if (m_Head != nullptr) {
    auto* temp = m_Head->next;
    delete m_Head;
    m_Head = temp;
    if (m_Head != nullptr) {
      m_Head->prev = nullptr;
    }
    m_Size--;
    if (m_Size == 0) {
      m_Tail = nullptr;
    }
  }
}

template <typename T>
T& my::double_list<T>::front() {
  return m_Head->data;
}

template <typename T>
T& my::double_list<T>::back() {
  return m_Tail->data;
}

template <typename T>
my::size_t my::double_list<T>::size() {
  return m_Size;
}

template <typename T>
bool my::double_list<T>::is_empty() {
  return m_Size == 0;
}

template <typename T>
my::double_list_iterator<T> my::double_list<T>::begin() {
  return my::double_list_iterator(this->m_Head);
}

template <typename T>
my::double_list_iterator<T> my::double_list<T>::end() {
  return my::double_list_iterator(this->m_null);
}

template <typename T>
my::double_list<T>::~double_list() {
  auto* temp = m_Head;
  while (m_Head) {
    temp = m_Head->next;
    delete m_Head;
    m_Head = temp;
  }
}

/////////////////////////////////
/// Implementation //////////////
/// std::ostream& operator //////
/////////////////////////////////

template <typename T>
std::ostream& operator<<(std::ostream& os, my::double_list<T>& list) {
  for (auto& i : list) {
    os << i << " ";
  }
  return os;
}

#endif  // DOUBLE_LIST_HPP
