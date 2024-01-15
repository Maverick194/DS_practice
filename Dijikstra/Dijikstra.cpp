#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

class Graph {
public:
    int V; // Number of vertices (cities)
    vector<vector<pair<int, int>>> adj; // Adjacency list

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    void dijkstra(int start) {
        vector<int> dist(V, INF);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the start city
        cout << "Shortest distances from city " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To city " << i << ": ";
            if (dist[i] == INF)
                cout << "INF";
            else
                cout << dist[i];
            cout << "\n";
        }
    }
};

int main() {
    int numCities, numEdges;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    Graph g(numCities);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges and weights (format: u v weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cout << "Edge with weight - " << i + 1 << ": ";
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int startCity;
    cout << "Enter the start city: ";
    cin >> startCity;

    // Run Dijkstra's algorithm
    g.dijkstra(startCity);

    return 0;
}
