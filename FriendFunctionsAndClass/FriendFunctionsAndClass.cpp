/*
Friend Functions; Friend Classes

Purpose: (What is this)
--------
1. Grant access to a function that isn't a member of the current class.
2. 


Rules:
------
1. declaring that function a "friend" inside the class declaration.
2. Friend function has access to all private and protected members of the class to which it is a friend.

Application:
------------
1. 

versions:
---------

c++98: here
c++03:
c++11: improved (TODO)
c++14:
c++17:
c++20:
c++23:

Demos:
------

demo1:   Friend function demo accessing private members
demo2:   Common friend function for 2 classes
demo3:   Friend of one class being member of another class
demo4:   Friend class

*/

#include <iostream>
using namespace std;

//#define demo1
//#define demo2
//#define demo3
#define demo4

/*
demo1:   Friend function demo accessing private members
*/
#if defined(demo1)
class myclass
{
    private:
        int a, b;   // private members
    public:
        friend int sum(myclass);
        myclass();
};

// Constructor
myclass::myclass()
{
    a = 5;
    b = 6;
}

// Friend function not part of class but has access to private and protected members
int sum(myclass X)
{
    return X.a+X.b;     
}

int main()
{
    myclass X;
    cout << sum(X) << endl;      // friend function call
    return 0;
}
#endif // demo1

/*
demo2:   Common friend function for 2 classes
*/
#if defined(demo2)

const int NOT_IN_USE = 0;
const int IN_USE = 1;

class c2;

class c1
{
    private:
        int status;
    public:
        c1();
        friend void isIdle(c1 ,c2);
};

c1::c1()
{
    status = IN_USE;  
}

class c2
{
    private:
        int status;
    public:
        c2();
        friend void isIdle(c1, c2);
};

c2::c2()
{
    status = NOT_IN_USE;
}

void isIdle(c1 a, c2 b)
{
    if( (a.status == IN_USE) || (b.status == IN_USE) )
    {
        cout << "Inuse" << endl;
    }
    else
    {
        cout << "Not In Use" << endl;
    }    
}

int main()
{
    c1 X;
    c2 Y;

    isIdle(X,Y);
    
    return 0;
}
#endif

/*
demo3:   Friend of one class being member of another class
*/
#if defined(demo3)

const int NOT_IN_USE = 0;
const int IN_USE = 1;

class c2;   // Forward declaration

class c1
{
    private:
        int status;
    public:
        c1();
        void isIdle(c2);
};

c1::c1()
{
    status = NOT_IN_USE;
}

class c2
{
    private:
        int status;
    public:
        c2();
        friend void c1::isIdle(c2);
};

c2::c2()
{
    status = NOT_IN_USE;
}

void c1::isIdle(c2 b)
{
    if( (status == IN_USE) || (b.status == IN_USE) )
    {
        cout << "InUse" << endl;
    }
    else
    {
        cout << "NOT_IN_USE" << endl;
    }
}

int main()
{
    c1 X;
    c2 Y;

    X.isIdle(Y);

    return 0;
}

#endif

/*
demo4:   Friend class
*/
#if defined(demo4)

class TwoValues
{
    private:
        int a;                      // private data members
        int b;
    public:
        TwoValues(int i,int j); 
        friend class Min;           // friend class
};

// constructor
TwoValues::TwoValues(int i, int j)
{
    a = i;
    b = j;
}

class Min
{
    public:
        int min(TwoValues x);       // Friend class using another class object private data members
};

int Min::min(TwoValues x)
{
    return x.a < x.b ? x.a : x.b;
}

int main()
{
    TwoValues obj(22,10);           // Obj 1
    Min m;                          // Friend class Obj

    cout << m.min(obj) << endl;     // Friedn class using Obj1 private data members

    return 0;
}

#endif

