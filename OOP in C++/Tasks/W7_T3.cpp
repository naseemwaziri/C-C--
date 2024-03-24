#include <iostream>
using namespace std;

class Player
{
    private:
    string name;
    string team_name;
    string position;
    float rating;

    public:
    Player(string name, string team_name, string position, float rating){
        this -> name = name;
        this -> team_name = team_name;
        this -> position = position;
        this -> rating = rating;
        cout<<name <<" "<<team_name <<" "<<position <<" " <<rating <<endl;
    }
    void set_name(string n){
        name = n;
    }
    void set_team_name(string t){
        team_name = t;
    }
    void set_position(string p){
        position = p;
    }
    void set_rating(float r){
        rating = r;
    }
    void display_details(){
        cout<<name << " "<<team_name <<" "<<position <<" "<<rating <<endl;
    }
};

int main()
{
    Player p("asad","tiger", "1st", 2.4);
    p.set_name("ali");
    p.set_team_name("lion");
    p.set_position("4th");
    p.set_rating(6.7);
    p.display_details();

    return 0;
}