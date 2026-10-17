#include <iostream>
#include <vector>

void generateSubsets(const std::vector<int>& set) {
    int n = set.size();
    int total = 1 << n;
    std::cout << "Subsets:\n";
    for (int mask = 0; mask < total; ++mask) {
        std::cout << "{ ";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) std::cout << set[i] << " ";
        }
        std::cout << "}\n";
    }
}

int main() {
    generateSubsets({1, 2, 3});
    return 0;
}
