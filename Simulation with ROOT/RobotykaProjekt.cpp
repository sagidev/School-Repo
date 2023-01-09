#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <math.h>

//#define E 2.71828182845904523536;
float randmax = RAND_MAX * 1.0;

int customrand(int od, int doo)
{
    return rand() % (doo-od) + od;
}

int losuj3(int szansa1, int szansa2) {
    float p = szansa1 / 100; //0.3
    float pp = szansa2 / 100; //0.5
    float r = (float)(rand() / randmax);
    if (r <= p)
        return 1;
    else if (r > p && r <= pp)
        return 2;
    else if (r > pp)
        return 3;
}

bool losuj(int szansa) {
    float p = szansa / 100.0;
    float r = (float)(rand() / randmax);
    if (r <= p)
        return true;
    else
        return false;
}

int main()
{
    std::srand(std::time(NULL));

    std::ofstream d;
    d.open("dane.txt");

    int min = 1000;
    int max = 0;

    for (int i = 0; i < 5000; i++) {
        int czas = 0;

        //jesli jest na l4 to jego praca jest odlozona o 20h
        bool l4 = losuj(25);
        if (l4) {
            czas += customrand(5,20);
        }
        else
            czas += customrand(1, 5);

        //jesli slabe zarobki to mniej wydajny bo mu sie nei chce
        bool zarobki = losuj(85);
        if (zarobki)
            czas += customrand(1, 5);
        else
            czas += customrand(5, 15);

        //jesli doswiadczony to 2x szybciej zrobi
        bool doswiadczony = losuj(50);
        if (doswiadczony)
            czas += customrand(15, 25);
        else
            czas += customrand(25, 50);

        //jesli nadgodziny to szybciej
        //bez nadgodzin 5h wiecej
        bool nadgodziny = losuj(30);
        if (nadgodziny)
            czas -= customrand(1, 5);
        else
            czas += customrand(1, 5);

        //malo snu 20
        //srednio snu 60
        //duzo snu 20
        int wynik_sen = losuj3(20, 60);
        if (wynik_sen == 1)
            czas += customrand(15, 25);
        else if (wynik_sen == 2)
            czas += customrand(10, 15);
        else if (wynik_sen == 3)
            czas += customrand(5, 10);

        //mozliwosc awarii sprzetu
        bool awaria = losuj(10);
        if (awaria)
            czas += customrand(20, 40);

        //mozliwosc pomocy
        //brak pomocy 40
        //mala pomoc 40
        //duza pomoc 20
        int wynik_pomocy = losuj3(40, 40);
        if (wynik_pomocy == 1)
            czas += customrand(1, 2);
        else if (wynik_pomocy == 2)
            czas -= customrand(1, 5);
        else if (wynik_pomocy == 3)
            czas -= customrand(5, 10);

        d << czas<< std::endl;
        if (czas > max)
            max = czas;
        if (czas < min)
            min = czas;
        std::cout << i << ":      " << czas << "h" << std::endl;
    }

    std::cout << "min:      " << min << ",       max: " << max << std::endl;

    d.close();
}
