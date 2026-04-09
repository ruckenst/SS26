#ifndef SS26_LINKEDLIST_H
#define SS26_LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
public:
    void insertBack(T value) {
        Node* newNode = new Node {value, nullptr};

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;

        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void print(void printFunction(T value)) {
        Node* curr = head;

        while(curr != nullptr) {
            printFunction(curr->value);
            std::cout << " -> ";
            curr = curr->next;
        }

        std::cout << "NULL" << std::endl;
    }

    void sort(bool sortFunction(T left, T right)) {

    }

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head = nullptr;
};

#endif //SS26_LINKEDLIST_H
