//
// Created by Даниил Шумский on 7.05.23.
//

#ifndef LW6_T1_NODE_H
#define LW6_T1_NODE_H

template <typename T>
struct Node {
    using size_t = unsigned long long;
     T data;
     size_t height;
     Node<T> *left, *right;
     Node(T data = T());
     ~Node();
};

template <typename T>
Node<T>::~Node() {
    delete left;
    delete right;
}

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 1;
}

#endif //LW6_T1_NODE_H
