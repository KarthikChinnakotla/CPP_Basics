/*

Purpose:
- Array of Objects

Rules:
- Array of Objects

Application:
- Array of Objects

c++98:
c++03:
c++11:
c++14:
c++17:
c++20:
c++23:


Demos:

demo 1:     Array of Objects with single parameterized constructor
demo 2:     Array of objects with multi parameterized constructor
demo 3:     Creating Uninitialized and Initialized arry of objects
*/

#include <iostream>
using namespace std;

//#define demo1
//#define demo2
#define demo3

#if defined(demo1)

#ifndef ARRAY_OF_OBJECTS
#define ARRAY_OF_OBJECTS

class c1
{
    private:
        int i;                  // private data member
    public:
        c1(int j);              // Parameterized constructor

        int get_i()
        {
            return i;
        }
};

c1::c1(int j)                   // parameterized constructor definition
{
    i = j;
}

int main()
{
    c1 obj[3] = {1,2,3};        // Array of objects of type class c1 initialized with single parameter
    int i;

    for(i=0;i<3;i++)
        cout << "i =" << obj[i].get_i() << endl;

    return 0;
}


#endif // ARRAY_OF_OBJECTS
#endif // demo 1

#if defined(demo2)          // Array of objects with multi parameterized constructor

#ifndef ARRAY_OF_OBJECTS
#define ARRAY_OF_OBJECTS

class c1
{
    private:
        int a,b,c;                  // private data members
    public:
        c1(int i, int j, int k);    // multi parameterized constructor

        int get_a()
        {
            return a;
        }

        int get_b()
        {
            return b;
        }

        int get_c()
        {
            return c;
        }
};

c1::c1(int i, int j, int k)         // constructor definition
{
    a = i;
    b = j;
    c = k;
}

int main()
{
    //c1 obj[3] = { {1,2,3}, {4,5,6}, {7,8,9} };            // Syntax style 1 // 3 objs created & initialized
    c1 obj[3] = { c1(1,2,3), c1(4,5,6), c1(7,8,9) };        // Syntax style 2 // 3 objs created & initialized
    int k =0;

    for(k=0;k<3;k++)
    {
        cout << "a = " << obj[k].get_a() << endl;
        cout << "b = " << obj[k].get_b() << endl;
        cout << "c = " << obj[k].get_c() << endl;
        cout << endl;
    }

    return 0;
}
#endif  // ARRAY_OF_OBJECTSc
#endif  // demo 2

#if defined(demo3)

#ifndef ARRAY_OF_OBJECTS            // Include guard
#define ARRAY_OF_OBJECTS

class c1
{
    private:
        int a,b;                    // Private data members
    public:
        c1();                       // Parameter Less constructor declaration
        c1(int i, int j);           // Parameterized constructor declaration
        
        int get_a()
        {
            return a;
        }

        int get_b()
        {
            return b;
        }
};

c1::c1(int i, int j)                // Parameterized constructor definition
{
    a = i;
    b = j;
}

c1::c1()                            // Parameter Less constructor definition
{
    a = 0;
    b = 0;
}

int main()
{
    c1 objA[3] = { {1,2}, {3,4}, {5,6} };       // 3 Objs created and initialized array
    c1 objB[3];                                 // 4 Objs created and non initialized array

    int k=0;

    for(k=0;k<3;k++)
    {
        cout << "objA Values" << endl;
        cout << "a = " << objA[k].get_a() << endl;
        cout << "b = " << objA[k].get_b() << endl;
        cout << endl;

        cout << "objB Values" << endl;
        cout << "a = " << objB[k].get_a() << endl;
        cout << "b = " << objB[k].get_b() << endl;
        cout << endl;   
    }

    return 0;
}

#endif  // ARRAY_OF_OBJECTS
#endif  // demo 3