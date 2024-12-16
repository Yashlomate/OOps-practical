#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Edge structure for graph
struct Edge {
    int src, dest, weight;
};

// Disjoint Set (Union-Find) for cycle detection
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm to find MST
vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    vector<Edge> result;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

    DisjointSet ds(n);

    for (auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            result.push_back(edge);
        }
    }

    return result;
}

int main() {
    int n = 5;  // Number of departments
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {0, 4, 5},
        {1, 2, 3}, {1, 3, 8},
        {2, 3, 7}, {3, 4, 9}
    };

    vector<Edge> mst = kruskalMST(n, edges);

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
