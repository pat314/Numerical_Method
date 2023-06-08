#include <bits/stdc++.h>
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

int main ()
{
	//INPUT MATRICE A,b
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
    //END INPUT MATRICE A,b

    //INITIALIZE THE DIAGONAL MATRICES
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
    // END INITIALIZE THE DIAGONAL MATRICES
    
    //DOOLITTLE METHOD
    //Step 1:
	u[0][0] = a[0][0];
    if (!(u[0][0]))
    {
        cout << "OUTPUT" << endl << "Factorization impossible! (1)";
        return 0;
    }
    
    //Step 2:
    for (int j = 1; j < n; j++)
    {
        u[0][j] = a[0][j] / l[0][0];
        l[j][0] = a[j][0] / u[0][0];
    }
    
    //Step 3:
    for (int i = 1; i < n-1; i++)
    {
    	//Step 4:
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
        
        //Step 5:
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
    
    //Step 6:
    double sigma4 = 0;
    for (int k = 0; k < n - 1; k++)
        sigma4 += l[n - 1][k] * u[k][n - 1];
    u[n - 1][n - 1] = a[n - 1][n - 1] - sigma4;
    //END DOOLITTLE METHOD
    
    //SOLVE THE EQUATION SYSTEM
	//SOLVE Ly = b:
	double x[MAX], y[MAX];
	for (int i = 0; i < n; i++)
	{
		double sigma = 0;
		for (int j = 0; j <= i-1 ; j++)
		{
				sigma = sigma + l[i][j]*y[j];
		}
		y[i] = b[i] - sigma;
	}
	
	//SOLVE Ux = y:
	for (int i = n - 1; i >= 0; i--)
	{
		double sigma = 0;
		for (int j = i+1; j < n; j++)
		{
			sigma = sigma + u[i][j]*x[j];
		}
		
		x[i] = (y[i] - sigma)/u[i][i]*1.0;
	}
	
	//PRINT SOLUTIONS:
	cout << "Solution:" << endl << "x = [";
	for (int i = 0; i < n-1; i++) cout << x[i] << ", ";
	cout << x[n-1] << "]^T";
	
	//END SOLVE THE EQUATION SYSTEM    
    return 0;
}
