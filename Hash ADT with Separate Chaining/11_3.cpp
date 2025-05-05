#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int DEFAULT_SIZE = 10; // Default hash table size
    vector<list<pair<int, int>>> table; // Vector of linked lists (key-value pairs)
    int currentSize;

    // Hash function to compute index
    int hashFunction(int key) {
        return key % table.size();
    }

    // Helper function to find an element in a chain
    auto findInChain(list<pair<int, int>>& chain, int key) {
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                return it;
            }
        }
        return chain.end();
    }

public:
    // Constructor
    HashTable(int size = DEFAULT_SIZE) : table(size), currentSize(0) {}

    // Insert a key-value pair
    void insert(int key, int value) {
        int index = hashFunction(key);
        auto& chain = table[index];

        // Check if key already exists
        auto it = findInChain(chain, key);
        if (it != chain.end()) {
            cout << "Key " << key << " already exists. Updating value." << endl;
            it->second = value;
        } else {
            chain.emplace_back(key, value);
            currentSize++;
            cout << "Inserted key " << key << " with value " << value << endl;
        }
    }

    // Delete a key
    void deleteKey(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        auto it = findInChain(chain, key);
        if (it != chain.end()) {
            chain.erase(it);
            currentSize--;
            cout << "Deleted key " << key << endl;
        } else {
            cout << "Key " << key << " not found!" << endl;
        }
    }

    // Search for a key
    void search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        auto it = findInChain(chain, key);
        if (it != chain.end()) {
            cout << "Key " << key << " found with value " << it->second << endl;
        } else {
            cout << "Key " << key << " not found!" << endl;
        }
    }

    // Get current size
    int size() const {
        return currentSize;
    }
};

int main() {
    int size, choice, key, value;
    cout << "Enter size of hash table (default is 10): ";
    cin >> size;

    HashTable hashTable(size > 0 ? size : 10);

    while (true) {
        cout << "\nHash Table ADT Menu (Separate Chaining)\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                hashTable.insert(key, value);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                hashTable.deleteKey(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                hashTable.search(key);
                break;
            case 4:
                cout << "Exiting program. Current size: " << hashTable.size() << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

/*
Time Complexity Analysis:
1. Insert: 
   - Average case: O(1) 
   - Worst case: O(n) when all keys hash to the same index
2. Delete: 
   - Average case: O(1) 
   - Worst case: O(n) when all keys hash to the same index
3. Search: 
   - Average case: O(1) 
   - Worst case: O(n) when all keys hash to the same index

Note: The average case assumes a good hash function that uniformly distributes keys.
The worst case occurs when all keys collide and end up in the same chain.
*/