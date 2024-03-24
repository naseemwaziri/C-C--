#include <iostream>
#include <string>

using namespace std;

class Question 
{
protected:
    int questionID;
    string questionText;

public:
    Question(int id, string text)
    {
        questionID = id;
        questionText = text;
    }

    void generateQuestion() {
        cout << "Question ID: " << questionID << "\n";
        cout << "Question Text: " << questionText << "\n";
    }
};

class MultipleChoiceQuestion : public Question 
{
private:
    string option1, option2, option3, option4;

public:
    MultipleChoiceQuestion(int id, string text) : Question(id, text) {}

    void setOptions(string opt1, string opt2, string opt3, string opt4) {
        option1 = opt1;
        option2 = opt2;
        option3 = opt3;
        option4 = opt4;
    }

    void generateQuestion() 
    {
        Question::generateQuestion();
        cout << "1. " << option1 << "\n";
        cout << "2. " << option2 << "\n";
        cout << "3. " << option3 << "\n";
        cout << "4. " << option4 << "\n";
    }
};

class TrueFalseQuestion : public Question 
{
private:
    bool isTrue;

    public:
    TrueFalseQuestion(int id, string text) : Question(id, text) {}

    void setIsTrue(bool truth) 
    { 
        isTrue = truth; 
    }

    void generateQuestion() 
    {
        Question::generateQuestion();
        if (isTrue) 
        {
            cout << "True" << "\n";
        } 
        else 
        {
            cout << "False" << "\n";
        }
    }
};

int main() {
    MultipleChoiceQuestion mcq(123, "What is the capital of France?");
    mcq.setOptions("London", "Paris", "Berlin", "Madrid");
    mcq.generateQuestion();

    TrueFalseQuestion tfq(456, "The Earth is flat.");
    tfq.setIsTrue(false);
    tfq.generateQuestion();

    return 0;
}