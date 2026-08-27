#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int cnt[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (cnt[i] < i) {
            ans += cnt[i];
        } else if (cnt[i] > i) {
            ans += cnt[i] - i;
        }
    }
    cout << ans << endl;
}
