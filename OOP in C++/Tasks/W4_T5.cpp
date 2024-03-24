#include <iostream>
#include <string>
using namespace std;

class BOOK {
private:
    int book_no;
    string book_title;
    float price;

    float calculate_total_cost(int N);

public:
    void INPUT();
    void PURCHASE();
};
    float BOOK :: calculate_total_cost(int N) {
        return price * N;
    }

    void BOOK :: INPUT() {
        cout<<"Enter the Book number: ";
        cin>>book_no;
        cout<<"Enter the Book Title: ";
        cin>>book_title;
        cout<<"Enter the Price per copy: ";
        cin>>price;
    }

    void BOOK :: PURCHASE() {
        cout<<"Book Number is: "<<book_no <<endl;
        cout<<"Book Title is: " <<book_title <<endl;
        cout<<"Book's Price per copy is: "<<price <<endl;
        int N;
        cout<<"Enter the number of copies to be purchased: ";
        cin>>N;
    
        float total_cost = calculate_total_cost(N);
        cout<<"Total cost to be paid by the user: "<<total_cost <<endl;
    }

int main() {
    BOOK book;

    book.INPUT();
    book.PURCHASE();
    
    return 0;
}
