#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string account_number;
    string account_holder_name;
    double balance;
    double interest_rate;
public:
    BankAccount() {
        this->account_number = "unknown";
        this->account_holder_name = "unknown";
        this->balance = 0;
        this->interest_rate = 0.01;
    }

    BankAccount(string account_number, string account_holder_name) {
        this->account_number = account_number;
        this->account_holder_name = account_holder_name;
        this->balance = 0;
        this->interest_rate = 0.01;
    }

    BankAccount(string account_number, string account_holder_name, double balance, double interest_rate) {
        this->account_number = account_number;
        this->account_holder_name = account_holder_name;
        this->balance = balance;
        this->interest_rate = interest_rate;
    }
};

int main() {

    BankAccount account1;

    BankAccount account2("123456", "Farhan Ahmad");

    BankAccount account3("789012", "Farhan Ahmad", 10000.0, 0.02);

    return 0;
}