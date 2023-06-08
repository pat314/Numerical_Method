#include <bits/stdc++.h>
using namespace std;

const int PI = 3.141592654;
const int E = 2.718281828;

double power (double x, int n)
{
	double p = 1;
	for (int i = 1; i <= n; i++) p *=x;
	return p;
}

double norm2 (vector <double> x, vector <double> x0, int n)
{
    double max = fabs (x[0] - x0[0]);
    for (int j = 1; j < n; j ++)
    {
        if (fabs(x[j] - x0[j]) > max) max = fabs(x[j] - x0[j]);
    }
    return max;
}

double function (double x, double a = 0)
{
	/*Trigonometric
	----------------------------------------
	//template: sin x
	return sin(x);
	//template: cos x
	return cos(x);
	//template: tan x
	return tan(x);
	//template: arcsin x
	return asin(x);
	//template: arccos x
	return acos(x);
	//template: arctan x
	return atan(x);
	----------------------------------------
	*/
	
	/*Exponential and logarithmic
	----------------------------------------
	//template: e^x
	return exp(x);
	//template: a^x
	return exp(x*log(a));
	//template: ln(x)
	return log(x);
	//template: log10(x)
	return log10(x);
	//template: log2 (x)
	return log2(x);
	//template loga(x)
	return log(x)/log(a);
	----------------------------------------
	*/
	
	/*Power functions
	----------------------------------------
	//template: x^a
	return pow(x, a);
	//template: sqrt(x)
	return sqrt(x);
	//template: cbrt(x);
	return cbrt(x);
	----------------------------------------
	*/
	//Enter you function here
	return (1.0/sqrt(2.0*PI))*exp(-x*x/2.0);	
}

int main ()
{
	//INITIALIZE DATA (X, Y)
	//Number of Data:
	cout << "Enter the number of data: ";
	int n;
	cin >> n;
	
	//Order of the approximation aquation (k <= 10)
	cout << "Enter order of approximation equation: ";
	int k;
	cin >> k;
	
	vector <double> x (n);
	vector <double> y (n);
	
	//Case 1: Enter the data directly:
	/*cout << "Enter data (x, y):\n"
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}*/
	
	//Case 2: Collect data from a continuous function:
	cout << "Enter interval [a, b]:\n";
	double a, B;
	cin >> a >> B;
	
	for (int i = 0; i < n; i++)
	{
		x[i] = a + i*(B-a)*1.0/(n-1);
		y[i] = function(x[i]);
	}
	//END INITIALIZE DATA (X, Y)
	
	//INITIALIZE THE COEFICIENTS OF SYSTEM OF EQUATION:
	vector < vector <double> > A(k+1);
	for (int i = 0; i < k+1; i++)
	{
		A[i].resize (k+1);
	}
	
	vector <double> xk (2*k+1, 0);
	xk[0] = n;
	vector <double> b (k+1,  0);
	
	for (int i = 1; i < 2*k+1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xk[i] += power(x[j], i);
		}
	}
	
	for (int i = 0; i < k+1; i++)
	{
		for (int j = 0; j < k+1; j++)
		{
			A[i][j] = xk[i+j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		b[0] += y[i];
	}
	
	for (int i = 1; i < k+1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i] += y[j]*power(x[j], i);
		}
	}
	//END INITIALIZE THE COEFICIENTS SYSTEM OF EQUATION
	
	//SOLVE THE SYSTEM OF EQUATION FOR ai, i = 0..k:
	vector <double> a0 (k+1, 0);
	vector <double> a1 (k+1);
	bool flag = false;
	
	int itr = 1;
    while (itr <= 100000000) //Number of iterations
    {
        for (int i = 0; i < k+1; i++)
        {
            double sum1 = 0, sum2 = 0;
            for (int j = 0; j <= i - 1; j ++) sum1 += (A[i][j] * a1[j]);
            for (int j = i + 1; j < k+1; j++) sum2 += (A[i][j] * a0[j]);

            a1[i] = (- sum1 - sum2 + b[i]) / A[i][i];
        }

        if (norm2 (a1, a0, k+1) < 1e-6) // Tolerance
        {
        	flag = true;
            break;
        }

        itr++;
        for (int i = 0; i < k+1; i++)
        {
            a0[i] = a1[i];
        }
    }

    if (!flag) 
	{
		cout << "Maximum number of iterations exceeded";
    	return 0;
	}
	//END SOLVE THE SYSTEM OF EQUATION FOR ai, i = 0..k
	
    //PRINT SOLUTION
    cout << endl << "The approximation equation is: \n" <<"P(x) = ";
    cout <<a1[0] << " + "<<a1[1] << "x + ";
    for (int i = 2; i < k-1; i++)
    {
    	cout <<a1[i] << "x^" << i << " + ";
	}
	cout << a1[k] << "x^" << k;
    
    return 0;
}
