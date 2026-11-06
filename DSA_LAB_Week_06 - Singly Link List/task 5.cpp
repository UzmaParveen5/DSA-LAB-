
#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int studentID;
    string studentName;
    int priority;
    Node* next;

    Node(int id, string name, int p) {
        studentID = id;
        studentName = name;
        priority = p;
        next = nullptr;
    }
};


class ReservationQueue {
private:
    Node* head;

public:
    
    ReservationQueue() {
        head = nullptr;
    }

   
    void addStudent(int id, string name, int priority) {
        Node* newNode = new Node(id, name, priority);

        
        
        if (head == nullptr ||
            priority < head->priority) {

            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;

           
            while (temp->next != nullptr &&
                temp->next->priority <= priority) {

                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Student " << name
            << " added successfully!" << endl;
    }

    
    void removeStudent(int id) {
        if (head == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

       
        while (temp != nullptr &&
            temp->studentID != id) {

            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

       
        if (prev == nullptr) {
            head = head->next;
        }
        else {
            prev->next = temp->next;
        }

        cout << "Reservation cancelled for "
            << temp->studentName << endl;

        delete temp;
    }

    
    void updatePriority(int id, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority!" << endl;
            return;
        }

        if (head == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        Node* temp = head;
        string name;

        
        while (temp != nullptr &&
            temp->studentID != id) {

            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        name = temp->studentName;

        
        removeStudent(id);

        
        addStudent(id, name, newPriority);

        cout << "Priority updated successfully!" << endl;
    }

    
    void displayQueue() {
        if (head == nullptr) {
            cout << "No students waiting!" << endl;
            return;
        }

        Node* temp = head;

        cout << "\nReservation List:\n";

        while (temp != nullptr) {

            cout << "ID: " << temp->studentID
                << " | Name: " << temp->studentName
                << " | Priority: ";

            if (temp->priority == 1)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << endl;

            temp = temp->next;
        }
    }

   
    void countStudents() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total students waiting: "
            << count << endl;
    }

    
    void serveNextStudent() {
        if (head == nullptr) {
            cout << "No students waiting for this book!"
                << endl;
            return;
        }

        Node* temp = head;

        cout << "Book returned! Now serving student: "
            << temp->studentName
            << " (ID: " << temp->studentID << ")"
            << endl;

        head = head->next;

        delete temp;
    }

  
    ~ReservationQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


class Library {
private:
    ReservationQueue books[2];

public:

    
    void addReservation(int book, int id,
        string name, int priority) {

        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        books[book - 1].addStudent(id, name, priority);
    }

   
    void cancelReservation(int book, int id) {
        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        books[book - 1].removeStudent(id);
    }

   
    void changePriority(int book, int id, int priority) {
        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        books[book - 1].updatePriority(id, priority);
    }

   
    void displayBookQueue(int book) {
        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        cout << "\nBook " << book << " Reservation Queue";
        books[book - 1].displayQueue();
    }

   
    void countBookStudents(int book) {
        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        books[book - 1].countStudents();
    }

   
    void returnBook(int book) {
        if (book < 1 || book > 2) {
            cout << "Invalid book number!" << endl;
            return;
        }

        books[book - 1].serveNextStudent();
    }
};


int main() {
    Library library;

    int choice, book, id, priority;
    string name;

    do {
        cout << "\n===== UNIVERSITY LIBRARY SYSTEM =====\n";

        cout << "1. Add Student Reservation\n";
        cout << "2. Cancel Student Reservation\n";
        cout << "3. Update Student Priority\n";
        cout << "4. Display Reservation List\n";
        cout << "5. Count Waiting Students\n";
        cout << "6. Return Book / Serve Next Student\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Book Number (1 or 2): ";
            cin >> book;

            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Student Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Priority:\n";
            cout << "1. Research\n";
            cout << "2. Assignment\n";
            cout << "3. Casual Reading\n";

            cout << "Enter priority: ";
            cin >> priority;

            if (priority >= 1 && priority <= 3) {
                library.addReservation(
                    book, id, name, priority
                );
            }
            else {
                cout << "Invalid priority!" << endl;
            }
            break;

        case 2:
            cout << "Enter Book Number: ";
            cin >> book;

            cout << "Enter Student ID: ";
            cin >> id;

            library.cancelReservation(book, id);
            break;

        case 3:
            cout << "Enter Book Number: ";
            cin >> book;

            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter New Priority (1-3): ";
            cin >> priority;

            library.changePriority(book, id, priority);
            break;

        case 4:
            cout << "Enter Book Number: ";
            cin >> book;

            library.displayBookQueue(book);
            break;

        case 5:
            cout << "Enter Book Number: ";
            cin >> book;

            library.countBookStudents(book);
            break;

        case 6:
            cout << "Enter Book Number: ";
            cin >> book;

            library.returnBook(book);
            break;

        case 7:
            cout << "Exiting Library System!" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
