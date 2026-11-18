#include <iostream>
#include <vector>
#include <stack>

void dfs1(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, const std::vector<std::vector<int>>& revAdj, std::vector<bool>& visited) {
    visited[u] = true;
    std::cout << u << " ";
    for (int v : revAdj[u]) {
        if (!visited[v]) dfs2(v, revAdj, visited);
    }
}

void findSCCs(int V, const std::vector<std::vector<int>>& adj) {
    std::stack<int> st;
    std::vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) dfs1(i, adj, visited, st);
    }

    std::vector<std::vector<int>> revAdj(V);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) revAdj[v].push_back(u);
    }

    std::fill(visited.begin(), visited.end(), false);
    std::cout << "Strongly Connected Components (Kosaraju):\n";
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            std::cout << "  Component: ";
            dfs2(u, revAdj, visited);
            std::cout << "\n";
        }
    }
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj(V);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    findSCCs(V, adj);
    return 0;
}
