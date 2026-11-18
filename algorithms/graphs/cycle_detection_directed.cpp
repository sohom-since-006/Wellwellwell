#include <iostream>
#include <vector>

bool isCyclicUtil(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v] && isCyclicUtil(v, adj, visited, recStack)) return true;
        else if (recStack[v]) return true;
    }

    recStack[u] = false;
    return false;
}

bool hasCycleDirected(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(V, false);
    std::vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && isCyclicUtil(i, adj, visited, recStack)) return true;
    }
    return false;
}

int main() {
    int V = 4;
    std::vector<std::vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);

    std::cout << "Directed graph contains cycle: " << (hasCycleDirected(V, adj) ? "Yes" : "No") << "\n";
    return 0;
}
