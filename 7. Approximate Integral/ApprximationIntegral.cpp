#include <bits/stdc++.h>
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
	return (1.0/sqrt(2.0*PI))*exp(-x*x*1.0/2.0);	
}

void Composite_Simpson (double a, double b, int n)
{
	if (n%2 == 1) return;
	double h = (b-a)*1.0/(n*1.0);
	vector <double> x (n+1);
	for (int i = 0; i <=n; i++)
	{
		x[i] = a + i*h;
	}
	
	double sigma1 = 0;
	for (int i = 1; i <= n - 1; i += 2)
	{
		sigma1 += function(x[i]);
	}
	
	double sigma2 = 0;
	for (int i = 2; i <= n - 2; i += 2)
	{
		sigma2 += function(x[i]);
	}
	
	double I = (h/3.0)*(function(a) + 2*sigma2 + 4*sigma1 + function(b));
	cout << "Integral Approximation: \n";
	cout << I << endl;
	cout << "with the error is -((b-a)/180)h^4.f(4)(m)\n";
	return;
}


void Composite_Trapezoidal (double a, double b, int n)
{
	double h = (b-a)*1.0/(n*1.0);
	vector <double> x (n+1);
	for (int i = 0; i <=n; i++)
	{
		x[i] = a + i*h;
	}
	
	double sigma = 0;
	for (int i = 1; i <= n - 1; i ++)
	{
		sigma += function(x[i]);
	}
	
	double I = (h/2.0)*(function(a) + 2*sigma + function(b));
	cout << "Integral Approximation: \n";
	cout << I << endl;
	cout << "with the error is -((b-a)/12)h^2.f''(m)\n";
	return;
}

void Composite_Midpoint (double a, double b, int n)
{
	if (n%2 == 0) return;
	double h = (b-a)*1.0/((n+2)*1.0);
	vector <double> x (n+3);
	for (int i = 0; i <=n; i++)
	{
		x[i] = a + i*h;
	}
	
	double sigma = 0;
	for (int i = 0; i <= n; i += 2)
	{
		sigma += function(x[i]);
	}
	
	double I = (2.0*h)*sigma;
	cout << "Integral Approximation: \n";
	cout << I << endl;
	cout << "with the error is -((b-a)/6)h^2.f''(m)\n";
	return;
}

int main ()
{
	cout << "Enter the interval [a, b]: ";
	double a, b;
	cin >> a >> b;
	cout << "Enter number of subintervals n: ";
	int n;
	cin >> n;
	
	cout << "----------OPTIONS----------" << endl;
	cout << "1. Composite Simpson's Rule.\n";
	cout << "2. Composite Trapezoidal Rule.\n";
	cout << "3. Composite Midpoint Rule.\n";
	cout << "Your option: ";
	int option;
	cin >> option;
	switch (option)
	{
		case 1:
			Composite_Simpson (a, b, n);
		break;
		
		case 2:
			Composite_Trapezoidal (a, b, n);
		break;
		
		case 3:
			Composite_Midpoint (a, b, n);
		break;
	}
	
	return 0;
}
