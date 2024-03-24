#include <iostream>
#include <string>
using namespace std;

class Poll 
{
    private:
    int pollID;
    string question;

    public:
    Poll(int id, string q) : pollID(id), question(q) {}

    void displayPoll()
        {
        cout <<"Poll ID: " <<pollID <<endl;
        cout <<"Question: " <<question <<endl;
    }
};

class MultipleChoicePoll : public Poll
{
    private:
    string option1, option2, option3;

    public:
    MultipleChoicePoll(int id, string q, string opt1, string opt2, string opt3) : Poll(id, q), option1(opt1), option2(opt2), option3(opt3) {}

    void displayPoll()
    {
        Poll::displayPoll();
        cout <<"Options:\n";
        cout <<"- " <<option1 <<endl;
        cout <<"- " <<option2 <<endl;
        cout<<"- " <<option3 <<endl;
    }
};

class YesNoPoll : public Poll 
{                                                                                   
    public:
    YesNoPoll(int id, string q) : Poll(id, q) {}

    void displayPoll() {
        Poll::displayPoll();
        cout << "Options:" <<endl;
        cout << "- Yes" <<endl;
        cout <<"- No" <<endl;
    }
};

int main()
{
    MultipleChoicePoll mcp(123, "Which programming languages do you know?", "C++", "Java", "Python");
    YesNoPoll ynp(456, "Do you enjoy coding?");

    mcp.displayPoll();
    cout << endl;
    ynp.displayPoll();

    return 0;
}