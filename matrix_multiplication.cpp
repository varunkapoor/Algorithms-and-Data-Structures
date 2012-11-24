#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
const int M = 1 << 30;

int G1[N][N] = {{0, 1, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0},
              };

void print(int A[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_multiplication(int G[][N]) {
    int M[N][N][N];

    memset(M, 0, sizeof M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            M[0][i][j] = G[i][j] | (i == j);

    for (int m = 1; m < N-1; m++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[m][i][j] = M[m-1][i][j];
                for (int k = 0; k < N; k++)
                    M[m][i][j] |= M[m-1][i][k] & G[k][j];
            }
        }

        if (m == 1 || m == 2) {
            cout << "Step " << m << endl;
            print(M[m]);
        }
        if (m == N-2) {
            cout << "Result: " << endl;
            print (M[m]);
        }
    }
}

int main() {
    matrix_multiplication(G1);
    return 0;
}

