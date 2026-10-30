
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PrintQueue {
private:
    queue<string> documents;

public:

   
    void enqueue(string document_name) {

        if (document_name.empty()) {
            cout << "Document name cannot be empty!" << endl;
            return;
        }

        documents.push(document_name);

        cout << document_name
            << " added to print queue successfully!"
            << endl;
    }

   
    void dequeue() {

        if (documents.empty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "Printing Document: "
            << documents.front() << endl;

        documents.pop();

        cout << "Document printed successfully!"
            << endl;
    }

   
    void front() {

        if (documents.empty()) {
            cout << "No documents in print queue!"
                << endl;
            return;
        }

        cout << "Next Document to Print: "
            << documents.front() << endl;
    }

 
    void display() {

        if (documents.empty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        queue<string> temp = documents;

        cout << "\nPending Print Jobs:" << endl;

        while (!temp.empty()) {

            cout << temp.front() << endl;

            temp.pop();
        }
    }

    
    bool isEmpty() {
        return documents.empty();
    }
};


int main() {

    PrintQueue printer;

    int choice;
    string document_name;

    do {

        cout << "\n===== DOCUMENT PRINTING SYSTEM ====="
            << endl;

        cout << "1. Add Print Job" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. Check Next Document" << endl;
        cout << "4. Display Print Queue" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice) {

        case 1:
            cout << "Enter Document Name: ";
            getline(cin, document_name);

            printer.enqueue(document_name);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            cout << "Exiting Document Printing System..."
                << endl;
            break;

        default:
            cout << "Invalid Choice! Please try again."
                << endl;
        }

    } while (choice != 5);

    return 0;
}
