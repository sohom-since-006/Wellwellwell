#include <iostream>
#include <vector>

const int INF = 1e9;

void floydWarshall(int V, std::vector<std::vector<int>>& dist) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int V = 4;
    std::vector<std::vector<int>> matrix = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(V, matrix);

    std::cout << "All-Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] == INF) std::cout << "INF ";
            else std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
