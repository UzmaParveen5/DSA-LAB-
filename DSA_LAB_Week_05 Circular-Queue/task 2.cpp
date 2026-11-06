
#include <iostream>
#include <string>
using namespace std;


struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};


class CinemaQueue {
private:
    Booking* arr;
    int maxSize;
    int front;
    int rear;
    int currentSize;

public:

    
    CinemaQueue(int size) {
        maxSize = size;
        front = 0;
        rear = -1;
        currentSize = 0;

        arr = new Booking[maxSize];
    }

    
    ~CinemaQueue() {
        delete[] arr;
    }

   
    bool isEmpty() const {
        return currentSize == 0;
    }

    
    bool isFull() const {
        return currentSize == maxSize;
    }

    
    int totalBookings() const {
        return currentSize;
    }

    
    void enqueue(Booking b) {

        if (isFull()) {
            cout << "\nBooking Queue is Full! "
                << "Cannot accept more bookings.\n";
            return;
        }

        
        rear = (rear + 1) % maxSize;

        arr[rear] = b;
        currentSize++;

        cout << "\nBooking added successfully!\n";
    }

   
    Booking dequeue() {

        if (isEmpty()) {
            cout << "\nQueue Underflow! No bookings available.\n";

            return { -1, "", 0 };
        }

        Booking cancelledBooking = arr[front];

        
        front = (front + 1) % maxSize;

        currentSize--;

        
        if (currentSize == 0) {
            front = 0;
            rear = -1;
        }

        return cancelledBooking;
    }

    
    Booking peek() const {

        if (isEmpty()) {
            cout << "\nNo booking available at the front.\n";

            return { -1, "", 0 };
        }

        return arr[front];
    }

    
    void display() const {

        if (isEmpty()) {
            cout << "\nNo bookings available.\n";
            return;
        }

        cout << "\n======= CINEMA BOOKINGS =======\n";

        for (int i = 0; i < currentSize; i++) {

            int index = (front + i) % maxSize;

            cout << "\nBooking " << i + 1 << endl;

            cout << "Customer ID      : "
                << arr[index].customerID << endl;

            cout << "Customer Name    : "
                << arr[index].customerName << endl;

            cout << "Number of Tickets: "
                << arr[index].numberOfTickets << endl;
        }

        cout << "\n===============================\n";
    }
};


int main() {

    int size;

    cout << "Enter maximum number of bookings: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 1;
    }

    CinemaQueue cinema(size);

    int choice;
    Booking b;

    do {

        cout << "\n====================================\n";
        cout << "     CINEMA TICKET BOOKING SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Book Tickets\n";
        cout << "2. Cancel the First Booking\n";
        cout << "3. Display the Next Booking\n";
        cout << "4. Display All Bookings\n";
        cout << "5. Show Total Number of Bookings\n";
        cout << "6. Exit\n";

        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "\nEnter Customer ID: ";
            cin >> b.customerID;

            cout << "Enter Customer Name: ";
            cin >> ws;
            getline(cin, b.customerName);

            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;

            if (b.customerID <= 0 ||
                b.numberOfTickets <= 0) {

                cout << "\nInvalid customer ID or ticket count!\n";
                break;
            }

            cinema.enqueue(b);

            break;

        case 2:

            if (!cinema.isEmpty()) {

                b = cinema.dequeue();

                cout << "\nBooking Cancelled Successfully!\n";

                cout << "Customer ID      : "
                    << b.customerID << endl;

                cout << "Customer Name    : "
                    << b.customerName << endl;

                cout << "Number of Tickets: "
                    << b.numberOfTickets << endl;
            }
            else {
                cinema.dequeue();
            }

            break;

        case 3:

            if (!cinema.isEmpty()) {

                b = cinema.peek();

                cout << "\n======= NEXT BOOKING =======\n";

                cout << "Customer ID      : "
                    << b.customerID << endl;

                cout << "Customer Name    : "
                    << b.customerName << endl;

                cout << "Number of Tickets: "
                    << b.numberOfTickets << endl;
            }
            else {
                cinema.peek();
            }

            break;

        case 4:

            cinema.display();

            break;

        case 5:

            cout << "\nTotal Number of Bookings: "
                << cinema.totalBookings() << endl;

            break;

        case 6:

            cout << "\nThank you for using Cinema Booking System!\n";

            break;

        default:

            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
