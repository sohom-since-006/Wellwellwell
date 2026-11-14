#include <iostream>
#include <vector>
#include <algorithm>

class SegmentTree {
    int n;
    std::vector<int> tree;
    void build(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = std::min(tree[2 * node], tree[2 * node + 1]);
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 1e9;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return std::min(query(2 * node, start, mid, l, r),
                        query(2 * node + 1, mid + 1, end, l, r));
    }
public:
    SegmentTree(const std::vector<int>& arr) : n(arr.size()), tree(4 * arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    int rangeMin(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree st(arr);
    std::cout << "Min in range [1, 5]: " << st.rangeMin(1, 5) << "\n";
    std::cout << "Min in range [2, 4]: " << st.rangeMin(2, 4) << "\n";
    return 0;
}
