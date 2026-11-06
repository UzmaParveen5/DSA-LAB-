
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Publication {
public:
    virtual void display() const = 0;

    virtual ~Publication() {}
};


class Book : public Publication {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() const {
        return title;
    }

    int getPages() const {
        return pages;
    }

    void display() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};


class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() const {
        return name;
    }

    string getEdition() const {
        return edition;
    }

    void display() const override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};


template <class T, class Key, class GetKey>
int linearSearch(const vector<T>& arr,
    const Key& key, GetKey getKey) {

    for (int i = 0; i < arr.size(); i++) {
        if (getKey(arr[i]) == key) {
            return i;
        }
    }

    return -1;
}


template <class T, class Key, class GetKey>
int binarySearch(const vector<T>& arr,
    const Key& key, GetKey getKey) {

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (getKey(arr[mid]) == key) {
            return mid;
        }
        else if (getKey(arr[mid]) < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}


class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:

    
    void addBook(Book b) {
        books.push_back(b);
    }

    
    void addNewspaper(Newspaper n) {
        newspapers.push_back(n);
    }

    
    void displayCollection() {

        cout << "\n===== BOOK COLLECTION =====\n";

        for (int i = 0; i < books.size(); i++) {
            books[i].display();
            cout << "-------------------\n";
        }

        cout << "\n===== NEWSPAPER COLLECTION =====\n";

        for (int i = 0; i < newspapers.size(); i++) {
            newspapers[i].display();
            cout << "-------------------\n";
        }
    }

  
    void sortBooksByPages() {

        sort(books.begin(), books.end(),
            [](const Book& a, const Book& b) {
                return a.getPages() < b.getPages();
            });

    }

    
    void sortNewspapersByEdition() {

        sort(newspapers.begin(), newspapers.end(),
            [](const Newspaper& a, const Newspaper& b) {
                return a.getEdition() < b.getEdition();
            });

    }

    
    Book* searchBookByTitle(string title) {

        int index = linearSearch(
            books, title,
            [](const Book& b) {
                return b.getTitle();
            }
        );

        if (index != -1) {
            return &books[index];
        }

        return nullptr;
    }

    
    Newspaper* searchNewspaperByName(string name) {

       
        vector<Newspaper*> temp;

        for (int i = 0; i < newspapers.size(); i++) {
            temp.push_back(&newspapers[i]);
        }

        
        sort(temp.begin(), temp.end(),
            [](Newspaper* a, Newspaper* b) {
                return a->getName() < b->getName();
            });

        int index = binarySearch(
            temp, name,
            [](Newspaper* n) {
                return n->getName();
            }
        );

        if (index != -1) {
            return temp[index];
        }

        return nullptr;
    }
};


int main() {

    
    Book book1("The Catcher in the Rye",
        "J.D. Salinger", 277);

    Book book2("To Kill a Mockingbird",
        "Harper Lee", 324);

    
    Newspaper newspaper1("Washington Post",
        "2024-10-13",
        "Morning Edition");

    Newspaper newspaper2("The Times",
        "2024-10-12",
        "Weekend Edition");

   
    Library library;

    
    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    
    cout << "Before Sorting:\n";

    library.displayCollection();

   
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    
    cout << "\nAfter Sorting:\n";

    library.displayCollection();

   
    Book* foundBook =
        library.searchBookByTitle(
            "The Catcher in the Rye"
        );

    if (foundBook != nullptr) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    
    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
