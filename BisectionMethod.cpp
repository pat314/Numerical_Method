#include <iostream>
using namespace std;

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
    double fa = (a + 2) * (a + 1) * a * (a - 1)* (a - 1) * (a - 1) * (a - 2);
	while (i < n0)
	{
		double p = a + (b - a) / 2;
		double fp = (p + 2) * (p + 1) * p * (p - 1)* (p - 1) * (p - 1) * (p - 2);
		if ((fp ==0) || ((b - a) / 2) < TOL)
		{
			cout <<"Approximation: "<< p << endl;
            cout <<"Iterations: " << i;
			return 0;
		}
		i ++;
		if (fa * fp > 0) a = p;
		else b = p;
	}
	cout << "Method failed after " << n0 << " iterations";
	return 0;
}