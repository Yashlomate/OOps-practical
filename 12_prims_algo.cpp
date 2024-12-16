#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Prim's Algorithm to find MST
void primMST(vector<vector<int>>& graph, int n) {
    vector<bool> inMST(n, false);  // To track included nodes in MST
    vector<int> key(n, INT_MAX);    // Minimum edge weight to include each vertex
    vector<int> parent(n, -1);      // To store MST
    key[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int minKey = INT_MAX, u;
        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        
        inMST[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Output MST
    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n = 5;  // Number of departments
    vector<vector<int>> graph = {
        {0, 2, INT_MAX, 6, 5},
        {2, 0, 3, 8, INT_MAX},
        {INT_MAX, 3, 0, 7, INT_MAX},
        {6, 8, 7, 0, 9},
        {5, INT_MAX, INT_MAX, 9, 0}
    };

    primMST(graph, n);

    return 0;
}
