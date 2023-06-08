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
	return log(x);	
}

void Foward_Backward_Difference_Formula (double x, double h)
{
	double result = (function(x+h) - function(x))*1.0/h;
	cout << "f'(x) = " << result << endl;
	cout << "with the error: " <<fabs(-h*1.0/2.0) << "|f''(e)|";
	return;
}

void Three_point_midpoint_Difference_Formula (double x, double h)
{
	double result = (function(x+h) - function(x-h))*1.0/(2*h);
	cout << "f'(x) = " << result << endl;
	cout << "with the error: " <<fabs(-h*h*1.0/6.0) << "|f(3)(e)|";
	return;
}

void Three_point_endpoint_Difference_Formula (double x, double h)
{
	double result = (-3*function(x) + 4*function(x+h) - function(x+2*h))*1.0/(2*h);
	cout << "f'(x) = " << result << endl;
	cout << "with the error: " <<fabs(-h*h*1.0/3.0) << "|f(3)(e)|";
	return;
}

void Five_point_midpoint_Difference_Formula (double x, double h)
{
	double result = (function(x-2*h) - 8*function(x - h) + 8*function(x+h) - function(x+2*h))*1.0/(12*h);
	cout << "f'(x) = " << result << endl;
	cout << "with the error: "  <<fabs(-h*h*h*h*1.0/30.0) << "|f(4)(e)|";
	return;
}

void Five_point_endpoint_Difference_Formula (double x, double h)
{
	double result = (-25*function(x) + 48*function(x + h) - 36*function(x+ 2*h) + 16*function(x + 3*h) - 3*function(x+ 4*h))*1.0/(12*h);
	cout << "f'(x) = " << result << endl;
	cout << "with the error: " <<fabs(-h*h*h*h*1.0/5.0) << "|f(4)(e)|";
	return;
}

void Second_Derivative_Midpoint_Formula (double x, double h)
{
	double result = (function(x - h) - 2*function(x) + function(x+ h))*1.0/(h*h);
	cout << "f''(x) = " << result << endl;
	cout << "with the error: " <<fabs(-h*h*1.0/12.0) << "|f(4)(e)|";
	return;
}

int main ()
{
	//INPUT THE DATA:
	cout << "Enter x0: ";
	double x;
	cin >> x;
	
	cout <<"Enter h: ";
	double h;
	cin >> h;
	
	cout << "----------OPTIONS----------" << endl;
	cout << "1. Forward/Backward Difference Formulae.\n";
	cout << "2. Three - point Midpoint Formula.\n";
	cout << "3. Three - point Endpoint Formula.\n";
	cout << "4. Five - point Midpoint Formula.\n";
	cout << "5. Five - point Endpoint Formula.\n";
	cout << "6. Second Derivative Midpoint Formula.\n";
	cout << "Your option: ";
	int option;
	cin >> option;
	switch (option)
	{
		case 1:
			Foward_Backward_Difference_Formula (x, h);
		break;
		
		case 2:
			Three_point_midpoint_Difference_Formula (x, h);
		break;
		
		case 3:
			Three_point_endpoint_Difference_Formula (x, h);
		break;
		
		case 4:
			Five_point_midpoint_Difference_Formula (x, h);
		break;
		
		case 5:
			Five_point_endpoint_Difference_Formula (x, h);
		break;
		
		case 6:
			Second_Derivative_Midpoint_Formula (x, h);
		break;
	}
	
	return 0;
}
