#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    float x;
    ifstream fin;
    fin.open("input.txt",ios::in);
    fin>>n>>x;
    cout.setf(ios::showbase|ios::uppercase);
    cout.fill('*');
    cout<<setw(10)<<left<<hex<<n;
    cout<<endl;
    cout.unsetf(ios::showbase|ios::uppercase);
    cout.setf(ios::fixed);
    cout.fill('#');
    cout<<setw(12)<<right<<x;
    fin.close();
    return 0;
}