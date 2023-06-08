#include <bits/stdc++.h>
using namespace std;

#define lb double

lb f(lb x, lb y)
{
    return 1 + x * x + y;
}

lb adamsMoulton4(lb x0, lb y0, lb h, lb x)
{
    int n = ((x - x0) / h);

    lb y = y0;
    lb x_prev, y_prev, f_prev;

    for (int i = 1; i <= 3; i++)
    {
        x_prev = x0 + (i - 1) * h;
        y_prev = y0;
        f_prev = f(x_prev, y_prev);

        lb k1, k2, k3, k4;
        k1 = h * f(x_prev, y_prev);
        k2 = h * f(x_prev + h / 2, y_prev + k1 / 2);
        k3 = h * f(x_prev + h / 2, y_prev + k2 / 2);
        k4 = h * f(x_prev + h, y_prev + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }

    for (int i = 4; i <= n; i++)
    {
        lb y_next = y + h * (55 * f(x, y) - 59 * f_prev + 37 * f(x_prev, y_prev) - 9 * f(x_prev - h, y_prev - h * f_prev)) / 24;

        x_prev = x;
        y_prev = y;
        f_prev = f(x_prev, y_prev);

        x += h;
        y = y_next;
    }

    return y;
}

int main()
{
    lb x0, y0, h, x;

    // Enter the initial values and step sizes
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter y0: ";
    cin >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter the value that need to approximate: ";
    cin >> x;

    lb result = adamsMoulton4(x0, y0, h, x);
    cout << "The approximation of y at x = " << x << " is : " << result << endl;

    system("pause");
}
