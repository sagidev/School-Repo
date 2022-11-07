#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>

int main()
{
    std::srand(std::time(NULL));
    float randmax = RAND_MAX * 1.0;    
    //float B = 1.5, C = 40;
    //int count = 0;
    //int missed = 0;
    //std::cout << "\ELIMINACJI" << std::endl;
    std::ofstream d;
    d.open("dane.txt");
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

    std::cout << "boxa" << std::endl;
    float mi = 5;
    float sigma = 10;
    float xii = 0;
    int count1 = 0;
    do
    {
        float u1 = rand() / randmax;
        float u2 = rand() / randmax;
        float R = sqrt(-2 * log(u1));
        float Theta = 2 * M_PI * u2;

        float z1 = R * sin(Theta);
        float z2 = R * cos(Theta);

        float x = z2 * sigma + mi;
        std::cout << x << std::endl;
        count1++;
    } while (count1 < 2000);

    std::cout << std::endl << std::endl << count1 << "2 " << std::endl;
    
    
    
    int count2 = 0;
    do
    {
        for (int i = 0; i < 6; i++)
        {
            float xi = rand() / randmax;
            xii += xi;
        }

        float mi1 = 0.5;

        float sigma1 = sqrt(1. / 12.);
        
        
        float y = ((1. / 6.) * xii - mi1) / (sigma1 / sqrt(6));
        float x = y * sigma + mi;
        std::cout << x << std::endl;
        count2++;
        xii = 0;
    } while (count2 < 2000);


    /*d << z1 << "\n";
    d << z1 << "\n";*/
    //std::cout << count1 << ":  " << x << std::endl;



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
