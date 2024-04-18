#include <iostream>
using namespace std;
class String
{
    private:
    char *str;
    int len;
    public:
    String()
    {
        cout<<"Please input len"<<endl;
        cin>>len;
        str= new char[len+1];
        cout<<"please input char:"<<endl;
        for(int i=0;i<len;i++)
        {
            cin>>str[i];
        }
        str[len]='\0';
    }
    String(int n,char *s)
    {
        len=n;
        str= new char[len+1];
        for(int i=0;i<=len;i++)
        {
            str[i]=s[i];
        }
    }
    String(const String &s)
    {
        str=new char[s.len+1];
        for(int i=0;i<=s.len;i++)
        {
            str[i]=s.str[i];
        }
        len=s.len;
    }
    ~String()
    {
        delete str;
        cout<<"delete completed"<<endl;
    }
    void set(char *s)
    {
        int i=0;
        char a=s[0];
        while(a!='\0')
        {
            i++;
            a=s[i];
        }
        len=i;
        delete str;
        str=new char[i+1];
        for(int j=0;j<=len;j++)
        {
            str[j]=s[j];
        }
    }
    void show()
    {
        cout<<len<<endl;
        for(int j=0;j<len;j++)
        {
            cout<<str[j];
        }
        cout<<endl;
    }
    int  length()
    {
        return len;
    }
    void dechar(char e)
    {
        char *a;
        a=new char[len+1];
        for(int i=0;i<=len;i++)
        {
            a[i]=str[i];
        }
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]==e)
            {
                for(int j=i;j<=len;j++)
                {
                    a[j]=a[j+1];   
                }
                len--;
                i--;
            }
        }
        int i=0;
        
        set(a);
    }
    String &operator=(String &s)
    {
        if(!str)
        {
            set(s.str);
            len=s.len;
            return *this;
        }
        else
        {
            str=new char[s.len+1];
            set(s.str);
            len=s.len;
            return *this;
        }
    }
    int operator==(String s)
    {
        int i=0;
        while(str[i]==s.str[i])
        {
            i++;
        }
        if(i=len+1)
        return 1;
        else return 0;
    }
    String operator+(String s)
    {
        String a(0,"\0");
        a.len=len+s.len;
        delete a.str;
        a.str=new char[a.len+1];
        int i,j;
        for(i=0;i<len;i++)
        {
            a.str[i]=str[i];
        }
        for(j=len;j<=a.len;j++)
        {
            a.str[j]=s.str[j-len];
        }
        return a;
    }
};

int main()
{
    String a,b(2,"in"),c(b);
    a.show();
    b.show();
    c.show();
    b.set("abiiic");
    b.show();
    b.dechar('i');
    b.show();
    cout<<"b length:"<<b.length()<<endl;
    String d(0,"\0");
    d=a;
    d.show();
    cout<<"a?d"<<endl;
    if(a==d) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    String e=a+b;
    e.show();
    return 0;
}