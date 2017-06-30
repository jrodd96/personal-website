/// conditional ternary operator (?) example

#include <iostream>

using namespace std;

int main()
{

    int a, b, c;

    a=2; b=7;
    c = (a > b) ? a : b;   /// if true, expression evaluates to a
                           /// otherwise, evaluates to b
    cout << c << endl;

} /// end main
