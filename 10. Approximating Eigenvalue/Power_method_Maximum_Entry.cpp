#include <bits/stdc++.h>

using namespace std;

double max_y(double a[][1], int n )
{
    double max1 = abs(a[0][0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
           if(abs(a[i][j]) >= max1)
                max1 = abs(a[i][j]);
        }
    }
    return max1;
}

int main()
{
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;
    int c;
    cout << "Enter the number of iterations: ";
    cin >> c;
    double esp ;
    cout << "Enter the error: ";
    cin >> esp;
    int count = 0; // so buoc nhay khi thoa man sai so
    double a[20][20];
    double b[20][1];
    double x[20][1];
    double y[20][1];
    double old_lamda = 0.0;
    double lamda, tu, mau;
    cout << "Enter the matrix A: " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the unit vector: " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            cin >> b[i][j];
        }
    }
    while(count<=c)
    {
        tu = 0;
        mau = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                y[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                for(int k=0;k<n;k++)
                {
                    y[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        double d = max_y(y, n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                x[i][j] = y[i][j]/d;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                tu += y[j][i] * x[i][j];
                mau += x[j][i] * x[i][j];
            }
        }
        lamda = tu/mau;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                b[i][j] = x[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                cout << setprecision(15) << fixed << x[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "The dominant eigenvalue: " ;
        cout << setprecision(15) << fixed << lamda << endl;
        if(abs(lamda-old_lamda) < esp) {break;}
        else {
        old_lamda = lamda;
        count++;}
        cout << endl;
    }
    cout << "Number of iterations: " << count;
    return 0;
}
