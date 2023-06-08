#include <bits/stdc++.h>
using namespace std;

#define lb double

lb f(lb x, lb y)
{
    return x * x - y;
}

lb Euler(lb x0, lb y0, lb h, lb x)
{
    int n = ((x - x0) * 1.0 / h);
    for (int i = 0; i < n; i++)
    {
        cout << "x = " << x0 << " y = " << y0 << endl;
        y0 += h * f(x0, y0);
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

    lb result = Euler(x0, y0, h, x);
    cout << "The value of y at x = " << x << " is: " << result << endl;
    system("pause");
}