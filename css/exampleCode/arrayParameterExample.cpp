/// arrays as parameters
#include <iostream>

using namespace std;

void printArray(int arg[], int length) {

    for(int n=0; n<length; ++n)
        cout << arg[n] << " ";
    cout << endl;

}
///==========================================
int main()
{

    int firstArray[] = {5,10,15};
    int secondArray[] = {2,4,6,8,10};

    printArray(firstArray, 3);
    printArray(secondArray, 5);

    return 0;

} /// end main
