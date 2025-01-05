#include <iostream>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, Edge edges[], int source) {
    int distance[n];

   for (int i = 0; i < n; ++i) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }


    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INT_MAX) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << distance[i] << "\n";
        }
    }
}

int main() {
    int n = 5, m = 8;
    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;
    bellmanFord(n, m, edges, source);

    return 0;
}
