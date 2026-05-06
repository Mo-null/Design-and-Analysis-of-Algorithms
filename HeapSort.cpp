#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

long long comparisons = 0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n)
    {
        comparisons++;

        if(arr[left] > arr[largest])
        {
            largest = left;
        }
    }

    if(right < n)
    {
        comparisons++;

        if(arr[right] > arr[largest])
        {
            largest = right;
        }
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    comparisons = 0;

    heapSort(arr, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons << endl;


    // Analysis Mode

    srand(time(0));

    cout << "\nSize,Average_Comparisons" << endl;

    for(int i = 0; i < 100; i++)
    {
        int size = 30 + (i * 970 / 99);

        long long totalComparisons = 0;

        for(int t = 0; t < 10; t++)
        {
            int* test = new int[size];

            for(int k = 0; k < size; k++)
            {
                test[k] = rand() % 10000;
            }

            comparisons = 0;

            heapSort(test, size);

            totalComparisons += comparisons;

            delete[] test;
        }

        cout << size << ", " << totalComparisons / 10 << endl;
    }

    return 0;
}