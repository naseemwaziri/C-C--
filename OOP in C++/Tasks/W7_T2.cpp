#include <iostream>
#include <string>
using namespace std;

class Book
{
    private:
    string title;
    string author;
    string publisher;
    int year_published;

    public:
    Book(){
        title = "unknown";
        author = "unknown";
        publisher = "unknown";
        year_published = 2000;
    }
    Book(string t, string a, string p){
        title = t;
        author = a;
        publisher = p;
        year_published = 2000;
    }
    Book(string t, string a, string p, int y)
    {
        title = t;
        author = a;
        publisher = p;
        year_published = y;
    }
    void displayBook(){
        cout << "Title: " << title <<endl;
        cout << "Author: " << author <<endl;
        cout << "Publisher: " << publisher <<endl;
        cout << "Year Published: " << year_published <<endl;
    }
    
};

int main()
{
    Book b1;
    b1.displayBook();

    Book b2("Math", "Ahmad", "Sufyan");
    b2.displayBook();

    Book b3("English", "Ali", "Faheem", 2023);
    b3.displayBook();

    return 0;
}
