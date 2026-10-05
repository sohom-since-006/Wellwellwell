#include <iostream>
#include <queue>

struct BNode {
    int data;
    BNode *left, *right;
    BNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

void levelOrder(BNode* root) {
    if (!root) return;
    std::queue<BNode*> q;
    q.push(root);
    while (!q.empty()) {
        BNode* curr = q.front();
        q.pop();
        std::cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    std::cout << "\n";
}

int main() {
    BNode* root = new BNode(10);
    root->left = new BNode(20);
    root->right = new BNode(30);
    std::cout << "Level Order: ";
    levelOrder(root);
    return 0;
}
