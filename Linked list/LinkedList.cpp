#include <iostream>
#include <cstdlib>
using namespace std;

class list {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    list() {
        head = NULL;
    }

    void insertbeg(int);
    void insertend(int);
    void deleteBeg();
    void deleteEnd();
    void deletePos(int);
    void reverse();
    void display();
};

void list::insertbeg(int data1) {
    node* newnode = new node;
    newnode->data = data1;
    newnode->next = head;
    head = newnode;
}

void list::insertend(int data1) {
    node* newnode = new node;
    newnode->data = data1;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void list::deleteBeg() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted from beginning.\n";
}

void list::deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    cout << "Deleted from end.\n";
}

void list::deletePos(int pos) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (pos == 0) {
        deleteBeg();
        return;
    }
    node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!\n";
        return;
    }
    node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    cout << "Deleted from position " << pos << ".\n";
}

void list::reverse() {
    node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "Linked list reversed.\n";
}

void list::display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    list list1;
    int choice, value, pos;
    do {
        cout << "\nSelect an operation:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Delete from Position\n";
        cout << "6. Reverse List\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list1.insertbeg(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list1.insertend(value);
            break;
        case 3:
            list1.deleteBeg();
            break;
        case 4:
            list1.deleteEnd();
            break;
        case 5:
            cout << "Enter position to delete: ";
            cin >> pos;
            list1.deletePos(pos);
            break;
        case 6:
            list1.reverse();
            break;
        case 7:
            list1.display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
