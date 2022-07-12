/*
CPP Basics
First cpp program - Simple print execution

//#define demo1 // print using cout
//#define demo2 // create string using vector string and print using iterator
//#define demo3 // vector string + using For loop with range - C++11
#define demo4 // vector string + using For loop with range + Efficient memory handling- C++11

c++98:
c++03: std::vector - instead of arrays
c++11: for loop with range
c++14:
c++17:
c++20:
c++23:

Performance: 
- Yes - see demo 3 and demo 4
*/

#include <iostream>
#include <vector>
#include <string>

//#define demo1 // print using cout
//#define demo2 // create string using vector string and print using iterator
//#define demo3 // vector string + using For loop with range - C++11
#define demo4 // vector string + using For loop with range + Efficient memory handling- C++11

using namespace std;

#if defined(demo1)
int main()
{
    cout << "Demo1 - Hello World First CPP Program" << endl;
}
#endif // demo1

#if defined(demo2)
int main()
{
    vector<string> str{"Demo2", "Hello", "World" , "First" , "CPP" , "Program"};
    vector<string>::iterator ptr;

    for(ptr=str.begin();ptr != str.end();ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}
#endif // demo2

#if defined(demo3)
int main()
{
    vector<string> str{"Demo3" , "Hello", "World", "First", "CPP", "Program"};

    // string tempStr : str - Copies each element of str to the tempStr variable in each iteration. 
    // This is not good for computer memory.
    for(const string tempStr : str)
    {
        cout << tempStr << " ";
    }

    cout << endl;
}
#endif // demo3

#if defined(demo4)
int main()
{
    vector<string> str{"Demo4" , "Hello", "World", "First", "CPP", "Program"};

    // string& tempStr: str - Does not copy each element of str to tempStr.
    // Instead, accesses the elements of str directly from str itself. This is more efficient.
    // Comparing to demo3
    for(const string& tempStr: str)
    {
        cout << tempStr << " ";
    }
}
#endif // demo4

    
    
