#include <bits/stdc++.h>
using namespace std;


//012
//345
//678
const int N = (1<<9);

int neis[9] = {
    0b000001011,
    0b000010111,
    0b000100110,
    0b001011001,
    0b010111010,
    0b100110100,
    0b011001000,
    0b111010000,
    0b110100000
};

void printgrid(int grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int idx = i * 3 + j;
            cout << ((grid >> idx)&1);
        }
        cout << endl;
    }
}

int dist[N];

int main() {
    for (int i = 0; i < N; ++i) {
        dist[i] = numeric_limits<int>::max();
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int vi = 0; vi < 9; ++vi) {
            int v = (u ^ neis[vi]);
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int t;
    cin >> t;

    string s[3];
    while (t-->0) {
        cin >> s[0] >> s[1] >> s[2];

        int goal = 0;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            int idx = i * 3 + j;
            if (s[i][j] == '*') {
                goal |= (1<<idx);
            }
        }
        cout << dist[goal] << endl;
    }
}
