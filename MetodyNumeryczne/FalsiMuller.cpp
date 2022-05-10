// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

float f(int x)
{
    return pow(x,3)+4*pow(x,2)-10;
    //return cos(x) - x * exp(x);
}

void muller(float x0, float x1, float x2, float e)
{
    double a, b, c,fx{},x{};
    double root1, root2, delta;
    double fx0 = f(x0), fx1=f(x1), fx2=f(x2);
    int step = 1;
    double skrot;
    while (step < 100)
    {
        skrot = (fx1 - fx2) / (x1 - x2);
        a = ((fx0 - fx2) / (x0 - x2) - skrot) / (x0 - x1);
        b = skrot - a * (x1 + x2);
        c = fx2 - x2 * (a * x2 + b);
        delta = pow(b, 2) - 4 * a * c;
        if (delta > 0)
        {
            root1 = (-b - sqrt(delta)) / 2 / a;
            root2 = (-b + sqrt(delta)) / 2 / a;
            if (fabs(root1 - x2) < fabs(root2 - x2))
            {
                x = root1;
            }
            else
            {
                x = root2;
            }
            fx = f(x);
            if ((fabs(fx) < e) || fabs(x - x2) < e)
                break;
            x0 = x1;
            x1 = x2;
            x2 = x;
            fx0 = fx1;
            fx1 = fx2;
            fx2 = fx;
        }
        step++;
        cout << "Step: " << step << ", x: " << x << ", f(x): " << fx << endl;
    }
}

void falsi(float a, float b, float e)
{
    if (f(a) * f(b) < 0)
    {
        int step = 1;
        float fx,x;
        float fa = f(a);
        float fb = f(b);
        float aa = a;
        float bb = b;
        cout << fixed;
        do
        {
            x = aa - (aa - bb) * fa / (fa / fb);
            fx = f(x);
            cout << "Step " << step << ":    x: " << x << "    f(x): " << fx << endl;
            if (fa * fx < 0)
            {
                bb = x;
                fb = fx;

            }
            else
            {
                aa = x;
                fa = fx;
            }
            step++;

        } while (fabs(fx > e));
        cout << "Root: " << x << endl;
    }
    else
    {
        cout << "error";
    }
}

int main()
{
    falsi(1, 2, 0.00001);
    muller(1, 2, 3, 0.0001);
}

// secant, false position

