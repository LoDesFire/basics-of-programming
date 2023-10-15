#ifndef VECTORLIBRARY_PAIR_H
#define VECTORLIBRARY_PAIR_H


template <typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;
    Pair(T1 _first, T2 _second) : first(_first), second(_second) {

    }
    Pair() : first(T1()), second(T2()) {
    }
    Pair(Pair const &pair) {
        first = pair.first;
        second = pair.second;
    }

    void operator=(Pair const &pair) {
        first = pair.first;
        second = pair.second;
    }


};

#endif //VECTORLIBRARY_PAIR_H
