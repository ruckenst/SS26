#ifndef SS26_LINKEDLIST_H
#define SS26_LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
public:
    void insertBack(T newValue);
    void print(void printElement(T element));

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head = nullptr;
};

template<typename T>
void LinkedList<T>::insertBack(T newValue) {
    Node* newNode = new Node{newValue, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}

template<typename T>
void LinkedList<T>::print(void printElement(T element)) {
    Node* curr = head;

    while (curr != nullptr) {
        printElement(curr->value);
        std::cout << " -> ";
        curr = curr->next;
    }

    std::cout << "NULL" << std::endl;
}

#endif