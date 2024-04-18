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
    friend Complex operator+(Complex a,Complex b);
    friend Complex operator-(Complex a,Complex b);
    friend Complex operator*(Complex a,Complex b);
    friend Complex operator/(Complex a,Complex b);
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
Complex operator+(Complex a,Complex b)
    {
        Complex e;
        e.real=a.real+b.real;
        e.imag=a.imag+b.imag;
        return e;
    }
    Complex operator-(Complex a,Complex b)
    {
        Complex e;
        e.real=a.real-b.real;
        e.imag=a.imag-b.imag;
        return e;
    }
    Complex operator*(Complex a,Complex b)
    {
        Complex e;
        e.real=a.real*b.real-a.imag*b.imag;
        e.imag=a.real*b.imag-a.imag*b.real;
        return e;
    }
    Complex operator/(Complex a,Complex b)
    {
        Complex e;
        e.real=(a.real*b.real-a.imag*b.imag)/(b.imag*b.imag+b.real*b.real);
        e.imag=(a.real*b.imag-a.imag*b.real)/(b.imag*b.imag+b.real*b.real);
        return e;
    }
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