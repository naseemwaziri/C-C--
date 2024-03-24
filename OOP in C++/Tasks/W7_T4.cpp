#include<iostream>
using namespace std;
class Sport{
	string nameOfSport;
	int duration;
	public:
		void displayDetails(){
			cout<<"Sports name : "<<nameOfSport<<endl;
			cout<<"Duration : "<<duration<<endl;
		}
		void createSport(){
			cout<<"Enter name of sports:"<<endl;
			cin>>nameOfSport;
			cout<<"Enter duration:"<<endl;
			cin>>duration;
		}
};
class Football : public Sport{
	int teamSize;
	public:
		void createSport(){
			Sport::createSport();
            cout<<"Enter team size:"<<endl;
			cin>>teamSize;
			cout<<"-----------------------"<<endl;
		}
		void displayDetails(){
			Sport::displayDetails();
			cout<<"Team Size : "<<teamSize<<endl;
			cout<<"-----------------------"<<endl;
		}
};
int main()
{
    int choice;
    int n;
    Football* f = new Football[3];
    cout<<"Sports managment System: "<<endl;
    do
    {
        cout<<"1.Add new sports"<<endl;
		cout<<"2.Display Details of football sports"<<endl;
        cout<<"3.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<""
            break;
        
        default:
            break;
        }
    } while (/* condition */);
    
}