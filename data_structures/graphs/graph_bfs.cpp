#include <iostream>
#include <vector>
#include <queue>

void bfs(int start, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    std::cout << "BFS Order: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    bfs(0, adj);
    return 0;
}
