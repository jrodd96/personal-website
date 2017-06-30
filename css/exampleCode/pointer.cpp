/// pointers
#include <iostream>

using namespace std;

int main()
{

    int firstValue = 5, secondValue = 15;
    int * p1, * p2;

    p1 = &firstValue;  /// p1 = address of firstValue
    p2 = &secondValue; /// p2 = address of secondValue
    *p1 = 10;         /// value pointed to by p1 = 10
    *p2 = *p1;    /// value pointed to by p2 = value pointed to by p1
    p1 = p2;          /// p1 = p2 (value of pointer is copied)
    *p1 = 20;         /// value pointed to by p1 = 20

    cout << "firstValue is " << firstValue << endl;
    cout << "secondValue is " << secondValue << endl;

    return 0;

} /// end main

/// Dereference operator (*): Precedes pointer name to access variable
/// they point to directly. "Value pointed by"
///
/// Address-of operator (&): Precedes name of a variable to obtain the
/// address of a variable in memory
