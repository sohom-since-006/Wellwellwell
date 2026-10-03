#include <iostream>

class SimpleDeque {
    int arr[100];
    int front, rear, size, cap;
public:
    SimpleDeque(int c = 100) : cap(c), front(-1), rear(0), size(0) {}
    void insertRear(int val) {
        if (size == cap) return;
        if (front == -1) { front = 0; rear = 0; }
        else rear = (rear + 1) % cap;
        arr[rear] = val;
        size++;
    }
    void insertFront(int val) {
        if (size == cap) return;
        if (front == -1) { front = 0; rear = 0; }
        else front = (front - 1 + cap) % cap;
        arr[front] = val;
        size++;
    }
    int getFront() { return size == 0 ? -1 : arr[front]; }
    int getRear() { return size == 0 ? -1 : arr[rear]; }
};

int main() {
    SimpleDeque dq;
    dq.insertFront(10);
    dq.insertRear(20);
    std::cout << "Front: " << dq.getFront() << ", Rear: " << dq.getRear() << "\n";
    return 0;
}
