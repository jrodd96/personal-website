/// static vs automatic storage
///
///   -Variables with static storage (such as global variables) that
///   are not explicitly initialized are automatically initialized to zeroes.
///
///   -Variables with automatic storage (such as local variables) that
///   are not explicitly initialized are left uninitialized, and thus
///   have an undetermined value.
///
///-------------------------------------------
#include <iostream>

using namespace std;

int x;  /// global variable = static = 0

int main()
{

    int y; /// local variable = automatic = ?

    cout << x << endl;
    cout << y << endl;

    return 0;

} /// end main
