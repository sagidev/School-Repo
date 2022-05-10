// RK4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

double f(double x, double y)
{
    return -y*y;
}

void RK4(double b, double a, double n, double x0, double y0, double x, double y)
{
    double h = (b - a) / n;
    double k1, k2, k3, k4;

    for (int i = 0; i < n; i++)
    {
        k1 = f(x0, y0);
        k2 = f(x0 + (h / 2), y0 + (h / 2) * k1);
        k3 = f(x0 + (h / 2), y0 + (h / 2) * k2);
        k4 = f(x0 + h, y0 + (h * k3));
        //k = (k1 / 6 + 2 * k2 / 6 + 2 * k3 / 6 + k4 / 6);
        y = y0 + (h * ((k1 / 6) + (2 * k2 / 6) + (2 * k3 / 6) + (k4 / 6)));
        cout << "x0: " << x0 << ", y0: " << y0 << ", y " << y << endl;
        //x0 = x0 + h;
        y0 = y;

    }
    cout << "Wartosc dla x: " << x << " jest rowna: " << y;
}
void RK5(double b, double a, double n, double x0, double y0, double x, double y)
{
    double h = (b - a) / n;
    double k1, k2, k3, k4, k5, k6;
    for (int i = 0; i < n; i++)
    {
        k1 = f(x0, y0) * h;
        k2 = f(x0 + (k1 / 4), y0 + (k1 / 4) * h) * h;
        k3 = f(x0 + (3 * k1 / 32) + (9 * k2 / 32), y0 + (3 * h / 8)) * h;
        k4 = f(x0 + (1932 * k1 / 2197) - (7200 * k2 / 2197) + (7296 * k3 / 2197), y0 + (12 * h / 13)) * h;
        k5 = f(x0 + (439 * k1 / 216) - 8 * k2 + (3680 * k3 / 513) - (845 * k4 / 4104), y0 + h) * h;
        k6 = f(x0 - (8 * k1 / 27) + 2 * k2 - (3544 * k3 / 2565) + (1859 * k4 / 4104) - (11 * k5 / 40), y0 + (h / 2)) * h;
        //k = (k1 / 6 + 2 * k2 / 6 + 2 * k3 / 6 + k4 / 6);
        y = y0 + (h * ((k1 / 6) + (2 * k2 / 6) + (2 * k3 / 6) + (k4 / 6)));
        cout << "x0: " << x0 << ", y0: " << y0 << ", y " << y << endl;

        //x0 = x0 + h;
        y0 = y;

    }
}
int main()
{
    double x = 1;
    double y = 0;
    double x0 = -1, y0 = 2, n = 15;
    double a = -1, b = 1;
    RK5(b, a, n, x0, y0,x,y);
}


