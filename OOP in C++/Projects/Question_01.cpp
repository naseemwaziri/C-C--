#include <iostream>
#include <string>
using namespace std;

class Avengers
{
    private:
    string avengersName;
    string alias;
    int powerLevel = 0;

    public:
    Avengers(string avengersName, string alias, int powerLevel){
        this->avengersName = avengersName;
        this->alias = alias;
        this->powerLevel = powerLevel;
    }

    void displayDetails()
    {
        cout<<"Name of Superman: "<<avengersName<<endl;
        cout<<"Name of Alis: "<<alias <<endl;
        cout<<"Superman Power : " << powerLevel <<endl;   
    }

    Avengers operator +(Avengers avengers){
        return (this->avengersName+avengers.avengersName, this->powerLevel+avengers.powerLevel);
    }
};

class Ironman : public Avengers
{
    private:
    string abilities;
    string wapon;

    public:
    Ironman(string avengersName, string alias, int powerLevel, string abilities, string wapon) : Avengers(avengersName,alias,powerLevel){
        this->abilities = abilities;
        this->wapon = wapon;
    }

    void displayDetails(){
        Avengers :: displayDetails();
        cout<<"Abilities of Iron Man: "<<abilities <<endl;
        cout<<"Wapons of iron Man: "<<wapon << endl;
    }

};

class CaptainAmerica :: public Avengers
{
    private: 
    string abilities;
    string wapon;

    public:
    CaptainAmerica(string avengersName, string alias, int powerLevel, string abilities, string wapon) : Avengers(avengersName,alias, powerLevel){
        this->abilities = abilities;
        this->wapon = wapon;
    }

    void displayDetails(){
        Avengers :: displayDetails();
        cout<<"Abilities of Captain America: "<< abilities <<endl;
        cout<<"Wapons of Captain America: "<<wapon << endl;
    }
};

class Thor : public Avengers
{
    private:
    string abilities;
    string wapon;

    public:
    Thor(string avengersName, string alias, int powerLevel, string abilities, string wapon) : Avengers(avengersName,alias, powerLevel){
        this->abilities;
        this->wapon = wapon;

    }

    void displayDetails(){
        Avengers ::displayDetails();
        cout<<"The Abilities of Thor is: "<< abilities << endl;
        cout<<"Wapons of Thor: "<<wapon << endl;
    }

};

int main()
{   
    Ironman ironman("Tony Stark", "Iran Man", 80, "Flight");
    CaptainAmerica captainamerica("Steve Rogers", "Captain America", 90, "Vibranium Shield");
    Thor thor("Thor Odinson", "Thor", 95, "Control of Lighting");

    ironman.displayDetails();
    captainamerica.displayDetails();
    thor.displayDetails();

    Avengers newAvengers = ironman + thor;
    newAvengers.displayDetails();
    
    return 0;
}