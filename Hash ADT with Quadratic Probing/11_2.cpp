#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int>* table;
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
    table = new list<int>[TABLE_SIZE];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hashFunction(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            cout << "Key already exists in the table.\n";
            return;
        }
    }
    
    table[index].push_back(key);
    cout << "Key " << key << " inserted at index " << index << ".\n";
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            cout << "Key " << key << " removed from index " << index << ".\n";
            return;
        }
    }
    
    cout << "Key " << key << " not found in the table.\n";
}

bool HashTable::search(int key) {
    int index = hashFunction(key);
    
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            return true;
        }
    }
    
    return false;
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (table[i].empty()) {
            cout << "Empty";
        } else {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << *it << " -> ";
            }
            cout << "NULL";
        }
        cout << "\n";
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
1. Insert: O(1) average case, O(n) worst case (when all keys hash to same index)
2. Delete: O(1) average case, O(n) worst case
3. Search: O(1) average case, O(n) worst case
4. Display: O(n) where n is total number of keys in the table
*/