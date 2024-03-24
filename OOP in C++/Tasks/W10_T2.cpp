#include <iostream>
#include <string>

using namespace std;

class User 
{
    private:
    int userID;
    string name;

    public:
    User(int id, string name) 
    {
        this->userID = id;
        this->name = name;
    }

    int getUserID() 
    {
        return userID;
    }

    string getName() 
    {
        return name;
    }

    void displayProfile() 
    {
        cout <<"User ID: " <<userID <<endl;
        cout <<"Name: " <<name <<endl;
    }

    void sendFriendRequest(User& user) 
    {
        cout <<"Friend request sent to " <<user.getName() <<endl;
    }
};

class Post : public User 
{
    private:
    int postID;
    string content;
    int numLikes;

    public:
    Post(int userID, string name, int postID, string content, int numLikes)
        : User(userID, name), postID(postID), content(content), numLikes(numLikes) {}

    int getPostID() 
    {
        return postID;
    }

    string getContent() 
    {
        return content;
    }

    int getNumLikes() 
    {
        return numLikes;
    }

    void displayPost() 
    {
        cout <<"Post ID: " <<postID <<endl;
        cout <<"Content: " <<content <<endl;
        cout <<"Number of likes: "<< numLikes <<endl;
    }

    void likePost() {
        numLikes++;
    }

    void sendFriendRequest(User& user) 
    {
        User::sendFriendRequest(user);
    }
};

int main() {
    int id;
    string name;

    cout <<"Enter user 1 ID: ";
    cin >>id;
    cout <<"Enter user 1 name: ";
    cin >>name;
    User user1(id, name);

    cout <<"Enter user 2 ID: ";
    cin >>id;
    cout <<"Enter user 2 name: ";
    cin >>name;
    User user2(id, name);

    user1.displayProfile();
    user2.displayProfile();

    user1.sendFriendRequest(user2);

    int postID, numLikes;
    string content;

    cout << "Enter post ID: ";
    cin >> postID;
    cin.ignore();
    cout << "Enter post content: ";
    getline(cin, content);
    cout << "Enter initial number of likes: ";
    cin >> numLikes;

    Post post(user1.getUserID(), user1.getName(), postID, content, numLikes);

    post.displayPost();

    post.likePost();

    post.displayPost();

    return 0;
}