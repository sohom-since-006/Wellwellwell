#include <iostream>
#include <stdexcept>

template <typename T, size_t Capacity>
class ArrayStack {
    T arr[Capacity];
    int topIdx;
public:
    ArrayStack() : topIdx(-1) {}
    void push(const T& val) {
        if (topIdx + 1 >= static_cast<int>(Capacity)) throw std::overflow_error("Stack Overflow");
        arr[++topIdx] = val;
    }
    T pop() {
        if (empty()) throw std::underflow_error("Stack Underflow");
        return arr[topIdx--];
    }
    const T& top() const {
        if (empty()) throw std::underflow_error("Stack is empty");
        return arr[topIdx];
    }
    bool empty() const { return topIdx == -1; }
    size_t size() const { return topIdx + 1; }
};

int main() {
    ArrayStack<int, 10> st;
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << "Top: " << st.top() << ", Popped: " << st.pop() << "\n";
    return 0;
}
