//
// Created by adm on 16.09.2021.
//

#ifndef S2_LABORATORY_WORK_1_MENU_H
#define S2_LABORATORY_WORK_1_MENU_H
#include "ArraySequence.h"
#include <string>
#include "iostream"
#include <cstdlib>
#include "DifferentSorts.h"
#include <ctime>
#include "chrono"
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include "tests.h"
using namespace std::chrono;
using namespace std;


int ChooseCount(){
    int count = 1;
    while(true){
        cout << "Введите кол-во элементов для проверки скорости сортировок:\n";
        cout << "\t:::";
        cin >> count;

        if (count > 0)
            return count;

        cout << "Вы ввели неправильное кол-во, введите заново!\n";
    }
}

int ChooseType(){
    int type = 1;
    cout << "С какими типами данных хотите работать?\n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: char\n"
         << ":::";

    while(true){
        cin >> type;
        if (type < 0 || type > 4){
            cout << "Вы ввели неправильное кол-во, введите заново!\n";
            continue;
        }
        return type;
    }
}
ArraySequence<int> MakeRandomIntMassive(int count) {
    int *a = new int[count];
    srand(679);
    for (int i = 0; i < count; i++) {
        a[i] = rand() % 1000;
        if (a[i] % 3 == 0)
            a[i] = a[i] * -1;
    }
    return ArraySequence<int>(a, count);
}

ArraySequence<float> MakeRandomFloatMassive(int count) {
    auto *a = new float[count];
    srand(679);
    for (int i = 0; i < count; i++) {
        a[i] = rand() % 100000;
        if (rand() % 100 % 3 == 0)
            a[i] = a[i] * -1 / 100;
    }
    return ArraySequence<float>(a, count);
}

ArraySequence<char> MakeRandomCharMassive(int count) {
    auto *a = new char[count];
    srand(2679);
    for (int i = 0; i < count; i++) {
        a[i] = rand() % 127 + 47;
    }
    return ArraySequence<char>(a, count);
}

ArraySequence<string> MakeRandomStringMassive(int count) {
    auto *a = new string[count];
    srand(2679);
    for (int i = 0; i < count; i++) {
        int lenghti = rand() % 10 + 1;
        while (lenghti > 0){
            a[i] += rand() % 127 + 47;
            lenghti--;
        }
    }
    return ArraySequence<string>(a, count);
}

template<class T>
void CheckTimeOne(ArraySequence<T>& arr, int type){

    auto time1 = system_clock::now();
    switch (type) {
        case 1: BubbleSort<T>().Sort(&arr, comparison); break;
        case 2: ShakerSort<T>().Sort(&arr, comparison); break;
        case 3: InsertSort<T>().Sort(&arr, comparison); break;
        case 4: SelectionSort<T>().Sort(&arr, comparison); break;
        case 5: CountingSort<T>().Sort(&arr, comparison); break;
        case 6: DoubleInsertSort<T>().Sort(&arr, comparison); break;
        case 7: QuadraticSort<T>().Sort(&arr, comparison); break;
    }

    auto time2 = system_clock::now();

    string str;
    switch (type) {
        case 1: str = "Сортировка пузырьком"; break;
        case 2: str = "Шейкерная сортировка"; break;
        case 3: str = "Сортировка вставкой"; break;
        case 4: str = "Сортировка простым выбором"; break;
        case 5: str = "Сортировка подсчетом";break;
        case 6: str = "Сортировка методом двоичных вставок"; break;
        case 7: str = "Квадратичная сортировка"; break;
    }

    cout << "\t" + str + " -> " <<  double (duration_cast<microseconds>(time2 - time1).count())/1000000 << endl;
}//проверяет время сортировки, какой-то сортировкой, одного массива

ArraySequence<int> ChooseSortsType(int count){
    ArraySequence<int> arr(count);
    cout << "Какие сортировки вы хотите проверить?\n"
         << "\t1: Сортировка пузырьком\n"
         << "\t2: Шейкерная сортировка\n"
         << "\t3: Сортировка вставкой\n"
         << "\t4: Сортировка с помощью простого выбора\n"
         << "\t5: Сортировка подсчетом\n"
         << "\t6: Сортировка методом двоичных вставок\n"
         << "\t7: Квадратичная сортировка\n"
         << "(Нажмите 0 - для окончания)\n"
         << ":::";

    int a = 1;
    //char *c = new char[100];
    while(true){
        cin >> a;
        if (a < 0){
            cout << "Сортировки с таким индексом нет, продолжайте!\n";
            continue;
        }

        if (a == 0)
            break;
        arr.Append(a);

/*
        //cin >> a;
        arr.Prepend(a);
//        cin.getline(c, 100);
//        if (c[0] == '\0')
//            break;
*/
    }

    return arr;
}//возвращает индексы сортировок в массиве, count - кол-во сортировок

template<class T>
ArraySequence<ArraySequence<T>> CreateSequencene(ArraySequence<int>& types, ArraySequence<T>& origin){
    ArraySequence<ArraySequence<T>> arr;
    for (int i = 0; i < types.GetLength(); i++){
        arr.Append(origin);
    }

    return arr;
}

/*
template<class T>
ISorter<T>* GetSort(int index){
    switch (index) {
        case 1: return new BubbleSort<T>();
        case 2: return ShakerSort<T>();
        case 3: return InsertSort<T>();
        case 4: return SelectionSort<T>();
        case 5: return CountingSort<T>();
        case 6: return DoubleInsertSort<T>();
        case 7: return QuadraticSort<T>();
    }
}
*/

template<class T>
void ShowTimeAll(ArraySequence<ArraySequence<T>>& arr, ArraySequence<int>& sortsType){
        for (int i = 0; i < arr.GetLength(); i++)
            CheckTimeOne(arr.Get(i), sortsType.Get(i));
}

template<class T>
void DoYouWTS(int index, Sequence<T>& arr){
    //arr - тот массив, насчет вывода которого мы и спрашиваем
    //index = 1 - рандомный массив
    string str;
    if (index != 1){
        switch(index){
            case 2: str = "Сортировка пузырьком"; break;
            case 3: str = "Шейкерная сортировка"; break;
            case 4: str = "Сортировка вставкой"; break;
            case 5: str = "Сортировка выбором"; break;
            case 6: str = "Сортировка подсчетом";break;
            case 7: str = "Сортировка методом двоичных вставок"; break;
            case 8: str = "Квадратичная сортировка"; break;
        }
    }
    bool wish = false;
    int countTS;
    switch(index){
        case 1:
            cout << "Хотите посмотреть получившийся массив (0,1)?\n";
            cout << "\t:::";
            cin >> wish;
            if (wish){
                cout << "Какое колличество элементов хотите видеть?\n";
                cout << "\t:::";
                cin >> countTS;
                if (countTS > arr.GetLength() || countTS < 0){
                    cout << "Вы ввели неправильное кол-во, поэтому будете видеть все" << endl;
                    countTS = arr.GetLength();
                }
            }
            break;
        default:
            cout << "Хотите посмотреть массив(0, 1), отсортированный с помощью \"" + str + "\" ?\n";
            cout << "\t:::";
            cin >> wish;
            if (wish){
                cout << "Какое колличество элементов хотите видеть?\n";
                cout << "\t:::";
                cin >> countTS;
                if (countTS > arr.GetLength() || countTS < 0){
                    cout << "Вы ввели неправильное кол-во, поэтому будете видеть все" << endl;
                    countTS = arr.GetLength();
                }
            }
    }

    if (wish){
        cout << '{';
        for (int i = 0; i < countTS; i++) {
            cout << arr.Get(i);
            if (i != countTS - 1) {
                cout << ", ";
            }
        }
        cout << '}' << endl;
    }
}

/*
template<class T>
void ChekTime(Sequence<T>& arr1, Sequence<T>& arr2, Sequence<T>& arr3, Sequence<T>& arr4, Sequence<T>& arr5, Sequence<T>& arr6){

    BubbleSort<T> bubbleSort;
    auto bubbleT1 = system_clock::now();
    bubbleSort.Sort(&arr1, comparison);
    auto bubbleT2 = system_clock::now();


    ShakerSort<T> shakerSort;
    auto shakerT1 = system_clock::now();
    shakerSort.Sort(&arr2, comparison);
    auto shakerT2 = system_clock::now();

    InsertSort<T> insertSort;
    auto insertT1 = system_clock::now();
    insertSort.Sort(&arr3, comparison);
    auto insertT2 = system_clock::now();


    SelectionSort<T> selectionSort;
    auto selectT1 = system_clock::now();
    selectionSort.Sort(&arr4, comparison);
    auto selectT2 = system_clock::now();


    //TODO только с int работает ----------------- не работает
    CountingSort<T> countingsort;
    auto countT1 = system_clock::now();
    countingsort.Sort(&arr5, comparison);
    auto countT2 = system_clock::now();

    //TODO добавить потом еще сортировок


    cout << "Время сортировок массива из " << arr1.GetLength() << " элементов: \n";
    //     << "\t1: Сортировка пузырьком -> " <<  double (duration_cast<microseconds>(bubbleT2 - bubbleT1).count())/1000000 << endl
    //     << "\t2: Сортиовка шейкером -> " << double (duration_cast<microseconds>(shakerT2 - shakerT1).count())/1000000 << endl
    //     << "\t3: Сортиовка вставкой -> " << double (duration_cast<microseconds>(insertT2 - insertT1).count())/1000000 << endl
    //     << "\t4: Сортиовка выбором -> " << double (duration_cast<microseconds>(selectT2 - selectT1).count())/1000000 << endl;
    //     << "\t5: Сортиовка подсчетом -> " << double (duration_cast<microseconds>(countT2 - countT1).count())/1000000 << endl;


    cout << ",hhhhhhhh" << endl;
}
*/

void menu(){
    bool test;
    cout << "Хотите запустить тесты?(0, 1)\n"
         << ":::\n";
    cin >> test;
    if (test)
        tests();


    int type = ChooseType();
    int count = ChooseCount();
    ArraySequence<int> types (ChooseSortsType(7));

    /*
    if (type == 1){
        ArraySequence<int> origin = MakeRandomIntMassive(count);
        DoYouWTS(1, origin);
        ArraySequence<ArraySequence<int>> many (CreateSequencene(types, origin));
    }
    else if (type == 2){
        ArraySequence<float> origin = MakeRandomFloatMassive(count);
        DoYouWTS(1, origin);
        ArraySequence<ArraySequence<float>> many (CreateSequencene(types, origin));
    }
    else{
        ArraySequence<int> origin = MakeRandomIntMassive(count);
        DoYouWTS(1, origin);
        ArraySequence<ArraySequence<int>> many (CreateSequencene(types, origin));
    }
    */

    switch(type){
        case 1:{
            ArraySequence<int> originint = MakeRandomIntMassive(count);
            DoYouWTS(1, originint);
            ArraySequence<ArraySequence<int>> manyint (CreateSequencene(types, originint));
            ShowTimeAll(manyint, types);
            for (int i = 0; i < manyint.GetLength(); i++){
                DoYouWTS(types.Get(i) + 1, manyint.Get(i));
            }
            break;
        }
        case 2:{
            ArraySequence<float> originfloat = MakeRandomFloatMassive(count);
            DoYouWTS(1, originfloat);
            ArraySequence<ArraySequence<float>> manyfloat (CreateSequencene(types, originfloat));
            ShowTimeAll(manyfloat, types);
            for (int i = 0; i < manyfloat.GetLength(); i++){
                DoYouWTS(types.Get(i) + 1, manyfloat.Get(i));
            }
            break;
        }
        case 3:{
            ArraySequence<char> originchar = MakeRandomCharMassive(count);
            DoYouWTS(1, originchar);
            ArraySequence<ArraySequence<char>> manychar (CreateSequencene(types, originchar));
            ShowTimeAll(manychar, types);
            for (int i = 0; i < manychar.GetLength(); i++){
                DoYouWTS(types.Get(i) + 1, manychar.Get(i));
            }
            break;
        }
        default:{
            cout << "Вы ошиблись с типом!!!" << endl;
        }
    }


    //DoYouWTS(1, origin);

    //ArraySequence<ArraySequence<int>> many (CreateSequencene(types, origin));

    //ShowTimeAll(many, types);


    //ChekTime(arr1, arr2, arr3, arr4, arr5, arr6);

    /*
    for (int i = 0; i < many.GetLength(); i++){
        DoYouWTS(types.Get(i) + 1, many.Get(i));
    }
     */
    //bubble.Sort(&arr, comparison);
    //DoYouWTS(2, arr1);
    //DoYouWTS(3, arr2);
    //DoYouWTS(4, arr3);
    //DoYouWTS(5, arr4);
    //DoYouWTS(6, arr5);


}
#endif //S2_LABORATORY_WORK_1_MENU_H
