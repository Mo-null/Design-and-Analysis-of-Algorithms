#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

long long comparisons = 0;

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;

    for(int j = p; j < r; j++)
    {
        comparisons++;

        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

void quickSort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);

        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main()
{

    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = 8;

    comparisons = 0;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons << endl;


    // Analysis Mode

    srand(time(0));

    cout << "\nSize, Average_Comparisons" << endl;

for(int i = 0; i < 100; i++)
{
    int size = 30 + (i * 970 / 99);

    long long totalComparisons = 0;

    for(int t = 0; t < 10; t++)
    {
        int* test = new int[size];

        for(int i = 0; i < size; i++)
        {
            test[i] = rand() % 10000;
        }

        comparisons = 0;

        quickSort(test, 0, size - 1);

        totalComparisons += comparisons;

        delete[] test;
    }

    cout << size << ", " << totalComparisons / 10 << endl;
}
    return 0;
}