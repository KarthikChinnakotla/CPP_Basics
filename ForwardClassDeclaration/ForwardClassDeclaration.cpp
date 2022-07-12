/*
Forward Declarations (Forward Reference)

Purpose: (what is this)
--------
1. class c2 is referred in class c1 declaration, 
 - but(before) class c2 is not yet declared;
    in a way telling compiler before hand that class c2 shall be declared shortly

Rules:
------
1. mention class c2 before and outside of class c1

Application:
------------
1. Telling compiler before hand that c2 is being used before declaration

versions:
----------
c++98: probably here
c++03:
c++11:
c++14:
c++17:
c++20:
c++23:

Demos:
------
demo 1: Forward class declartion

*/

#include <iostream>
using namespace std;

#define demo1

#if defined(demo1)

class c2;                  // Forward declaration telling compiler that definition of Class c2 is coming
                           // shortly

class c1                   // class c1
{
   private:
      int a;
   public:
      c1();
      void set_value(class c2);        // class c1 refers class c2 before c2 is being defined
};

class c2
{
   public:
      int b = 25;
};

// constructor 
c1::c1()
{
   a = 5;                               // initial value of a = 5
   cout << "a = " << a << endl;
}  

void c1::set_value(c2 x)                // class c2 obj is passed to class c1 member function
{
   a = x.b;                             // class c1 data member is assigned with value from class c2 member
   cout << "a = " << a << endl;
}

int main()
{
   c1 x;                                // Obj of class c1
   c2 y;                                // Obj of class c2

   x.set_value(y);                      // class c1 member function called

   return 0;
}

#endif // demo 1
