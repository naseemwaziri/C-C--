#include<iostream>
using namespace std;

class ComboLock
{
    private:
    int combo[3];
    int currentPosition;
    bool isOpen;

    public:
    ComboLock(int first, int second, int third)
    {
        combo[0] = first;
        combo[1] = second;
        combo[2] = third;
        currentPosition = 0;
        isOpen = false;
    }

    void reset()
    {
        currentPosition = 0;
    }

    void turn_left(int ticks)
    {
        currentPosition = (currentPosition - ticks);
    }

    void turn_right(int ticks)
    {
        currentPosition = (currentPosition + ticks);
    }

    bool open() 
    {
        if(currentPosition == combo[2]) 
        {
            isOpen = true;
        }
        return isOpen;
    }
};

int main() 
{
    int first, second, third;
    cout<<"Enter the first number of the combination: ";
    cin>>first;
    cout<<"Enter the second number of the combination: ";
    cin>>second;
    cout<<"Enter the third number of the combination: ";
    cin>>third;

    ComboLock lock(first, second, third);
    lock.reset();

    int ticks;
    cout<<"Turn right to the first number: ";
    cin>>ticks;
    lock.turn_right(ticks);

    cout<<"Turn left to the second number: ";
    cin>>ticks;
    lock.turn_left(ticks);

    cout<<"Turn right to the third number: ";
    cin>>ticks;
    lock.turn_right(ticks);

    if(lock.open())
    {
        cout<<"Lock is open!"<<endl;
    } else 
    {
        cout<<"Failed to open the lock."<<endl;
    }

    return 0;
}