#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertPosition(int val, int pos) {
        if (pos <= 1) {
            insertBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) {
            insertEnd(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void deleteEnd() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void deletePosition(int pos) {
        if (pos <= 1) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        if (temp == tail) {
            deleteEnd();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found." << endl;
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~DoublyLinkedList() {
        while (head) deleteBeginning();
    }
};

int main() {
    DoublyLinkedList list;
    int choice, val, pos;
    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertEnd(val);
                break;
            case 3:
                cout << "Enter value and position: "; cin >> val >> pos;
                list.insertPosition(val, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: "; cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: "; cin >> val;
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    return 0;
}
