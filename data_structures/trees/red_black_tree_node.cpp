#include <iostream>

enum Color { RED, BLACK };

struct RBNode {
    int data;
    Color color;
    RBNode *left, *right, *parent;
    RBNode(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

bool validateRBProperties(RBNode* root, int& blackHeight, int currentBlackHeight = 0) {
    if (!root) {
        if (blackHeight == -1) blackHeight = currentBlackHeight;
        return blackHeight == currentBlackHeight;
    }

    if (root->color == RED) {
        if ((root->left && root->left->color == RED) || (root->right && root->right->color == RED)) {
            return false; // Consecutive red violation
        }
    }

    int nextBlackHeight = currentBlackHeight + (root->color == BLACK ? 1 : 0);
    return validateRBProperties(root->left, blackHeight, nextBlackHeight) &&
           validateRBProperties(root->right, blackHeight, nextBlackHeight);
}

int main() {
    RBNode* root = new RBNode(10);
    root->color = BLACK;
    root->left = new RBNode(5);
    root->right = new RBNode(20);

    int blackHeight = -1;
    bool isValid = validateRBProperties(root, blackHeight);
    std::cout << "Sample Red-Black tree is structurally valid: " << (isValid ? "True" : "False") << "\n";
    return 0;
}
