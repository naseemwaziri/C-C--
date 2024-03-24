#include <iostream>
#include <string>
using namespace std;

class Flight_information 
{
    private:
    int flight_num;
    string destination;
    float distance;
    float fuel;

    void CALFUEL();

    public:
    void FEEDINFO();
    void SHOWINFO();
};

void Flight_information :: CALFUEL()
{
    if (distance <= 1000)
    {
        fuel = 500;
    }
    else if (distance > 1000 && distance <= 2000)
    {
        fuel = 1100;
    }
    else
    {
        fuel = 2200;
    }
}
void Flight_information :: FEEDINFO()
{
    cout<<"Enter Flight Number: ";
    cin>>flight_num;
    cout<<"Enter Destination: ";
    cin>>destination;
    cout<<"Enter Distance: ";
    cin>>distance;
    CALFUEL();
}
void Flight_information :: SHOWINFO()
{
        cout<<"Flight Number: "<<flight_num<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Distance: "<<distance<<endl;
        cout<<"Fuel: "<<fuel<<endl;
}
int main()
{
    Flight_information FI;
    FI.FEEDINFO();
    FI.SHOWINFO();

    return 0;
}
