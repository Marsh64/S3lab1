#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Sequence.h"
#include <cstdlib>
#include "ISorter.h"
#include "DifferentSorts.h"
#include "menu.h"

template<class T>
std::ostream &operator << (std::ostream &cout, Sequence<T> seq) {
    cout << '{';
    for (int i = 0; i < seq.GetLength(); i++) {
        cout << seq.Get(i);
        if (i != seq.GetLength() - 1) {
            cout << ", ";
        }
    }
    cout << '}';
    return cout;
}

int main() {
    menu();
    return 0;
}
