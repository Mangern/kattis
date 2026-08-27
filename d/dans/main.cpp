#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int nxt[32][mxN];
int ans[mxN];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p, --p;
        nxt[0][p] = i;
    }

    for (int j = 1; j < 32; ++j) {
        for (int i = 0; i < n; ++i) {
            nxt[j][i] = nxt[j-1][nxt[j-1][i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        int ptr = i;
        for (int j = 0; j < 32; ++j) {
            if ((k >> j) & 1) {
                ptr = nxt[j][ptr];
            }
        }
        ans[ptr] =i;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
