#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <math.h>

//#define E 2.71828182845904523536;

float algo1(float lambda) {
    float randmax = RAND_MAX * 1.0;
    float X = -1, S = 1, q = pow(M_E,-lambda);
    while (S > q)
    {
        float U = (rand() / randmax);
        S = S * U;
        X = X + 1;
    }
    return X;
}

float algo(float lambda) {
    float randmax = RAND_MAX * 1.0;
    float x = -1, s = 0;
    
    while (s <= lambda)
    {
        float Y = -log((rand() / randmax));
        s = s + Y;
        x = x + 1;
    }
    return x;
}

int main()
{
    std::srand(std::time(NULL));
    float randmax = RAND_MAX * 1.0;  
    std::mt19937 GEN(time(nullptr));

    std::ofstream d;
    d.open("dane.txt");

    float lambda1 = 15;
    float lambda2 = 3;


    float sumax = 0;
    float sredniax = 0;
    float sredniaxkw = 0;
    float sumaxkw = 0;
    float sumax1 = 0;
    float sumax1kw = 0;
    float sumax2 = 0;
    float sumax2kw = 0;
    float sredniax1 = 0;
    float sredniax1kw = 0;
    float sredniax2 = 0;
    float sredniax2kw = 0;
    for (int i = 0; i < 2000; i++) {

        float x1 = algo(lambda1);
        //std::cout << x1 << std::endl;
        sumax1 += x1;
        sumax1kw += (x1 * x1);

        float x2 = algo1(lambda2);
        //std::cout << x2 << std::endl;
        sumax2 += x2;
        sumax2kw += (x2 * x2);

        float x = x1 + x2;
        sumax += x;
        sumaxkw += (x * x);
        d << x << std::endl;
    }
    sredniax1 = sumax1 / 2000;
    sredniax2 = sumax2 / 2000;
    sredniax1kw = sumax1kw / 2000;
    sredniax2kw = sumax2kw / 2000;

    sredniax = sumax / 2000;
    sredniaxkw = sumaxkw / 2000;

    float wariancjax1 = sredniax1kw - (sredniax1 * sredniax1);
    float wariancjax2 = sredniax2kw - (sredniax2 * sredniax2);
    float wariancjax = sredniaxkw - (sredniax * sredniax);
    std::cout << "wariancja x1 : " << wariancjax1 << std::endl;
    std::cout << "wariancja x2 : " << wariancjax2 << std::endl << std::endl;;
    std::cout << "lambda x1 : " << lambda1 << std::endl;
    std::cout << "lambda x2 : " << lambda2 << std::endl;

    std::cout << "wariancja x : " << wariancjax << std::endl << std::endl;;

    //rozklad dwumianowy Bernoulliego
    //float p = 0.5;
    //float n = 10;
    //int k = 0;
    //float suma = 0;
    //float sumak = 0;
    //for (int i = 0; i < 1000; i++) {
    //    k = 0;
    //    for (int j = 0; j < n; j++) {
    //        float ran = (rand() / randmax);
    //        if (ran <= p) {
    //            k++;
    //        }
    //    }
    //    
    //    d << k << std::endl;
    //    std::cout << k << std::endl;
    //    suma += k;
    //    sumak += k * k;
    //}


    //float srednia = n * p;
    //float wariancja = srednia * (1 - p);

    //float sredniaR = suma / 1000;
    //float odchylenie = sumak / 1000;
    //float wariancjaR = odchylenie - (sredniaR * sredniaR);


    //std::cout << "Wariancja teoretyczna: " << wariancja << std::endl;
    //std::cout << "Wariancja rzeczywista:  " << wariancjaR << std::endl;
    //std::cout << "Srednia teoretyczna: " << srednia << std::endl;
    //std::cout << "Srednia rzeczywista:  " << sredniaR << std::endl;

    /*float kkw = k * k;
    float sumakw = suma * suma;
    float srednia = suma / 1000;
    float sredniakw = sumakw / 1000;
    float wariancja = sredniakw - (srednia * srednia);*/

    
    //int missed = 0;
    //std::cout << "\ELIMINACJI" << std::endl;
    //do
    //{
    //    float x = C + (100 - C) * rand() / randmax;
    //    float y = 0 + (B - 0) * rand() / randmax;
    //    float fx = B * exp(-B * (x - C));

    //    if (y <= fx)
    //    {
    //        count++;
    //        d << x << "\n";
    //        std::cout << x << std::endl;
    //    }
    //    else
    //    {
    //        missed++;
    //    }

    //} while (count < 2000);
    //d.close();



    //1
    //std::cout << "boxa" << std::endl;
    //float mi = 5;
    //float sigma = 10;
    //float xii = 0;
    //int count1 = 0;
    //do
    //{
    //    float u1 = rand() / randmax;
    //    float u2 = rand() / randmax;
    //    float R = sqrt(-2 * log(u1));
    //    float Theta = 2 * M_PI * u2;

    //    float z1 = R * sin(Theta);
    //    float z2 = R * cos(Theta);

    //    float x = z2 * sigma + mi;
    //    d << x << "\n";
    //    std::cout << x << std::endl;
    //    count1++;
    //} while (count1 < 2000);

    //std::cout << std::endl << std::endl << count1 << "2 " << std::endl;
    //
    //
    ////2
    //int count2 = 0;
    //do
    //{
    //    for (int i = 0; i < 6; i++)
    //    {
    //        float xi = rand() / randmax;
    //        xii += xi;
    //    }

    //    float mi1 = 0.5;

    //    float sigma1 = sqrt(1. / 12.);
    //    
    //    float y = ((1. / 6.) * xii - mi1) / (sigma1 / sqrt(6));
    //    float x = y * sigma + mi;
    //    std::cout << x << std::endl;
    //    count2++;
    //    xii = 0;
    //} while (count2 < 2000);


    /*d << z1 << "\n";
    d << z1 << "\n";*/
    //std::cout << count1 << ":  " << x << std::endl;

   // std::normal_distribution<> dodatkowa_drzemka(80., 20);

    //std::cout << "\nODWROCONA DYSTRYBUANTA" << std::endl;
    //int count1 = 0;
    //do
    //{
    //    float D = rand() / randmax;
    //    float x = (asin((2*D)-1) / 2)- (M_PI/4);
    //    d << x << "\n";
    //    //std::cout << count1 << ":  " << x << std::endl;
    //    count1++;

    //} while (count1 < 2000);


    //std::cout << "\eliminacja" << std::endl;
    //int count2 = 0;
    //do
    //{
    //    float x = -(M_PI/2) + (0 - (-M_PI/2)  * rand() / randmax);
    //    float y = rand() / randmax;

    //    float fx = cos((2 * x) + (M_PI / 2));

    //    if (y <= fx)
    //    {
    //       
    //        count2++;
    //        //std::cout << count2 << ":  " << x << std::endl;
    //    }

    //} while (count2 < 2000);
    d.close();
    //std::cout << missed << std::endl;
}
