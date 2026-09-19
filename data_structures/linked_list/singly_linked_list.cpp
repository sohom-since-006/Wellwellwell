#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
    void insertFront(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);
    list.print();
    return 0;
}
