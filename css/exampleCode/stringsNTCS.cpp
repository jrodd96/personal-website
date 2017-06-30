/// strings and NTCS:
#include <iostream>
#include <string>

using namespace std;

int main()
{

    char question1[] = "What is your name? ";  /// NTCS
    string question2 = "Where do you live? ";  /// same thing in string form
    char answer1[80];
    string answer2;

    cout << question1;
    cin >> answer1;
    cout << question2;
    cin >> answer2;
    cout << "Hello, " << answer1;
    cout << " from " << answer2 << "!\n";

    //----------------------------------------------

    char myNTCS[] = "some text";
    string mystring = myNTCS;  /// convert c-string to string
    cout << mystring;         /// printed as library string
    cout << mystring.c_str(); /// printed as c-string

    return 0;

} /// end main
