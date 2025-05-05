#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int* table;
    bool* isOccupied;
public:
    HashTable();
    ~HashTable();
    int hashFunction(int key);
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void display();
};

HashTable::HashTable() {
    table = new int[TABLE_SIZE];
    isOccupied = new bool[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        isOccupied[i] = false;
    }
}

HashTable::~HashTable() {
    delete[] table;
    delete[] isOccupied;
}

int HashTable::hashFunction(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    while (isOccupied[index]) {
        if (table[index] == key) {
            cout << "Key already exists in the table.\n";
            return;
        }
        index = (originalIndex + i * i) % TABLE_SIZE;
        i++;
        if (i == TABLE_SIZE) {
            cout << "Hash table is full or key cannot be inserted.\n";
            return;
        }
    }
    
    table[index] = key;
    isOccupied[index] = true;
    cout << "Key " << key << " inserted at index " << index << ".\n";
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    while (isOccupied[index]) {
        if (table[index] == key) {
            isOccupied[index] = false;
            cout << "Key " << key << " removed from index " << index << ".\n";
            return;
        }
        index = (originalIndex + i * i) % TABLE_SIZE;
        i++;
        if (i == TABLE_SIZE) {
            break;
        }
    }
    
    cout << "Key " << key << " not found in the table.\n";
}

bool HashTable::search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    while (isOccupied[index]) {
        if (table[index] == key) {
            return true;
        }
        index = (originalIndex + i * i) % TABLE_SIZE;
        i++;
        if (i == TABLE_SIZE) {
            break;
        }
    }
    
    return false;
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i]) {
            cout << "Index " << i << ": " << table[i] << "\n";
        } else {
            cout << "Index " << i << ": Empty\n";
        }
    }
}

int main() {
    HashTable ht;
    int choice, key;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (ht.search(key)) {
                    cout << "Key found in the table.\n";
                } else {
                    cout << "Key not found in the table.\n";
                }
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}

/*
Time Complexity Analysis:
1. Insert: O(n) in worst case (when table is nearly full and clustering occurs)
2. Delete: O(n) in worst case
3. Search: O(n) in worst case
4. Display: O(n) where n is the table size
*/