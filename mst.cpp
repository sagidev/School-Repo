#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

#define krawedz pair<int, int>
class Krawedz {
public:
    int x, x1, waga;
};

class Graf {
    //deklaracja grafu i mst
    vector<pair<int, krawedz> > G;
    vector<pair<int, krawedz> > T;
    int rogi;
    int* rodzic;
public:
    Graf(int rogi) {
        rodzic = new int[rogi];
        for (int i = 0; i < rogi; i++)
        {
            rodzic[i] = i;
        }
        G.clear(); //graf
        T.clear(); //mst
    };
    void DodajKrawedz(int x1, int x2, int waga)
    {
        G.push_back(make_pair(waga, krawedz(x1, x2)));
    }
    int Znajdz(int k)
    {
        if (k == rodzic[k])
            return k;
        else
            return Znajdz(rodzic[k]);
    }
    void Ustaw(int x, int v)
    {
        rodzic[x] = rodzic[v];
    }
    void Wyswietl()
    {
        cout << "Krawedz " << " Waga" << endl;
        for (int i = 0; i < T.size(); i++) {
            cout << Zamiana(T[i].second.first) << " " << Zamiana(T[i].second.second) << "  "
                << T[i].first;
            cout << endl;
        }
    }
    string Zamiana(int liczba)
    {
        string tekst = to_string(liczba);
        if (tekst == "1")
            return "AA";
        if (tekst == "2")
            return "BB";
        if (tekst == "3")
            return "CC";
        if (tekst == "4")
            return "DD";
    }
    void Kruskal()
    {
        int i, x, v;
        //sortowanie krawedzi wedlug wag
        sort(G.begin(), G.end());
        for (int i = 0; i < G.size(); i++)
        {
            //wybieramy krawedz z najnizsza waga
            x = Znajdz(G[i].second.first);
            v = Znajdz(G[i].second.second);
            if (x != v)
            {
                //dodajemy do rozwiazania
                T.push_back(G[i]);
                Ustaw(x, v);
            }
        }
    }
    int* liczby;
    string* stringArray;
    void Wczytaj()
    {
        //wczytywanie nazw poszczegolnych rogow
        ifstream file("dane.txt");
        string data = "";
        int chars;
        while (getline(file, data, ' '))
        {
            stringArray = new string[stoi(data)];
            liczby = new int[stoi(data)];
            chars = stoi(data);
            for (int i = 1; i <= chars; i++)
            {
                liczby[i] = stoi(data);
                stringArray[i] = data;
            }
        }
    }
};
int main()
{
    Graf graf(5);
    graf.DodajKrawedz(1, 2, 3);
    graf.DodajKrawedz(2, 3, 5);
    graf.DodajKrawedz(4, 1, 6);
    graf.DodajKrawedz(3, 4, 2);
    graf.DodajKrawedz(2, 4, 3);
    graf.Kruskal();
    graf.Wyswietl();
}