#include <iostream>
#include <stack>
#include <stdexcept>

class MinStack {
    std::stack<int> mainStack;
    std::stack<int> minStack;
public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    void pop() {
        if (mainStack.empty()) throw std::underflow_error("Stack is empty");
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    int top() const {
        return mainStack.top();
    }
    int getMin() const {
        return minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(18);
    ms.push(19);
    ms.push(29);
    ms.push(15);
    ms.push(16);

    std::cout << "Current Min: " << ms.getMin() << "\n";
    ms.pop(); // Pop 16
    ms.pop(); // Pop 15
    std::cout << "Min after popping 15: " << ms.getMin() << "\n";
    return 0;
}
