#include <iostream>
#include <string>

using namespace std;

class Appointment
{
public:
    string description;
    int year, month, day, time;

    Appointment(string desc, int y, int m, int d, int t)
        : description(desc), year(y), month(m), day(d), time(t) {}

    virtual void occurs_on(int y, int m, int d)
    {
        if (year == y && month == m && day == d)
        {
            cout << "Appointment: " << description << endl;
        }
    }
};

class Onetime : public Appointment
{
public:
    Onetime(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}
};

class Daily : public Appointment
{
public:
    Daily(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    void occurs_on(int y, int m, int d)
    {
        cout << "Appointment: " << description << endl;
    }
};

class Weekly : public Appointment
{
public:
    Weekly(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    void occurs_on(int y, int m, int d) override
    {
        if (day == d)
        {
            cout << "Appointment: " << description << endl;
        }
    }
};

class Monthly : public Appointment
{
public:
    Monthly(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    void occurs_on(int y, int m, int d) override
    {
        if (day == d)
        {
            cout << "Appointment: " << description << endl;
        }
    }
};

int main()
{
    Appointment *appointments[4];
    appointments[0] = new Onetime("See the docter", 2022, 12, 15, 10);
    appointments[1] = new Daily("Workout", 2022, 12, 16, 8);
    appointments[2] = new Weekly("Shopping", 2022, 12, 17, 11);
    appointments[3] = new Monthly("Pay rent", 2022, 12, 18, 12);

    int year, month, day;
    cout << "Enter a date (year month day): ";
    cin >> year >> month >> day;

    for (int i = 0; i < 4; i++)
    {
        appointments[i]->occurs_on(year, month, day);
    }

    return 0;
}