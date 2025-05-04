// list.h - Header file for List ADT using singly linked list
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
    struct Node {
        int data;
        Node* next;
    } *head;

    Node* gethead() { return head; } // Private function to return head pointer

public:
    List() { head = NULL; }
    void insertAscending(int);
    static List merge(List&, List&);
    void display() const;
};

// Function to insert elements while maintaining ascending order
void List::insertAscending(int data) {
    Node* newNode = new Node{data, NULL};
    if (!head || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < data)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to merge two sorted lists into a third sorted list
List List::merge(List& list1, List& list2) {
    List mergedList;
    Node *ptr1 = list1.gethead(), *ptr2 = list2.gethead(), **ptr3 = &mergedList.head;
    
    while (ptr1 && ptr2) {
        if (ptr1->data <= ptr2->data) {
            *ptr3 = new Node{ptr1->data, NULL};
            ptr1 = ptr1->next;
        } else {
            *ptr3 = new Node{ptr2->data, NULL};
            ptr2 = ptr2->next;
        }
        ptr3 = &((*ptr3)->next);
    }
    while (ptr1) {
        *ptr3 = new Node{ptr1->data, NULL};
        ptr1 = ptr1->next;
        ptr3 = &((*ptr3)->next);
    }
    while (ptr2) {
        *ptr3 = new Node{ptr2->data, NULL};
        ptr2 = ptr2->next;
        ptr3 = &((*ptr3)->next);
    }
    return mergedList;
}

// Function to display the list
void List::display() const {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif
