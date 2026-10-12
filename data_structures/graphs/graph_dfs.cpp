#include <iostream>
#include <vector>

void dfsHelper(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    std::cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsHelper(v, adj, visited);
        }
    }
}

void dfs(int start, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);
    std::cout << "DFS Order: ";
    dfsHelper(start, adj, visited);
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    dfs(0, adj);
    return 0;
}
