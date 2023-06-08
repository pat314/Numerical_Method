#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout << "Nhap ma tran cap: ";
    cin >> n;
    double c;
    cout << "Nhap so lan hoi tu: ";
    cin >> c;
    double truc_giao_i = 0;
    double di;
    double x0[20][1] ;
    double y[20][1] ;
    double a[20][20];
    double b[20][1];
    double lamda = 0;
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


    while(c--)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                y[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++){

            for(int k=0;k<n;k++)
            {
                y[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    truc_giao_i = 0;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            truc_giao_i += pow(y[i][j], 2);
        }
    }
    di = sqrt(truc_giao_i);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            x0[i][j] = y[i][j]/di;
        }
    }
    lamda = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            lamda += y[j][i] * x0[i][j];
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            b[i][j] = x0[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            cout << setprecision(15) << fixed << x0[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Gia tri rieng lamda la: ";
    cout << setprecision(15) << fixed << lamda << endl;
    cout << endl;
    }
}

