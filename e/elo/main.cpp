#include <bits/stdc++.h>
using namespace std;

const int mxN = 6000;

bool can[mxN];

int main() {
    int n,x ;
    cin >> n >> x;

    vector<tuple<int,int,int>> a(n);
    for (auto &[l, r, inc] : a) cin >> l >> r >> inc;

    can[x] = 1;

    int ans = 0;
    for (int i = x; i < mxN; ++i) {
        if (can[i]) {
            ans = max(ans, i);

            for (auto [l, r, inc] : a) {
                if (l <= i && i <= r) {
                    can[i + inc] = 1;
                }
            }
        }
    }

    cout << ans << endl;
}
