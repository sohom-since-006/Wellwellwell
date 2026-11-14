#include <iostream>
#include <vector>

const int INF = 1e9;

struct Edge {
    int src, dest, weight;
};

bool bellmanFord(int V, int E, int src, const std::vector<Edge>& edges, std::vector<int>& dist) {
    dist.assign(V, INF);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
            return false; // Negative weight cycle detected
        }
    }
    return true;
}

int main() {
    int V = 5, E = 8;
    std::vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    std::vector<int> dist;
    if (bellmanFord(V, E, 0, edges, dist)) {
        std::cout << "Vertex distances from source 0:\n";
        for (int i = 0; i < V; ++i) std::cout << "  " << i << " : " << dist[i] << "\n";
    } else {
        std::cout << "Graph contains negative weight cycle!\n";
    }
    return 0;
}
