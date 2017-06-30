/// factorial calculator (recursivity)
#include <iostream>

using namespace std;

long factorial (long a) {

    if(a > 1)
        return (a * factorial(a-1));
    else
        return 1;

    /// recursivity = function calling itself

}
///====================================
int main()
{

    long number = 0;
    cout << "Enter number of factorial: ";
    cin >> number;
    cout << "\n" << number << "! = " << factorial(number);

    return 0;

} /// end main
