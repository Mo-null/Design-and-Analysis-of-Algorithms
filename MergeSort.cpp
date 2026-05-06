#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long comparisons = 0;

// Merge Function
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        comparisons++;

        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Merge Sort Function
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    comparisons = 0;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons << endl;


    // Analysis Mode

    srand(time(0));

    cout << "\nSize, Average_Comparisons" << endl;

    for (int i = 0; i < 100; i++)
    {
        int size = 30 + (i * 970 / 99);

        long long totalComparisons = 0;

        for (int t = 0; t < 10; t++)
        {
            int* test = new int[size];

            for (int k = 0; k < size; k++)
            {
                test[k] = rand() % 10000;
            }

            comparisons = 0;

            mergeSort(test, 0, size - 1);

            totalComparisons += comparisons;

            delete[] test;
        }

        cout << size << ", " << totalComparisons / 10 << endl;
    }

    return 0;
}