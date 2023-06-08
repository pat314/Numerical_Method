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
    cout << "Nhap ma tran cap: ";
    cin >> n;
    int c;
    cout << "Nhap so buoc nhay: ";
    cin >> c;
    double esp ;
    cout << "Nhap sai so: ";
    cin >> esp;
    int count = 0; // so buoc nhay khi thoa man sai so
    double a[20][20];
    double b[20][1];
    double x[20][1];
    double y[20][1];
    double old_lamda = 0.0;
    double lamda, tu, mau;
    cout << "Nhap ma tran A: " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Nhap vector don vi: " << endl;
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
        cout << "Gia tri rieng la: " ;
        cout << setprecision(15) << fixed << lamda << endl;
        if(abs(lamda-old_lamda) < esp) {break;}
        else {
        old_lamda = lamda;
        count++;}
        cout << endl;
    }
    cout << "So buoc nhay: " << count;
    return 0;
}
