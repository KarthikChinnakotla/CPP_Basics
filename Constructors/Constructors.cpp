/*
Demonstration of Constructor

Purpose:

1. initialize variables of object when it is created
(or) to invoke functions when an object of your class is created
2. Assign dynamic memory

Rules:

1. should have same name as Class
2. no return type allowed - even void is not allowed
3. cannot be called explicitly like regular member functions
4. You can define as many overloaded constructors as needed to customize initialization in various ways.
5. Scope:
    Typically, constructors have public accessibility so that code outside the class definition or
    inheritance hierarchy can create objects of the class. 
    But you can also declare a constructor as protected or private.
6. Initializing types:
    2 types generally
    1 - assigning values in the constructor body
    2 - Constructors can optionally take a member initializer list. 
        It's a more efficient way to initialize class members than assigning values in the constructor body.

Things to know:

1. Default constructor
2. Initialization
3. Copy constructor
4. Copy Assignment
5. move constructor - Modern C++ 14
6. move assignment  - Modern C++ 14

Advanced:

1. constructor operation during Inheritance
2. cosntructor operation during Aggregation
3. 

Investigations: (To Rename)

1. what if constructor is not written explicitly?
2. For default constructors, what are the initialized values?
3. Can default constructor and explicit constructor co-exist?
4. Do we need to write default constructor definition or will the compiler take care of it?
4. If explicit constructor is written, whether default constructor would be called?
5. 

c++98:
c++03:
c++11:
c++14:
c++17:
c++20:
c++23:

// Demo1:
// 

// Demo2: 
// Creating Array of Objects without Default constructor is not allowed

// Demo 3:

// Demo 4:
*/

//#define demo1
//#define demo2
//#define demo3
#define demo4
//constexpr demo3;

#if defined(demo1)

#include <iostream>
using namespace std;

class CRectangle
{
    int width;
    int height;

    public:
        CRectangle(int, int);   // constructor prototype

        int area()
        {
            return (width * height);
        }
};

// Constructor function definition
CRectangle::CRectangle(int a, int b)
{
    width = a;
    height = b;

    cout << "In Constructor - width = " << width << endl;
    cout << "In Constructor - height = " << height << endl;

}

int main()
{

    CRectangle recta(3,4);  // constructor function is invoked after object is created;not explicitly called
    CRectangle rectb(5,6);  // constructor function is invoked after object is created;not explicitly called

    cout << "recta area = " << recta.area() << endl;
    cout << "rectb.area = " << rectb.area() << endl;

    return 0;
}
#endif // Demo1

// Demo2: 
// Creating Array of Objects without Default constructor is not allowed
#if defined(demo2)

class Box
{
    public:
        // No default constructor
        
        // Parameterized - Member initialized list constructor
        Box(int width,int height,int length):m_width(width),m_height(height),m_length(length){}
    private:
        int m_width;
        int m_height;
        int m_length;
};

int main()
{
    //Box boxes[3];       // Cant do this "array of Objects" - without Default constructor
                        // Compiler will throw error "no default constructor exists for class "Box""

    // Correct soln for the above error is.,
    // 1. have a default constructor written
    // 2. see below 
    Box boxes[3]{ {1,2,3}, {1,2,3}, {1,2,3} };
    return 0;
}
#endif


// Demo3: 
// Creating Array of Objects without Default constructor is not allowed
// Here Constructor is not inlined inside, but only declared
// the defintion of constructor is done as a function. This style is mostly followed for 
// Large programs
#if defined(demo3)

#include <iostream>

class Box
{
    public:
        Box(int width, int height, int length);
    private:
        int m_width;
        int m_height;
        int m_length;
};

Box::Box(int width, int height, int length): 
    m_width(width),
    m_height(height),
    m_length(length)
{}

int main()
{
    Box B[3]{ {1,2,3}, {1,2,3}, {1,2,3} };

    return 0;
}

#endif

#if defined(demo4)

#include <iostream>

class Box
{
    public:
        Box();                  // constructor
        Box(Box& BoxCopy);      // Copy the constructor - copy constructor 
                                // Copies to a new object
                                // Copy assignment copies to already existing object
};

int main()
{
    return 0;
}
#endif