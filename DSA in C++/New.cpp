#include <iostream>
#include <iostream>
#include <string>

using namespace std;

class Building {
protected:
    string building_type;
    int floor_count;

public:
    Building(string building_type, int floor_count) {
        this->building_type = building_type;
        this->floor_count = floor_count;
    }

    virtual void constructBuilding() = 0; 
    virtual void displayDetails() = 0; 
};

class Skyscraper : public Building {
public:
    Skyscraper(string building_type, int floor_count) : Building(building_type, floor_count) {}

    void constructBuilding(){
        cout << "Constructing Skyscraper";
    }

    void displayDetails(){
        cout << "Skyscraper Details: Type: " << building_type << "Floors: " << floor_count << endl;
    }
};

class Library : public Building {
private:
    int books_count;

public:
    Library(string building_type, int floor_count, int books_count) : Building(building_type, floor_count), books_count(books_count) {}

    void constructBuilding(){
        cout << "Constructing Library...\n";
    }

    void displayDetails(){
        cout << "Library Details:\nType: " << building_type << "\nFloors: " << floor_count << "\nBooks: " << books_count << "\n";
    }
};

class Residence : public Building {
private:
    int residents_count;

public:
    Residence(string building_type, int floor_count, int residents_count) : Building(building_type, floor_count), residents_count(residents_count) {}

    void constructBuilding(){
        cout << "Constructing Residence...\n";
    }

    void displayDetails(){
        cout << "Residence Details:Type: " << building_type << "\nFloors: " << floor_count << "\nResidents: " << residents_count << "\n";
    }
};

int main() {
    Skyscraper skyscraper("Skyscraper", 50);
    skyscraper.constructBuilding();
    skyscraper.displayDetails();

    Library library("Library", 3, 10000);
    library.constructBuilding();
    library.displayDetails();

    Residence residence("Residence", 10, 200);
    residence.constructBuilding();
    residence.displayDetails();

    return 0;
}