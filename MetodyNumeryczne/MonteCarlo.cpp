// DT_metody8.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;


double f(double x)
{
    return sin(x);
}

double monteCarlo(double max, double min, int n)
{
    double suma = 0;
    for (int i = 0; i < n; i++)
    {
        double x = min + (max - min) * (float(rand()) / RAND_MAX);
        suma += f(x);
    }
    suma = suma / n;
    double l = (max - min) * suma;
    return l;
}

int main()
{
    double max = 3.14;
    double min = 0;
    int n = 100000;

    cout << "calka: " << monteCarlo(max, min, n) << ", liczba iteracji: " << n;
}

