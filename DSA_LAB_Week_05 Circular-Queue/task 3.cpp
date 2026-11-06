
#include <iostream>
#include <string>
using namespace std;


struct PrintJob {
    int jobID;
    string userName;
    int pages;
};


class PrinterQueue {
private:
    PrintJob* arr;
    int maxSize;
    int front;
    int rear;
    int currentSize;

public:

   
    PrinterQueue(int size) {
        maxSize = size;
        front = 0;
        rear = -1;
        currentSize = 0;

        arr = new PrintJob[maxSize];
    }

    
    ~PrinterQueue() {
        delete[] arr;
    }

    
    bool isEmpty() const {
        return currentSize == 0;
    }

  
    bool isFull() const {
        return currentSize == maxSize;
    }

    
    int totalJobs() const {
        return currentSize;
    }

    
    void enqueue(PrintJob p) {

        if (isFull()) {
            cout << "\nQueue Overflow! Printer queue is full.\n";
            return;
        }

        
        rear = (rear + 1) % maxSize;

        arr[rear] = p;
        currentSize++;

        cout << "\nPrint job submitted successfully!\n";
    }

   
    PrintJob dequeue() {

        if (isEmpty()) {
            cout << "\nQueue Underflow! No pending print jobs.\n";

            return { -1, "", 0 };
        }

        PrintJob completedJob = arr[front];

      
        front = (front + 1) % maxSize;

        currentSize--;

       
        if (currentSize == 0) {
            front = 0;
            rear = -1;
        }

        return completedJob;
    }

    
    PrintJob peek() const {

        if (isEmpty()) {
            cout << "\nNo print job available.\n";

            return { -1, "", 0 };
        }

        return arr[front];
    }

    
    void display() const {

        if (isEmpty()) {
            cout << "\nNo pending print jobs.\n";
            return;
        }

        cout << "\n======= PENDING PRINT JOBS =======\n";

        for (int i = 0; i < currentSize; i++) {

            int index = (front + i) % maxSize;

            cout << "\nPrint Job " << i + 1 << endl;

            cout << "Job ID    : "
                << arr[index].jobID << endl;

            cout << "User Name : "
                << arr[index].userName << endl;

            cout << "Pages     : "
                << arr[index].pages << endl;
        }

        cout << "\n==================================\n";
    }
};


int main() {

    int size;

    cout << "Enter maximum printer queue capacity: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 1;
    }

    PrinterQueue printer(size);

    int choice;
    PrintJob p;

    do {

        cout << "\n====================================\n";
        cout << "       PRINTER JOB MANAGEMENT\n";
        cout << "====================================\n";

        cout << "1. Submit a New Print Job\n";
        cout << "2. Process the Next Print Job\n";
        cout << "3. Display the Next Print Job\n";
        cout << "4. Display All Pending Print Jobs\n";
        cout << "5. Show Total Pending Print Jobs\n";
        cout << "6. Exit\n";

        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "\nEnter Job ID: ";
            cin >> p.jobID;

            cout << "Enter User Name: ";
            cin >> ws;
            getline(cin, p.userName);

            cout << "Enter Number of Pages: ";
            cin >> p.pages;

            if (p.jobID <= 0 || p.pages <= 0) {
                cout << "\nInvalid Job ID or Page Count!\n";
                break;
            }

            printer.enqueue(p);

            break;

        case 2:

            if (!printer.isEmpty()) {

                p = printer.dequeue();

                cout << "\nPrint Job Processed Successfully!\n";

                cout << "Job ID    : "
                    << p.jobID << endl;

                cout << "User Name : "
                    << p.userName << endl;

                cout << "Pages     : "
                    << p.pages << endl;
            }
            else {
                printer.dequeue();
            }

            break;

        case 3:

            if (!printer.isEmpty()) {

                p = printer.peek();

                cout << "\n======= NEXT PRINT JOB =======\n";

                cout << "Job ID    : "
                    << p.jobID << endl;

                cout << "User Name : "
                    << p.userName << endl;

                cout << "Pages     : "
                    << p.pages << endl;
            }
            else {
                printer.peek();
            }

            break;

        case 4:

            printer.display();

            break;

        case 5:

            cout << "\nTotal Pending Print Jobs: "
                << printer.totalJobs() << endl;

            break;

        case 6:

            cout << "\nExiting Printer Management System...\n";

            break;

        default:

            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
