#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Appointment {
public:
    string description;
    int year, month, day, time;

    Appointment(string desc = "", int y = 0, int m = 0, int d = 0, int t = 0)
        : description(desc), year(y), month(m), day(d), time(t) {}

    virtual bool occurs_on(int y, int m, int d) {
        return year == y && month == m && day == d;
    }

    virtual void save(ostream out) {
        out << description << " " << year << " " << month << " " << day << " " << time << "\n";
    }

    virtual void load(istream in) {
        in >> description >> year >> month >> day >> time;
    }
};

class Onetime : public Appointment {
public:
    using Appointment::Appointment;

    void save(ostream& out) override {
        out << "Onetime ";
        Appointment::save(out);
    }
};

class Daily : public Appointment {
public:
    using Appointment::Appointment;

    bool occurs_on(int y, int m, int d) override {
        return true;
    }

    void save(ostream& out) override {
        out << "Daily ";
        Appointment::save(out);
    }
};

class Weekly : public Appointment {
public:
    using Appointment::Appointment;

    bool occurs_on(int y, int m, int d) override {
        return day == d;
    }

    void save(ostream& out) override {
        out << "Weekly ";
        Appointment::save(out);
    }
};

class Monthly : public Appointment {
public:
    using Appointment::Appointment;

    bool occurs_on(int y, int m, int d) override {
        return day == d;
    }

    void save(ostream& out) override {
        out << "Monthly ";
        Appointment::save(out);
    }
};

int main() {
    Appointment* appointments[10];
    int appointmentCount = 0;

    char loadAppointments;
    cout << "Do you want to load appointments from a file? (y/n): ";
    cin >> loadAppointments;

    if (loadAppointments == 'y') {
        ifstream in("appointments.txt");

        while (!in.eof()) {
            string type;
            in >> type;

            if (type == "Onetime") {
                appointments[appointmentCount] = new Onetime();
            } else if (type == "Daily") {
                appointments[appointmentCount] = new Daily();
            } else if (type == "Weekly") {
                appointments[appointmentCount] = new Weekly();
            } else if (type == "Monthly") {
                appointments[appointmentCount] = new Monthly();
            }

            appointments[appointmentCount++]->load(in);
        }

        in.close();
    }

    while (true) {
        int year, month, day;
        cout << "Enter a date (year month day): ";
        cin >> year >> month >> day;

        for (int i = 0; i < appointmentCount; i++) {
            if (appointments[i]->occurs_on(year, month, day)) {
                cout << "Appointment: " << appointments[i]->description << "\n";
            }
        }

        char addAppointment;
        cout << "Do you want to add a new appointment? (y/n): ";
        cin >> addAppointment;

        if (addAppointment == 'n') {
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

        ofstream out("appointments.txt", ios::app);

        if (type == "Onetime") {
            appointments[appointmentCount] = new Onetime(description, year, month, day, time);
        } else if (type == "Daily") {
            appointments[appointmentCount] = new Daily(description, year, month, day, time);
        } else if (type == "Weekly") {
            appointments[appointmentCount] = new Weekly(description, year, month, day, time);
        } else if (type == "Monthly") {
            appointments[appointmentCount] = new Monthly(description, year, month, day, time);
        }

        appointments[appointmentCount++]->save(out);
        out.close();
    }

    for (int i = 0; i < appointmentCount; i++) {
        delete appointments[i];
    }

    return 0;
}