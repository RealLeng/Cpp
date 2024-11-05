#include <iostream>
using namespace std;
class A
{
    private:
    int a;
    int b;
    A(int q,int w)
    {
        a=q;
        w=b;
    }
    friend ostream& operator<<(ostream& stream,A& s);
    friend istream& operator>>(istream& stream,A& s);
};
ostream& operator<<(ostream& stream,A& s)
{
    stream<<s.a<<ends<<s.b;
    return stream;
}
istream& operator>>(istream& stream,A& s)
{
    stream>>s.a>>s.b;
    return stream;
}
int main()
{
    A s(1,2);
    cout<<s;
    cin>>s;
    cout<<s;
}