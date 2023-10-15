#ifndef LIST_H
#define LIST_H

#include "employee.h"
#include <QDebug>

class List
{
    struct Node
    {
        Node *next, *previous;
        Employee *data;

        Node(Employee *_data) : data(_data), next(nullptr), previous(nullptr)
        {}
    };

    Node *front, *back;
    static void merge(List *, int, int, int, bool (*)(Employee *, Employee *));
public:
    List(Employee *);
    List(List::Node *, List::Node *);
    List();
    ~List();
    void push_back(Employee *);
    void push_front(Employee *);
    void insert(Employee *, unsigned long long);
    void pop_back();
    void pop_front();
    void erase(unsigned long long);
    Node *operator[](unsigned long long);
    unsigned long long get_size();
    static void mergeSort(List *, int, int, bool (*)(Employee *, Employee *));
};

#endif // LIST_H
