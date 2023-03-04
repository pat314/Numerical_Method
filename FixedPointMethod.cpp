#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double p0, TOL;
    int n0;
    cout << "INPUT: " << endl;
    
    cout << "Initial point: ";
    cin >> p0;
       
    cout <<"Tolerance: ";
    cin >> TOL; 
    
    cout << "Enter maximum iterations you want: ";    
    cin >> n0;
    
    //FIXED - POINT METHOD
    int i = 1;
    while (i <= n0)
	{
		double p = sqrt (sqrt (3*p0*p0 + 3));
		if (fabs(p - p0) < TOL)
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