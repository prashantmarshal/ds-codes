#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Base  {
public:
    Base()    { cout << "Constructor: Base" << endl; }
    virtual ~Base()   { cout << "Destructor : Base" << endl; }
};

class Derived: public Base {
public:
    Derived()   { cout << "Constructor: Derived" << endl; }
    virtual ~Derived()   { cout << "Destructor : Derived" << endl; }
};

int main()  {
    Derived *Var = new Derived();
    delete Var;
    return 0;
}