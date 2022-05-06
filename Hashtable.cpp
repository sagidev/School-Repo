#include <iostream>
#include <fstream>
using namespace std;

class Hashtable
{
public:
    int key, distance;
    string chain;

    //Hashtable(int kkey, int ddistance, string cchain)
    //{
    //    key = kkey;
    //    disctance = ddistance;
    //    chain = cchain;
    //}
    string Print()
    {
        return (key + " " + chain);
        //cout << key << " " << chain << endl;
    }
};

void DoHashtable(string fileIn, string fileOut)
{
    ifstream dane(fileIn);
    ofstream save(fileOut);
    string script;
    int size, cases, tests = 0;
    dane >> cases;
    dane >> script >> size;
    Hashtable* arr = new Hashtable[size];
    cout << "Hashujemy dla " << cases << " przypadkow";
    while (tests < cases && !dane.eof())
    {
        dane >> script;
        
        if (script == "size")
        {
            dane >> size;
            arr = new Hashtable[size];
        }
        if (script == "print")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].key != NULL)
                {
                    save << i << " " << arr[i].Print();
                }
            }
        }
        if (script == "add")
        {
            dane >> arr->key >> arr->chain;
            int index = arr->key % size;
            int distance = 0;
            while (arr[index].key != NULL)
            {
                if (index == size - 1)
                {
                    index = -1;
                }
                index++;
                distance++;
            }
            arr[index].key = arr->key;
            arr[index].chain = arr->chain;
            arr[index].distance = distance;
        }
        if (script == "stop")
        {
            tests++;
        }
        if (script == "delete")
        {
            dane >> arr->key;
            int index = arr->key % size;
            while (arr[index].key != NULL)
            {
                if (index == size - 1)
                {
                    index = -1;
                }
                index++;
            }
            arr[index].key = NULL;
            arr[index].chain = "";
            arr[index].distance = NULL;
        }
    }
    dane.close();
    save.close();
    delete[] arr;
}

int main()
{
    DoHashtable("hashtablein.txt", "hashtableout.txt");
}

