//
// Created by adm on 05.09.2021.
//
#include "Sequence.h"

#ifndef S2_LABORATORY_WORK_1_ISORTER_H
#define S2_LABORATORY_WORK_1_ISORTER_H

template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T>* seq, bool (*isBigger) (T, T)) = 0;
};

#endif //S2_LABORATORY_WORK_1_ISORTER_H