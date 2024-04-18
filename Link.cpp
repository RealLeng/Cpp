#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T Data;
    struct Node *Next;
};
template <typename T>
class Link
{
    private:
    Node<int> *head,*tail;
    int len;
    public:
    Link()
    {}
    void Creat()
    {
        head=NULL;
        tail=NULL;
        len=0;
    }
    void addT(T a)
    {
        Node<int> *s;
        s=new Node<int>;
        s->Data=a;
        if(!head)
        {
            head=s;
            s->Next=NULL;
            tail=head;
        }
        else{
            s->Next=head;
            head=s;
        }
        len++;
        return;
    }
    void addW(T a)
    {
        Node<int> *s;
        s=new Node<int>;
        s->Data=a;
        if(!head)
        {
            head=s;
            s->Next=NULL;
            tail=head;
        }
        else{
            tail->Next=s;
            tail=s;
            s->Next=NULL;
        }
        len++;
    }
    void add(T a,int j)
    {
        if(j>len)
        {
            cout<<"Worry!!!!!"<<endl;
            return;
        }
        Node<int> *s;
        s=head;
        for(int i=1;i<j;i++)
        {
            s=s->Next;
        }
        Node<int> *p;
        p=new Node<int>;
        p->Data=a;
        if(j==1)
        {
            p->Next=s;
            head=p;
        }
        else{
            p->Next=s->Next;
            s->Next=p;
        }
        
        len++;
        return;
    }
    void del(int i)
    {
        Node<int> *s,*p;
        s=head;
        if(i>len||i<0)
        {
            cout<<"Worry!!!!!"<<endl;
            return;
        }
        for(int j=1;j<i-1;j++)
        {
            s=s->Next;
        }
        p=s->Next;
        s->Next=p->Next;
        free(p);
        len--;
        if(len==0)
        {
            head=NULL;
            tail=NULL;
        }
        return;
    }
    T find(int i)
    {
        Node<int> *s;
        s=head;
        if(i>len||i<0)
        {
            cout<<"Worry!!!!!"<<endl;
            return;
        }
        for(int j=1;j<=i;j++)
        {
            s=s->Next;
        }
        return s->Data;
    }
    void show()
    {
        Node<int> *s;
        s=head;
        for(int j=1;j<=len;j++)
        {
            cout<<"No."<<j<<" is"<<s->Data<<" ";
            s=s->Next;
        }
        cout<<endl;
    }
    void change(int a,int i)
    {
        Node<int> *s;
        s=head;
        if(i>len||i<0)
        {
            cout<<"Worry!!!!!"<<endl;
            return;
        }
        for(int j=1;j<=i;j++)
        {
            s=s->Next;
        }
        s->Data=a;
        return;
    }
    void clear()
    {
        Node<int> *s,*p;
        s=head;
        while(s!=NULL)
        {
            p=s;
            s=s->Next;
            free(p);
        }
        cout<<"Clear Completed"<<endl;
    }
    void bing(Link &s)
    {
        Node<int> *p;
        p=s.head;
          len+=s.len;
        for(int i=1;i<=s.len;i++)
        {
            tail->Next=p;
            p=p->Next;
            tail=p;
        }
        return;
    }
    void chai(int i1,int i2)
    {
        Node<int> *s,*p;
        s=head;
        for(int i=1;i<=i1;i++)
        {
            s=s->Next;
        }
        head=s;
        for(int i=i1;i<=i2;i++)
        {
            s=s->Next;
        }
        tail=s;
        tail->Next=NULL;
        len=i2-i1+1;
        return;
    }
};
int main()
{
    Link<int> a,b;
    a.Creat();
    b.Creat();
    a.addT(2);
    a.show();
    a.addW(3);
    a.show();
    a.add(1,1);
    a.show();
    a.del(2);
    a.show();
    b.addW(1);
    b.addW(1);
    b.addW(1);
    b.addW(1);
    b.show();
    a.bing(b);
    a.show();
    a.chai(1,3);
    a.show();
}