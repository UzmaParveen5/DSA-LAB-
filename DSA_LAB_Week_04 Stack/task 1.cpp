
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
    int maxSize;
    int currentSize;

public:
   
    myStack(int size) {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
    }

   
    ~myStack() {
        delete[] arr;
    }

  
    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow! Stack is full.\n";
            return;
        }

        arr[currentSize] = value;
        currentSize++;

        cout << value << " pushed into stack.\n";
    }

   
    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return T();
        }

        currentSize--;
        T value = arr[currentSize];

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
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
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
            if (!s.isEmpty()) {
                cout << "Top element: " << s.top() << endl;
            }
            else {
                cout << "Stack is empty.\n";
            }
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
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
