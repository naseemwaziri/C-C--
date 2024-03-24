#include <iostream>
using namespace std;

bool all_the_same(int x, int y, int z){
    return (x==y) && (y == z);
}
bool all_the_different(double x, double y, double z){
    return (x != y) && (y != z) && (x != z);
}
bool sorted(double x, double y, double z){
    return (x <= y) && (y <= z);
}

int main(){
    int a = 12, b = 12, c = 12 ;
    double m = 3.5, n = 4.6, o = 7.8;
    double p = 1.2, q = 2.3, r = 3.5;
    cout<<boolalpha;
    cout<<"All are same: (25,25,25)  "<<all_the_same(a,b,c)<<endl;
    cout<<"All are different: (3.5, 4.6, 7.8)  "<<all_the_different(m,n,o)<<endl;
    cout<<"All are sorted: (1.2, 2.3, 3.5)  "<<sorted(p,q,r)<<endl;
    return 0;
}