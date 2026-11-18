#include <iostream>
#include <vector>

bool isCyclicDFS(int u, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (isCyclicDFS(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirected(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && isCyclicDFS(i, -1, adj, visited)) return true;
    }
    return false;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    adj[1].push_back(0); adj[0].push_back(1);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[2].push_back(1); adj[1].push_back(2);
    adj[0].push_back(3); adj[3].push_back(0);
    adj[3].push_back(4); adj[4].push_back(3);

    std::cout << "Undirected graph has cycle: " << (hasCycleUndirected(V, adj) ? "Yes" : "No") << "\n";
    return 0;
}
