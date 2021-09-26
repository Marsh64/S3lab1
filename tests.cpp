//
// Created by adm on 26.09.2021.
//

#include "tests.h"
#include "iostream"
using namespace std;

ArraySequence<int> MakeRandomMassive(int count) {
    int *a = new int[count];
    srand(124);
    for (int i = 0; i < count; i++) {
        a[i] = rand() % 1000;
        if (a[i] % 3 == 0)
            a[i] = a[i] * -1;
    }
    return ArraySequence<int>(a, count);
}

void tests(){
    /*
    int rand;
    cout << "Введите случайное число\n"
         << ":::\n";
    cin >> rand;
     */

    int count;
    cout << "Введите число, на которое хотите проверить сортировки\n"
         << ":::\n";
    cin >> count;

    ArraySequence<int> origin(MakeRandomMassive(count));

    BubbleSort<int> bubbleSort;
    ShakerSort<int> shakerSort;
    InsertSort<int> insertSort;
    SelectionSort<int> selectionSort;
    CountingSort<int> countingSort;
    DoubleInsertSort<int> doubleInsertSort;
    QuadraticSort<int> quadraticSort;

    ArraySequence<int> arrBubble(origin);
    ArraySequence<int> arrShaker(origin);
    ArraySequence<int> arrInsert(origin);
    ArraySequence<int> arrSelection(origin);
    ArraySequence<int> arrCounting(origin);
    ArraySequence<int> arrDouble(origin);
    ArraySequence<int> arrQuadratic(origin);

    bubbleSort.Sort(&arrBubble, comparison);
    shakerSort.Sort(&arrShaker, comparison);
    insertSort.Sort(&arrInsert, comparison);
    selectionSort.Sort(&arrSelection, comparison);
    countingSort.Sort(&arrCounting, comparison);
    doubleInsertSort.Sort(&arrDouble, comparison);
    quadraticSort.Sort(&arrQuadratic, comparison);

    bool equal = true;
    for (int i = 0; i < count; i++){
        if (arrBubble.Get(i) != arrShaker.Get(i)){
            cout << "Bubble и Shaker не равны на " << i << " элементе\n";
            equal = false;
        }

        if (arrShaker.Get(i) != arrInsert.Get(i)){
            cout << "Insert и Shaker не равны на " << i << " элементе\n";
            equal = false;
        }

        if (arrInsert.Get(i) != arrSelection.Get(i)){
            cout << "Insert и Selection не равны на " << i << " элементе\n";
            equal = false;
        }

        if (arrSelection.Get(i) != arrCounting.Get(i)){
            cout << "Counting и Selection не равны на " << i << " элементе\n";
            equal = false;
        }

        if (arrCounting.Get(i) != arrDouble.Get(i)){
            cout << "Counting и DoubleInsert не равны на " << i << " элементе\n";
            equal = false;
        }

        if (arrDouble.Get(i) != arrQuadratic.Get(i)){
            cout << "Quadratic и DoubleInsert не равны на " << i << " элементе\n";
            equal = false;
        }
    }

    /*
    cout << '{';
    for (int i = 0; i < count; i++) {
        cout << arrBubble.Get(i);
        if (i != count - 1) {
            cout << ", ";
        }
    }
    cout << '}' << endl;

    cout << '{';
    for (int i = 0; i < count; i++) {
        cout << arrDouble.Get(i);
        if (i != count - 1) {
            cout << ", ";
        }
    }
    cout << '}' << endl;

    cout << endl;

    cout << '{';
    for (int i = 0; i < count; i++) {
        cout << arrQuadratic.Get(i);
        if (i != count - 1) {
            cout << ", ";
        }
    }
    cout << '}' << endl;
    */

    if (equal){
        cout << "Все элементы совпадают!!!" << endl;
    }
}