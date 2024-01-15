#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <SFML/Graphics.hpp>

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

class GraphVisualizer {
private:
    const Graph& graph;

public:
    GraphVisualizer(const Graph& graph) : graph(graph) {}

    void drawGraph() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Graph Visualization");
        window.setFramerateLimit(60);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            // Draw edges
            for (int u = 0; u < graph.V; ++u) {
                for (const auto& neighbor : graph.adj[u]) {
                    int v = neighbor.first;
                    drawEdge(window, u, v);
                }
            }

            // Draw vertices
            for (int i = 0; i < graph.V; ++i) {
                drawVertex(window, i);
            }

            window.display();
        }
    }

private:
    void drawEdge(sf::RenderWindow& window, int u, int v) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(u * 100, v * 100)),
            sf::Vertex(sf::Vector2f(v * 100, u * 100))
        };

        window.draw(line, 2, sf::Lines);
    }

    void drawVertex(sf::RenderWindow& window, int vertex) {
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(vertex * 100 - 20, 300 - 20); // Adjust the position for visualization

        window.draw(circle);
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

    // Visualize the graph
    GraphVisualizer graphVisualizer(g);
    graphVisualizer.drawGraph();

    return 0;
}
