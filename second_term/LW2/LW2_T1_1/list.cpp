#include "list.h"

List::List(Employee *_data)
{
    front = new Node(_data);
    back = front;
}

List::List()
{
    front = nullptr;
    back = nullptr;
}

List::~List()
{
    Node *_cur = front;

    while (_cur && _cur->next) {
        _cur = _cur->next;
        delete _cur->previous;
    }

    if (_cur && !_cur->next)
        delete _cur;
}


void List::push_back(Employee *_data) {
    Node *_back = new Node(_data);

    if (back) {
        back->next = _back;
        _back->previous = back;
    }
    else // if (!front) может быть баг :)
        front = _back;
    back = _back;
}

void List::push_front(Employee *_data) {
    Node *_front = new Node(_data);

    if (front) {
        front->previous = _front;
        _front->next = front;
    }
    else // if (!back) может быть баг :)
        back = _front;
    front = _front;
}

void List::insert(Employee *_data, unsigned long long _num) {
    Node *_cur = (*this)[_num];

    if (_cur == front)
        push_front(_data);
    else {
        if (_cur == back)
            push_back(_data);
        else
        {
            Node *_tmp = new Node(_data);
            if (_cur) {
                _tmp->next = _cur;
                _tmp->previous = _cur->previous;
                _cur->previous->next = _tmp;
                _cur->previous = _tmp;
            }
            else
            {
                _cur = back;
                _tmp->previous = _cur;
                _cur->next = _tmp;
                back = _tmp;
            }
        }
    }
}

void List::pop_back()
{
    if (!back)
        throw "list pop_back exception";

    if (back->previous) {
        back = back->previous;
        delete back->next;
        back->next = nullptr;
    }
    else {
        delete back;
        front = nullptr;
        back = front;
    }
}

void List::pop_front()
{
    if (!front)
        throw "list pop_front exception";

    if (front->next) {
        front = front->next;
        delete front->previous;
        front->previous = nullptr;
    }
    else {
        delete front;
        front = nullptr;
        back = front;
    }
}


void List::erase(unsigned long long _num) {
    Node *_cur = (*this)[_num];
    if (!_cur) _cur = back;

    if (_cur == front) {
        try {
            pop_front();
        }
        catch (const char *msg) {
            qDebug() << msg;
            throw "list erase exception";

        }
    }
    else {
        if (_cur == back) {
            try {
                pop_back();
            }
            catch (const char *msg) {
                qDebug() << msg;
                throw "list erase exception";
            }
        }
        else {
            _cur->previous->next = _cur->next;
            _cur->next->previous = _cur->previous;
            delete _cur;
        }
    }
}


List::Node *List::operator[](unsigned long long _num) {
    Node *_cur = front;

    while (_num-- && _cur) {
        _cur = _cur->next;
    }
    return _cur;
}

unsigned long long List::get_size()
{
    Node *_cur = front;
    unsigned long long amount = 0;

    while (_cur) {
        _cur = _cur->next;
        amount++;
    }
    return amount;
}

void List::mergeSort(List *list, int l, int r, bool (*comp)(Employee *a, Employee *b)) {
    if (l < r) {
        int q = l + (r - l) / 2;

        mergeSort(list, l, q, comp);
        mergeSort(list, q + 1, r, comp);

        merge(list, l, q, r, comp);
    }
}

void List::merge(List *list, int l, int q , int r, bool (*comp)(Employee *a, Employee *b)) {
    int n1 = q - l + 1, n2 = r - q;
    List N, M;
    for (int i = 0; i < n1; i++) {
        N.push_back(new Employee(*((*list)[l + i]->data)));
    }

    for (int i = 0; i < n2; i++) {
        M.push_back(new Employee(*(*list)[q + 1 + i]->data));
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(N[i]->data, M[j]->data)) {

            (*list)[k]->data = N[i]->data;
            i++;
        }
        else {
            (*list)[k]->data = M[j]->data;
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*list)[k]->data = N[i]->data;
        i++;
        k++;
    }

    while (j < n2) {
        (*list)[k]->data = M[j]->data;
        j++;
        k++;
    }
 }

List::List(List::Node *beg, List::Node *end) : front(beg), back(end)
{}
