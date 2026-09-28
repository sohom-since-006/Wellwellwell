#include <iostream>
#include <stack>
#include <string>

int evaluatePostfix(const std::string& exp) {
    std::stack<int> st;
    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
            }
        }
    }
    return st.top();
}

int main() {
    std::string exp = "231*+9-";
    std::cout << "Evaluated: " << evaluatePostfix(exp) << "\n";
    return 0;
}
