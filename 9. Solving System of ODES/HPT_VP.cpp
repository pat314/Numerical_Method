#include <bits/stdc++.h>
using namespace std;

// Function f(x, y) representing the higher-order ordinary differential equation y^(n) = f(x, y, y', ..., y^(n-1))
void f(double x, const vector<double> &y, vector<double> &dy)
{
    dy[0] = y[1];
    dy[1] = 2 * y[0] - y[1];
}

// Function to solve the system of first-order ordinary differential equations using the 4th order Runge-Kutta method
void solveODE(double x0, const vector<double> &y0, double h, double x, vector<double> &y)
{
    int n = y0.size();

    vector<double> k1(n), k2(n), k3(n), k4(n);

    double x_current = x0;
    vector<double> y_current = y0;

    while (x_current < x)
    {
        double x_next = x_current + h;

        // Calculate k1
        f(x_current, y_current, k1);

        // Calculate k2
        vector<double> y_next = y_current;
        for (int i = 0; i < n; i++)
        {
            y_next[i] = y_current[i] + h / 2 * k1[i];
        }
        f(x_current + h / 2, y_next, k2);

        // Calculate k3
        for (int i = 0; i < n; i++)
        {
            y_next[i] = y_current[i] + h / 2 * k2[i];
        }
        f(x_current + h / 2, y_next, k3);

        // Calculate k4
        for (int i = 0; i < n; i++)
        {
            y_next[i] = y_current[i] + h * k3[i];
        }
        f(x_current + h, y_next, k4);

        // Update y
        for (int i = 0; i < n; i++)
        {
            y_current[i] += h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
        }

        x_current = x_next;
    }

    y = y_current;
}

int main()
{
    double x0, h, x;
    int n;

    // Enter initial values and step size
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter the value of x to be calculated: ";
    cin >> x;
    cout << "Enter the dimension of the ODE: ";
    cin >> n;

    vector<double> y0(n);
    cout << "Enter initial values of y: ";
    for (int i = 0; i < n; i++)
    {
        cin >> y0[i];
    }

    vector<double> y(n);

    // Call the function to solve the ODE system using the 4th order Runge-Kutta method
    solveODE(x0, y0, h, x, y);

    cout << "The value of y at x = " << x << " is: ";
    for (int i = 0; i < n; i++)
    {
        cout << y[i] << " ";
    }
    cout << endl;

    return 0;
}
