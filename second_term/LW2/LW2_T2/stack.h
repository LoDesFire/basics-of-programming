#ifndef STACK_H
#define STACK_H


class Stack
{
    struct Node
    {
        Node *next;
        int row, index;
        char c;
        Node(char _c, int _row, int _index) : row(_row), index(_index), c(_c)
        {}
    };
    Node *_top;
public:
    Stack();
    ~Stack();
    Stack::Node top();
    void pop();
    void push(char, int, int);
    bool empty();
    void clear();
};

#endif // STACK_H
