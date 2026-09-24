#include <iostream>

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int d, StackNode* n) : data(d), next(n) {}
};

class LinkedStack {
    StackNode* topNode;
public:
    LinkedStack() : topNode(nullptr) {}
    ~LinkedStack() {
        while (!empty()) pop();
    }
    void push(int val) {
        topNode = new StackNode(val, topNode);
    }
    int pop() {
        if (empty()) return -1;
        StackNode* temp = topNode;
        int val = temp->data;
        topNode = topNode->next;
        delete temp;
        return val;
    }
    bool empty() const { return topNode == nullptr; }
};

int main() {
    LinkedStack s;
    s.push(42);
    s.push(84);
    std::cout << "Popped: " << s.pop() << ", Popped: " << s.pop() << "\n";
    return 0;
}
