#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Edge {
    int dest;
    int weight;
};

class GraphList {
private:
    vector<list<Edge>> adjList;
    int vertexCount;

    bool isValidVertex(int v) {
        return v >= 0 && v < vertexCount;
    }

public:
    // Constructor
    GraphList(int size);

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

    GraphList graph(size);

    while (true) {
        cout << "\nGraph ADT with Adjacency List\n";
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
GraphList::GraphList(int size) : vertexCount(size) {
    adjList.resize(size);
}

// Insert edge between src and dest with given weight
void GraphList::insertEdge(int src, int dest, int weight) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        cout << "Invalid vertices!\n";
        return;
    }
    // Check if edge already exists
    for (const auto& edge : adjList[src]) {
        if (edge.dest == dest) {
            cout << "Edge already exists\n";
            return;
        }
    }
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight}); // For undirected graph
    cout << "Edge inserted between " << src << " and " << dest << endl;
}

// Delete edge between src and dest
void GraphList::deleteEdge(int src, int dest) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        cout << "Invalid vertices!\n";
        return;
    }
    
    // Remove dest from src's list
    auto it = find_if(adjList[src].begin(), adjList[src].end(), 
                     [dest](const Edge& e) { return e.dest == dest; });
    if (it != adjList[src].end()) {
        adjList[src].erase(it);
    } else {
        cout << "Edge doesn't exist\n";
        return;
    }
    
    // Remove src from dest's list (for undirected graph)
    it = find_if(adjList[dest].begin(), adjList[dest].end(), 
                [src](const Edge& e) { return e.dest == src; });
    if (it != adjList[dest].end()) {
        adjList[dest].erase(it);
    }
    
    cout << "Edge deleted between " << src << " and " << dest << endl;
}

// Search for edge between src and dest
bool GraphList::searchEdge(int src, int dest) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        return false;
    }
    for (const auto& edge : adjList[src]) {
        if (edge.dest == dest) {
            return true;
        }
    }
    return false;
}

// Display the adjacency list
void GraphList::display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertexCount; ++i) {
        cout << i << " -> ";
        for (const auto& edge : adjList[i]) {
            cout << "(" << edge.dest << ", " << edge.weight << ") ";
        }
        cout << endl;
    }
}

/*
Time Complexity Analysis:
1. Insert Edge: O(V) - Need to check if edge exists (worst case)
2. Delete Edge: O(V) - Need to search through list
3. Search Edge: O(V) - Need to search through list
4. Display: O(V + E) - Need to visit all vertices and edges
*/