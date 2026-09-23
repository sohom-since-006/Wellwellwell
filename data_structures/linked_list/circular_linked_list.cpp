#include <iostream>

struct CNode {
    int val;
    CNode* next;
    CNode(int v) : val(v), next(nullptr) {}
};

class CircularList {
    CNode* head;
public:
    CircularList() : head(nullptr) {}
    void insert(int v) {
        CNode* n = new CNode(v);
        if (!head) {
            head = n;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }
    void display() const {
        if (!head) return;
        CNode* temp = head;
        do {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "(head)\n";
    }
};

int main() {
    CircularList cl;
    cl.insert(1);
    cl.insert(2);
    cl.insert(3);
    cl.display();
    return 0;
}
