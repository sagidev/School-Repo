// dt_metody9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;
float f(float y)
{
    return -(y*y);
    //return (1 / (y + 3 / 2));
}


void Euler(float x0, float y0, float n, float a, float b)
{
    cout << "Liczba krokow: " << n << endl << endl;
    float y = y0;
    float x = 0;
    float aa = x0;
    float h = (b - a) / n;
    for (int i = 0; i < n; i++)
    {
        y = y + h * (f(y));
        //x = x + h;
        x = aa + (i+1) * h;
        cout << "x: " << x << ",   y: " << y << endl;
    }
    
}

void Huen(float x0, float y0, float n, float a, float b)
{
    float y = y0;
    float x = x0;
    float h = (b - a) / n;
    for (int i = 0; i < n; i++)
    {
       // y= y+h((f(y)+f(y+h) / 2)
    }
}

int main()
{
    float x0 = -1;
    float y0 = 2;
    //przedzial <-1,1>
    Euler(x0, y0, 20, -1, 1);
}
