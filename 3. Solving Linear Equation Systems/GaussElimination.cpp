#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX = 200;

void input (const int& n, double equationSystem[][MAX])
{
    cout << "Enter the increasing matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n ; j ++)
            cin >> equationSystem[i][j];
    }
}

void swap (double equationSystem[][MAX], const int& rol1, const int& rol2, int n)
{
    for (int j = 0; j <=n; j++)
    {
        double tmp = equationSystem[rol1][j];
        equationSystem[rol1][j] = equationSystem[rol2][j];
        equationSystem[rol2][j] = tmp;
    }
}

void primaryRule (double equationSystem[][MAX], const int& rol1,const int& rol2, const double& m, const int &n)
{
    for (int j = 0; j <=n; j++)
    {
        double tmp =  m * equationSystem[rol2][j];
        equationSystem[rol1][j] -= tmp;
    }
}

void printSolution (const int& n, double x[MAX])
{
    cout << "OUTPUT:" << endl << "Solution" << endl;
    for (int i = 0; i < n; i++)
    {
        cout <<fixed << setprecision(5) << "x" << i + 1 <<" = " << x[i] << endl;
    }

}

int main()
{
    cout << "INPUT:" << endl;
    cout << "Number of equations: ";
    int n;
    cin >> n;

    double equationSystem[MAX][MAX];
    input (n, equationSystem);

    //GAUSS ELIMINATION WITH BACKWARD SUBSTITUTION
    for (int i = 0 ; i < n-1; i++)
    {
        int p = i;
        while (p < n && equationSystem[p][i] == 0) p ++;

        if (equationSystem[p][i] == 0)
        {
            cout << "OUTPUT:" << endl;
            cout <<"No unique solution exists!";
            return 0;
        }
        if (p != i) swap (equationSystem, p, i, n);
        for (int j = i + 1; j < n; j ++)
        {
            double m = equationSystem[j][i]*1.0 / equationSystem[i][i];
            primaryRule (equationSystem, j, i, m, n);
        }
    }
    if (equationSystem[n-1][n-1] == 0)
    {
        cout <<"No unique solution exists!";
        return 0;
    }
    double x[MAX];
    x[n-1] = (equationSystem[n-1][n]*1.0) / equationSystem[n-1][n-1];

    for (int i = n-2; i >=0 ; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum +=equationSystem[i][j] * x[j];
        }
        x[i] = 1.0*(equationSystem[i][n] - sum) / equationSystem[i][i];
    }
    printSolution (n, x);
}