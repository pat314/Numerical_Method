#include <iostream>
using namespace std;

double f(double x)
{
    return ((x + 2) * (x + 1) * x * (x - 1) * (x - 1) * (x - 1) * (x - 2));
}

int main() {
    double a, b, TOL;
    int n0;
    cout << "INPUT: " << endl;
    
    cout << "Interval [a; b]" << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
   
    cout <<"Tolerance: ";
    cin >> TOL; 
    
    cout << "Enter maximum iterations you want: ";    
    cin >> n0;
    
    //BISECTION METHOD
    int i = 1;
    while (i <= n0)
	{
		double p = a + (b - a) / 2;
		if ((f(p) == 0) || ((b - a) / 2) < TOL)
		{
            cout << "OUTPUT: " << endl;
			cout <<"Approximation: "<< p << endl;
            cout <<"Iterations: " << i;
			return 0;
		}
		i ++;
		if (f(a) * f(p) > 0) a = p;
		else b = p;
	}
    cout << "OUTPUT: " << endl;
	cout << "Method failed after " << n0 << " iterations";
	return 0;
}
