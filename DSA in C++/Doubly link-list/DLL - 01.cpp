#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class List{
    public:
    Node* head;

    List(){
        this->head = NULL;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data <<" ";
            temp = temp->next;
        } 
    }

    void insertAtStart(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        if(head != NULL){
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtPosition(int data, int pos){
        if(pos == 0){
            insertAtStart(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        int currentPos = 0;

        while(currentPos != pos-1){
            temp = temp->next;
            currentPos++;
        }
        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtStart(){
        Node* temp = head; 
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd(){ 
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->prev != NULL){
            temp->prev->next = NULL;
        }
        delete temp;
    }

    void deleteAtPosition(int pos){
        if(pos == 0){
            deleteAtStart();
            return;
        }
        int currentPos = 0;
        Node* temp = head;
        while(currentPos != pos){
            temp = temp->next; 
            currentPos++;
        }
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        if(temp->prev != NULL){
            temp->prev->next = temp->next;
        }
        delete temp;
    }
};

int main(){
    List list;

    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.display();
    cout<<endl;

    list.insertAtStart(2);
    list.insertAtStart(1);
    list.display();
    cout<<endl;

    list.insertAtPosition(34, 3);
    list.display();
    cout<<endl;

    list.deleteAtStart();
    list.display();
    cout<<endl;

    list.deleteAtEnd();
    list.display();
    cout<<endl;

    list.deleteAtPosition(2);
    list.display();

    return 0;
}