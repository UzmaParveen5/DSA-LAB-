
#include <iostream>
#include <string>
using namespace std;

class Publication
{
public:
    virtual void display() = 0;
    virtual ~Publication() {}
};

class Book : public Publication
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t = "", string a = "", int p = 0)
    {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() const
    {
        return title;
    }

    int getPages() const
    {
        return pages;
    }

    void display() override
    {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public Publication
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n = "", string d = "", string e = "")
    {
        name = n;
        date = d;
        edition = e;
    }

    string getName() const
    {
        return name;
    }

    string getEdition() const
    {
        return edition;
    }

    void display() override
    {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};


template <typename T, typename Key, typename Compare>
int linearSearch(T arr[], int size, Key key, Compare compare)
{
    for (int i = 0; i < size; i++)
    {
        if (compare(arr[i], key))
            return i;
    }

    return -1;
}


template <typename T, typename Key, typename Compare>
int binarySearch(T arr[], int size, Key key, Compare compare)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int result = compare(arr[mid], key);

        if (result == 0)
            return mid;
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


class Library
{
private:
    Book books[100];
    Newspaper newspapers[100];

    int bookCount;
    int newspaperCount;

public:
    Library()
    {
        bookCount = 0;
        newspaperCount = 0;
    }

    
    void addBook(Book book)
    {
        if (bookCount < 100)
            books[bookCount++] = book;
        else
            cout << "Book collection is full!" << endl;
    }

   
    void addNewspaper(Newspaper newspaper)
    {
        if (newspaperCount < 100)
            newspapers[newspaperCount++] = newspaper;
        else
            cout << "Newspaper collection is full!" << endl;
    }

    
    void displayCollection()
    {
        cout << "\n--- Books ---" << endl;

        for (int i = 0; i < bookCount; i++)
        {
            books[i].display();
            cout << endl;
        }

        cout << "--- Newspapers ---" << endl;

        for (int i = 0; i < newspaperCount; i++)
        {
            newspapers[i].display();
            cout << endl;
        }
    }

   
    void sortBooksByPages()
    {
        for (int i = 0; i < bookCount - 1; i++)
        {
            for (int j = 0; j < bookCount - i - 1; j++)
            {
                if (books[j].getPages() > books[j + 1].getPages())
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    
    void sortNewspapersByEdition()
    {
        for (int i = 0; i < newspaperCount - 1; i++)
        {
            for (int j = 0; j < newspaperCount - i - 1; j++)
            {
                if (newspapers[j].getEdition() >
                    newspapers[j + 1].getEdition())
                {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    
    Book* searchBookByTitle(string title)
    {
        int index = linearSearch(
            books, bookCount, title,
            [](const Book& book, const string& key)
            {
                return book.getTitle() == key;
            });

        if (index != -1)
            return &books[index];

        return nullptr;
    }

   
    Newspaper* searchNewspaperByName(string name)
    {
        int index = linearSearch(
            newspapers, newspaperCount, name,
            [](const Newspaper& paper, const string& key)
            {
                return paper.getName() == key;
            });

        if (index != -1)
            return &newspapers[index];

        return nullptr;
    }

    Book* binarySearchBookByTitle(string title)
    {
        
        for (int i = 0; i < bookCount - 1; i++)
        {
            for (int j = 0; j < bookCount - i - 1; j++)
            {
                if (books[j].getTitle() > books[j + 1].getTitle())
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }

        int index = binarySearch(
            books, bookCount, title,
            [](const Book& book, const string& key)
            {
                if (book.getTitle() == key)
                    return 0;

                return (book.getTitle() < key) ? -1 : 1;
            });

        if (index != -1)
            return &books[index];

        return nullptr;
    }
};

int main()
{
    
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    
    Newspaper newspaper1(
        "Washington Post", "2024-10-13", "Morning Edition");

    Newspaper newspaper2(
        "The Times", "2024-10-12", "Weekend Edition");

    
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
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
    {
        cout << "\nBook not found.\n";
    }

   
    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper)
    {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else
    {
        cout << "\nNewspaper not found.\n";
    }

    
    Book* binaryFound =
        library.binarySearchBookByTitle("To Kill a Mockingbird");

    if (binaryFound)
    {
        cout << "\nBook found using Binary Search:\n";
        binaryFound->display();
    }
    else
    {
        cout << "\nBook not found using Binary Search.\n";
    }

    return 0;
}
