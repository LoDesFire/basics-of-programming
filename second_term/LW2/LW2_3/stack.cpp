#include "stack.h"

template <typename T>
Stack<T>::Stack()
{
    _top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while (_top) {
        Stack::Node *tmp = _top->next;
        delete _top;
        _top = tmp;
    }
}

template <typename T>
T Stack<T>::top() {
    return _top->value;
}

template <typename T>
void Stack<T>::pop() {
    Stack<T>::Node *tmp = _top->next;
    delete _top;
    _top = tmp;
}

template <typename T>
void Stack<T>::push(T _value) {
    Stack<T>::Node *tmp = new Node(_value);
    tmp->next = _top;
    _top = tmp;
}

template <typename T>
bool Stack<T>::empty() {
    if (_top)
        return false;
    else
        return true;
}

template <typename T>
void Stack<T>::clear() {
    while (_top) {
        Stack<T>::Node *tmp = _top->next;
        delete _top;
        _top = tmp;
    }
    _top = nullptr;
}
