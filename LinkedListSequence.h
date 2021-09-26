//
// Created by adm on 05.09.2021.
//
#include "Sequence.h"
#include "LinkedList.h"
#ifndef S2_LABORATORY_WORK_1_LINKEDLISTSEQUENCE_H
#define S2_LABORATORY_WORK_1_LINKEDLISTSEQUENCE_H

template <class T>
class LinkedListSequence : Sequence<T>{
private:
    LinkedList<T> listSequence;
public:
    class IndexOutOfRange : LinkedList<T>::IndexOutOfRange{};

    //Создание объекта
    LinkedListSequence (T* items, int count){
        listSequence = LinkedList<T>(items, count);
    }//Копирует элемнеты из переданного массива
    LinkedListSequence (){
        listSequence = LinkedList<T>();
    }//Создает пустую последовательность
    explicit LinkedListSequence (const LinkedList <T> &list){
        listSequence = LinkedList<T>(list);
    }//Копирующий конструктор

    //Удаление объекта
    ~LinkedListSequence(){
        listSequence.Delete_LinkedList();
    }//деструктор
    void Delete_LinkedListSequene(){
        listSequence.Delete_LinkedList();
    }//функция удаление последовательности

    //Декомпозиция
    T GetFirst(){
        return listSequence.GetFirst();
    }//Возвращает первый элемент
    T GetLast(){
        return listSequence.GetLast();
    }//Возвращает последний элемент
    T& Get(int index){
        return listSequence.Get(index);
    }//Возвращает элемент по индексу
    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex){
        //auto *new_LinkedList = new LinkedList<T>;
        auto new_LinkedList = listSequence.GetSubList(startIndex, endIndex);
        auto *new_LinkedListSequence = new LinkedListSequence<T>(new_LinkedList);
        return new_LinkedListSequence;
    }//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
    int GetLength(){
        return listSequence.GetLength();
    }

    //Операции
    void Append(T item){
        listSequence.Append(item);
    }//Добавляет элемент в конец списка
    void Prepend(T item){
        listSequence.Prepend(item);
    }//Добавляет элемент в начало списка
    void InsertAt(T item, int index){
        listSequence.InsertAt(item, index);
    }//Вставляет элемент в заданную позицию
    void InsertInstead(T item, int index){
        listSequence.Set(item, index);
    }//Заменяет элемент в данной позиции
    void Swap(int index1, int index2){
        T savedShell = listSequence.Get(index1);
        listSequence.Set(index1, listSequence.Get(index2));
        listSequence.Set(index2, savedShell);
    }

};


#endif //S2_LABORATORY_WORK_1_LINKEDLISTSEQUENCE_H
