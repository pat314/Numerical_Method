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
	double A, B;
	cin >> A >> B;
	
	vector <double> x(n);
	vector <double> y(n);
	
	//If you want to input discrete points, use these codes:
	/*for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];		
	}*/
	
	
	for (int i = 0; i < n; i++)
	{
		x[i] = A + i*(B-A)*1.0/(n-1);
		y[i] = function(x[i]);
	}
	
	vector <double> a(n);
	vector <double> b(n-1);
	vector <double> c(n);
	vector <double> d(n-1);
	vector <double> h(n-1);
	
	for (int i = 0; i < n; i++)
	{
		a[i] = y[i];
	}
	
	//END INITIALIZE DATA (X,Y)
	
	//NATURAL CUBIC SPLINE INTERPOLATION
	//Step 1:
	for (int i = 0; i <n-1; i++) h[i] = x[i+1] - x[i];
	
	//Step 2:
	vector <double> alpha (n-1, 0);
	for (int i = 1; i < n-1; i++) 
	{
		alpha[i] = (3.0*(a[i+1]-a[i]))/h[i] - (3.0*(a[i]-a[i-1]))/h[i-1];
	}
	
	//Step 3:
	vector <double> mu (n, 0);
	vector <double> z (n, 0);
	vector <double> l (n, 0);
	l[0] = 1;
	
	//Step 4:
	for (int i = 1; i < n-1; i++)
	{
		l[i] = 2*(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
		mu[i] = h[i]*1.0/l[i];
		z[i] = (alpha[i] - h[i-1]*z[i-1])*1.0/l[i];
	}
	
	//Step 5:
	l[n-1] = 1;
	
	//Step 6:
	for (int j = n-2; j >=0; j--)
	{
		c[j] = z[j] - mu[j]*c[j+1];
		b[j] = (a[j+1] - a[j])*1.0/h[j] - h[j]*(c[j+1] +2*c[j])/3.0;
		d[j] = (c[j+1] - c[j])/(3.0*h[j]);
	}
	//END NATURAL CUBIC SPLINE INTERPOLATION
	
	//PRINT SOLUTION
	cout << "S(x) = \n";
	for (int i = 0; i < n-1; i++)
	{
		cout << a[i] << " + " << b[i] << "(x - " << x[i] << ")"
			 << " + " << c[i] << "(x - " << x[i] << ")^2"
			 << " + " << d[i] << "(x - " << x[i] << ")^3     with x in ["<< x[i] << "; " << x[i+1] << "]";
		cout << endl;
	}
	
	
	//END PRINT SOLUTION
	
}
	
