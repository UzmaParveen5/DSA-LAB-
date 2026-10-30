
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue {
private:
    queue<int> q;

public:

   
    void enqueue(int value) {
        q.push(value);
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = q.front();
        q.pop();
        return value;
    }

    
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return q.front();
    }

   
    bool isEmpty() {
        return q.empty();
    }

   
    void display() {
        queue<int> temp = q;

        cout << "Queue: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

   
    void reverseFirstK(int k) {

        int n = q.size();

        
        if (k <= 1) {
            cout << "No reversal needed!" << endl;
            return;
        }

        if (k > n) {
            cout << "K is greater than Queue size!" << endl;
            return;
        }

        stack<int> s;

        
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

       
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "First " << k << " elements reversed successfully!"
            << endl;
    }
};


int main() {
    Queue q;
    int n, value, k;

    cout << "Enter number of Queue elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

  
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        q.enqueue(value);
    }

    cout << "\nOriginal ";
    q.display();

    
    cout << "\nEnter value of K: ";
    cin >> k;

   
    q.reverseFirstK(k);

   
    cout << "\nFinal ";
    q.display();

    return 0;
}
