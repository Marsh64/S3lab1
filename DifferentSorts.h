//
// Created by adm on 06.09.2021.
//
#include <iostream>
#include "ISorter.h"
#include "ArraySequence.h"
#ifndef S2_LABORATORY_WORK_1_DIFFERENTSORTS_H
#define S2_LABORATORY_WORK_1_DIFFERENTSORTS_H

template<class T>
bool comparison(T arg1, T arg2){
    return (arg1 > arg2);
}

template<class T>
class BubbleSort : public ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger)(T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        int lenght = seq->GetLength();
        for (int i = 0; i < lenght - 1; i++){
            for (int j = 0; j < lenght - 1 - i; j++){
                if (isBigger(seq->Get(j), seq->Get(j + 1)))
                    seq->Swap(j, j + 1);
            }
        }
    }
};


template<class T>
class ShakerSort : ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        int lenght = seq->GetLength();
        int left, right, i;
        left = 0;
        right = lenght - 2;
        while (left <= right){
            for (i = right; i >= left; i--){
                if (isBigger(seq->Get(i), seq->Get(i + 1)))
                    seq->Swap(i, i + 1);
            }
            left++;
            for (i = left; i <= right; i++){
                if (isBigger(seq->Get(i), seq->Get(i + 1)))
                    seq->Swap(i, i + 1);
            }
            right--;
        }
    }
};


template<class T>
class InsertSort : ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        for (int i = 0; i < seq->GetLength() - 1; i++)
        {
            int key = i + 1; // наш указатель переводим на первый элемент, так как в цикле мы идём от 0
             T temp = seq->Get(key); //temp - это тот элемент, который мы будем пробовать вставлять
            for (int j = i + 1; j > 0; j--)
            {
                if (temp < seq->Get(j - 1)) // если тот элемент, который мы хотим переставить меньше элемента, расположенного слева от него, то
                {
                    seq->InsertInstead(seq->Get(j - 1), j);// меняем их местами
                    key = j - 1; // указатель сдвигаем, и он выйдет в отрицательный диапозон, вследствие чего цикл прервётся
                }

            }
            seq->InsertInstead(temp, key);
        }
    }
};

template<class T>
class SelectionSort : public ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        int lenght = seq->GetLength();
        int min;
        T temp;
        for (int i = 0; i < lenght; i++){
            min = i;
            for (int j = i + 1; j < lenght; j++){
                if (isBigger(seq->Get(min), seq->Get(j)))
                    min = j;
            }
            temp = seq->Get(i);
            seq->InsertInstead(seq->Get(min), i);
            seq->InsertInstead(temp, min);
        }
    }
};

template<class T>
class CountingSort : ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        //работает только с int, функция сравнения тут не нужна
        int lenght = seq->GetLength();
        int min = INT16_MAX;
        int max = INT16_MIN;
        for (int i = 0; i < lenght; i++){
            if (isBigger(seq->Get(i), max))
                max = seq->Get(i);
            if (isBigger(min, seq->Get(i)))
                min = seq->Get(i);
        }

        ArraySequence<int>* var = new ArraySequence<int>(max + 1 - min);
        for (int i = 0; i < max + 1 - min; i++){
            var->InsertInstead(0, i);
        }
        for (int i = 0; i < lenght; i++){
            var->InsertInstead(var->Get(seq->Get(i) - min) + 1,seq->Get(i) - min);
        }

        int i = 0;
        for (int j = min; j < max + 1; j++){
            int temp = var->Get(j - min);
            while (temp != 0){
                seq->InsertInstead(j, i);
                //var->InsertInstead(var->Get(j - min) - 1, j - min);
                temp--;
                i++;
            }
        }
        delete var;
    }
}; //он только под int

template<class T>
class DoubleInsertSort : ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        if (isBigger(seq->Get(0), seq->Get(1)))
            seq->Swap(0, 1);

        for (int i = 2; i < seq->GetLength(); i++){
            int min = 0;
            int max = i;
            int last = -1;
            while (min != max){
                int index = (min + max)/2;
                if (isBigger(seq->Get(index), seq->Get(i)))
                    max = index;
                else
                    min = index;

                if (last == index)
                    break;
                last = index;
            }

            for (int j = max; j < i; j++)
                seq->Swap(i, j);
        }
    }
};

template<class T>
class QuadraticSort : ISorter<T>{
public:
    void Sort (Sequence<T>* seq, bool (*isBigger) (T arg1, T arg2)){
        if (seq->GetLength() < 2)
            return;

        for (int i = 1, end = seq->GetLength() - 1; i < end; i++, end--){
            int min = i - 1;
            int max = i;
            if (isBigger(seq->Get(min), seq->Get(max))){
                max = min;
                min = i;
            }
            for (int j = i + 1; j <= end; j++){
                if (isBigger(seq->Get(min), seq->Get(j)))
                    min = j;

                if (isBigger(seq->Get(j), seq->Get(max)))
                    max = j;
            }

            if (min == end && max == i - 1){
                seq->Swap(min, max);
            }else if (min != end && max == i - 1){
                seq->Swap(end, max);
                seq->Swap(min, i - 1);
            }else{
                seq->Swap(min, i - 1);
                seq->Swap(max, end);
            }
        }

    }
};



#endif //S2_LABORATORY_WORK_1_DIFFERENTSORTS_H
