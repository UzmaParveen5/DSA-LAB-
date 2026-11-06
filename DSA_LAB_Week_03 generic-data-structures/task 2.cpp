
#include <iostream>
using namespace std;


template <class Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:

    
    List(int size = 10, int current = 0) {
        maxSize = size;
        currentSize = 0;

        arr = new Type[maxSize];
    }

    /
    List(const List& other) {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    
    virtual void addElementAtFirstIndex(Type value) = 0;

    virtual void addElementAtLastIndex(Type value) = 0;

    virtual Type removeElementFromEnd() = 0;

    virtual void removeElementFromStart() = 0;

    
    virtual ~List() {
        delete[] arr;
    }
};



template <class Type>
class MyList : public List<Type> {

public:

   
    MyList(int size = 10, int current = 0)
        : List<Type>(size, current) {
    }

   
    MyList(const MyList& other)
        : List<Type>(other) {
    }

   
    bool empty() {
        return this->currentSize == 0;
    }

    
    bool full() {
        return this->currentSize == this->maxSize;
    }

    
    int size() {
        return this->currentSize;
    }

   
    void addElementAtFirstIndex(Type value) override {

        if (full()) {
            cout << "List is full!" << endl;
            return;
        }

        for (int i = this->currentSize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[0] = value;
        this->currentSize++;

        cout << "Element inserted at beginning." << endl;
    }


    void addElementAtLastIndex(Type value) override {

        if (full()) {
            cout << "List is full!" << endl;
            return;
        }

        this->arr[this->currentSize] = value;
        this->currentSize++;

        cout << "Element inserted at end." << endl;
    }

    
    Type removeElementFromEnd() override {

        if (empty()) {
            cout << "List is empty!" << endl;
            return Type();
        }

        Type value = this->arr[this->currentSize - 1];

        this->currentSize--;

        return value;
    }

    
    void removeElementFromStart() override {

        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < this->currentSize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->currentSize--;

        cout << "First element removed." << endl;
    }

    
    bool insertAt(int index, Type value) {

        if (full() || index < 0 ||
            index > this->currentSize) {
            return false;
        }

        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    
    Type last() {

        if (empty()) {
            cout << "List is empty!" << endl;
            return Type();
        }

        return this->arr[this->currentSize - 1];
    }

  
    bool search(Type value) {

        for (int i = 0; i < this->currentSize; i++) {

            if (this->arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    
    void display() {

        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List elements: ";

        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }

        cout << endl;
    }

};


// Main Function
int main() {

    MyList<int> list(10);

    int choice, value, index;

    do {

        cout << "\n===== MY LIST MENU =====\n";

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Remove from Beginning\n";
        cout << "4. Remove from End\n";
        cout << "5. Insert at Specific Index\n";
        cout << "6. Check if List is Empty\n";
        cout << "7. Check if List is Full\n";
        cout << "8. Display List Size\n";
        cout << "9. Get Last Element\n";
        cout << "10. Search Element\n";
        cout << "11. Display List\n";
        cout << "12. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;

            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;

            list.addElementAtLastIndex(value);
            break;

        case 3:
            list.removeElementFromStart();
            break;

        case 4:
            if (!list.empty()) {
                cout << "Removed element: "
                    << list.removeElementFromEnd() << endl;
            }
            else {
                cout << "List is empty!" << endl;
            }
            break;

        case 5:
            cout << "Enter index: ";
            cin >> index;

            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value)) {
                cout << "Element inserted successfully." << endl;
            }
            else {
                cout << "Invalid index or list is full!" << endl;
            }
            break;

        case 6:
            if (list.empty()) {
                cout << "List is empty." << endl;
            }
            else {
                cout << "List is not empty." << endl;
            }
            break;

        case 7:
            if (list.full()) {
                cout << "List is full." << endl;
            }
            else {
                cout << "List is not full." << endl;
            }
            break;

        case 8:
            cout << "Current list size: "
                << list.size() << endl;
            break;

        case 9:
            if (!list.empty()) {
                cout << "Last element: "
                    << list.last() << endl;
            }
            else {
                cout << "List is empty!" << endl;
            }
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value)) {
                cout << "Element found in the list." << endl;
            }
            else {
                cout << "Element not found." << endl;
            }
            break;

        case 11:
            list.display();
            break;

        case 12:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 12);

    return 0;
}
