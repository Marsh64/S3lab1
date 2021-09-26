//
// Created by adm on 05.09.2021.
//

#ifndef S2_LABORATORY_WORK_1_DYNAMICARRAY_H
#define S2_LABORATORY_WORK_1_DYNAMICARRAY_H

template <class T>
class DynamicArray {
private:
    T* array;
    int lenght; //сколько заполненных ячеек
    int size; //на сколько элементов расчитан массив
public:
    class IndexOutOfRange{};

    // Создание объект
    DynamicArray(); //создание пустого массива
    DynamicArray(T* items, int count); //создает пустой массив и копирует элементы из исходного
    explicit DynamicArray(int newSize); //создание пустого массива заданной длины
    DynamicArray(const DynamicArray& dynArr) {
        size = dynArr.size;
        lenght = dynArr.lenght;

        array = new T[size];
        for (int i = 0; i < lenght; i++) {
            array[i] = dynArr.array[i];
        }
    }

    //Удаление объекта
    ~DynamicArray(); //деструктор
    void Delete_DynamicArray(); //удаление массива

    //Декомпозиция
    T& Get(int index); //возвращает элемент по индексу
    int GetLen();
    int GetSize();


    //Операции над параметрами массива
    void Set(int index, T value); //Задает элемент по индексу
    void Resize(int newSize); //Изменяет размерност массива
    void Relen(int newLen); //Изменяет длину массива

    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetSize());
        size = dynamicArray.GetSize();
        lenght = dynamicArray.GetLen();
        for (int i = 0; i < lenght; i++){
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }
};


#endif //S2_LABORATORY_WORK_1_DYNAMICARRAY_H
