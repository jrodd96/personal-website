/// pointers as arguments
#include <iostream>

using namespace std;

void incrementAll(int* start, int* stop) {

    int * current = start;
    while(current != stop) {
        ++(*current);  // increment value pointed
        ++current;      // increment pointer
    }

}
///============================================
void printAll(const int* start, const int* stop) {

    const int * current = start;
    while(current != stop) {
        cout << *current << endl;
        ++current;  // increment pointer
    }

}
///============================================
int main()
{

    int numbers[] = {10,20,30};
    incrementAll(numbers, numbers+3);
    printAll(numbers, numbers+3);

    return 0;

} /// end main
