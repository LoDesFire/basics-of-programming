#ifndef LIST_H
#define LIST_H

#include "Shared_ptr.h"

class Queue {
private:
    void pop_back();
protected:
    struct Node {
        Shared_ptr<Node> next, previous;
        long long data;

        explicit Node(long long _data) : data(_data), next(nullptr), previous(nullptr) {}
    };

    Shared_ptr<Node> front, back;
public:
    explicit Queue(long long);

    Queue();

    long long top();

    void push(long long);

    void pop();

    unsigned long long size();

    bool isEmpty();
    //    void push_front(long long);
    //void insert(long long, unsigned long long);
    //    void pop_back();
    void erase(Shared_ptr<Queue::Node>);
    //Queue(Shared_ptr<Queue::Node>, Shared_ptr<Queue::Node>);
};

#endif // LIST_H
