#include <iostream>
#include <string>

using namespace std;

class Subscription
{
    private:
    int subscriptionID;
    string title;
    int duration;

    public:
    Subscription(int id, string t, int d) : subscriptionID(id), title(t), duration(d) {}

    void displayDetails() 
    {
        cout << "ID: " << subscriptionID << ", Title: " << title << ", Duration: " << duration << " minutes\n";
    }

    void operator -() 
    {
        cout << "Subscription " << title << " has been cancelled.\n";
    }

    Subscription operator +(Subscription s)
    {
        string newTitle = this->title + s.title;
        int newDuration = this->duration + s.duration;
        return Subscription(0, newTitle, newDuration);
    }
};

class TVShow : public Subscription 
{
public:
    int seasons;

    TVShow(int id, string t, int d, int s) : Subscription(id, t, d), seasons(s) {}

    void displayDetails() {
        Subscription::displayDetails();
        cout << "Seasons: " << seasons <<endl;
    }
};

class Movie : public Subscription 
{
public:
    int releaseYear;

    Movie(int id, string t, int d, int y) : Subscription(id, t, d), releaseYear(y) {}

    void displayDetails() 
    {
        Subscription::displayDetails();
        cout << "Release Year: " << releaseYear <<endl;
    }
};

int main() 
{
    TVShow tvShow(123, "Friends", 25, 10);
    Movie movie(456, "Inception", 148, 2010);

    tvShow.displayDetails();
    movie.displayDetails();
    -tvShow;
    Subscription newSubscription = tvShow + movie;
    newSubscription.displayDetails();

    return 0;
}