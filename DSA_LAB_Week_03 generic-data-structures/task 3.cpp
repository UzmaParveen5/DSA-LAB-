
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
    }

    
    void addElementAtLastIndex(Type value) override {

        if (full()) {
            cout << "List is full!" << endl;
            return;
        }

        this->arr[this->currentSize++] = value;
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
            if (this->arr[i] == value)
                return true;
        }

        return false;
    }

    
    void display() {

        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List: ";

        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }

        cout << endl;
    }
};



template <class Type>
class CustomList : public MyList<Type> {

public:

    
    CustomList(int size = 10, int current = 0)
        : MyList<Type>(size, current) {
    }

    CustomList(const CustomList& other)
        : MyList<Type>(other) {
    }

    
    bool isPrime(int n) {

        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    
    Type sum_ofPrime() {

        Type sum = Type();

        for (int i = 0; i < this->currentSize; i++) {

            if (isPrime(static_cast<int>(this->arr[i]))) {
                sum += this->arr[i];
            }
        }

        return sum;
    }

    
    Type secondMaxEven() {

        Type max1 = Type();
        Type max2 = Type();

        bool found1 = false;
        bool found2 = false;

        for (int i = 0; i < this->currentSize; i++) {

            Type value = this->arr[i];

            if (value % 2 == 0) {

                if (!found1 || value > max1) {

                    if (found1 && value != max1) {
                        max2 = max1;
                        found2 = true;
                    }

                    max1 = value;
                    found1 = true;
                }
                else if (value < max1 &&
                    (!found2 || value > max2)) {

                    max2 = value;
                    found2 = true;
                }
            }
        }

        if (!found2) {
            cout << "Second maximum even number not found!";
            return Type();
        }

        return max2;
    }

    
    Type secondMinOdd() {

        Type min1 = Type();
        Type min2 = Type();

        bool found1 = false;
        bool found2 = false;

        for (int i = 0; i < this->currentSize; i++) {

            Type value = this->arr[i];

            if (value % 2 != 0) {

                if (!found1 || value < min1) {

                    if (found1 && value != min1) {
                        min2 = min1;
                        found2 = true;
                    }

                    min1 = value;
                    found1 = true;
                }
                else if (value > min1 &&
                    (!found2 || value < min2)) {

                    min2 = value;
                    found2 = true;
                }
            }
        }

        if (!found2) {
            cout << "Second minimum odd number not found!";
            return Type();
        }

        return min2;
    }

    
    void printDuplicates() {

        bool found = false;

        cout << "Duplicate elements: ";

        for (int i = 0; i < this->currentSize; i++) {

            bool alreadyChecked = false;

            for (int k = 0; k < i; k++) {
                if (this->arr[k] == this->arr[i]) {
                    alreadyChecked = true;
                    break;
                }
            }

            if (alreadyChecked)
                continue;

            int count = 0;

            for (int j = 0; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j]) {
                    count++;
                }
            }

            if (count > 1) {
                cout << this->arr[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "No duplicates found.";

        cout << endl;
    }

   
    void rotateRight(int start, int end, int r) {

        int len = end - start;

        if (len <= 1)
            return;

        r = r % len;

        for (int k = 0; k < r; k++) {

            Type lastValue = this->arr[end - 1];

            for (int i = end - 1; i > start; i--) {
                this->arr[i] = this->arr[i - 1];
            }

            this->arr[start] = lastValue;
        }
    }

   
    void rotateLeft(int start, int end, int r) {

        int len = end - start;

        if (len <= 1)
            return;

        r = r % len;

        for (int k = 0; k < r; k++) {

            Type firstValue = this->arr[start];

            for (int i = start; i < end - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }

            this->arr[end - 1] = firstValue;
        }
    }

   
    void rotateClockwaise(int r) {

        int mid = this->currentSize / 2;

        rotateRight(0, mid, r);

        rotateRight(mid, this->currentSize, r);

        cout << "List rotated clockwise successfully." << endl;
    }

    
    void rotateanitclockwaise(int rt) {

        int mid = this->currentSize / 2;

        rotateLeft(0, mid, rt);

        rotateLeft(mid, this->currentSize, rt);

        cout << "List rotated anti-clockwise successfully." << endl;
    }

   
    ~CustomList() {
        
    }
};



int main() {

    CustomList<int> list(20);

    int choice, value, r;

    do {

        cout << "\n===== CUSTOM LIST MENU =====\n";

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Display List\n";
        cout << "4. Sum of Prime Numbers\n";
        cout << "5. Second Maximum Even Number\n";
        cout << "6. Second Minimum Odd Number\n";
        cout << "7. Print Duplicate Elements\n";
        cout << "8. Rotate Clockwise\n";
        cout << "9. Rotate Anti-clockwise\n";
        cout << "10. Exit\n";

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
            list.display();
            break;

        case 4:
            cout << "Sum of prime numbers: "
                << list.sum_ofPrime() << endl;
            break;

        case 5:
            cout << "Second maximum even number: "
                << list.secondMaxEven() << endl;
            break;

        case 6:
            cout << "Second minimum odd number: "
                << list.secondMinOdd() << endl;
            break;

        case 7:
            list.printDuplicates();
            break;

        case 8:
            cout << "Enter rotation count: ";
            cin >> r;

            if (r < 0) {
                cout << "Enter a non-negative number!" << endl;
            }
            else {
                list.rotateClockwaise(r);
            }
            break;

        case 9:
            cout << "Enter rotation count: ";
            cin >> r;

            if (r < 0) {
                cout << "Enter a non-negative number!" << endl;
            }
            else {
                list.rotateanitclockwaise(r);
            }
            break;

        case 10:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 10);

    return 0;
}
