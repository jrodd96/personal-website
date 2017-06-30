/// passing parameters by reference
#include <iostream>

using namespace std;

void duplicate(int& a, int&b, int&c) {

    a *= 2;
    b *= 2;   /// ^^& passes values by reference
    c *= 2;   /// <= *= is "multiply by this equal value"
    //c = 2*2;

}
///==============================================
inline string concatenate(const string& a, const string& b) {

    return a+b;   /// ^^by qualifying string as reference and const, function is
                  /// forbidden to modify values of a nor b, but can access their
                  /// values as references without making copies of strings

                  /// ^^using inline informs compiler that function body should be inserted
                  /// at each point the function is called instead of being invoked with regular
                  /// function call.
}
///==============================================
int main()
{

    int x = 1, y =3, z = 7;
    duplicate(x, y, z);
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
 /// x != 1 instead x = 1*2 = 2
 /// y != 3 instead y = 3*2 = 6
 /// z != 7 instead z = 7*2 = 14

 /// if function duplicate was duplicate(int a, int b, int c),
 /// results would be x=1, y=3, z=7.

    string a, b;
    concatenate(a, b);

    return 0;

} /// end main
