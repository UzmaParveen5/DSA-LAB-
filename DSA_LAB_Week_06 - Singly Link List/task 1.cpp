
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


Node* head = nullptr;


void CreateNode(int value) {
    Node* newNode = new Node(value);

   
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;

       
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        
        temp->next = newNode;
    }
}


void Display() {
    Node* temp = head;

    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}


int main() {
    CreateNode(10);
    CreateNode(20);
    CreateNode(30);
    CreateNode(40);

    Display();

    return 0;
}
