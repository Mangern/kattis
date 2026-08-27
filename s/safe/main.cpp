#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

//012
//345
//678
const int N = (1<<18);

void printgrid(int grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int idx = 2*(i * 3 + j);
            cout << ((grid >> idx)&0x3) << " ";
        }
        cout << endl;
    }
}

int click(int grid, int i, int j) {
    // row
    for (int k = 0; k < 3; ++k) {
        int idx = 2 * (i * 3 + k);
        int v = ((grid >> idx)&3);
        grid ^= (v<<idx);
        v = (v + 1) % 4;
        grid |= (v<<idx);
    }

    // col
    for (int k = 0; k < 3; ++k) if (k != i) {
        int idx = 2 * (k * 3 + j);
        int v = ((grid >> idx)&3);
        grid ^= (v<<idx);
        v = (v + 1) % 4;
        grid |= (v<<idx);
    }

    assert(grid < N);
    return grid;
}


int dist[N];

int main() {

    int grid = 0;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
        int idx = 2 * (i * 3 + j);
        int v;
        cin >> v;

        grid |= (v<<idx);
    }

    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
    }

    dist[grid] = 0;

    queue<int> q;
    q.push(grid);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            int v = click(u, i, j);

            if (dist[v] > dist[u] + 1) { 
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << (dist[0] == INF ? -1 : dist[0]) << endl;
}
