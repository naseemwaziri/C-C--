#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    int numPages;
};

int calculateTotalPages(Book books[], int numBooks) {
    int totalPages = 0;

    for (int i = 0; i < numBooks; i++) {
        totalPages += books[i].numPages;
    }

    return totalPages;
}

int main() {
    int NUM_BOOKS = 3;
    Book library[NUM_BOOKS] = {
        {"Book 1", "Author 1", "ISBN-1", 200},
        {"Book 2", "Author 2", "ISBN-2", 300},
        {"Book 3", "Author 3", "ISBN-3", 250}
    };

    int totalNumPages = calculateTotalPages(library, NUM_BOOKS);

    cout << "Total number of pages across all books: " << totalNumPages << endl;

    return 0;
}
