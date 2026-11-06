
#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int patientID;
    string patientName;
    Node* next;

    Node(int id, string name) {
        patientID = id;
        patientName = name;
        next = nullptr;
    }
};


class HospitalQueue {
private:
    Node* head;

public:
    
    HospitalQueue() {
        head = nullptr;
    }

    
    void addPatient(int id, string name) {
        Node* newNode = new Node(id, name);

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

        cout << "Patient " << name
            << " added successfully!" << endl;
    }

    
    void removePatient(int id) {
        if (head == nullptr) {
            cout << "No patients in the queue!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        
        while (temp != nullptr &&
            temp->patientID != id) {
            prev = temp;
            temp = temp->next;
        }

        
        if (temp == nullptr) {
            cout << "Patient ID not found!" << endl;
            return;
        }

      
        if (prev == nullptr) {
            head = head->next;
        }
        else {
            prev->next = temp->next;
        }

        cout << "Patient " << temp->patientName
            << " removed successfully!" << endl;

        delete temp;
    }

    
    void displayPatients() {
        if (head == nullptr) {
            cout << "No patients waiting!" << endl;
            return;
        }

        Node* temp = head;

        cout << "\nCurrent Patient Queue:\n";

        while (temp != nullptr) {
            cout << "Patient ID: " << temp->patientID
                << " | Name: " << temp->patientName
                << endl;

            temp = temp->next;
        }
    }

    
    void countPatients() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total patients in queue: "
            << count << endl;
    }

    
    ~HospitalQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    HospitalQueue hospital;

    int choice, id;
    string name;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM ====="
            << endl;

        cout << "1. Add New Patient" << endl;
        cout << "2. Remove Patient (Cancel Appointment)" << endl;
        cout << "3. Display Patient Queue" << endl;
        cout << "4. Count Total Patients" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin >> ws;
            getline(cin, name);

            hospital.addPatient(id, name);
            break;

        case 2:
            cout << "Enter Patient ID to remove: ";
            cin >> id;

            hospital.removePatient(id);
            break;

        case 3:
            hospital.displayPatients();
            break;

        case 4:
            hospital.countPatients();
            break;

        case 5:
            cout << "Exiting Hospital Management System!"
                << endl;
            break;

        default:
            cout << "Invalid choice! Try again."
                << endl;
        }

    } while (choice != 5);

    return 0;
}
