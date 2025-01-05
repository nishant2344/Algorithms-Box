#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    // To sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Class to represent a Union-Find (Disjoint Set) data structure
class UnionFind {
public:
    int *parent, *rank;

    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        // Initially, each node is its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union function with union by rank
    bool union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int kruskal(int n, Edge edges[], int m) {
    UnionFind uf(n);
    int mst_cost = 0;
    int mst_edges = 0;

    sort(edges, edges + m);

    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (uf.union_sets(u, v)) {
            mst_cost += weight;
            mst_edges++;

            if (mst_edges == n - 1) break;
        }
    }
    return mst_cost;
}

int main() {
    int n = 4, m = 5;

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mst_cost = kruskal(n, edges, m);

    cout << "Minimum Cost of Spanning Tree: " << mst_cost << endl;

    return 0;
}
