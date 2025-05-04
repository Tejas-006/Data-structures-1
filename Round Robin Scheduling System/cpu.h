#include <iostream>
using namespace std;

struct Node {
    int time;
    Node* next;
};

class CPU {
private:
    Node* tail;
    int quantum;
public:
    CPU(int q) : tail(nullptr), quantum(q) {}

    void insertProcess(int time) {
        Node* newNode = new Node{time, nullptr};
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void execute() {
        if (!tail) {
            cout << "No processes to execute.\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Executing process with time: " << temp->time << endl;
        temp->time -= quantum;
        if (temp->time > 0) {
            tail = tail->next;
        } else {
            cout << "Process completed.\n";
            if (tail == temp) {
                tail = nullptr;
            } else {
                tail->next = temp->next;
            }
            delete temp;
        }
    }

    void display() {
        if (!tail) {
            cout << "No processes in the queue.\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Process Queue: ";
        do {
            cout << temp->time << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Head)\n";
    }
};

#endif
