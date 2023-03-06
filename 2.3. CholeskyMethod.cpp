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
    double l[MAX][MAX];
    
    for (int i = 0; i < n ; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (j > i)
            {
                l[i][j] = 0;
            }
            else 
            {
                l[i][j] = 1;
            }
        }
    }

    //CHOLESKY METHOD
    l[0][0] = sqrt(a[0][0]);
    
    for (int j = 1; j < n; j++)
    {
        l[j][0] = a[j][0] / l[0][0];
    }

    for (int i = 1; i < n-1; i++)
    {
        double sigma1 = 0;
        for (int k = 0; k <= i-1; k++)
        {
            sigma1 += l[i][k] * l[i][k];
        }

        l[i][i] =  sqrt(a[i][i] - sigma1);

        for (int j = i + 1; j < n; j++)
        {
            double sigma2 = 0;
            for (int k = 0; k <= i - 1; k++) 
                sigma2 += l[i][k] * l[j][k];
            l[j][i] = (a[j][i] - sigma2) / l[i][i];
        }
    }

    double sigma3 = 0;
    for (int k = 0; k < n - 1; k++)
        sigma3 += l[n - 1][k] * l[n - 1][k];
    l[n - 1][n - 1] = sqrt(a[n - 1][n - 1] - sigma3);

    //SOLVE THE EQUATION SYSTEM
    double x[MAX], y[MAX];

    y[0] = b[0] / l[0][0];
    for (int i = 1; i < n; i ++)
    {
        double sigma4 = 0;
        for (int j = 0; j <= i - 1; j++)
            sigma4 += l[i][j] * y[j];
        y[i] = (b[i] - sigma4) / l[i][i];
    }

    x[n - 1] = y[n - 1] / l[n - 1][n - 1];
    for (int i = n - 2; i >=0; i--)
    {
        double sigma5 = 0;
        for (int j = i + 1; j < n; j++)
            sigma5 += l[j][i] * x[j];
        x[i] = (y[i] - sigma5) / l[i][i];
    }

    printSolution (n, x);
}
