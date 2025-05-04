#include <iostream>
#include <algorithm>
using namespace std;

class ListADT {
private:
    int arr[5];
    int size;
    const int MAX_SIZE = 5;

public:
    ListADT() : size(0) {}

    
    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void shiftRight(int start, int end) {
        for (int i = end; i > start; i--) {
            arr[i] = arr[i-1];
        }
    }

    void shiftLeft(int start, int end) {
        for (int i = start; i < end; i++) {
            arr[i] = arr[i+1];
        }
    }

    // Insert operations
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int pos);

    // Delete operations
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);

    // Other operations
    int search(int value);
    void display();
    void rotateRight(int k);

    // Rotation methods
    void rotateWithTempArray(int k);
    void rotateWithReversal(int k);  // O(1) space solution
    void rotateOneByOne(int k);
};

int main() {
    ListADT list;
    int choice, value, pos, k;

    while (true) {
        cout << "\nList ADT Menu\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Rotate Right\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (list.isFull()) {
                    cout << "List is full!\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                if (list.isFull()) {
                    cout << "List is full!\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                if (list.isFull()) {
                    cout << "List is full!\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (0-based): ";
                cin >> pos;
                list.insertPosition(value, pos);
                break;
            case 4:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                list.deleteBeginning();
                break;
            case 5:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                list.deleteEnd();
                break;
            case 6:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                cout << "Enter position (0-based) to delete: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                cout << "Enter value to search: ";
                cin >> value;
                pos = list.search(value);
                if (pos == -1) {
                    cout << "Value not found!\n";
                } else {
                    cout << "Value found at position " << pos << endl;
                }
                break;
            case 8:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                list.display();
                break;
            case 9:
                if (list.isEmpty()) {
                    cout << "List is empty!\n";
                    break;
                }
                cout << "Enter number of rotations: ";
                cin >> k;
                list.rotateRight(k);
                cout << "List after rotation:\n";
                list.display();
                break;
            case 10:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Insert at beginning
void ListADT::insertBeginning(int value) {
    if (isFull()) {
        cout << "List is full. Cannot insert.\n";
        return;
    }
    shiftRight(0, size);
    arr[0] = value;
    size++;
    cout << "Inserted " << value << " at beginning.\n";
}

// Insert at end
void ListADT::insertEnd(int value) {
    if (isFull()) {
        cout << "List is full. Cannot insert.\n";
        return;
    }
    arr[size] = value;
    size++;
    cout << "Inserted " << value << " at end.\n";
}

// Insert at specific position
void ListADT::insertPosition(int value, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    if (isFull()) {
        cout << "List is full. Cannot insert.\n";
        return;
    }
    shiftRight(pos, size);
    arr[pos] = value;
    size++;
    cout << "Inserted " << value << " at position " << pos << ".\n";
}

// Delete from beginning
void ListADT::deleteBeginning() {
    if (isEmpty()) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    int deleted = arr[0];
    shiftLeft(0, size-1);
    size--;
    cout << "Deleted " << deleted << " from beginning.\n";
}

// Delete from end
void ListADT::deleteEnd() {
    if (isEmpty()) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    int deleted = arr[size-1];
    size--;
    cout << "Deleted " << deleted << " from end.\n";
}

// Delete from specific position
void ListADT::deletePosition(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!\n";
        return;
    }
    if (isEmpty()) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    int deleted = arr[pos];
    shiftLeft(pos, size-1);
    size--;
    cout << "Deleted " << deleted << " from position " << pos << ".\n";
}

// Search for a value
int ListADT::search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Display the list
void ListADT::display() {
    cout << "List: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size-1) cout << ", ";
    }
    cout << "]\n";
}

// Rotate right by k positions (wrapper function)
void ListADT::rotateRight(int k) {
    if (size == 0) return;
    k = k % size;  // Handle cases where k > size
    
    // Choose one of the rotation methods:
    // rotateWithTempArray(k);
    rotateWithReversal(k);  // Using the O(1) space solution
    // rotateOneByOne(k);
}

// Rotation method 1: Using temporary array
void ListADT::rotateWithTempArray(int k) {
    int temp[k];
    // Store the last k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[size - k + i];
    }
    // Shift the remaining elements right
    for (int i = size - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    // Put the temp elements at the beginning
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

// Rotation method 2: Using reversal (O(1) space)
void ListADT::rotateWithReversal(int k) {
    // Reverse the entire array
    reverse(arr, arr + size);
    // Reverse the first k elements
    reverse(arr, arr + k);
    // Reverse the remaining elements
    reverse(arr + k, arr + size);
}

// Rotation method 3: Rotate one by one
void ListADT::rotateOneByOne(int k) {
    for (int i = 0; i < k; i++) {
        int last = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}