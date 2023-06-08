#include <bits/stdc++.h>
using namespace std;

#define lb double

lb f(lb x, lb y)
{
    return 1 + y + x * x;
}

lb RK2(lb x0, lb y0, lb h, lb x)
{
    int n = (x - x0) / h;
    lb K1, K2;
    for (int i = 0; i < n; i++)
    {
        K1 = f(x0, y0);
        K2 = f(x0 + h, y0 + h * K1);
        y0 = y0 + h / 2 * (K1 + K2);
        x0 += h;
    }
    return y0;
}

int main()
{
    lb x0, y0, h, x;

    // Enter initial values and step size
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter y0: ";
    cin >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter the value of x to calculate: ";
    cin >> x;

    // Call the Runge-Kutta function and display the result
    lb result = RK2(x0, y0, h, x);
    cout << "The value of y at x = " << x << " is: " << result << endl;
    system("pause");
}