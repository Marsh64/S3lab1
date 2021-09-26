//
// Created by adm on 05.09.2021.
//

#include "DynamicArray.h"

template <class T>
void DynamicArray<T>::Resize(int newSize){
    if (newSize < 0){
        throw IndexOutOfRange();
    }// неправильный размер массива

    if (newSize == 0){
        delete[] array;
        array = nullptr;
        size = 0;
        lenght = 0;
        return;
    }// удаление массива

    if (newSize == size){return;}// длина не изменится

    if (newSize < size){
        T *new_array = new T[newSize];
        for (int i = 0; i < newSize; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        size = newSize;
        if (lenght > newSize){ lenght = newSize;}
        array = new_array;
        return;
    }// укорачивание массива

    if (newSize > 0 && size == 0){
        T *new_array = new T[newSize];
        delete[] array;
        size = newSize;
        array = new_array;
    }//увеличение размера массива 0 длины

    if (newSize > size){
        T *new_array = new T[newSize];
        for (int i = 0; i < lenght; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        size = newSize;
        array = new_array;
        return;
    }// увеличение длины
}

template <class T>
void DynamicArray<T>::Relen(int newLen){
    if (newLen > size || newLen < 0 || newLen < lenght){
        throw IndexOutOfRange();
    }
    lenght = newLen;
}

template <class T>
DynamicArray<T>::DynamicArray() {
    array = nullptr;
    lenght = 0;
    size = 0;
}

template <class T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    array = nullptr;
    size = 0;
    lenght = count;

    Resize(count);
    for (int i = 0; i < count; i++){
        array[i] = items[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int newSize){
    if (newSize < 0){newSize = 0;}

    array = nullptr;
    size = 0;
    lenght = 0;
    Resize(newSize);
}

template <class T>
T& DynamicArray<T>::Get(int index) {
    if (index < 0 || index >= lenght){
        throw IndexOutOfRange();
    }

    return array[index];
}

template <class T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index >= lenght){
        throw IndexOutOfRange();
    }

    array[index] = value;
}

template <class T>
int DynamicArray<T>::GetLen() {
    return lenght;
}

template <class T>
int DynamicArray<T>::GetSize() {
    return size;
}

template <class T>
void DynamicArray<T> :: Delete_DynamicArray(){
    delete[] array;
    array = nullptr;
    size = 0;
    lenght = 0;
}

template <class T>
DynamicArray<T> :: ~DynamicArray(){
    delete[] array;
    array = nullptr;
    size = 0;
    lenght = 0;
}

