#include <iostream>
using namespace std;

#include <iostream>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void display_date()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main(){
    Date date1;
    date1.display_date();

    Date date2(15, 11, 2023);
    date2.display_date();

    return 0;
}
