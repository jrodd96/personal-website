/// overloading functions
/// functions can be overloaded if their parameters
/// are different; either different number or type
#include <iostream>

using namespace std;

int operate(int a, int b) {

    return (a*b);

}
//---------------------------------------
double operate(double a, double b) {

    return (a/b);

}
///*************************************************
template <class T>  // using template allows overloading
T sum(T a, T b) {

    T result;
    result = a + b;
    return result;

}
///*************************************************
template <class U, class V>  // multiple template parameters
bool areEqual(U a, V b) {

    return (a==b);

}
///*************************************************
///==============================================
int main()
{

    int x=5, y=2;
    double n=5.0, m=2.0;

    cout << operate(x,y) << endl;
    cout << operate(n,m) << endl;

    //------------------------------------------

    int i=5, j=6, k;
    double f=2.0, g=0.5, h;

    k=sum<int>(i,j);     // overload sum for int parameter
    h=sum<double>(f,g);  // overload sum for double parameter

    cout << k << "\n" << h << endl;

    //------------------------------------------

    if(areEqual(10,10.0))
        cout << "x and y are equal" << endl;
    else
        cout << "x and y are not equal" << endl;

    //-------------------------------------------

    return 0;

} /// end main
