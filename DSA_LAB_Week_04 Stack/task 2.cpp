
#include <iostream>
using namespace std;


template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractStack() {}
};


template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;       
    T* minArr;    

    int maxSize;
    int currentSize;
    int minSize;

public:

    
    myStack(int size) {
        maxSize = size;
        currentSize = 0;
        minSize = 0;

        arr = new T[maxSize];
        minArr = new T[maxSize];
    }

    
    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    
    void push(T value) override {

        if (isFull()) {
            cout << "Stack Overflow! Stack is full.\n";
            return;
        }

        arr[currentSize] = value;
        currentSize++;

        
        if (minSize == 0 || value <= minArr[minSize - 1]) {
            minArr[minSize] = value;
            minSize++;
        }

        cout << value << " pushed into stack.\n";
    }

   
    T pop() override {

        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return T();
        }

        T value = arr[currentSize - 1];
        currentSize--;

        
        if (value == minArr[minSize - 1]) {
            minSize--;
        }

        cout << value << " popped from stack.\n";

        return value;
    }

    
    T top() const override {

        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return T();
        }

        return arr[currentSize - 1];
    }

   
    bool isEmpty() const override {
        return currentSize == 0;
    }

   
    bool isFull() const override {
        return currentSize == maxSize;
    }

   
    T getMin() const {

        if (isEmpty()) {
            cout << "Stack is empty. No minimum element.\n";
            return T();
        }

        return minArr[minSize - 1];
    }

   
    void display() const {

        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nStack elements (Top to Bottom):\n";

        for (int i = currentSize - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};


int main() {

    int size;

    cout << "Enter maximum size of stack: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid stack size!\n";
        return 1;
    }

    myStack<int> s(size);

    int choice;
    int value;

    do {

        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top element: " << s.top() << endl;
            else
                cout << "Stack is empty.\n";
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is Not Empty.\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full.\n";
            else
                cout << "Stack is Not Full.\n";
            break;

        case 6:
            s.display();
            break;

        case 7:
            if (!s.isEmpty())
                cout << "Minimum element: " << s.getMin() << endl;
            else
                cout << "Stack is empty. No minimum element.\n";
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
