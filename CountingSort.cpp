#include <iostream>

using namespace std;

void countingSort(int A[], int n, int k) {
    int* B = new int[n];
    int* C = new int[k + 1];

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j]; // -1 for 0-origin indexing adjustment
        C[A[j]] = C[A[j]] - 1;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    delete[] B;
    delete[] C;
}

int main() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = 8;
    
    int k = 0;
    for(int i = 0; i < n; i++) if(arr[i] > k) k = arr[i];

    countingSort(arr, n, k);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}