#include<iostream>
using namespace std;
class Rectangle {
    protected:
    float height;
    float width;
    public:
    Rectangle(){
        height=3.0;
        width=1.0;
    }
    Rectangle(float h, float w){
        width=w;
        height=h;
    }
    void area(){
        cout<<"Area : "<<width*height<<endl;
    }
    void pare(){
        cout<<"Paremeter : "<<2*(width+height)<<endl;
    }
    Rectangle operator + (Rectangle r2){

    return Rectangle(this->height+r2.height,this->width+r2.width);
    }
};
int main(){
    Rectangle r1,r2(2.0,3.0),r3;
    r1.area();
    r1.pare();
    r2.area();
    r2.pare();
    cout<<endl;
    r3=r1+r2;
    cout<<endl;
    r3.area();
    r3.pare();
    r2.area();
    r2.pare();
    return 0;
}
