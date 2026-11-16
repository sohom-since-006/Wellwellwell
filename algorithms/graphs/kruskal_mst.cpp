#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSetUnion {
    std::vector<int> parent, rank;
public:
    DisjointSetUnion(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else { parent[rootY] = rootX; rank[rootX]++; }
        return true;
    }
};

int kruskalMST(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    DisjointSetUnion dsu(n);
    int mstWeight = 0;
    int edgesCount = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesCount++;
            if (edgesCount == n - 1) break;
        }
    }
    return mstWeight;
}

int main() {
    int n = 4;
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int mstCost = kruskalMST(n, edges);
    std::cout << "Kruskal Minimum Spanning Tree Total Weight: " << mstCost << "\n";
    return 0;
}
