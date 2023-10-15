#include "list.h"

List::List(Abiturient *_data)
{
    array = new Abiturient*[2];
    array[0] = _data;
    sumOfMarks = array[0]->getSummary();
    length = 1;
    size = 2;
}

List::List()
{
    length = 0;
    size = 0;
    array = nullptr;
    sumOfMarks = 0;
}

List::~List()
{
    if (array)
        for (unsigned long long i = 0; i < length; i++) {
            if (array[i])
                delete array[i];
        }
}


void List::push_back(Abiturient *_data) {
    if (length + 2 > size) {
        size = ((length + 1)*3)/2 + 1;
        Abiturient **tmp = new Abiturient*[size];
        for (unsigned long long i = 0; i < length; i++) {
            tmp[i] = array[i];
        }
        tmp[length] = _data;
        if (array)
            delete[] array;
        array = tmp;
    }
    else {
        array[length] = _data;
    }
    sumOfMarks += array[length]->getSummary();
    length++;
}

void List::pop_back()
{
    sumOfMarks -= array[length - 1]->getSummary();
    delete array[length - 1];
    length--;
}

void List::pop_front()
{
    sumOfMarks -= array[0]->getSummary();
    delete array[0];
    for (unsigned long long i = 1; i < length; i++) {
        array[i - 1] = array[i];
    }
    length--;
}


void List::erase(unsigned long long _num) {

    if (_num == length - 1)
        pop_back();
    else {
        sumOfMarks -= array[_num]->getSummary();
        delete array[_num];
        for (unsigned long long i = _num + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;
    }
}


Abiturient *List::operator[](unsigned long long _num) {
    if (_num >= length)
        throw "Pizdec";
    return array[_num];
}

unsigned long long List::get_size()
{
    return length;
}

void List::mergeSort(List *list, int l, int r, bool (*comp)(Abiturient *a, Abiturient *b)) {
    if (l < r) {
        int q = l + (r - l) / 2;

        mergeSort(list, l, q, comp);
        mergeSort(list, q + 1, r, comp);

        merge(list, l, q, r, comp);
    }
}

void List::merge(List *list, int l, int q , int r, bool (*comp)(Abiturient *a, Abiturient *b)) {
    int n1 = q - l + 1, n2 = r - q;
    List N, M;
    for (int i = 0; i < n1; i++) {
        N.push_back(new Abiturient(*(*list)[l + i]));
    }

    for (int i = 0; i < n2; i++) {
        M.push_back(new Abiturient(*(*list)[q + 1 + i]));
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(N[i], M[j])) {
            list->setAbiturient(N[i], k);
            i++;
        }
        else {
            list->setAbiturient(M[j], k);
            j++;
        }
        k++;
    }

    while (i < n1) {
        list->setAbiturient(N[i], k);
        i++;
        k++;
    }

    while (j < n2) {
        list->setAbiturient(M[j], k);
        j++;
        k++;
    }
 }

void List::setAbiturient(Abiturient *abit, int _k) {
    Abiturient *tmp = new Abiturient(*abit);
    array[_k] = tmp;
}

float List::getAvMark() {
    return sumOfMarks / length / 3;
}
