#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root; // Root of the binary tree

    // Helper functions for recursive operations
    Node* insertHelper(Node* node, char value);
    void preorderHelper(Node* node);
    void inorderHelper(Node* node);
    void postorderHelper(Node* node);
    bool searchHelper(Node* node, char value);

public:
    BinaryTree() : root(nullptr) {} // Constructor
    void insert(char value);       // Insert a node
    void preorder();               // Preorder traversal
    void inorder();                // Inorder traversal
    void postorder();              // Postorder traversal
    void search(char value);       // Search for a node
};

// Main function
int main() {
    BinaryTree tree;
    int choice;
    char value;

    while (true) {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                cout << endl;
                break;
            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// Function to insert a node into the binary tree
void BinaryTree::insert(char value) {
    root = insertHelper(root, value);
}

// Recursive helper function for insertion
Node* BinaryTree::insertHelper(Node* node, char value) {
    if (node == nullptr) {
        return new Node(value); // Create a new node if the current node is null
    }

    if (value < node->data) {
        node->left = insertHelper(node->left, value); // Insert in the left subtree
    } else if (value > node->data) {
        node->right = insertHelper(node->right, value); // Insert in the right subtree
    }

    return node; // Return the unchanged node if the value already exists
}

// Function to perform preorder traversal
void BinaryTree::preorder() {
    preorderHelper(root);
}

// Recursive helper function for preorder traversal
void BinaryTree::preorderHelper(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " "; // Visit the root
    preorderHelper(node->left); // Traverse the left subtree
    preorderHelper(node->right); // Traverse the right subtree
}

// Function to perform inorder traversal
void BinaryTree::inorder() {
    inorderHelper(root);
}

// Recursive helper function for inorder traversal
void BinaryTree::inorderHelper(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderHelper(node->left); // Traverse the left subtree
    cout << node->data << " "; // Visit the root
    inorderHelper(node->right); // Traverse the right subtree
}

// Function to perform postorder traversal
void BinaryTree::postorder() {
    postorderHelper(root);
}

// Recursive helper function for postorder traversal
void BinaryTree::postorderHelper(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderHelper(node->left); // Traverse the left subtree
    postorderHelper(node->right); // Traverse the right subtree
    cout << node->data << " "; // Visit the root
}

// Function to search for a node in the binary tree
void BinaryTree::search(char value) {
    if (searchHelper(root, value)) {
        cout << "Character '" << value << "' found in the tree." << endl;
    } else {
        cout << "Character '" << value << "' not found in the tree." << endl;
    }
}

// Recursive helper function for searching
bool BinaryTree::searchHelper(Node* node, char value) {
    if (node == nullptr) {
        return false; // Value not found
    }
    if (value == node->data) {
        return true; // Value found
    }
    if (value < node->data) {
        return searchHelper(node->left, value); // Search in the left subtree
    }
    return searchHelper(node->right, value); // Search in the right subtree
}

/*
Time Complexity:
- Insert: O(h), where h is the height of the tree.
- Preorder, Inorder, Postorder: O(n), where n is the number of nodes.
- Search: O(h), where h is the height of the tree.
*/