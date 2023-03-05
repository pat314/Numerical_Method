#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX = 200;

void inputMatrix (double a[MAX][MAX], int nRows, int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j ++)
        {
            cin >> a[i][j];
        }
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

void GaussEliminationMethod (double equationSystem[][MAX], int n, double x[MAX])
{
    for (int i = 0 ; i < n-1; i++)
    {
        int p = i;
        while (p < n && equationSystem[p][i] == 0) p ++;

        if (equationSystem[p][i] == 0)
        {
            /*cout << "OUTPUT:" << endl;
            cout <<"No unique solution exists!";*/
            return;
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
        //cout <<"No unique solution exists!";
        return;
    }
    //double x[MAX];
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
}

void printMatrix (double a[][MAX], int nRows, int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j =0; j < nCols; j ++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
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
    cout << "INPUT" << endl;
    cout <<"Number of equation and the unknowns: ";
    int n;
    cin >> n;

    cout << "Matrix A: " << endl;
    double a[MAX][MAX];
    inputMatrix (a, n, n);

    cout << "Matrix b: " << endl;
    double b[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    //The triangular matrices
    double u[MAX][MAX], l[MAX][MAX];
    
    for (int i = 0; i < n ; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (j == i)
            {
                u[i][j] = 1;
                l [i][j] = 1;
            }
            else if (j > i)
            {
                u[i][j] = 1;
                l[i][j] = 0;
            }
            else 
            {
                l[i][j] = 1;
                u[i][j] = 0;
            }
        }
    }

    //DOOLITTLE METHOD
    u[0][0] = a[0][0];
    if (!(u[0][0]))
    {
        cout << "OUTPUT" << endl << "Factorization impossible! (1)";
        return 0;
    }

    for (int j = 1; j < n; j++)
    {
        u[0][j] = a[0][j] / l[0][0];
        l[j][0] = a[j][0] / u[0][0];
    }

    for (int i = 1; i < n-1; i++)
    {
        double sigma1 = 0;
        for (int k = 0; k <= i-1; k++)
        {
            sigma1 += l[i][k] * u[k][i];
        }

        u[i][i] =  a[i][i] - sigma1;

        if ((u[i][i]) == 0)
        {
            cout << "OUTPUT" << endl << "Factorization impossible! (2)";
            return 0;
        }

        for (int j = i + 1; j < n; j++)
        {
            double sigma2 = 0;
            for (int k = 0; k <= i - 1; k++) 
                sigma2 += l[i][k] * u[k][j];
            u[i][j] = (a[i][j] - sigma2) / l[i][i];

            double sigma3 = 0;
            for (int k = 0; k <= i - 1; k++)
                sigma3 += l[j][k] * u[k][i];
            l[j][i] = (a[j][i] - sigma3) / u[i][i];
        }

    }

    double sigma4 = 0;
    for (int k = 0; k < n - 1; k++)
        sigma4 += l[n - 1][k] * u[k][n - 1];
    u[n - 1][n - 1] = a[n - 1][n - 1] - sigma4;

    //SOLVE THE EQUATION SYSTEM
    double x[MAX], y[MAX];

    double eq1[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            eq1[i][j] = l[i][j];
        }
        eq1[i][n] = b[i]; 
    }

    GaussEliminationMethod (eq1, n, y);

    double eq2[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            eq2[i][j] = u[i][j];
        }
        eq2[i][n] = y[i]; 
    }

    GaussEliminationMethod (eq2, n, x);
    printSolution (n, x);
}