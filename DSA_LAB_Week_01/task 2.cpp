
#include <iostream>
#include <string>
using namespace std;


template <class T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


template <class T>
void selectionSort(T arr[], int size) {

    for (int i = 0; i < size - 1; i++) {

        int SmallSub = i;

        for (int j = i + 1; j < size; j++) {

            if (arr[j] < arr[SmallSub]) {
                SmallSub = j;
            }
        }

        
        T temp = arr[i];
        arr[i] = arr[SmallSub];
        arr[SmallSub] = temp;
    }
}


int main() {

   
    int intArray[5] = { 64, 25, 12, 22, 11 };

    cout << "Original integer array: ";
    printArray(intArray, 5);

    selectionSort(intArray, 5);

    cout << "Sorted integer array: ";
    printArray(intArray, 5);


    
    string stringArray[4] = {
        "apple", "orange", "banana", "grape"
    };

    cout << "\nOriginal string array: ";
    printArray(stringArray, 4);

    selectionSort(stringArray, 4);

    cout << "Sorted string array: ";
    printArray(stringArray, 4);

    return 0;
}

