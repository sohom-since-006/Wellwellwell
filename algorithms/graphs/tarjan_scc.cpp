#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void sccUtil(int u, const std::vector<std::vector<int>>& adj, std::vector<int>& disc,
             std::vector<int>& low, std::stack<int>& st, std::vector<bool>& inStack, int& timer) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            sccUtil(v, adj, disc, low, st, inStack, timer);
            low[u] = std::min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        std::cout << "SCC: ";
        while (true) {
            int w = st.top();
            st.pop();
            inStack[w] = false;
            std::cout << w << " ";
            if (u == w) break;
        }
        std::cout << "\n";
    }
}

void tarjanSCC(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<int> disc(V, -1), low(V, -1);
    std::vector<bool> inStack(V, false);
    std::stack<int> st;
    int timer = 0;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1) sccUtil(i, adj, disc, low, st, inStack, timer);
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

    std::cout << "Strongly Connected Components:\n";
    tarjanSCC(V, adj);
    return 0;
}
