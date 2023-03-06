#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
    return 230 * x*x*x*x + 18 * x*x*x + 9 * x*x - 221 * x - 9;
}

int main() {
    double a, b, p0, p1, TOL;
    int n0;
    cout << "INPUT: " << endl;
    
    cout << "Interval [a; b]" << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Initial point 1 (A Fourier point): ";
    cin >> p0;
    
    cout << "Initial point 2 (Not a Fourier point): ";
    cin >> p1;

    cout <<"Tolerance: ";
    cin >> TOL; 
    
    cout << "Enter maximum iterations you want: ";    
    cin >> n0;
    
    //SECANT METHOD
    int i = 2;
    double q0 = f(p0);
    double q1 = f(p1);
    while (i <= n0)
	{
		double p = p1 - (q1*(p1 - p0)) / (q1 - q0);
		if (fabs(p - p1) < TOL && p >= a && p <= b)
		{
            cout << "OUTPUT: " << endl;
			cout <<"Approximation: "<< p << endl;
            cout <<"Iterations: " << i;
			return 0;
		}
		i ++;
		p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = f(p);
	}
    cout << "OUTPUT: " << endl;
	cout << "Method failed after " << n0 << " iterations";
	return 0;
}
