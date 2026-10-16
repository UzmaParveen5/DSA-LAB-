
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CustomList {
private:
    int* arr;
    int size;

    bool isPrime(int n) const {
        if (n < 2)
            return false;

        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    CustomList(int s = 5, int value = 0) {
        size = (s > 0) ? s : 1;
        arr = new int[size];

        for (int i = 0; i < size; i++)
            arr[i] = value;
    }

  
    CustomList(const CustomList& other) {
        size = other.size;
        arr = new int[size];

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    
    ~CustomList() {
        delete[] arr;
    }

   
    void input() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

  
    void display() const {
        cout << "List: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

  
    int sum_ofPrime() const {
        int sum = 0;

        for (int i = 0; i < size; i++) {
            if (isPrime(arr[i]))
                sum += arr[i];
        }

        return sum;
    }

    
        int largest = 0, second = 0;
        bool hasLargest = false, hasSecond = false;

        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                if (!hasLargest || arr[i] > largest) {
                    if (hasLargest && arr[i] != largest) {
                        second = largest;
                        hasSecond = true;
                    }
                    largest = arr[i];
                    hasLargest = true;
                }
                else if (arr[i] < largest &&
                    (!hasSecond || arr[i] > second)) {
                    second = arr[i];
                    hasSecond = true;
                }
            }
        }

        if (!hasSecond) {
            cout << "No second distinct even number exists.\n";
            return 0;
        }

        return second;
    }

   
    int secondMinOdd() const {
        int smallest = 0, second = 0;
        bool hasSmallest = false, hasSecond = false;

        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0) {
                if (!hasSmallest || arr[i] < smallest) {
                    if (hasSmallest && arr[i] != smallest) {
                        second = smallest;
                        hasSecond = true;
                    }
                    smallest = arr[i];
                    hasSmallest = true;
                }
                else if (arr[i] > smallest &&
                    (!hasSecond || arr[i] < second)) {
                    second = arr[i];
                    hasSecond = true;
                }
            }
        }

        if (!hasSecond) {
            cout << "No second distinct odd number exists.\n";
            return 0;
        }

        return second;
    }

   
    void printDuplicates() const {
        bool found = false;

        cout << "Duplicate numbers: ";

        for (int i = 0; i < size; i++) {
            bool alreadyPrinted = false;

            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    alreadyPrinted = true;
                    break;
                }
            }

            if (alreadyPrinted)
                continue;

            int count = 0;
            for (int j = 0; j < size; j++) {
                if (arr[j] == arr[i])
                    count++;
            }

            if (count > 1) {
                cout << arr[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }

    
    void rotateClockwaise(int r) {
        int mid = size / 2;
        r = (r % size + size) % size;

      
        int firstSize = mid;
        if (firstSize > 0) {
            int k = r % firstSize;
            reverse(arr, arr + firstSize);
            reverse(arr, arr + k);
            reverse(arr + k, arr + firstSize);
        }

       
        int secondSize = size - mid;
        if (secondSize > 0) {
            int k = r % secondSize;
            reverse(arr + mid, arr + size);
            reverse(arr + mid, arr + mid + k);
            reverse(arr + mid + k, arr + size);
        }
    }

    
    void rotateanitclockwaise(int rt) {
        int mid = size / 2;
        rt = (rt % size + size) % size;

       
        int firstSize = mid;
        if (firstSize > 0) {
            int k = rt % firstSize;
            reverse(arr, arr + k);
            reverse(arr + k, arr + firstSize);
            reverse(arr, arr + firstSize);
        }

       
        int secondSize = size - mid;
        if (secondSize > 0) {
            int k = rt % secondSize;
            reverse(arr + mid, arr + mid + k);
            reverse(arr + mid + k, arr + size);
            reverse(arr + mid, arr + size);
        }
    }
};

int main() {
    int n;

    cout << "Enter list size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid list size.\n";
        return 0;
    }

    CustomList list(n);
    list.input();

    int choice, rotations;

    do {
        cout << "\n===== CUSTOM LIST MENU =====\n";
        cout << "1. Display list\n";
        cout << "2. Sum of prime numbers\n";
        cout << "3. Second maximum even number\n";
        cout << "4. Second minimum odd number\n";
        cout << "5. Print duplicates\n";
        cout << "6. Rotate clockwise\n";
        cout << "7. Rotate anti-clockwise\n";
        cout << "8. Test copy constructor\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            list.display();
            break;

        case 2:
            cout << "Sum of prime numbers = "
                << list.sum_ofPrime() << endl;
            break;

        case 3:
            cout << "Second maximum even number = "
                << list.secondMaxEven() << endl;
            break;

        case 4:
            cout << "Second minimum odd number = "
                << list.secondMinOdd() << endl;
            break;

        case 5:
            list.printDuplicates();
            break;

        case 6:
            cout << "Enter rotation count: ";
            cin >> rotations;
            list.rotateClockwaise(rotations);
            list.display();
            break;

        case 7:
            cout << "Enter rotation count: ";
            cin >> rotations;
            list.rotateanitclockwaise(rotations);
            list.display();
            break;

        case 8: {
            CustomList copy(list);
            cout << "Copied list:\n";
            copy.display();
            break;
        }

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
