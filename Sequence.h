//
// Created by adm on 05.09.2021.
//

#ifndef S2_LABORATORY_WORK_1_SEQUENCE_H
#define S2_LABORATORY_WORK_1_SEQUENCE_H

template <class T>
class Sequence {
public:
    //Декомпозиция
    virtual T GetFirst() = 0;//Получение первого элемента
    virtual T GetLast() = 0;//Получение последнего элемента
    virtual T& Get(int index) = 0;//Получение элемента по индексу
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;//Получене списка элемента по индексам
    virtual int GetLength() = 0;//Получение длины последовательности

    //Операции
    virtual void Append(T item) = 0; //Добавление элемента в конец последовательности
    virtual void Prepend(T item) = 0; //Добавление элемента в начало последовательности
    virtual void InsertAt(T item, int index) = 0; //Вставка элемента в заданную позицию последовательности
    virtual void InsertInstead(T item, int index) = 0; //Заменяет элемент в данной позиции
    virtual void Swap(int index1, int index2) = 0; //Меняет местами значение в ячейках данных индексов

};


#endif //S2_LABORATORY_WORK_1_SEQUENCE_H
