#include <iostream>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int** graph, int V) {
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function to implement Prim's Minimum Spanning Tree algorithm
void primMST(int** graph, int V) {
    int* parent = new int[V]; // To store the MST
    int* key = new int[V];   // To store the minimum edge weight
    bool* mstSet = new bool[V]; // To track vertices included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // Starting vertex has a key value of 0
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
    }

    // Define a static adjacency matrix
    int staticGraph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Copy static graph into dynamically allocated graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i < 5 && j < 5) {
                graph[i][j] = staticGraph[i][j];
            } else {
                graph[i][j] = 0;
            }
        }
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    primMST(graph, V);

    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
