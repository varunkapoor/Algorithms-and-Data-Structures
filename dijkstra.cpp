#include <iostream>
using namespace std;

const int N = 5;
const int M = 1 << 30;

int G1[N][N] = {{0, 5, 0, 4, 0},
                {0, 0, 5, 0, 1},
                {0, 2, 0, 0, 3},
                {0, 0, 4, 0, 6},
                {4, 0, 0, 0, 0},
              };

int G2[N][N] = {{0, 5, 0, 4, 0},
                {0, 0, 5, 0, -1},
                {0, -2, 0, 0, 3},
                {0, 0, -4, 0, 6},
                {4, 0, 0, 0, 0},
              };

void dijkstra(int v, int G[][N]) {
    int dist[N];
    int s[N];
    for (int i = 0; i < N; i++) {
        dist[i] = M;
        s[i] = 0;
    }

    cout << "Starting from v" << v << endl;

    dist[v] = 0;
    for (int i = 0; i < N; i++) {
        int m = M, mi = -1;
        for (int j = 0; j < N; j++) 
            if (m > dist[j] && !s[j])
                m = dist[j], mi = j;

        if (mi == -1) 
            break;

        cout << "\tstep " << i << ", picking v" << mi << endl;

        for (int j = 0; j < N; j++) {
            if (!s[j] && G[mi][j])
                if (dist[j] > dist[mi] + G[mi][j])
                    dist[j] = dist[mi] + G[mi][j];
        }
        s[mi] = 1;

        cout << "\tdist = ";
        for (int k = 0; k < N; k++) 
            if (dist[k] == M) 
                cout << "-inf ";
            else 
                cout << dist[k] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < N; i++) {
        dijkstra(i, G2);
    }
    return 0;
}

