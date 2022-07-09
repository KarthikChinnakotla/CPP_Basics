/*

Purpose:
1. prevent re-definition
2. prevent multiple inclusions in a single compilation unit

Rules:
1. using pre-processor directives
2. standard: capitalize the name of the header file; replace periods with underscore

Application:
1. All Header files
4
Demo:
demo1: Basic Header file include guard

*/

#define demo1

#if defined(demo1)

#include <iostream>
using namespace std;

#ifndef HEADER_FILE_INCLUDE_GUARD           // File name in CAPS as Include guard
#define HEADER_FILE_INCLUDE_GUARD

class c1
{
    public:
        c1();
        int a, b;
};

c1::c1()
{
    a = 5;
    b = 6;
}

int main()
{
    c1 x;

    cout << x.a << endl;
    cout << x.b << endl;

    return 0;
}

#endif // HEADER_FILE_INCLUDE_GUARD         // Include guard ends here

#endif