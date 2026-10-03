#include <iostream>
#include <vector>

class MinPriorityQueue {
    std::vector<int> heap;
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] < heap[p]) {
                std::swap(heap[i], heap[p]);
                i = p;
            } else break;
        }
    }
    void siftDown(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
            if (right < n && heap[right] < heap[left]) smallest = right;
            if (heap[smallest] < heap[i]) {
                std::swap(heap[i], heap[smallest]);
                i = smallest;
            } else break;
        }
    }
public:
    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }
    int pop() {
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
        return top;
    }
    bool empty() const { return heap.empty(); }
};

int main() {
    MinPriorityQueue pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);
    std::cout << "Min-extracted: " << pq.pop() << "\n";
    return 0;
}
