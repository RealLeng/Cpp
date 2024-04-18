#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Person
{
    protected:
    string Name,Sex;
    public:
    Person()
    {};
    void input(string a,string b)
    {
        Name=a;
        Sex=b;
    }
    void show()
    {
        cout<<"姓名:"<<Name<<endl<<"性别:"<<Sex<<endl;
    }
};
class Student:virtual public Person
{
    protected:
    string No;
    int Score;
    public:
    Student():Person()
    {};
    void inno(string a)
    {
        No=a;
    }
    void inscore(int a)
    {
        Score=a;
    }
    void showno()
    {
        cout<<"学号:"<<No<<endl;
    }
    void showscore()
    {
        cout<<"成绩:"<<Score<<endl;
    }
};

class UStudent:public Student
{
    protected:
    string Major;
    public:
    UStudent():Student()
    {};
    void input(string a)
    {
        Major=a;
    }
    void show()
    {
        cout<<"专业:"<<Major<<endl;
    }
};

class Employee:virtual public Person
{
    protected:
    int Salary;
    public:
    Employee():Person()
    {};
    void input(int a)
    {
        Salary=a;
    }
    void show()
    {
        cout<<"工资:"<<Salary<<endl;
    }
};
class E_UStudent:public Employee,UStudent
{
    public:
    E_UStudent(string a,string b,string c,int d,string e,int f):Person(),UStudent(),Employee()
    {
        Student::inno(a);
        Person::input(b,c);
        Student::inscore(d);
        UStudent::input(e);
        Employee::input(f);
    };
    void show()
    {
        Student::showno();
        Person::show();
        Student::showscore();
        UStudent::show();
        Employee::show();
    }
};

int main()
{
    E_UStudent s("20191001","张三","男",90,"数学",8500);
    s.show();
    return 0;
}
