//
// Created by Даниил Шумский on 9.05.23.
//

#ifndef LW6_T3_STACK_H
#define LW6_T3_STACK_H

template<typename T>
struct Node {
    Node *next;
    T data;

    explicit Node(T Data, Node* Next = nullptr) :
        data(Data),
        next(Next)
    {}

    ~Node()
    {
        data.~T();
        delete next;
    }
};

template<typename T>
class Stack {
    Node<T> *front;
public:
    Stack();
    ~Stack();
    void push(T value);
    void pop();
    bool isEmpty();
    void clear();
    T& top();
    Node<T> *topNode();
};

template<typename T>
Node<T> *Stack<T>::topNode() {
    return front;
}

template<typename T>
Stack<T>::Stack() :
    front(nullptr)
{}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
void Stack<T>::push(T value) {
    if (isEmpty()) {
        front = new Node<T>(value);
        return;
    }

    auto *tmp = new Node<T>(value);
    tmp->next = front;
    front = tmp;
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::exception();
    }

    Node<T> *tmp = front;
    front = front->next;

    tmp->next = nullptr;
    delete tmp;
}

template<typename T>
T& Stack<T>::top() {
    if (isEmpty()) {
        throw std::exception();
    }

    return front->data;
}

template <typename T>
void Stack<T>::clear() {
    delete front;
    front = nullptr;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return front == nullptr;
}

#endif //LW6_T3_STACK_H
