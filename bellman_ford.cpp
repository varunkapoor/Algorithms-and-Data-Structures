#include <iostream>
using namespace std;

const int N = 5;
const int M = 1 << 30;

int G1[N][N] = {{0, 5, 0, 4, 0},
                {0, 0, 5, 0, -1},
                {0, -2, 0, 0, 3},
                {0, 0, -4, 0, 6},
                {4, 0, 0, 0, 0},
              };

int G2[N][N] = {{0, 5, 0, 4, 0},
                {0, 0, 5, 0, -1},
                {0, -4, 0, 0, 3},
                {0, 0, -4, 0, 6},
                {4, 0, 0, 0, 0},
              };

void bellman_ford(int v, int G[][N]) {
    int dist[N];
    for (int i = 0; i < N; i++) {
        dist[i] = M;
    }

    cout << "Starting from v" << v << endl;

    dist[v] = 0;
    for (int i = 0; i < N-1; i++) {

        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (G[j][k] && dist[k] > dist[j] + G[j][k])
                    dist[k] = dist[j] + G[j][k];
    }

    cout << "\tdist = ";
    for (int k = 0; k < N; k++) 
        if (dist[k] == M) 
            cout << "-inf ";
        else 
            cout << dist[k] << " ";
    cout << endl;
}

int main() {
    for (int i = 0; i < N; i++) {
        bellman_ford(i, G2);
    }
    return 0;
}

