#include <iostream>
using namespace std;

struct shelf
{
    string ISBN;
    string title;
    string author;
    string publishingYear;
};

void divider() {
    cout << "-------------------------" << endl;
}


void displayAllBooks(shelf b[], int totalB) {
    for (int i = 0; i < totalB; i++) {
        cout << "Book " << i + 1 << ":\n" << endl;
        cout << "Title: " << b[i].title << endl;
        cout << "Author: " << b[i].author << endl;
        cout << "International Standard Book Number: " << b[i].ISBN << endl;
        cout << "Publishing year: " << b[i].publishingYear << endl;
        divider();
    }
}

void displayChosenBook(shelf b[], int choice) {
    cout << "Book " << choice << ":\n" << endl;
    cout << "Title: " << b[choice - 1].title << endl;
    cout << "Author: " << b[choice - 1].author << endl;
    cout << "International Standard Book Number: " << b[choice - 1].ISBN << endl;
    cout << "Publishing year: " << b[choice - 1].publishingYear << endl;
    divider();
}

int main()
{
    int totalBooks;
    cout << "How many books do you want to store? ";
    cin >> totalBooks;
    cin.ignore();

    shelf book[totalBooks];

    for (int i = 0; i < totalBooks; i++)
    {
        cout << "Enter title of book " << i + 1 << ": ";
        getline(cin, book[i].title);
        cout << "Enter the International Standard Book Number of book " << i + 1 << ": ";
        cin >> book[i].ISBN;
        cin.ignore();
        cout << "Who is the author of this book? ";
        getline(cin, book[i].author);
        cout << "What is the publishing year of this book? ";
        cin >> book[i].publishingYear;
        cin.ignore();
        divider();
    }

    int choice;
    string quitProgram;
    bool choosing = true;

    while (choosing)
    {
        cout << "Enter the book number to see its details and enter 0 to see all. ";
        cin >> choice;

        divider();

        if (choice <= 0)
        {
            displayAllBooks(book, totalBooks);
        }
        else if (choice > 0 && choice <= totalBooks)
        {
            displayChosenBook(book, choice);
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        cout << "Quit? (Y/n): ";
        cin >> quitProgram;

        if (quitProgram == "Y" || quitProgram == "y")
        {
            choosing = false;
        }
    }


    return 0;
}
