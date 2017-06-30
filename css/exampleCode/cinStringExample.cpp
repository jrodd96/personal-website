/// cin with strings example
#include <iostream>
#include <string>

using namespace std;

int main()
{

    string mystr;
    cout << "What's your name? ";
    getline(cin, mystr);
    cout << "Hello " << mystr << "." << endl;
    cout << "What is your favorite team? ";
    getline(cin, mystr);
    cout << "I like " << mystr << " too!" << endl;
    return 0;

} /// end main
