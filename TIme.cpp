#include <iostream>
#include <stdlib.h>
using namespace std;
class Time
{
    public:
    Time()
    {
        cout<<"请输入时、分和秒"<<endl;
        cin>>h>>m>>s;
        if(h<0||m<0||s<0)
        {
            cout<<"输入有错!"<<endl;
            exit(0);
        }

    }
    Time(int a,int b,int c)
    {
        a=h;
        b=m;
        c=s;
    }
    void show()
{
    cout<<"时间为"<<h<<":"<<m<<":"<<s<<endl;
}
    void increase(int q,int w,int e)
    {
        h+=q;
        m+=w;
        s+=e;
        while(s>=60)
        {
            s-=60;
            m+=1;
        }
        while(m>=60)
        {
            m-=60;
            h+=1;
        }
        while(h>=24) h-=24;
    }
    private:
    int h,m,s;
};

int main()
{
    Time t1,t2(23,59,59);
    t1.show();
    t2.show();
    t2.increase(0,0,1);
    t2.show();
    t2.increase(12,100,100);
    t2.show();
    return 0;
}