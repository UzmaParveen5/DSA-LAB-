
#include <iostream>
#include <string>
using namespace std;


struct Customer {
    string name;
    string transaction;
};


class BankQueue {
private:
    Customer* arr;
    int maxSize;
    int front;
    int rear;
    int currentSize;

public:

   
    BankQueue(int size) {
        maxSize = size;
        front = 0;
        rear = -1;
        currentSize = 0;

        arr = new Customer[maxSize];
    }

   
    ~BankQueue() {
        delete[] arr;
    }

    
    bool isEmpty() const {
        return currentSize == 0;
    }

    
    bool isFull() const {
        return currentSize == maxSize;
    }

    
    int totalCustomers() const {
        return currentSize;
    }

   
    void enqueue(Customer c) {

        if (isFull()) {
            cout << "\nQueue Overflow! Bank waiting area is full.\n";
            return;
        }

        
        rear = (rear + 1) % maxSize;

        arr[rear] = c;
        currentSize++;

        cout << "\nCustomer " << c.name
            << " added to the queue successfully.\n";
    }

   
    Customer dequeue() {

        if (isEmpty()) {
            cout << "\nQueue Underflow! No customer is waiting.\n";

            return { "", "" };
        }

        Customer servedCustomer = arr[front];

        
        front = (front + 1) % maxSize;

        currentSize--;

        
        if (currentSize == 0) {
            front = 0;
            rear = -1;
        }

        return servedCustomer;
    }

    
    void display() const {

        if (isEmpty()) {
            cout << "\nNo customers are waiting.\n";
            return;
        }

        cout << "\n======= BANK CUSTOMER QUEUE =======\n";

        for (int i = 0; i < currentSize; i++) {

            int index = (front + i) % maxSize;

            cout << "\nCustomer " << i + 1 << endl;
            cout << "Name        : " << arr[index].name << endl;
            cout << "Transaction : " << arr[index].transaction << endl;
        }

        cout << "\n===================================\n";
    }
};


int main() {

    int size;

    cout << "Enter maximum queue capacity: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 1;
    }

    BankQueue bank(size);

    int choice;
    Customer c;

    do {

        cout << "\n====================================\n";
        cout << "     BANK CUSTOMER MANAGEMENT\n";
        cout << "====================================\n";

        cout << "1. Add a Customer (Enqueue)\n";
        cout << "2. Serve a Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Show Total Waiting Customers\n";
        cout << "5. Check if Queue is Empty\n";
        cout << "6. Check if Queue is Full\n";
        cout << "7. Exit\n";

        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "\nEnter Customer Name: ";
            cin >> ws;
            getline(cin, c.name);

            cout << "Enter Transaction Type: ";
            getline(cin, c.transaction);

            bank.enqueue(c);

            break;

        case 2:

            if (!bank.isEmpty()) {

                c = bank.dequeue();

                cout << "\nCustomer Served Successfully!\n";
                cout << "Customer Name : " << c.name << endl;
                cout << "Transaction   : " << c.transaction << endl;
            }
            else {
                bank.dequeue();
            }

            break;

        case 3:

            bank.display();

            break;

        case 4:

            cout << "\nTotal Customers Waiting: "
                << bank.totalCustomers() << endl;

            break;

        case 5:

            if (bank.isEmpty())
                cout << "\nQueue is Empty.\n";
            else
                cout << "\nQueue is Not Empty.\n";

            break;

        case 6:

            if (bank.isFull())
                cout << "\nQueue is Full.\n";
            else
                cout << "\nQueue is Not Full.\n";

            break;

        case 7:

            cout << "\nThank you for using Bank Management System!\n";

            break;

        default:

            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
