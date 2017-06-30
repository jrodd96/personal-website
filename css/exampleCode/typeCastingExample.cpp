/// type casting operator example

#include <iostream>

using namespace std;

int main()
{

    int i;
    float f = 3.14;
  //i = int (f);
    i = (int) f;        /// converts decimal 3.14 to integer
    cout << f << endl;  /// value 3. Remainder lost.

    int x;
    x = sizeof (char);  /// x is assigned value of 1.
    cout << x << endl;  /// char is type with size 1 byte



} /// end main
