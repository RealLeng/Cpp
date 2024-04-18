#include <iostream>
using namespace std;
template <typename T>
class Set
{
    private:
    T *a;
    int x;
    public:
    Set(T *s,int i)
    {
        a=s;
        x=i;
    }
    Set()
    {}
    void input()
    {
        int i,p;
        cout<<"Input:"<<endl;
        cin>>p;
        x=p;
        for(i=0;i<x;i++)
        {
            T k;
            cin>>k;
            a[i]=k;
        }
    }
    Set Bing(Set &s)
    {
        int i,j,l;
        T *b;
        b=new T[40];
        for(i=0;i<x;i++)
        {
            b[i]=a[i];
        }
        l=i;
        j=0;
        while(j<s.x)
        {
            int tag=0;
            for(int p=0;p<s.x;p++)
            {
                if(s.a[j]==a[p])
                {
                    tag=1;
                    j++;
                    break;
                }
            }
             if(tag==0)
            {
                cout<<s.a[j]<<endl;

                b[l]=s.a[j];
                j++;
                l++;
            }
        }
        cout<<b[l-1]<<endl;
        Set f(b,l);
        cout<<f.a[2]<<endl;
        return f;
    }
    void Jiao(Set s)
    {
        
    }
    void Cha(Set s)
    {
        
    }
    show()
    {
        for(int i=0;i<x;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int q[5]={1,2,5,6,7},w[3]={1,2,3};
    Set <int>a(q,5),b(w,3);
    Set <int>c=a.Bing(b);
    c.show();
}