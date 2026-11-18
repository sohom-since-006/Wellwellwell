#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

int primMST(int V, const std::vector<std::vector<std::pair<int, int>>>& adj) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<int> key(V, INF);
    std::vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;
    int mstWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += w;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return mstWeight;
}

int main() {
    int V = 5;
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    adj[0].push_back({1, 2}); adj[1].push_back({0, 2});
    adj[0].push_back({3, 6}); adj[3].push_back({0, 6});
    adj[1].push_back({2, 3}); adj[2].push_back({1, 3});
    adj[1].push_back({3, 8}); adj[3].push_back({1, 8});
    adj[1].push_back({4, 5}); adj[4].push_back({1, 5});
    adj[2].push_back({4, 7}); adj[4].push_back({2, 7});
    adj[3].push_back({4, 9}); adj[4].push_back({3, 9});

    std::cout << "Prim MST Total Weight: " << primMST(V, adj) << "\n";
    return 0;
}
