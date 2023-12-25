#ifndef NODE_STRUCTURE_HPP
#define NODE_STRUCTURE_HPP

#include "../../config.hpp"

NS_BEGIN(node)
template <typename T>
struct singleNode {
  T data;
  singleNode<T> *next;
  explicit singleNode(T t_data = {}, singleNode<T> *t_next = nullptr)
      : data(t_data), next(t_next) {}
};

template <typename T>
struct doubleNode {
  T data;
  doubleNode<T> *next;
  doubleNode<T> *prev;
  explicit doubleNode(T t_data = {}, doubleNode<T> *t_next = nullptr,
                      doubleNode<T> *t_prev = nullptr)
      : data(t_data), next(t_next), prev(t_prev) {}
};

NS_END(nodes)

#endif  // NODE_STRUCTURE_HPP

