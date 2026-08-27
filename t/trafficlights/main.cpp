#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;

bool gr[10][mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int r, g;
        cin >> r >> g;

        for (int t = 0; t < mxN; ++t) {
            if (t % ( r + g) >= r) {
                gr[i][t] = 1;
            }
        }
    }

    for (int t = 0; t < mxN; ++t) {
        bool al=1;
        for (int i = 0; i < n; ++i) {
            if (!gr[i][t]) {
                al=0;
                break;
            }
        }
        if (al) {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
