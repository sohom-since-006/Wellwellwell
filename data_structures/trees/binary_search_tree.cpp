#include <iostream>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

bool search(TreeNode* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    std::cout << "Search 30: " << (search(root, 30) ? "Found" : "Not Found") << "\n";
    return 0;
}
