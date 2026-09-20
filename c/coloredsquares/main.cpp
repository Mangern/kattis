#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

int n, c, k;

vector<int> idx[mxN];

int main() {
    cin >> n >> c >> k;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        idx[x].push_back(i);
    }

    int ans = 0;
    for (int col = 1; col <= c; ++col) {
        int sz = idx[col].size();

        for (int i = 0; i < sz; ++i) {
            int lo = i;
            int hi = sz - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;

                int rem = max(0, idx[col][mid] - idx[col][i] + 1 - (mid - i + 1));

                if (rem > k) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                }
            }
            ans = max(ans, lo - i + 1);
        }
    }
    cout << ans << endl;
}
