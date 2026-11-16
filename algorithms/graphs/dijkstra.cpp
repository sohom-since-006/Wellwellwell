#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

struct Edge {
    int to, weight;
};

std::vector<int> dijkstra(int start, int n, const std::vector<std::vector<Edge>>& adj) {
    std::vector<int> dist(n, INF);
    // Min-heap storing pair of (distance, vertex)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    std::vector<std::vector<Edge>> adj(n);
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    auto distances = dijkstra(0, n, adj);
    std::cout << "Shortest distances from source node 0:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "  Node " << i << ": " << distances[i] << "\n";
    }
    return 0;
}
