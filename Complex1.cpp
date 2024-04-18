#include <iostream>
using namespace std;
class Complex
{
    private:
    int real,imag;
    public:
    Complex(int a=0,int b=0)
    {
        real=a;
        imag=b;
    }
    Complex operator+(Complex &s)
    {
        Complex e;
        e.real=real+s.real;
        e.imag=imag+s.imag;
        return e;
    }
    Complex operator-(Complex &s)
    {
        Complex e;
        e.real=real-s.real;
        e.imag=imag-s.imag;
        return e;
    }
    Complex operator*(Complex &s)
    {
        Complex e;
        e.real=real*s.real-imag*s.imag;
        e.imag=real*s.imag-imag*s.real;
        return e;
    }
    Complex operator/(Complex &s)
    {
        Complex e;
        e.real=(real*s.real-imag*s.imag)/(s.imag*s.imag+s.real*s.real);
        e.imag=(real*s.imag-imag*s.real)/(s.imag*s.imag+s.real*s.real);
        return e;
    }
    void show()
    {
        cout<<"real:"<<real;
        cout<<"imag:"<<imag<<endl;
    }
    ~Complex()
    {
        cout<<"888"<<endl;
    }
};

int main()
{
    Complex a(1,1),b(2,2),c;
    a.show();
    b.show();
    c=a+b;
    c.show();
    (a+b).show();
    (a-b).show();
    (a*b).show();
    (b/a).show();
}