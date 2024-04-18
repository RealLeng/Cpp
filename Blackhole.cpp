#include <iostream>
#include <cmath>
using namespace std;
class Blackhole
{
    private:
    int s[4];
    public:
    Blackhole(int a)
    {
    s[0]=a/1000;
    s[1]=a%1000/100;
    s[2]=a%100/10;
    s[3]=a%10;
    for(int i=0;i=0;i++)
    {
        for(int j=i+1;j<=3;j++)
        {
            if(s[i]==s[j])
            {
                cout<<"输入有错，要求个位数字不完全相同";
                return;
            }
        }
    }
    }
    Blackhole()
{
    int a;
    cout<<"请输入一个四位正整数，要求各个数字不完全相同"<<endl;
    cin>>a;
    s[0]=a/1000;
    s[1]=a%1000/100;
    s[2]=a%100/10;
    s[3]=a%10;
}
    void show()
    {
    int i,j,Max,k,l,sx=0,jx=0;
    for(i=0;i<=3;i++)
    {
        Max=i;
        for(j=i;j<=3;j++)
        {
            if(s[j]>s[Max])
            {
                Max=j;
            }
        }
        k=s[i];
        s[i]=s[Max];
        s[Max]=k;
    }
    for(int i=0;i<=3;i++)
    {
        jx+=s[i]*pow(10,3-i);
    }
    cout<<jx<<endl;
    k=s[0];
    l=s[1];
    s[0]=s[3];
    s[1]=s[2];
    s[2]=l;
    s[3]=k;
    for(int i=0;i<=3;i++)
    {
        sx+=s[i]*pow(10,3-i);
    }
    cout<<sx<<endl;
    cout<<jx<<"-"<<sx<<"="<<jx-sx<<endl;
    if(jx-sx!=6174)
    {
        px(jx-sx);
    }
    px(6174);
    return;
    }

    void px(int a)
    {
    int p[4];
    p[0]=a/1000;
    p[1]=a%1000/100;
    p[2]=a%100/10;
    p[3]=a%10;
    int i,j,Max,k,l,sx=0,jx=0;
    for(i=0;i<=3;i++)
    {
        Max=i;
        for(j=i;j<=3;j++)
        {
            if(p[j]>p[Max])
            {
                Max=j;
            }
        }
        k=p[i];
        p[i]=p[Max];
        p[Max]=k;
    }
    for(int i=0;i<=3;i++)
    {
        jx+=p[i]*pow(10,3-i);
    }
    k=p[0];
    l=p[1];
    p[0]=p[3];
    p[1]=p[2];
    p[2]=l;
    p[3]=k;
    for(int i=0;i<=3;i++)
    {
        sx+=p[i]*pow(10,3-i);
    }
    cout<<jx<<"-"<<sx<<"="<<jx-sx<<endl;
    if(jx-sx!=6174)
    {
        px(jx-sx);
    }
    return;
    }
};


int main()
{
    Blackhole a(1645);
    a.show();
    return 0;
}