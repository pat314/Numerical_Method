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
            if (i == j) a[i][j] = 1;
            else if ((j == i + 1)) a[i][j] = (1.0/3) - 1;
            else if (j == i - 1) a[i][j] = -(1.0/3);
            else a[i][j] = 0;
        }
    }
}

void inputVector (double a[MAX], int n)
{
    a[0] = 1.0/3.0;
    for (int i = 1; i < n; i++)
    {
        a[i] = 0;
    }
}

double norm2 (double x[], double x0[], int n)
{
    double max = fabs (x[0] - x0[0]);
    for (int j = 1; j < n; j ++)
    {
        if (fabs(x[j] - x0[j]) > max) max = fabs(x[j] - x0[j]);
    }
    return max;
}

void printSolution (double x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << " = " << x[i] << endl;
    }
}

int main()
{
    cout <<"Number of probabilities: ";
    int n;
    cin >> n;
    n = n - 1;

    cout << "Solving Equation System AP = b: " << endl << "INPUT" << endl;
    
    double A [MAX][MAX];
    inputMatrix (A, n, n);

    double b [MAX];
    inputVector (b, n);

    double x0 [MAX];
    for (int i = 0; i < n; i++)
    {
        x0[i] = 0;
    }

    cout << "Tolerance: ";
    double TOL;
    cin >> TOL;

    cout <<"Maximum number of iterations: ";
    int N;
    cin >> N;

    //GAUSS - SEIDEL METHOD
    int k = 1;
    while (k <= N)
    {
        double x[MAX];
        for (int i = 0; i < n; i++)
        {
            double sum1 = 0, sum2 = 0;
            for (int j = 0; j <= i - 1; j ++) sum1 += (A[i][j] * x[j]);
            for (int j = i + 1; j < n; j++) sum2 += (A[i][j] * x0[j]);

            x[i] = (- sum1 - sum2 + b[i]) / A[i][i];
        }

        if (norm2 (x, x0, n) < TOL)
        {
            cout << endl << "OUTPUT" << endl;
            printSolution (x, n);
            cout << "Iterations: " << k;
            return 0;
        }

        k++;
        for (int i = 0; i < n; i++)
        {
            x0[i] = x[i];
        }
    }

    cout << "Maximum number of iterations exceeded";
    return 0;
}