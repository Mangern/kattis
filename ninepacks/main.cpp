#include <bits/stdc++.h>
using namespace std;

const int mxN = 100005;

int hot[mxN];
int bun[mxN];

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &x : h) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;

    memset(hot, -1, sizeof hot);
    memset(bun, -1, sizeof bun);
    hot[0] = 0;
    bun[0] = 0;

    for (int x : h) {
        for (int i = mxN - 1; i >= x; --i) {
            if (hot[i-x] != -1) {
                if (hot[i] == -1 || hot[i-x] + 1 < hot[i]) {
                    hot[i] = hot[i-x] + 1;
                }
            }
        }
    }
    for (int x : b) {
        for (int i = mxN - 1; i >= x; --i) {
            if (bun[i-x] != -1) {
                if (bun[i] == -1 || bun[i-x] + 1 < bun[i]) {
                    bun[i] = bun[i-x] + 1;
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < mxN; ++i) {
        if (hot[i] != -1 && bun[i] != -1) {
            ans = min(ans, hot[i] + bun[i]);
        }
    }
    if (ans == INT_MAX) {
        cout << "impossible" << endl;
    } else cout << ans << endl;
}
