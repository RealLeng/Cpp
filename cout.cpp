#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    ifstream in;
    in.open("input.txt",ios::in);
    int a;
    float b;
    in>>a>>b;
    in.close();
    cout.setf(ios::showbase|ios::uppercase|ios::left);
    cout.fill('*');
    cout<<hex<<setw(10)<<a;
    cout.unsetf(ios::showbase|ios::uppercase|ios::left);
    cout.setf(ios::fixed);
    cout.fill('#');
    cout<<dec<<setw(12)<<a;
    return 0;
}