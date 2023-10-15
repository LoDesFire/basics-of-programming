//
// Created by Даниил Шумский on 7.05.23.
//

#ifndef LW6_T1_AVLTREE_H
#define LW6_T1_AVLTREE_H

#include "Node.h"

template<typename T> //required operators: '>', '<', '==', '!='
class Tree {
protected:
    Node<T> *root = nullptr;

    Node<T> *insert_node(Node<T> *, T&);
    Node<T> *deleteNode(Node<T> *, int);
    void printNode(Node<T>*, int, void (*)(Node<T>*));
    void searchNode(Node<T>*, int, void (*)(Node<T>*));

    long long getBalance(Node<T>*);
    size_t getHeight(Node<T> *);
    Node<T> *minValueNode(Node<T> *node);

    Node<T> *rightRotate(Node<T> *);
    Node<T> *leftRotate(Node<T> *);

    template <typename T2>
    T2 max(T2, T2);

public:
    bool isEmpty();
    void insert(T value = T());
    void deleteByKey(int key);
    void searchByKey(int key, void (*)(Node<T>*));
    void print(int mode, void (*)(Node<T>*));
    ~Tree();

    enum PrintModes
    {
        RIGHT_ORDER,
        SORTED_ORDER,
        REVERSE_ORDER,
    };
};

template<typename T>
void Tree<T>::searchNode(Node<T> *node, int key, void (*printOneNode)(Node<T>*)) {
    if (!node) {
        printOneNode(nullptr);
        return;
    }

    if (key < node->data) {
        searchNode(node->left, key, printOneNode);
    }
    else if (key > node->data) {
        searchNode(node->right, key, printOneNode);
    }
    else {
        printOneNode(node);
    }
}

template<typename T>
void Tree<T>::searchByKey(int key, void (*printOneNode)(Node<T>*)){
    if (!root) {
        std::cerr << "There are no elements\n";
        throw std::exception();
    }

    searchNode(root, key, printOneNode);
}

template <typename T>
void Tree<T>::deleteByKey(int key) {
    if (!root) {
        std::cerr << "There are no elements\n";
        throw std::exception();
    }

    root = deleteNode(root, key);
}

template <typename T> //KEY
Node<T> *Tree<T>::deleteNode(Node<T> *node, int key) {
    if (!node)
        return node;

    if (key < node->data) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->data) {
        node->right = deleteNode(node->right, key);
    }
    else {
        if (!(node->left && node->right)) {
            Node<T> *temp = node->left ?
                                    node->left :
                                    node->right;
            node->right = nullptr;
            node->left = nullptr;
            delete node;
            node = temp;
        }
        else {
            Node<T> *temp = minValueNode(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
    }

    // Если в дереве остался один узел
    if (!node)
        return node;

    /// Height evaluation
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    /// Rotations
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename T>
Node<T> *Tree<T>::insert_node(Node<T> *node, T& value) {
    if (!node)
        return new Node<T>(value);
    if (value < node->data) {
        node->left = insert_node(node->left, value);
    }
    else if (value == node->data) {
        std::cerr << "Keys are equal\n";
        throw std::exception();
    }
    else {
        node->right = insert_node(node->right, value);
    }

    /// Height evaluation

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    /// Rotations

    long long balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename T>
void Tree<T>::insert(T value) {
    if (!root) {
        root = new Node<T>(value);
        return;
    }

    root = insert_node(root, std::forward<T &>(value));
}

template<typename T>
void Tree<T>::print(int mode, void (*nodePrint)(Node<T>*)) {
    if (!root)
        throw std::exception();

    printNode(root, mode, nodePrint);
}

template<typename T>
void Tree<T>::printNode(Node<T>* node, int mode, void (*nodePrint)(Node<T>*)) {

    if (mode == 0) nodePrint(node);

    if (node->left)
        printNode(node->left, mode, nodePrint);

    if (mode == 1) nodePrint(node);

    if (node->right)
        printNode(node->right, mode, nodePrint);

    if (mode == 2) nodePrint(node);
}

template<typename T>
Tree<T>::~Tree() {
    delete root;
}


template<typename T>
bool Tree<T>::isEmpty() {
    return !root;
}

template<typename T>
size_t Tree<T>::getHeight(Node<T> *node) {
    if (!node)
        return 0;
    return node->height;
}

template <typename T>
long long Tree<T>::getBalance(Node<T> *node) {
    if (!node)
        return 0;
    return (long long)getHeight(node->left) - (long long)getHeight(node->right);
}

template <typename T>
template <typename T2>
T2 Tree<T>::max(T2 a, T2 b) {
    return (a > b) ? a : b;
}

template<typename T>
Node<T> *Tree<T>::rightRotate(Node<T> *node) {
    Node<T> *x = node->left;
    Node<T> *T2 = x->right;

    // Выполняем поворот
    x->right = node;
    node->left = T2;

    // Обновляем высоту
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Возвращаем новый корень
    return x;
}

template<typename T>
Node<T> *Tree<T>::leftRotate(Node<T> *node) {
    Node<T> *y = node->right;
    Node<T> *T2 = y->left;

    // Выполняем поворот
    y->left = node;
    node->right = T2;

    // Обновляем высоту
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Возвращаем новый корень
    return y;
}

template <typename T>
Node<T> *Tree<T>::minValueNode(Node<T> *node) {
    Node<T> *current = node;

    while (current->left)
        current = current->left;

    return current;
}

#endif //LW6_T1_AVLTREE_H
