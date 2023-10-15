#ifndef LIST_H
#define LIST_H

#include "abiturient.h"
#include <QDebug>

class List
{
    Abiturient **array;
    float sumOfMarks;
    unsigned long long size, length;

    static void merge(List *, int, int, int, bool (*)(Abiturient *, Abiturient *));
    void setAbiturient(Abiturient *, int);
public:
    List(Abiturient *);
    List();
    ~List();
    Abiturient *operator[](unsigned long long);

    void push_back(Abiturient *);
    void pop_back();
    void pop_front();
    void erase(unsigned long long);
    unsigned long long get_size();
    float getAvMark();

    static void mergeSort(List *, int, int, bool (*)(Abiturient *, Abiturient *));
};

#endif // LIST_H
