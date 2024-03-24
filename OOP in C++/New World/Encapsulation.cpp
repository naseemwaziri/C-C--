#include <iostream>
using namespace std;

class Rectangle{
    private:
    int height;
    int weight;

    public:
    void set_height(int h){
        height = h;
    }
    void set_weight(int w){
        weight = w;
    }
    int get_height(){
        return height;
    }
    int get_weight(){
        return weight;
    }
    int get_area(){
        return height * weight;
    }

};

int main(){
    Rectangle rect;
    int inputHeight, inputWeight;
    cout<<"Enter Height: ";
    cin>>inputHeight;
    cout<<"Enter Weight: ";
    cin>>inputWeight;

 // rect.set_height(5);  default value
 // rect.set_weight(4);  default value

    rect.set_height(inputHeight);
    rect.set_weight(inputWeight);

    cout<<"Height is: "<<rect.get_height() <<endl;
    cout<<"Weight is: "<<rect.get_weight() << endl;
    cout<<"Area OF Rectangle Is: "<<rect.get_area();
 
    return 0;
}