#include <bits/stdc++.h>
#include <math.h>
using namespace std;

const int PI = 3.141592654;
const int E = 2.718281828;

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
	return sin(x);	
}

int main ()
{
	//INITIALIZE DATA (X,Y)
	cout << "Enter the number of data: ";
	int n;
	cin >> n;

	cout << "Enter interval [a, b]\n";
	double a, b;
	cin >> a >> b;
	
	vector <double> x(n);
	vector <double> y(n);
	
	for (int i = 0; i < n; i++)
	{
		x[i] = a + i*(b-a)*1.0/(n-1);
		y[i] = function(x[i]);
	}	
	//END INITIALIZE DATA (X,Y)
	
	
	//LAGRANGE INTERPOLATION
	cout << "P(x) = ";
	
	for (int i = 0; i < n; i++)
	{
		double denominator;
		double multiply = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j) multiply *= (x[i]-x[j]);
		}
		denominator = y[i]*1.0/multiply;
		
		cout << denominator;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			 cout << "(x - " << x[j] <<")";
		}
		 cout << "\n + ";
	}
	cout << "err" << endl;
	cout << "with ""err"" is the error function of the interpolation method with: \n";
	cout << "err = (d^(n+1)F(e)/dx)";
	for (int j = 0; j < n; j++)
	{
		cout << "(x - " << x[j] <<")";
	}
	
	return 0;
}
