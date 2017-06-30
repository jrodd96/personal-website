// namespace example
#include <iostream>

using namespace std;

namespace foo
{
    int value() {                /// same name
        return 5;
    }
}
///====================================
namespace bar
{
    const double pi = 3.1416;
    double value() {             /// same name
        return 2*pi;
    }
}
///====================================
///************************************
namespace first
{
    int x = 5;
    int y = 10;
}
///====================================
namespace second
{
    double x = 3.1416;
    double y = 2.7183;
}
///====================================
int main()
{

    cout << foo::value() << endl;  /// no redefinition thanks to namespaces
    cout << bar::value() << endl;
    cout << bar::pi << endl;

    cout << endl;

    //---------------------------------------------

    using first::x;     /// avoid having to restate first::x
    using second::y;    /// avoid having to restate second::y

    cout << x << endl;  /// example using x w/o first::
    cout << y << endl;  /// example using y w/o second::
    cout << first::y << endl;
    cout << second::x << endl;

    return 0;

} /// end main
