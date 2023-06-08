#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
    return 230 * x*x*x*x + 18 * x*x*x + 9 * x*x - 221 * x - 9;
}

double df(double x)
{
    return 920 * x*x*x + 54 * x*x + 18 * x - 221;
}

int main() {
    double a, b, p0, TOL;
    int n0;
    cout << "INPUT: " << endl;
    
    cout << "Interval [a; b]" << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Initial point: ";
    cin >> p0;
       
    cout <<"Tolerance: ";
    cin >> TOL; 
    
    cout << "Enter maximum iterations you want: ";    
    cin >> n0;
    
    //NEWTON METHOD
    int i = 1;
    while (i <= n0)
	{
		double p = p0 - (f(p0) / df(p0));
		if (fabs(p - p0) < TOL && p <= b && p >= a)
		{
            cout << "OUTPUT: " << endl;
			cout <<"Approximation: "<< p << endl;
            cout <<"Iterations: " << i;
			return 0;
		}
		i ++;
		p0 = p;
	}
    cout << "OUTPUT: " << endl;
	cout << "Method failed after " << n0 << " iterations";
	return 0;
}