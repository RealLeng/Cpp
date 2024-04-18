#include <iostream>
using namespace std;
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
    private:
    int y,m,d;
    public:
    Date(int a,int b,int c)
    {
        y=a;
        m=b;
        d=c;
    }
    Date()
    {}
    int Run(Date a)
    {
        if(a.y%400==0||a.y%4==0&&a.y%100!=0)
        return 1;
        else return 0;
    }
    void show()
    {
        cout<<y<<" "<<m<<" "<<d<<endl;
    }
    Date operator+(Date a)
    {
        Date b;
        b.y=y+a.y;
        b.m=m+a.m;
        if(b.m>12)
        {
            b.y+=b.m/12;
            b.m=b.m%12;
        }
        b.d=d+a.d;
        if(b.m==2)
        {
            if(b.d>p[b.m-1]+Run(b))
            {
                b.m+=b.d/(p[b.m-1]+Run(b));
                b.d=b.d%(p[b.m-1]+Run(b));
            }
        }
        else
        {
            if(b.d>p[b.m-1])
            {
                b.m+=b.d/(p[b.m-1]);
                b.d=b.d%(p[b.m-1-(b.d/(p[b.m-1]))]);
            }
        }
        return b;
    }
    Date operator-(Date a)
    {
        Date p1,p2,b;
        if(y>a.y)
        {
           p1=*this;
           p2=a;
        }
        else
        {
            p2=*this;
            p1=a;
        }
        b.y=p1.y-p2.y;
        if(p1.m<p2.m)
        {
            if(p1.d<=p2.d)
            {
                b.m=12+p1.m-p2.m-1;
                b.y--;
                if(b.m<0)
                {
                    b.m=12;
                }
                if(b.m==2)
                b.d=p[b.m]+Run(b)-(p1.d-p2.d);
                else
                b.d=p[b.m]-(p2.d-p1.d);
            }
            else if(p1.d>p2.d)
            {
               b.d=p1.d-p2.d;
               b.m=12+p1.m-p2.m;
               b.y--;
            }
        }
        
        if(p1.m==p2.m)
        {
            if(p1.d==p2.d)
            {
                b.m=12;
                b.d=31;
                b.y--;
            }
            else if(p1.d>p2.d)
            {
                b.d=p1.d-p2.d;
            }
            else if (p1.d<p2.d)
            {
                b.m--;
                if(b.m<1)
                {
                    b.m=12;
                    b.d=31;
                    b.y--;
                }
            }
        }
        else if(p1.m>p2.m)
        {
            if(p1.d>p2.d)
            {
                b.m=p1.m-p2.m;
                b.d=p1.d-p2.d;
            }
            else if (p1.d<=p2.d)
            {
                b.m=p1.m-p2.m;
                b.m--;
                if(b.m==2)
                b.d=p[b.m]+Run(b)-(p1.d-p2.d);
                else
                b.d=p[b.m]-(p2.d-p1.d);
            }
        }
        return b;
    }
    Date operator++()
    {
        d++;
        if(m==2)
        {
            if(d>p[m-1]+Run(*this))
            {
                m++;
                d=1;
            }
        }
        else
        {
            if(d>p[m-1])
            {
                m++;
                if(m>12)
                {
                    y++;
                    m=1;
                    d=1;
                }
                else d=1;
            }
        }
        return *this;
    }
    Date operator++(int)
    {
        Date b(*this);
        d++;
        if(m==2)
        {
            if(d>p[m-1]+Run(*this))
            {
                m--;
                d=d%p[m-1]+Run(*this);
            }
        }
        else
        {
            if(d>p[m-1])
            {
                m++;
                if(m>12)
                {
                    y++;
                    m=1;
                    d=1;
                }
                else d=1;
            }
        }
        return b;
    }
};


int main()
{
    Date a(1,12,31),b(2,1,2);
    a.show();
    b.show();
    Date c=a+b;
    c.show();
    Date d=b-a;
    d.show();
    ++a;
    a.show();
    a++;
    a.show();
    return 0;
}