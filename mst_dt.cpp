// mst_dt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <string>
#include <list>
#include <algorithm>
using namespace std;
class edge {
public:
    int x;
    string name;

};

class krawedz {
public:
    int x, x1, waga;
};

#include <iostream>
bool comp(const krawedz& lhs, const krawedz& rhs)
{
    return lhs.waga < rhs.waga;
}
int main()
{
    int nKrawedzi, nRogow;
    cout << "ile rogow" << endl;
    cin >> nRogow;
    cout << "ile krawedzi" << endl;
    cin >> nKrawedzi;
    edge* edges = new edge[nRogow];
    krawedz* krawedzie = new krawedz[nKrawedzi];
    cout << endl << "ile krawedzi" << endl;
    for (int i = 0; i < nRogow; i++)
    {
        cout << "x: " << endl;
        cin >> edges[i].x;
        cout << "name: " << endl;
        cin >> edges[i].name;
    }
    for (int i = 0; i < nKrawedzi; i++)
    {
        cout << "x: " << endl;
        cin >> krawedzie[0].x;
        cout << "x1: " << endl;
        cin >> krawedzie[0].x1;
        cout << "waga: " << endl;
        cin >> krawedzie[0].waga;
    }

    
    
    sort(krawedzie, krawedzie + 10, comp);
    cout << krawedzie[0].waga << ", " << krawedzie[0].x;
    //42sort(krawedzie, krawedzie + nKrawedzi);

}

