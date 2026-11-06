
#include <iostream>
#include <string>
using namespace std;


class myCarStack {
private:
    string* cars;
    int maxSize;
    int currentSize;

public:

    
    myCarStack(int size) {
        maxSize = size;
        currentSize = 0;
        cars = new string[maxSize];
    }

    
    ~myCarStack() {
        delete[] cars;
    }

   
    bool isEmpty() const {
        return currentSize == 0;
    }

    
    bool isFull() const {
        return currentSize == maxSize;
    }

  
    int totalCars() const {
        return currentSize;
    }

    
    void push(string carNumber) {

        if (isFull()) {
            cout << "\nParking Lot is Full! Cannot park more cars.\n";
            return;
        }

        cars[currentSize] = carNumber;
        currentSize++;

        cout << "\nCar " << carNumber
            << " parked successfully!\n";
    }

   
    string pop() {

        if (isEmpty()) {
            cout << "\nParking Lot is Empty!\n";
            return "";
        }

        currentSize--;

        string carNumber = cars[currentSize];

        return carNumber;
    }

  
    string top() const {

        if (isEmpty()) {
            return "";
        }

        return cars[currentSize - 1];
    }

   
    bool search(string carNumber) const {

        for (int i = 0; i < currentSize; i++) {

            if (cars[i] == carNumber) {
                return true;
            }
        }

        return false;
    }

    
    void display() const {

        if (isEmpty()) {
            cout << "\nParking Lot is Empty!\n";
            return;
        }

        cout << "\n===== PARKED CARS =====\n";

        for (int i = currentSize - 1; i >= 0; i--) {

            if (i == currentSize - 1) {
                cout << cars[i] << "  <-- TOP (Exit)\n";
            }
            else {
                cout << cars[i] << endl;
            }
        }

        cout << "=======================\n";
    }

    
    void removeCar(string carNumber) {

        if (isEmpty()) {
            cout << "\nParking Lot is Empty!\n";
            return;
        }

       
        if (!search(carNumber)) {
            cout << "\nCar " << carNumber
                << " not found in parking lot.\n";
            return;
        }

        
        myCarStack temp(maxSize);

     
        while (top() != carNumber) {
            temp.push(pop());
        }

        
        string removedCar = pop();

        cout << "\nCar " << removedCar
            << " removed successfully!\n";

       
        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};


int main() {

    myCarStack parking(8);

    int choice;
    string carNumber;

    do {

        cout << "\n=================================\n";
        cout << "     PARKING LOT MANAGEMENT\n";
        cout << "=================================\n";

        cout << "1. Park a New Car\n";
        cout << "2. Remove a Car by Car Number\n";
        cout << "3. Search for a Car\n";
        cout << "4. View Currently Parked Cars\n";
        cout << "5. View Total Cars Parked\n";
        cout << "6. View Car at Exit (Top)\n";
        cout << "7. Check if Parking Lot is Full\n";
        cout << "8. Check if Parking Lot is Empty\n";
        cout << "9. Exit\n";

        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Car Number: ";
            cin >> carNumber;

           
            if (parking.search(carNumber)) {
                cout << "\nThis car is already parked!\n";
            }
            else {
                parking.push(carNumber);
            }

            break;

        case 2:

            cout << "Enter Car Number to Remove: ";
            cin >> carNumber;

            parking.removeCar(carNumber);

            break;

        case 3:

            cout << "Enter Car Number to Search: ";
            cin >> carNumber;

            if (parking.search(carNumber)) {
                cout << "\nCar " << carNumber
                    << " is present in parking lot.\n";
            }
            else {
                cout << "\nCar " << carNumber
                    << " is not present in parking lot.\n";
            }

            break;

        case 4:

            parking.display();

            break;

        case 5:

            cout << "\nTotal Cars Parked: "
                << parking.totalCars() << " / 8\n";

            break;

        case 6:

            if (parking.isEmpty()) {
                cout << "\nParking Lot is Empty!\n";
            }
            else {
                cout << "\nCar at Exit (Top): "
                    << parking.top() << endl;
            }

            break;

        case 7:

            if (parking.isFull()) {
                cout << "\nParking Lot is Full!\n";
            }
            else {
                cout << "\nParking Lot is Not Full.\n";
            }

            break;

        case 8:

            if (parking.isEmpty()) {
                cout << "\nParking Lot is Empty!\n";
            }
            else {
                cout << "\nParking Lot is Not Empty.\n";
            }

            break;

        case 9:

            cout << "\nThank you for using Parking Lot Management System!\n";

            break;

        default:

            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
