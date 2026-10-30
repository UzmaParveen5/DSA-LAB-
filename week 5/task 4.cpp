
#include <iostream>
#include <queue>
using namespace std;

class CustomerSupport {
private:
    queue<int> tickets;

public:


    void enqueue(int ticket_id) {

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Enter a 4-digit ID."
                << endl;
            return;
        }

        
        queue<int> temp = tickets;

        while (!temp.empty()) {
            if (temp.front() == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
            temp.pop();
        }

        tickets.push(ticket_id);

        cout << "Ticket #" << ticket_id
            << " added successfully!" << endl;
    }

    
    void dequeue() {

        if (tickets.empty()) {
            cout << "No pending tickets to resolve!"
                << endl;
            return;
        }

        cout << "Ticket #" << tickets.front()
            << " has been resolved." << endl;

        tickets.pop();
    }

   
    void front() {

        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Next ticket to resolve: #"
            << tickets.front() << endl;
    }

    
    void display() {

        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        queue<int> temp = tickets;

        cout << "\nPending Support Tickets:" << endl;

        while (!temp.empty()) {
            cout << "Ticket #" << temp.front() << endl;
            temp.pop();
        }
    }

    
    bool isEmpty() {
        return tickets.empty();
    }
};


int main() {

    CustomerSupport cs;
    int choice, ticket_id;

    do {

        cout << "\n===== CUSTOMER SUPPORT TICKET SYSTEM ====="
            << endl;

        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Check Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;

            cs.enqueue(ticket_id);
            break;

        case 2:
            cs.dequeue();
            break;

        case 3:
            cs.front();
            break;

        case 4:
            cs.display();
            break;

        case 5:
            cout << "Exiting Customer Support System..."
                << endl;
            break;

        default:
            cout << "Invalid Choice! Please try again."
                << endl;
        }

    } while (choice != 5);

    return 0;
}
