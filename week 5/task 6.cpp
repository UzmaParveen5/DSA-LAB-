
#include <iostream>
#include <queue>
#include <string>
using namespace std;


struct Package {
    int packageID;
    string address;
    int startTime;
    int endTime;
};

class DeliverySystem {
private:
    queue<Package> packages;

public:

   
    void enqueue(int id, string address, int start, int end) {

        if (id < 1000 || id > 9999) {
            cout << "Package ID must be 4 digits!" << endl;
            return;
        }

        if (start < 0 || end > 23 || start >= end) {
            cout << "Invalid delivery time window!" << endl;
            return;
        }

        
        queue<Package> temp = packages;

        while (!temp.empty()) {
            if (temp.front().packageID == id) {
                cout << "Package ID already exists!" << endl;
                return;
            }
            temp.pop();
        }

        Package p;

        p.packageID = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;

        packages.push(p);

        cout << "Package added successfully!" << endl;
    }

    
    void dequeue() {

        if (packages.empty()) {
            cout << "No packages available!" << endl;
            return;
        }

        Package p = packages.front();

        cout << "\nPackage #" << p.packageID
            << " delivered successfully!" << endl;

        packages.pop();
    }

   
    void front() {

        if (packages.empty()) {
            cout << "No packages in queue!" << endl;
            return;
        }

        Package p = packages.front();

        cout << "\nNext Package Details:" << endl;
        cout << "Package ID: " << p.packageID << endl;
        cout << "Address: " << p.address << endl;
        cout << "Start Time: " << p.startTime << ":00" << endl;
        cout << "End Time: " << p.endTime << ":00" << endl;
    }

   
    void display() {

        if (packages.empty()) {
            cout << "No pending packages!" << endl;
            return;
        }

        queue<Package> temp = packages;

        cout << "\n===== PENDING PACKAGES =====" << endl;

        while (!temp.empty()) {

            Package p = temp.front();

            cout << "\nPackage ID: " << p.packageID << endl;
            cout << "Address: " << p.address << endl;
            cout << "Delivery Window: "
                << p.startTime << ":00 - "
                << p.endTime << ":00" << endl;

            temp.pop();
        }
    }

    
    void timeToDeliver(int currentTime) {

        if (currentTime < 0 || currentTime > 23) {
            cout << "Invalid current time!" << endl;
            return;
        }

        while (!packages.empty()) {

            Package p = packages.front();

           
            if (currentTime >= p.endTime) {

                cout << "\nPackage #" << p.packageID
                    << " has expired!" << endl;

                packages.pop();
            }

            
            else if (currentTime < p.startTime) {

                cout << "\nPackage #" << p.packageID
                    << " is not ready for delivery yet."
                    << endl;

                cout << "Delivery starts at "
                    << p.startTime << ":00" << endl;

                return;
            }

           
            else {

                cout << "\nPackage #" << p.packageID
                    << " can be delivered now!" << endl;

                cout << "Address: " << p.address << endl;

                return;
            }
        }

        cout << "No packages available for delivery."
            << endl;
    }

    
    bool isEmpty() {
        return packages.empty();
    }
};


int main() {

    DeliverySystem ds;

    int choice;
    int id, start, end, currentTime;
    string address;

    do {

        cout << "\n===== PACKAGE DELIVERY SYSTEM ====="
            << endl;

        cout << "1. Add New Package" << endl;
        cout << "2. Deliver Package" << endl;
        cout << "3. Check Next Package" << endl;
        cout << "4. Display All Packages" << endl;
        cout << "5. Check Delivery Time" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice) {

        case 1:

            cout << "Enter 4-digit Package ID: ";
            cin >> id;

            cin.ignore(10000, '\n');

            cout << "Enter Recipient Address: ";
            getline(cin, address);

            cout << "Enter Delivery Start Hour (0-23): ";
            cin >> start;

            cout << "Enter Delivery End Hour (0-23): ";
            cin >> end;

            ds.enqueue(id, address, start, end);
            break;

        case 2:

            ds.dequeue();
            break;

        case 3:

            ds.front();
            break;

        case 4:

            ds.display();
            break;

        case 5:

            cout << "Enter Current Hour (0-23): ";
            cin >> currentTime;

            ds.timeToDeliver(currentTime);
            break;

        case 6:

            cout << "Exiting Package Delivery System..."
                << endl;
            break;

        default:

            cout << "Invalid Choice! Try Again."
                << endl;
        }

    } while (choice != 6);

    return 0;
}
