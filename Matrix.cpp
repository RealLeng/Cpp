#include <iostream>
#define N 3
using namespace std;
class Matrix
{
    private:
    int a[N][N];
    public:
    Matrix(int s[N][N])
    {
            for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                a[i][j]=s[i][j];
            }
        }
    }
    Matrix()
    {}
    Matrix operator+(Matrix s)
    {
        Matrix b;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                b.a[i][j]=a[i][j]+s.a[i][j];
            }
        }
        return b;
    }
    Matrix operator-(Matrix s)
    {
        Matrix b;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                b.a[i][j]=a[i][j]-s.a[i][j];
            }
        }
        return b;
    }
    Matrix operator*(Matrix s)
    {
        Matrix b;
        int i,j,k;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                int n=0;
                for(k=0;k<N;k++)
                {
                    n+=a[i][k]*a[k][j];
                    if(k==N-1)b.a[i][j]=n;
                }
            }
        }
        return b;
    }
    void show()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int s[N][N]={{1,1,1},{1,1,1},{1,1,1}};
    Matrix a(s);
    Matrix b(s);
    a.show();
    Matrix f=a+b;
    f.show();
    Matrix c=b-a;
    c.show();
    Matrix e=a*b;
    e.show();
    return 0;
}