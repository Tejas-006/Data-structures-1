#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> adjMatrix;
    int vertexCount;

    bool isValidVertex(int v) {
        return v >= 0 && v < vertexCount;
    }

public:
    // Constructor
    GraphMatrix(int size);

    // Graph operations
    void insertEdge(int src, int dest, int weight = 1);
    void deleteEdge(int src, int dest);
    bool searchEdge(int src, int dest);
    void display();

    // Helper function to get vertex count
    int getVertexCount() { return vertexCount; }
};

// Main function for menu-driven program
int main() {
    int size, choice, src, dest, weight;
    cout << "Enter number of vertices: ";
    cin >> size;

    GraphMatrix graph(size);

    while (true) {
        cout << "\nGraph ADT with Adjacency Matrix\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices (0-" << size-1 << "): ";
                cin >> src >> dest;
                cout << "Enter weight (default 1): ";
                cin >> weight;
                graph.insertEdge(src, dest, weight);
                break;
            case 2:
                cout << "Enter source and destination vertices to delete: ";
                cin >> src >> dest;
                graph.deleteEdge(src, dest);
                break;
            case 3:
                cout << "Enter source and destination vertices to search: ";
                cin >> src >> dest;
                if (graph.searchEdge(src, dest)) {
                    cout << "Edge exists between " << src << " and " << dest << endl;
                } else {
                    cout << "Edge does not exist\n";
                }
                break;
            case 4:
                graph.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Constructor
GraphMatrix::GraphMatrix(int size) : vertexCount(size) {
    adjMatrix.resize(size, vector<int>(size, 0));
}

// Insert edge between src and dest with given weight
void GraphMatrix::insertEdge(int src, int dest, int weight) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        cout << "Invalid vertices!\n";
        return;
    }
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight; // For undirected graph
    cout << "Edge inserted between " << src << " and " << dest << endl;
}

// Delete edge between src and dest
void GraphMatrix::deleteEdge(int src, int dest) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        cout << "Invalid vertices!\n";
        return;
    }
    if (adjMatrix[src][dest] == 0) {
        cout << "Edge doesn't exist\n";
        return;
    }
    adjMatrix[src][dest] = 0;
    adjMatrix[dest][src] = 0; // For undirected graph
    cout << "Edge deleted between " << src << " and " << dest << endl;
}

// Search for edge between src and dest
bool GraphMatrix::searchEdge(int src, int dest) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        return false;
    }
    return adjMatrix[src][dest] != 0;
}

// Display the adjacency matrix
void GraphMatrix::display() {
    cout << "\nAdjacency Matrix:\n";
    cout << "  ";
    for (int i = 0; i < vertexCount; ++i) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < vertexCount; ++i) {
        cout << i << " ";
        for (int j = 0; j < vertexCount; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Time Complexity Analysis:
1. Insert Edge: O(1) - Direct access to matrix cell
2. Delete Edge: O(1) - Direct access to matrix cell
3. Search Edge: O(1) - Direct access to matrix cell
4. Display: O(V^2) - Need to print entire matrix
*/