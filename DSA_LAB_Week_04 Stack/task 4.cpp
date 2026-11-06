
#include <iostream>
#include <string>
using namespace std;


struct Action {
    char character;
    string operation;
};


class myStack {
private:
    Action* arr;
    int maxSize;
    int currentSize;

public:

   
    myStack(int size) {
        maxSize = size;
        currentSize = 0;
        arr = new Action[maxSize];
    }

    
    ~myStack() {
        delete[] arr;
    }

   
    bool isEmpty() const {
        return currentSize == 0;
    }

    
    bool isFull() const {
        return currentSize == maxSize;
    }

    void push(Action value) {
        if (isFull()) {
            cout << "History Stack is Full!\n";
            return;
        }

        arr[currentSize] = value;
        currentSize++;
    }

    
    Action pop() {
        if (isEmpty()) {
            return { '\0', "" };
        }

        currentSize--;

        return arr[currentSize];
    }

    
    void display() const {
        if (isEmpty()) {
            cout << "No history available.\n";
            return;
        }

        for (int i = currentSize - 1; i >= 0; i--) {
            cout << arr[i].operation
                << " : " << arr[i].character << endl;
        }
    }

    
    void clear() {
        currentSize = 0;
    }
};


class TextEditor {
private:
    string text;

    myStack undoStack;
    myStack redoStack;

public:

    
    TextEditor(int size)
        : undoStack(size), redoStack(size) {
        text = "";
    }

  
    void typeCharacter(char ch) {

        if (undoStack.isFull()) {
            cout << "Undo history is full! Cannot perform action.\n";
            return;
        }

        
        Action action = { ch, "TYPE" };
        undoStack.push(action);

        
        redoStack.clear();

        
        text += ch;

        cout << "Character '" << ch
            << "' added successfully.\n";
    }

    
    void deleteCharacter() {

        if (text.empty()) {
            cout << "Text is already empty!\n";
            return;
        }

        if (undoStack.isFull()) {
            cout << "Undo history is full! Cannot perform action.\n";
            return;
        }

        char ch = text.back();

     
        Action action = { ch, "DELETE" };
        undoStack.push(action);

       
        redoStack.clear();

        
        text.pop_back();

        cout << "Character '" << ch
            << "' deleted successfully.\n";
    }

    
    void undo() {

        if (undoStack.isEmpty()) {
            cout << "Nothing to undo!\n";
            return;
        }

        if (redoStack.isFull()) {
            cout << "Redo history is full!\n";
            return;
        }

        Action action = undoStack.pop();

        if (action.operation == "TYPE") {

           
            if (!text.empty()) {
                text.pop_back();
            }

            cout << "Undo successful: Character '"
                << action.character << "' removed.\n";
        }

        else if (action.operation == "DELETE") {

            
            text += action.character;

            cout << "Undo successful: Character '"
                << action.character << "' restored.\n";
        }

        
        redoStack.push(action);
    }

   
    void redo() {

        if (redoStack.isEmpty()) {
            cout << "Nothing to redo!\n";
            return;
        }

        if (undoStack.isFull()) {
            cout << "Undo history is full!\n";
            return;
        }

        Action action = redoStack.pop();

        if (action.operation == "TYPE") {

            
            text += action.character;

            cout << "Redo successful: Character '"
                << action.character << "' added.\n";
        }

        else if (action.operation == "DELETE") {

            
            if (!text.empty()) {
                text.pop_back();
            }

            cout << "Redo successful: Character '"
                << action.character << "' deleted.\n";
        }

      
        undoStack.push(action);
    }

    
    void displayText() const {

        cout << "\n========== CURRENT TEXT ==========\n";

        if (text.empty()) {
            cout << "(Empty Text)\n";
        }
        else {
            cout << text << endl;
        }

        cout << "==================================\n";
    }

   
    void displayUndoHistory() const {

        cout << "\n========== UNDO HISTORY ==========\n";
        undoStack.display();
    }

   
    void displayRedoHistory() const {

        cout << "\n========== REDO HISTORY ==========\n";
        redoStack.display();
    }
};


int main() {

    TextEditor editor(100);

    int choice;
    char ch;

    do {

        cout << "\n=================================\n";
        cout << "       TEXT EDITOR MENU\n";
        cout << "=================================\n";

        cout << "1. Type a Character\n";
        cout << "2. Delete Last Character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display Current Text\n";
        cout << "6. Display Undo History\n";
        cout << "7. Display Redo History\n";
        cout << "8. Exit\n";

        cout << "=================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter character to type: ";
            cin >> ch;

            editor.typeCharacter(ch);
            break;

        case 2:

            editor.deleteCharacter();
            break;

        case 3:

            editor.undo();
            break;

        case 4:

            editor.redo();
            break;

        case 5:

            editor.displayText();
            break;

        case 6:

            editor.displayUndoHistory();
            break;

        case 7:

            editor.displayRedoHistory();
            break;

        case 8:

            cout << "Exiting Text Editor...\n";
            break;

        default:

            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 8);

    return 0;
}
