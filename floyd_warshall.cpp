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

void warshall(int G[][N]) {
    int M[N+1][N][N];
    memset(M, 0, sizeof M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[0][i][j] = G[i][j] | (i == j);
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[k][i][j] = M[k-1][i][j] | (M[k-1][i][k] & M[k-1][k][j]);
            }
        }

        if (k == N) {
            cout << "Result: " << endl;
            print (M[k]);
        }
    }
}

int main() {
    cout << "Initial:" << endl;
    print(G1);

    warshall(G1);
    return 0;
}

