#include <bits/stdc++.h>
using namespace std;

const int PI = 3.141592654;
const int E = 2.718281828;

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

//Example 9
//Input each function of System of DEs here:
double f (double t, vector <double> w, int index)
{
	switch (index)
	{
		case 1:
			//return w[2];
			return (-4.0*w[1] + 3.0*w[2] + 6.0);
		break;
		
		case 2:
			//return (exp(-w[2]) - cos(t) + w[1]);
			return (-2.4*w[1] + 1.6*w[2] + 3.6);
		break;
		
		/*case 3:
			return (cbrt(w[3]) - t*w[2]);
		break;*/
	}
	
}

int main ()
{
	//INPUT
	cout << "Enter endpoints a, b: ";
	double a, b;
	cin >> a >> b;
	
	cout << "Enter number of equations m: "; // m = 3
	int m;
	cin >> m;
	
	cout << "Enter number of subintervals N: ";
	int N;
	cin >> N;
	
	cout << "Enter initial conditions alpha_i: ";
	vector <double> alpha (m+1);
	for (int i = 1; i <= m; i++) cin >> alpha[i];
	//END INPUT
	
	//Step 1:
	double h = (b-a)*1.0/N;
	double t = a;
	
	//Step 2:
	vector <double> w (m+1);
	for (int i = 1; i <= m; i++) w[i] = alpha[i];
	
	//Step 3: OUTPUT (t, w1,..,wm) at t = a
	cout << t << "   ";
	for (int i = 1; i <= m; i++) cout << w[i] << "   ";
	cout << endl;
	
	//Step 4:
	vector <double> k1 (m+1);
	vector <double> k2 (m+1);
	vector <double> k3 (m+1);
	vector <double> k4 (m+1);
	for (int i = 1; i <= N; i++)
	{
		//Step 5: Calculate k1,j
		for (int j = 1; j <= m; j++)
		{
			k1[j] = h*f(t, w, j);
		}
		
		//Step 6: Calculate k2,j
		vector <double> w2 (m+1);
		for (int j = 1; j <= m; j++)
		{
			w2[j] = (w[j] + 0.5*k1[j]);
		}
		
		for (int j = 1; j <= m; j++)
		{
			k2[j] = h*f(t + 0.5*h, w2, j);
		}
		
		//Step 7: Calculate k3,j
		vector <double> w3 (m+1);
		for (int j = 1; j <= m; j++)
		{
			w3[j] = w[j] + 0.5*k2[j];
		}
		
		for (int j = 1; j <= m; j++)
		{
			k3[j] = h*f(t + 0.5*h, w3, j);
		}
		
		//Step 8: Calculate k4,j
		vector <double> w4 (m+1);
		for (int j = 1; j <= m; j++)
		{
			w4[j] = w[j] + k3[j];
		}
		
		for (int j = 1; j <= m; j++)
		{
			k4[j] = h*f(t + h, w4, j);
		}
		
		//Step 9: Calculate wj at t = a+ ih
		for (int j = 1; j <=m; j++)
		{
			w[j] = w[j] + (k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6.0;
		}
		
		//Step 10: 
		t = a + i*h;
		
		//Step 11: OUTPUT (t, w1,..,wm) at t = a + ih
		cout << t << "   ";
		for (int i = 1; i <= m; i++) cout << fixed << setprecision(6) << w[i] << "   ";
		cout << endl;
	}
	
	//Step 12: STOP
	return 0;
}
