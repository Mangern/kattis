#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int r = n; // start of rgt segment
    vector<int> lcnt(t, 0);
    vector<int> cnt(t, 0);

    for (; r > 0; --r) {
        if (cnt[a[r-1]] == 1) break;
        ++cnt[a[r-1]];
    }

    int ans = r;
    int al = 0;
    int ar = r - 1;

    for (int l = 0; l < n; ++l) {
        // Cannot add
        if (lcnt[a[l]] == 1) break;
        ++lcnt[a[l]];
        ++cnt[a[l]];

        while (cnt[a[l]] > 1) {
            --cnt[a[r]];
            ++r;
        }

        if (r - l - 1 < ans) {
            ans = r - l - 1;
            al = l + 1;
            ar = r - 1;
        }
    }
    cout << al << " " << ar << endl;
}
