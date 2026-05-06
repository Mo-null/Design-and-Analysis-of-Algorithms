#include <iostream>
using namespace std;

void strassen2x2(int A[2][2], int B[2][2], int C[2][2]) {

    int a11 = A[0][0], a12 = A[0][1], a21 = A[1][0], a22 = A[1][1];
    int b11 = B[0][0], b12 = B[0][1], b21 = B[1][0], b22 = B[1][1];

    int s1 = b12 - b22;
    int s2 = a11 + a12;
    int s3 = a21 + a22;
    int s4 = b21 - b11;
    int s5 = a11 + a22;
    int s6 = b11 + b22;
    int s7 = a12 - a22;
    int s8 = b21 + b22;
    int s9 = a11 - a21;
    int s10 = b11 + b12;

    int p1 = a11 * s1;
    int p2 = s2 * b22;
    int p3 = s3 * b11;
    int p4 = a22 * s4;
    int p5 = s5 * s6;
    int p6 = s7 * s8;
    int p7 = s9 * s10;

    C[0][0] = p5 + p4 - p2 + p6;
    C[0][1] = p1 + p2;
    C[1][0] = p3 + p4;
    C[1][1] = p5 + p1 - p3 - p7;
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassen2x2(A, B, C);

    cout << "Result Matrix (C = A * B):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}