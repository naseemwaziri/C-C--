#include <iostream>
#include <string>
using namespace std;

bool login(string username, string password) {
    string validUsername = "Admin2";
    string validPassword = "Bigbang@23";

    if (username == validUsername && password == validPassword) {
        return true; 
    } else {
        return false;
    }
}

int main() {
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (login(username, password)) {
        cout << "Login successful!";
    } else {
        cout << "Invalid username or password!";
    }

    return 0;
}
