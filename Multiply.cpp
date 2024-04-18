#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("9.txt",ios::out);
    if(!fout)
    {
        cout<<"Open Failed";
        return 0;
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=i;j<=9;j++)
        {
            fout<<setw(2)<<left<<i<<setw(2)<<left<<"*"<<setw(2)<<j<<setw(2)<<"="<<setw(3)<<i*j<<"  ";
        }
        fout<<endl;
    }
    fout.close();
    return 0;
}