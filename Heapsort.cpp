// DT_Heap.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void Heapify(int arr[], int i, int max)
{
    int largest = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<max && arr[left]>arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right<max && arr[right]>arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, largest, max);

    }
}

void HeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}

void readInput(string path)
{
    ifstream input_file;
    input_file.open(path);
    string line;
    istringstream ss(line);
    string del;
    while (getline(input_file, del, ' '))
    {

    }
}

string howManyTests(string path)
{
    ifstream input_file;
    input_file.open(path);
    string line;
    while (getline(input_file, line)) {
        return line;
        break;
    }
}

int main()
{
    string path = "input.txt";
    int numberOfTries;
    numberOfTries = stoi(howManyTests(path));
    for (int i = 0; i < numberOfTries; i++)
    {
        int arr[] = { 5,5,1,8,3,7 };//predefiniowana tabela
        int n = sizeof(arr) / sizeof(arr[0]);
        HeapSort(arr, n);
        printArray(arr, n);
        cout << endl;
    }

}

