#include <iostream>
#include <string>

using namespace std;

class Appointment {
public:
    string description;
    int year, month, day, time;

    Appointment(string desc, int y, int m, int d, int t)
        : description(desc), year(y), month(m), day(d), time(t) {}

    virtual bool occurs_on(int y, int m, int d) {
        if (year == y && month == m && day == d) {
            return true;
        } else {
            return false;
        }
    }
};

class Onetime : public Appointment {
public:
    Onetime(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}
};

class Daily : public Appointment {
public:
    Daily(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    bool occurs_on(int y, int m, int d) override {
        if (year == y && month == m && day == d) {
            return true;
        } else {
            return false;
        }
    }
};

class Weekly : public Appointment {
public:
    Weekly(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    bool occurs_on(int y, int m, int d) {
        if (day == d) {
            return true;
        } else {
            return false;
        }
    }
};

class Monthly : public Appointment {
public:
    Monthly(string desc, int y, int m, int d, int t) : Appointment(desc, y, m, d, t) {}

    bool occurs_on(int y, int m, int d) {
        if (day == d) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Appointment* appointments[10];
    int appointmentCount = 4;
    appointments[0] = new Onetime("See the dentist", 2022, 12, 15, 10);
    appointments[1] = new Daily("Workout", 2022, 12, 16, 8);
    appointments[2] = new Weekly("Grocery shopping", 2022, 12, 17, 11);
    appointments[3] = new Monthly("Pay rent", 2022, 12, 18, 12);

    while (true) {
        int year, month, day;
        cout << "Enter a date (year month day): ";
        cin >> year >> month >> day;

        for (int i = 0; i < appointmentCount; i++) {
            if (appointments[i]->occurs_on(year, month, day)) {
                cout << "Appointment: " << appointments[i]->description << endl;
            }
        }

        string addAppointment;
        cout << "Do you want to add a new appointment? (yes/no): ";
        cin >> addAppointment;

        if (addAppointment == "no") {
            break;
        }

        string type, description;
        int time;
        cout << "Enter the type of the appointment (Onetime, Daily, Weekly, Monthly): ";
        cin >> type;
        cout << "Enter the description of the appointment: ";
        cin >> description;
        cout << "Enter the date and time of the appointment (year month day time): ";
        cin >> year >> month >> day >> time;

        if (type == "Onetime") {
            appointments[appointmentCount++] = new Onetime(description, year, month, day, time);
        } else if (type == "Daily") {
            appointments[appointmentCount++] = new Daily(description, year, month, day, time);
        } else if (type == "Weekly") {
            appointments[appointmentCount++] = new Weekly(description, year, month, day, time);
        } else if (type == "Monthly") {
            appointments[appointmentCount++] = new Monthly(description, year, month, day, time);
        }
    }
    
    return 0;
}