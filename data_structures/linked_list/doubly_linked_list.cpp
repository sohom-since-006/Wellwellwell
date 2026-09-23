#include <iostream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr) {
            DNode* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
    void pushBack(int val) {
        DNode* n = new DNode(val);
        if (!head) {
            head = n;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }
    void printForward() const {
        DNode* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.pushBack(100);
    dll.pushBack(200);
    dll.pushBack(300);
    dll.printForward();
    return 0;
}
