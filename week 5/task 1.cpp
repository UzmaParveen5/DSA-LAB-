
#include <iostream>
using namespace std;


template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};


template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int count;
    int frontIndex;
    int rearIndex;

public:
    
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];

        count = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    
    ~myQueue() {
        delete[] arr;
    }

  
    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        cout << value << " inserted into queue." << endl;
    }

    
    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = arr[frontIndex];

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }

        return value;
    }

    
    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return arr[frontIndex];
    }

    
    bool isEmpty() const override {
        return count == 0;
    }

    
    bool isFull() const override {
        return count == capacity;
    }

    
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements (Front to Rear): ";

        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % capacity;
            cout << arr[index] << " ";
        }

        cout << endl;
    }
};


int main() {
    int size, choice, value;

    cout << "Enter maximum size of Queue: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    myQueue<int> q(size);

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed element: " << q.deQueue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 5:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is Not Full." << endl;
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Program Terminated." << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 7);

    return 0;
}
