#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX; 
const int MAX_NODES = 5; 

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int dest, int n) {
    int dist[MAX_NODES];     
    bool visited[MAX_NODES]; 
    int parent[MAX_NODES];  


    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1; 
    }

    dist[src] = 0; 

    // Main Dijkstra loop
    for (int count = 0; count < n - 1; count++) {
        // Find the nearest unvisited node
        int minDist = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break; 
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; 
            }
        }
    }

    if (dist[dest] == INF) {
        cout << "No path exists from " << char(src + 'A') << " to " << char(dest + 'A') << ".\n";
        return;
    }


    cout << "Shortest distance from " << char(src + 'A') << " to " << char(dest + 'A') << ": " << dist[dest] << "\n";


    cout << "Path: ";
    int current = dest;
    int path[MAX_NODES], pathIndex = 0;
    while (current != -1) {
        path[pathIndex++] = current;
        current = parent[current];
    }
    for (int i = pathIndex - 1; i >= 0; i--) {
        cout << char(path[i] + 'A');
        if (i != 0) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    int n = 5; 
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 4, 2, 0, 0}, 
        {0, 0, 0, 5, 0}, 
        {0, 1, 0, 8, 10}, 
        {0, 0, 0, 0, 2}, 
        {0, 0, 0, 0, 0}  
    };

    char srcChar, destChar;
    cout << "Enter the starting point source node (A-E): ";
    cin >> srcChar;
    cout << "Enter the destination node (A-E): ";
    cin >> destChar;

    int src = srcChar - 'A';
    int dest = destChar - 'A';

    dijkstra(graph, src, dest, n);

    return 0;
}
