#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Graph representation using adjacency matrix
const int INF = INT_MAX;

// Dijkstra's Algorithm to find shortest path
void dijkstra(vector<vector<int>>& graph, int n, int source) {
    vector<int> dist(n, INF);      // Distance from source to each node
    vector<bool> visited(n, false);  // To track visited nodes
    dist[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        // Select the minimum distance node
        int u = -1;
        int minDist = INF;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output shortest distances
    cout << "Shortest paths from source " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Distance to " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int n = 5;  // Number of landmarks
    vector<vector<int>> graph = {
        {0, 10, INF, 30, 100},
        {10, 0, 50, INF, INF},
        {INF, 50, 0, 20, 10},
        {30, INF, 20, 0, 60},
        {100, INF, 10, 60, 0}
    };

    int source = 0;  // Starting landmark
    dijkstra(graph, n, source);

    return 0;
}
