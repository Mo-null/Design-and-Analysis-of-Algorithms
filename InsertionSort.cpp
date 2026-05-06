#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long comparisons = 0;

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0)
        {
            comparisons++;

            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    comparisons = 0;

    insertionSort(arr, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons << endl;


    // Analysis Mode

    srand(time(0));

cout << "\nSize,Average_Comparisons" << endl;

for (int i = 0; i < 100; i++) {
    int size = 30 + (i * 970 / 99); 
    
    long long totalComparisons = 0;
    for (int t = 0; t < 10; t++) {
        int* test = new int[size];
        for (int k = 0; k < size; k++) test[k] = rand() % 10000;

        comparisons = 0;
        insertionSort(test, size); 
        
        totalComparisons += comparisons;
        delete[] test;
    }
    cout << size << ", " << totalComparisons / 10 << endl;
}

    return 0;
}