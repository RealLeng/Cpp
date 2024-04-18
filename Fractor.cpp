#include <iostream>
using namespace std;
class Fractor
{
    private:
    int z,m;
    public:
    Fractor(int i,int j)
    {
        z=i;
        m=j;
    }
    Fractor()
    {}
    void show()
    {
        cout<<z<<"/"<<m<<endl;
    }
    Fractor operator+(Fractor s)
    {
        Fractor q;
        q.z=z*s.m+s.z*m;
        q.m=m*s.m;
        q=tf(q);
        return q;
    }
    Fractor tf(Fractor &s)
    {
        while(gy(s))
        {
            for(int i=1;i<=s.z;i++)
        {
            if(s.z%i==0)
            {
                if(s.m%i==0)
                {
                    s.z=s.z/i;
                    s.m=s.m/i;
                }
            }
        }
        return s;
        }
    }
    int gy(Fractor s)
    {
        for(int i=1;i<=s.z;i++)
        {
            if(s.z%i==0)
            {
                if(s.m%i==0)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    Fractor operator-(Fractor s)
    {
        Fractor q;
        q.z=z*s.m-s.z*m;
        q.m=m*s.m;
        if(q.z==0)
        {
            q.m=0;
        }
        tf(q);
        return q;
    }
    Fractor operator*(Fractor s)
    {
        Fractor q;
        q.z=z*s.z;
        q.m=m*s.m;
        tf(q);
        return q;
    }
    Fractor operator/(Fractor s)
    {
        Fractor q;
        q.z=z*s.m;
        q.m=m*s.z;
        tf(q);
        return q;
    }
    Fractor operator++()
    {
        Fractor s=*this;
        z+=m;
        return s;
    }
    Fractor operator++(int)
    {
        z+=m;
        return *this;
    }
};
int main()
{
    Fractor a(2,5),b(2,6);
    Fractor c=a+b;
    c.show();
    c=a-b;
    c.show();
    c=a*b;
    c.show();
    c=a/b;
    c.show();
    c=a++;
    c.show();
    c=++b;
    c.show();
}

