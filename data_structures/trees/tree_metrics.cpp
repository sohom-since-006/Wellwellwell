#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    std::cout << "Height: " << getHeight(root) << ", Node Count: " << countNodes(root) << "\n";
    return 0;
}
