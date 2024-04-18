#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int Data;
    Node *next;
};
class Stack
{
    private:
    Node *Top;
    int n;
    public:
    Stack()
    {
        n=0;
        Top=NULL;
    }
    void init()
    {
        int q;
        cout<<"Please input the length"<<endl;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            cout<<"Please input the Data"<<endl;
            int p;
            cin>>p;
            push(p);
        }
    }
    void push(int a)
    {
        Node *p;
        p=new Node;
        p->Data=a;
        if(!Top)
        {
            Top=p;
            p->next=NULL;
            n++;
        }
        else 
        {
            p->next=Top;
            Top=p;
            n++;
        }
    }
    int pop()
    {
        if(!Top)
        {
            cout<<"asdasd"<<endl;
            return 0;
        }
        int a;
        a=Top->Data;
        Top=Top->next;
        n--;
        return a;
    }
    void del()
    {
        if(!Top)
        {
            cout<<"栈已空";
            return;
        }
        
        while(!Top)
        {   Node *p;
            p=Top;
            Top=Top->next;
            free(p);
        }
        n=0;
        Top=NULL;
        cout<<"清空完毕"<<endl;
        return;
    }
    ~Stack()
    {
        del();
    }
    void save()
    {
        ofstream fo;
        fo.open("out.txt",ios::out);
        if(!fo)
    {
        cout<<"Open Failed";
        return;
    }    Node *p;
         p=Top;
        for(int i=1;i<=n;i++)
        {
            
            fo<<p->Data<<endl;
            p=p->next;
        }
        fo.close();
    }
    friend ostream& operator<<(ostream& cout,Stack &a)
    {
        Node *p;
            p=a.Top;
    for(int i=1;i<=a.n;i++)
        {
            cout<<p->Data<<endl;
            p=p->next;
        }
        cout<<endl;
        return cout;
     }
    friend ostream& operator>>(ostream& cout,Stack &a)
    {
        a.del();
        a.init();
        return cout;
     }
};

int main()
{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout<<a.pop()<<endl;
    cout<<a;
    cout>>a;
    a.save();
    
}
