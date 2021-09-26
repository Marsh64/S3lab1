//
// Created by adm on 05.09.2021.
//

#include "LinkedList.h"

template <class T>
void LinkedList<T>::Append(T item) {
    auto *new_cell = new struct element;
    new_cell->value = item;
    new_cell->next_element = nullptr;

    if (head_element == nullptr){ //случай, когда список пустой
        head_element = new_cell;
        end_element = new_cell;
        len = 1;
        return;
    }

    end_element->next_element = new_cell;
    end_element = new_cell;
    len++;
}

template <class T>
LinkedList<T>::LinkedList() {
    len = 0;
    head_element = nullptr;
    end_element = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(T *items, int count) {
    len = 0;
    head_element = nullptr;
    end_element = nullptr;

    for (int i = 0; i < count; i++){
        Append(items[i]);
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    len = 0;
    head_element = nullptr;
    end_element = nullptr;
    struct element *cell = list.head_element;
    for (int i = 0; i < list.len; i++, cell = cell->next_element){
        Append(cell->value);
    }
}

template <class T>
T LinkedList<T>::GetFirst() {
    if (head_element == nullptr){
        throw IndexOutOfRange();
    }

    return head_element->value;
}

template <class T>
T LinkedList<T>::GetLast() {
    if (end_element == nullptr){
        throw IndexOutOfRange();
    }

    return end_element->value;
}

template <class T>
T& LinkedList<T>::Get(int index) {
    if (index < 0 || index >= len){
        throw IndexOutOfRange();
    }

    struct element *cell = head_element;
    for (int i = 0; i < index; i++, cell = cell->next_element);

    return cell->value;
}

template <class T>
LinkedList<T> LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex >= len || endIndex >= len || startIndex < 0 || endIndex < 0){
        throw IndexOutOfRange();
    }

    LinkedList<T> new_list = LinkedList<T>();
    auto *cell = new struct element;
    cell = head_element;
    for (int i = 0; i < startIndex; i++, cell = cell->next_element);
    for (int i = startIndex; i <= endIndex; i++, cell = cell->next_element){
        new_list.Append(cell->value);
    }

    return new_list;
}

template <class T>
int LinkedList<T>::GetLength() {
    return len;
}

template<class T>
void LinkedList<T>::Set(T item, int index){
    struct element* shell = head_element;
    for (int i = 0; i < len; i++){
        if (i == index){
            shell->value = item;
        }else{
            shell = head_element->next_element;
        }
    }
}//TODO проработать ошибки

template <class T>
void LinkedList<T>::Prepend(T item) {
    auto *new_cell = new struct element;
    new_cell->value = item;

    if (head_element == nullptr){
        end_element = new_cell;
    }

    new_cell->next_element = head_element;
    head_element = new_cell;
    len++;
}

template <class T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index >= len || index < 0){
        throw IndexOutOfRange();
    }

    if (index == 0){Append(item); return;}
    else if (index == len - 1){Prepend(item); return;}
    else{
        auto *new_cell = new struct element;
        new_cell->value = item;
        struct element *previous_cell = head_element;
        for (int i = 0; i < index - 1; i++, previous_cell = previous_cell->next_element);
        new_cell->next_element = previous_cell->next_element;
        previous_cell->next_element = new_cell;
        len++;
    }
}

template<class T>
LinkedList<T> :: ~LinkedList(){
    Delete_LinkedList();
}

template <class T>
void LinkedList<T> :: Delete_LinkedList() {
    struct element* this_cell;
    while(head_element != nullptr){
        this_cell = head_element;
        head_element = head_element->next_element;
        delete this_cell;
    }
    end_element = nullptr;
    len = 0;
}