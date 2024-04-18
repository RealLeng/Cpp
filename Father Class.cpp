#include <iostream>
#include <string>
using namespace std;
class Student
{
    protected: 
    int cj;
    string Name,No;

    public:
    Student(string a,string b,int c)
    {
        No=a;
        Name=b;
        cj=c;
    }
    Student()
    {
        cout<<"学号:"<<endl;
        cin>>No;
        cout<<"姓名:"<<endl;
        cin>>Name;
        cout<<"成绩:"<<endl;
        cin>>cj;
    }
    void Show()
    {
        cout<<No<<" "<<Name<<" "<<cj<<endl;
    }
    ~Student()
    {
        cout<<"Student die"<<endl;
    }
};

class UStudent: public Student
{
    private:
    string Major;

    public:
    UStudent(string a,string b,int c,string d):Student(a,b,c)
    {
        Major=d;
    }
    UStudent():Student ()
    {
        
        cout<<"专业:"<<endl;
        cin>>Major;
    }
    void Show()
    {
        cout<<No<<" "<<Name<<" "<<cj<<" "<<Major<<endl;
    }
    ~UStudent()
    {
        cout<<"UStudent die"<<endl;
    }
};

int main()
{
    UStudent s("1001","张三",95,"信息"),t;
    s.Show();
    t.Show();
    return 0;
}