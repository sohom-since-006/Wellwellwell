#include <iostream>
#include <vector>
#include <queue>

bool isBipartite(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<int> color(V, -1);

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            std::queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4;
    std::vector<std::vector<int>> adj(V);
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(3); adj[3].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);

    std::cout << "Graph is bipartite: " << (isBipartite(V, adj) ? "True" : "False") << "\n";
    return 0;
}
