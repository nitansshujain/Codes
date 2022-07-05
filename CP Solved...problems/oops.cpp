#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

class A
{
public:
    void fun() { cout << 'A'; }
};
class B
{
public:
    void fun() { cout << 'B'; }
};
class C : public A, public B
{
public:
    void fun()
    {
        A::fun();
        B::fun();
    }
};
int main()
{
    C c;

    c.fun();
    return 0;
}