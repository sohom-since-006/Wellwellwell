#include <iostream>

class CircularQueue {
    int* arr;
    int front, rear, size, capacity;
public:
    CircularQueue(int k) : capacity(k), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }
    ~CircularQueue() { delete[] arr; }
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    int Front() { return isEmpty() ? -1 : arr[front]; }
    int Rear() { return isEmpty() ? -1 : arr[rear]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};

int main() {
    CircularQueue cq(3);
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << "\n";
    return 0;
}
