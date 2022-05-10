#include <iostream>

//#define   f(x)   pow(x,4)-9*pow(x,3)-15
//#define   fp(x)   4*pow(x,3)-27*pow(x,2) 

float f(int x)
{
    return pow(x, 4) - 9 * pow(x, 3) - 15;
}

float fp(int x)
{
    return 4 * pow(x, 3) - 27 * pow(x, 2);
}

float fpp(int x)
{
    return 12 * pow(x, 2) - 54 *x;
}
using namespace std;
void newton(int x)
{
    int i = 0, x1;
    while (abs(f(x) > 0.001))
    {
        i++;
        x1 = x - (f(x) / fp(x));
        cout << "i: " << i << ", root: " << x1;
        x = x1;
    }
}
void Halley(float x)
{
    float i = 0, x1;
    do 
    {
        i++;
        x1 = x - (2 * f(x) * fp(x)) / (2 * ((fp(x) * fp(x)) - f(x) * fpp(x)));
        cout << "i: " << i << ", root: " << x1 << endl;
        x = x1;
        //if (f(x1) == 0)
        //    break;
    } while (abs(f(x1) < 0.001));
}
int main()
{
    Halley(8);
}

