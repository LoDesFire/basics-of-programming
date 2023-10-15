#include "stack.h"

Stack::Stack()
{
    _top = nullptr;
}

Stack::~Stack()
{
    while (_top) {
        Stack::Node *tmp = _top->next;
        delete _top;
        _top = tmp;
    }
}

Stack::Node Stack::top() {
    return *_top;
}

void Stack::pop() {
    Stack::Node *tmp = _top->next;
    delete _top;
    _top = tmp;
}

void Stack::push(char c, int row, int index) {
    Stack::Node *tmp = new Node(c, row, index);
    tmp->next = _top;
    _top = tmp;
}

bool Stack::empty() {
    if (_top)
        return false;
    else
        return true;
}

void Stack::clear() {
    while (_top) {
        Stack::Node *tmp = _top->next;
        delete _top;
        _top = tmp;
    }
    _top = nullptr;
}
