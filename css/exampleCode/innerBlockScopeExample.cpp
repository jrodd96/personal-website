/// inner block scopes
#include <iostream>

using namespace std;

int main()
{

    int x = 10;
    int y = 20;
    {
        int x;  // ok, inner scope
        x = 50; // sets value to inner x
        y = 50; // sets value to (outer) y
        cout << "inner block:" << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
    cout << "outer block:" << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;

} /// end main
