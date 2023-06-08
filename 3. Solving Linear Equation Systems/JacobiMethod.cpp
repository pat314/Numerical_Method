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

void inputVector (double a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
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

double norm1 (double x[], int n)
{
    double max = fabs (x[0]);
    for (int j = 1; j < n; j ++)
    {
        if (fabs(x[j]) > max) max = fabs(x[j]);
    }
    return max;
}

void printSolution (double x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main()
{
    cout << "INPUT" << endl << "Number of equations and unknowns: ";
    int n;
    cin >> n;

    cout << "Solving Equation System Ax = b: " << endl << "INPUT" << endl;
    cout << "Enter matrix A: " << endl;
    double A [MAX][MAX];
    inputMatrix (A, n, n);

    cout << "Enter matrix b: " << endl;
    double b [MAX];
    inputVector (b, n);

    cout << "Enter the initial approximation: " << endl;
    double x0 [MAX];
    inputVector (x0, n);

    cout << "Tolerance: ";
    double TOL;
    cin >> TOL;

    cout <<"Maximum number of iterations: ";
    int N;
    cin >> N;

    cout << endl << "Value table" << endl
             << "i        ";
        for (int i =0; i < n; i++)
        {
            cout << "x" << i + 1 << "         ";
        }
        cout << endl;
    //JACOBI METHOD
    int k = 1;
    while (k <= N)
    {
        double x[MAX];
        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j ++)
            {
                if ((j != i)) sum += A[i][j] * x0[j];
            }

            x[i] = (- sum + b[i]) / A[i][i];
        }

        cout << k << "        ";
        for (int i =0; i < n; i++)
        {
            cout << fixed << setprecision(5) << x[i] << "   ";
        }
        cout << endl;

        if (norm2 (x, x0, n) < TOL)// * norm1 (x, n))
        {
            cout << "OUTPUT" << endl;
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
