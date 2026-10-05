#include <iostream>

struct TNode {
    int val;
    TNode *left, *right;
    TNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorder(TNode* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void preorder(TNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

int main() {
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    std::cout << "Inorder: "; inorder(root); std::cout << "\n";
    return 0;
}
