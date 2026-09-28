#include <iostream>

template <typename T, size_t Cap>
class LinearQueue {
    T arr[Cap];
    int frontIdx, rearIdx;
public:
    LinearQueue() : frontIdx(0), rearIdx(-1) {}
    void enqueue(const T& val) {
        if (rearIdx + 1 >= static_cast<int>(Cap)) return;
        arr[++rearIdx] = val;
    }
    T dequeue() {
        if (empty()) return T();
        return arr[frontIdx++];
    }
    bool empty() const { return frontIdx > rearIdx; }
};

int main() {
    LinearQueue<int, 5> q;
    q.enqueue(10);
    q.enqueue(20);
    std::cout << "Dequeued: " << q.dequeue() << "\n";
    return 0;
}
