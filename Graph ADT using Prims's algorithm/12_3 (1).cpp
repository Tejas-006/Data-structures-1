#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
    
    // For priority queue comparison
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

class GraphAlgorithms {
private:
    vector<list<pair<int, int>>> adjList; // dest, weight
    int vertexCount;

    bool isValidVertex(int v) {
        return v >= 0 && v < vertexCount;
    }

    // Union-Find functions for Kruskal's
    int findParent(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    // Constructor
    GraphAlgorithms(int size);

    // Graph operations
    void insertEdge(int src, int dest, int weight = 1);
    void display();

    // Algorithms
    void primMST();
    void kruskalMST();
    void dijkstra(int start);

    // Helper function to get all edges (for Kruskal's)
    vector<Edge> getAllEdges();
};

// Main function for menu-driven program
int main() {
    int size, choice, src, dest, weight, start;
    cout << "Enter number of vertices: ";
    cin >> size;

    GraphAlgorithms graph(size);

    while (true) {
        cout << "\nGraph ADT with Algorithms\n";
        cout << "1. Insert Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST Algorithm\n";
        cout << "4. Kruskal's MST Algorithm\n";
        cout << "5. Dijkstra's Shortest Path Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices (0-" << size-1 << "): ";
                cin >> src >> dest;
                cout << "Enter weight: ";
                cin >> weight;
                graph.insertEdge(src, dest, weight);
                break;
            case 2:
                graph.display();
                break;
            case 3:
                graph.primMST();
                break;
            case 4:
                graph.kruskalMST();
                break;
            case 5:
                cout << "Enter starting vertex: ";
                cin >> start;
                graph.dijkstra(start);
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Constructor
GraphAlgorithms::GraphAlgorithms(int size) : vertexCount(size) {
    adjList.resize(size);
}

// Insert edge between src and dest with given weight
void GraphAlgorithms::insertEdge(int src, int dest, int weight) {
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        cout << "Invalid vertices!\n";
        return;
    }
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight}); // For undirected graph
    cout << "Edge inserted between " << src << " and " << dest << endl;
}

// Display the adjacency list
void GraphAlgorithms::display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertexCount; ++i) {
        cout << i << " -> ";
        for (const auto& edge : adjList[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

// Get all edges for Kruskal's algorithm
vector<Edge> GraphAlgorithms::getAllEdges() {
    vector<Edge> edges;
    for (int src = 0; src < vertexCount; ++src) {
        for (const auto& edge : adjList[src]) {
            // To avoid duplicates in undirected graph
            if (src < edge.first) {
                edges.push_back({src, edge.first, edge.second});
            }
        }
    }
    return edges;
}

// Prim's Minimum Spanning Tree algorithm
void GraphAlgorithms::primMST() {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<bool> inMST(vertexCount, false);
    vector<Edge> mstEdges;
    int totalWeight = 0;

    // Start with vertex 0
    inMST[0] = true;
    for (const auto& edge : adjList[0]) {
        pq.push({0, edge.first, edge.second});
    }

    while (!pq.empty() && mstEdges.size() < vertexCount - 1) {
        Edge current = pq.top();
        pq.pop();

        if (inMST[current.dest]) continue;

        inMST[current.dest] = true;
        mstEdges.push_back(current);
        totalWeight += current.weight;

        for (const auto& edge : adjList[current.dest]) {
            if (!inMST[edge.first]) {
                pq.push({current.dest, edge.first, edge.second});
            }
        }
    }

    // Display MST
    cout << "\nPrim's MST Edges:\n";
    for (const auto& edge : mstEdges) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

// Kruskal's Minimum Spanning Tree algorithm
void GraphAlgorithms::kruskalMST() {
    vector<Edge> edges = getAllEdges();
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(vertexCount);
    vector<int> rank(vertexCount, 0);
    for (int i = 0; i < vertexCount; ++i) {
        parent[i] = i;
    }

    vector<Edge> mstEdges;
    int totalWeight = 0;

    for (const Edge& edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
            unionSets(parent, rank, x, y);
        }
    }

    // Display MST
    cout << "\nKruskal's MST Edges:\n";
    for (const auto& edge : mstEdges) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

// Dijkstra's Shortest Path algorithm
void GraphAlgorithms::dijkstra(int start) {
    if (!isValidVertex(start)) {
        cout << "Invalid starting vertex!\n";
        return;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(vertexCount, INT_MAX);
    vector<int> parent(vertexCount, -1);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Display shortest paths
    cout << "\nDijkstra's Shortest Paths from vertex " << start << ":\n";
    for (int i = 0; i < vertexCount; ++i) {
        cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path = ";
        
        vector<int> path;
        for (int v = i; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        
        for (size_t j = 0; j < path.size(); ++j) {
            if (j != 0) cout << " -> ";
            cout << path[j];
        }
        cout << endl;
    }
}