#include <iostream>
using namespace std;

class Sport {
public:
    string name;
    int duration;

    virtual void displayDetails() {
        cout << "Sport: " << name << ", Duration: " << duration << " minutes\n";
    }
};

class Football : public Sport {
public:
    int teamSize;

    void displayDetails() override {
        cout << "Sport: " << name << ", Duration: " << duration << " minutes, Team size: " << teamSize << "\n";
    }
};

class Tennis : public Sport {
public:
    string courtType;

    void displayDetails() override {
        cout << "Sport: " << name << ", Duration: " << duration << " minutes, Court type: " << courtType << "\n";
    }
};

Sport* sports[100];
int sportCount = 0;

void createSport() {
    int choice;
    cout << "Enter sport type (1 for Football, 2 for Tennis): ";
    cin >> choice;

    Sport* sport;
    if (choice == 1) {
        sport = new Football();
        cout << "Enter team size: ";
        cin >> ((Football*)sport)->teamSize;
    } else if (choice == 2) {
        sport = new Tennis();
        cout << "Enter court type: ";
        cin >> ((Tennis*)sport)->courtType;
    }

    cout << "Enter sport name: ";
    cin >> sport->name;
    cout << "Enter duration: ";
    cin >> sport->duration;

    sports[sportCount++] = sport;
}

void displaySports() {
    for (int i = 0; i < sportCount; i++) {
        sports[i]->displayDetails();
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add sport\n2. Display sports\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createSport();
            break;
        case 2:
            displaySports();
            break;
        }
    } while (choice != 3);

    for (int i = 0; i < sportCount; i++) {
        delete sports[i];
    }

    return 0;
}