#include <iostream>
using namespace std;

struct Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class List {
public:
    Node* head;

    List() {
        this->head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        
    }

    void prepend(int data)
    {
        Node* newNode = new Node(data);
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void updateNode(int key, int newData)
    {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
        { 
            temp = temp->next;
        }
        if (temp != NULL)
        {
            temp->data = newData;
        }
    }

    void deleteNode(int key) {
    if (head == NULL) return; 

    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}
};

int main() {
    List list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.display();
    cout << endl;

    list.prepend(9);
    list.display();
    cout << endl;

    list.updateNode(2, 10);
    list.display();
    cout << endl;

    list.deleteNode(3);
    list.display();


    return 0;
}