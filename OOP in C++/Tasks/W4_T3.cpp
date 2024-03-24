#include <iostream>
#include <string>
using namespace std;

class Batsman
{
    private:
    int bcode;
    string bname;
    int innings, notout, runs ;

    float calavg();

    public:
    void readata();
    void displayData();
}
float Batsman :: calavg(){
    return batavg = runs / (innings-notout);
}
void Batsman :: readata(){
    cout<<"Enter Batsman Code: ";
    cin>>bcode;
    cout<<"Enter Batsman Name: ";
    cin>> bname;
    cout<<"Enter Batsman Innings: ";
    cin>> innings;
    cout<<"Enter Batsman Not Out: ";
    cin>> notout;
    cout<<"Enter Batsman Runs: ";
    cin>> runs;
}
void Batsman ::displayData(){
    cout<<"Batsman code: "<<bcode << endl;
    cout<<"Batsman Name: "<<bname << endl;
    cout<<"Batsman Innings: "<<innings << endl;
    cout<<"Batsman Notout: "<<notout << endl;
}
