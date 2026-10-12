#include <iostream>

struct BSTNode {
    int val;
    BSTNode *left, *right;
    BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

BSTNode* findMin(BSTNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

BSTNode* deleteNode(BSTNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            BSTNode* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            BSTNode* l = root->left;
            delete root;
            return l;
        }
        BSTNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() {
    BSTNode* root = new BSTNode(5);
    root->left = new BSTNode(3);
    root->right = new BSTNode(6);
    root = deleteNode(root, 3);
    std::cout << "Root after deletion: " << root->val << "\n";
    return 0;
}
