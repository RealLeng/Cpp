#include <iostream>
using namespace std;
class Container
{
    public:
    Container()
    {}
    virtual void shows()
    {}
    virtual void showv()
    {}
};
class Sphere:public Container
{
    private:
    float r;
    public:
    Sphere(float a)
    {
        r=a;
    }
    void shows()
    {
        cout<<"Spheres:"<<4*3.14*r*r<<endl;
    }
    void showv()
    {
        cout<<"Spherev:"<<(4/3)*3.14*r*r*r<<endl;
    }
};

class Cylinder:public Container
{
    private:
    float r,h;
    public:
    Cylinder(float a,float b)
    {
        r=a;
        h=b;
    }
    void shows()
    {
        cout<<"Cylinders:"<<2*r*r*3.14+2*r*3.14*h<<endl;
    }
    void showv()
    {
        cout<<"Cylinderv:"<<r*r*3.14*h<<endl;
    }
};
class Cube:public Container
{
    private:
    float a,b,h;
    public:
    Cube(float s,float e,float c)
    {
        a=s;
        b=e;
        h=c;
    }
    void shows()
    {
        cout<<"Cubes:"<<2*(a*b+a*h+b*h)<<endl;
    }
    void showv()
    {
        cout<<"Cubev:"<<a*b*h<<endl;
    }
};

int main()
{
    Container *a;
    Sphere p(1);
    Cylinder q(1,1);
    Cube e(1,1,1);
    a=&p;
    a->shows();
    a->showv();
    a=&q;
    a->shows();
    a->showv();
    a=&e;
    a->shows();
    a->showv();
}