#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    // Function prototypes
    void insert(int value);
    int deleteMax();
    void display() const;
    bool search(int value) const;
    void heapSort();
    bool isEmpty() const { return heap.empty(); }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\nPriority Queue (Max Heap) Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                if (!pq.isEmpty()) {
                    cout << "Deleted element: " << pq.deleteMax() << endl;
                } else {
                    cout << "Priority Queue is empty!\n";
                }
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value)) {
                    cout << "Value found in the priority queue.\n";
                } else {
                    cout << "Value not found.\n";
                }
                break;
            case 5:
                pq.heapSort();
                cout << "Sorted elements: ";
                pq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// Function definitions for MaxHeap class
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

void MaxHeap::heapifyDown(int index) {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap.size() && heap[left] > heap[maxIndex]) {
        maxIndex = left;
    }

    if (right < heap.size() && heap[right] > heap[maxIndex]) {
        maxIndex = right;
    }

    if (index != maxIndex) {
        swap(heap[index], heap[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MaxHeap::deleteMax() {
    if (heap.empty()) {
        return -1; // Or throw an exception
    }

    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return max;
}

void MaxHeap::display() const {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

bool MaxHeap::search(int value) const {
    return find(heap.begin(), heap.end(), value) != heap.end();
}

void MaxHeap::heapSort() {
    vector<int> tempHeap = heap;
    vector<int> sorted;

    while (!heap.empty()) {
        sorted.push_back(deleteMax());
    }

    heap = tempHeap;
    // To maintain the heap property after sorting
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }

    // Display sorted elements
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << endl;
}