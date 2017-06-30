/// stringstream example
#include <iostream>
#include <sstream>

using namespace std;

int main()
{

    string mystr;
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin, mystr);           /// input for mystr
    stringstream(mystr) >> price;  /// converts string to float value of price
    cout << "Enter quantity: ";
    getline(cin, mystr);             /// input
    stringstream(mystr) >> quantity; /// convert to integer for quantity
    cout << "Total price: " << price * quantity << endl;
    return 0;

} /// end main
