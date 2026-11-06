
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


class SinglyLinkedList {
private:
    Node* head;

public:
    
    SinglyLinkedList() {
        head = nullptr;
    }

    
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning." << endl;
    }

   
    void insertEnd(int value) {
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

        cout << value << " inserted at end." << endl;
    }

    
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        
        if (head->data == value) {
            head = head->next;
            delete temp;

            cout << value << " deleted successfully." << endl;
            return;
        }

        Node* prev = nullptr;

       
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        
        if (temp == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }

        
        prev->next = temp->next;
        delete temp;

        cout << value << " deleted successfully." << endl;
    }

    
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    
    ~SinglyLinkedList() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    SinglyLinkedList list;

    list.insertBeginning(20);
    list.insertBeginning(10);

    list.insertEnd(30);
    list.insertEnd(40);

    list.display();

    list.deleteNode(30);

    list.display();

    return 0;
}
