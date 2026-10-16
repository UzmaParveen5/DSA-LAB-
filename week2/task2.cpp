
#include <iostream>
using namespace std;

template <class T>
class MyList
{
private:
    T* arr;
    int capacity;
    int currentSize;

public:
   
    MyList(int cap = 10)
    {
        capacity = cap;
        currentSize = 0;
        arr = new T[capacity];
    }

   
    MyList(const MyList<T>& other)
    {
        capacity = other.capacity;
        currentSize = other.currentSize;

        arr = new T[capacity];

        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    
    ~MyList()
    {
        delete[] arr;
    }

    
    bool empty()
    {
        return currentSize == 0;
    }

     
    bool full()
    {
        return currentSize == capacity;
    }

   
    int size()
    {
        return currentSize;
    }

    
    bool insertAt(int index, T value)
    {
        if (full() || index < 0 || index > currentSize)
        {
            return false;
        }

        for (int i = currentSize; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        currentSize++;

        return true;
    }

    
    T last()
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return T();
        }

        return arr[currentSize - 1];
    }

   
    bool search(T value)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (arr[i] == value)
            {
                return true;
            }
        }

        return false;
    }

   
    void display()
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List elements: ";

        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int capacity;

    cout << "Enter list capacity: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Capacity must be greater than zero." << endl;
        return 1;
    }

    MyList<int> list(capacity);

    int choice, index, value;

    do
    {
        cout << "\n===== MyList MENU =====" << endl;
        cout << "1. Check if list is empty" << endl;
        cout << "2. Check if list is full" << endl;
        cout << "3. Get list size" << endl;
        cout << "4. Insert value at index" << endl;
        cout << "5. Get last element" << endl;
        cout << "6. Search for a value" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Copy list (test copy constructor)" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "List is not empty." << endl;
            break;

       
            if (list.full())
                cout << "List is full." << endl;
            else
                cout << "List is not full." << endl;
            break;

        
            cout << "Current size: " << list.size() << endl;
            break;

        
            cout << "Enter index (0-based): ";
            cin >> index;

            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Value inserted successfully." << endl;
            else
                cout << "Insertion failed. Check index or capacity." << endl;
            break;

        
            if (!list.empty())
                cout << "Last element: " << list.last() << endl;
            else
                cout << "List is empty; no last element." << endl;
            break;

        
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Value found in the list." << endl;
            else
                cout << "Value not found." << endl;
            break;

            list.display();
            break;

        
        {
            MyList<int> copiedList(list);

            cout << "Copied list created successfully." << endl;
            copiedList.display();
            break;
        }

        
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
