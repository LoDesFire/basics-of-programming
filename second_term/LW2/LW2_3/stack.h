#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
    struct Node
    {
        Node *next;
        T value;
        Node(T _value) : value(_value)
        {}
    };
    Node *_top;
public:
    Stack();
    ~Stack();
    T top();
    void pop();
    void push(T);
    bool empty();
    void clear();
};

#endif // STACK_H
