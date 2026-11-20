#include <iostream>
#include <vector>

class FenwickTree {
    int n;
    std::vector<int> tree;
public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void update(int i, int delta) {
        for (++i; i <= n; i += i & (-i)) {
            tree[i] += delta;
        }
    }

    int query(int i) const {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }

    int queryRange(int l, int r) const {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

int main() {
    std::vector<int> arr = {2, 1, 4, 6, 3, 7, 5};
    FenwickTree bit(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) bit.update(i, arr[i]);

    std::cout << "Sum [0, 4]: " << bit.queryRange(0, 4) << "\n";
    bit.update(2, 6); // Add 6 to element at index 2
    std::cout << "Sum [0, 4] after update: " << bit.queryRange(0, 4) << "\n";
    return 0;
}
