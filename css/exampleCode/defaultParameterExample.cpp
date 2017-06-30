/// default values in functions
#include <iostream>

using namespace std;

int divide(int a, int b=2) {

    int r;
    r = a/b;
    return (r);

}
///=====================================
int main()
{

    cout << divide(12) << endl;     /// a = 12, b = default value of 2
    // 12 / 2 = 6
    cout << divide(20, 4) << endl;  /// a = 20, b = set value of 4
    // 20 / 4 = 5
    return 0;

} /// end main
