#include "queue.h"

Queue::Queue(long long _data)
{
    front = make_shared<Queue::Node>(_data);//new Node(_data);
    back = front;
}

Queue::Queue()
{
    front = Shared_ptr<Queue::Node>();
    back = Shared_ptr<Queue::Node>();
}



void Queue::push(long long _data) {
    Shared_ptr<Queue::Node> _back = make_shared<Queue::Node>(_data);

    if (back) {
        back->next = _back;
        _back->previous = back;
    }
    else // if (!front) может быть баг :)
        front = _back;
    back = _back;
}

void Queue::pop()
{
    if (!front)
        throw "list pop exception";

    if (front->next) {
        front = front->next;
        front->previous = Shared_ptr<Queue::Node>();
    }
    else {
        front = Shared_ptr<Queue::Node>();
        back = front;
    }
}

void Queue::pop_back()
{
    if (!back)
        throw "list pop_back exception";

    if (back->previous) {
        back = back->previous;
        back->next = Shared_ptr<Queue::Node>();
    }
    else {
        front = Shared_ptr<Queue::Node>();
        back = front;
    }
}

unsigned long long Queue::size()
{
    Shared_ptr<Queue::Node> _cur = front;
    unsigned long long amount = 0;

    while (_cur) {
        _cur = _cur->next;
        amount++;
    }
    return amount;
}

long long Queue::top() {
    return front->data;
}

bool Queue::isEmpty() {
    return size() == 0;
}

void Queue::erase(Shared_ptr<Queue::Node> _cur) {
//    Shared_ptr<Queue::Node> _cur = front;
//    while (_num--) {
//        _cur = _cur->next;
//    }

    if (!_cur) _cur = back;

    if (_cur.operator->() == front.operator->()) {
        try {
            pop();
        }
        catch (const char *msg) {
            throw "list erase exception";

        }
    }
    else {
        if (_cur.operator->() == back.operator->()) {
            try {
                pop_back();
            }
            catch (const char *msg) {
                throw "list erase exception";
            }
        }
        else {
            _cur->previous->next = _cur->next;
            _cur->next->previous = _cur->previous;
        }
    }
}