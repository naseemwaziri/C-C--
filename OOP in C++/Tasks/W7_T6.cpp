#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;

public:
    Person() : name("unknown"), age(0), gender('U') {}

    Person(string name, int age) : name(name), age(age), gender('U') {}

    Person(string name, int age, char gender) : name(name), age(age), gender(gender) {}
};