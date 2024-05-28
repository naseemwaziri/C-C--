#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    Node* last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Element not found" << endl;
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (head == temp)
        head = temp->next;

    delete temp;
    return head;
}

void display(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 15);
    display(head);
    head = deleteNode(head, 10);
    display(head);
    return 0;
}