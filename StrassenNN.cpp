#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix createMatrix(int n) {
    return vector<vector<int>>(n, vector<int>(n, 0));
}

Matrix add(Matrix A, Matrix B, int n) {
    Matrix res = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] + B[i][j];
    return res;
}

Matrix sub(Matrix A, Matrix B, int n) {
    Matrix res = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] - B[i][j];
    return res;
}

Matrix strassen(Matrix A, Matrix B, int n) {
    // Base Case
    if (n == 1) {
        Matrix res = createMatrix(1);
        res[0][0] = A[0][0] * B[0][0];
        return res;
    }

    int k = n / 2;

    Matrix a11 = createMatrix(k), a12 = createMatrix(k), a21 = createMatrix(k), a22 = createMatrix(k);
    Matrix b11 = createMatrix(k), b12 = createMatrix(k), b21 = createMatrix(k), b22 = createMatrix(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];         a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j];     a22[i][j] = A[i + k][j + k];
            b11[i][j] = B[i][j];         b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j];     b22[i][j] = B[i + k][j + k];
        }
    }

    Matrix s1 = sub(b12, b22, k);
    Matrix s2 = add(a11, a12, k);
    Matrix s3 = add(a21, a22, k);
    Matrix s4 = sub(b21, b11, k);
    Matrix s5 = add(a11, a22, k);
    Matrix s6 = add(b11, b22, k);
    Matrix s7 = sub(a12, a22, k);
    Matrix s8 = add(b21, b22, k);
    Matrix s9 = sub(a11, a21, k);
    Matrix s10 = add(b11, b12, k);

    Matrix p1 = strassen(a11, s1, k);
    Matrix p2 = strassen(s2, b22, k);
    Matrix p3 = strassen(s3, b11, k);
    Matrix p4 = strassen(a22, s4, k);
    Matrix p5 = strassen(s5, s6, k);
    Matrix p6 = strassen(s7, s8, k);
    Matrix p7 = strassen(s9, s10, k);

    Matrix C = createMatrix(n);
    Matrix c11 = add(sub(add(p5, p4, k), p2, k), p6, k);
    Matrix c12 = add(p1, p2, k);
    Matrix c21 = add(p3, p4, k);
    Matrix c22 = sub(sub(add(p5, p1, k), p3, k), p7, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];
            C[i + k][j + k] = c22[i][j];
        }
    }
    return C;
}

int main() {
    int n = 4;
    Matrix A = {{1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4}};
    Matrix B = {{5,5,5,5}, {6,6,6,6}, {7,7,7,7}, {8,8,8,8}};

    Matrix C = strassen(A, B, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}