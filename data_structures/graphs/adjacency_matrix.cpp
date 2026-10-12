#include <iostream>
#include <vector>

class GraphAdjMatrix {
    int V;
    std::vector<std::vector<int>> matrix;
public:
    GraphAdjMatrix(int vertices) : V(vertices), matrix(vertices, std::vector<int>(vertices, 0)) {}
    void addEdge(int u, int v) {
        if (u < V && v < V) {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
    bool hasEdge(int u, int v) const {
        return (u < V && v < V) ? matrix[u][v] == 1 : false;
    }
};

int main() {
    GraphAdjMatrix g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    std::cout << "Has Edge (0,1): " << (g.hasEdge(0, 1) ? "Yes" : "No") << "\n";
    return 0;
}
