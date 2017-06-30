/// arrays example
#include <iostream>

#define WIDTH 5
#define HEIGHT 3

using namespace std;

int foo [] = {16, 2, 77, 40, 12071};
int i, result = 0;

int jimmy [HEIGHT][WIDTH];  /// multidimensional array
int john [HEIGHT * WIDTH];  /// pseudo-multidimensional array
int n, m;


int main()
{

    for(i=0; i<5; ++i)
        result += foo[i];
    cout << result << endl;

    //------------------------------------

    for(n=0; n<HEIGHT; n++)
        for(m=0; m<WIDTH; m++)
        {
            jimmy[n][m]=(n+1)*(m+1);
            john[n*WIDTH+m]=(n+1)*(m+1);
        }

    return 0;

} /// end main
