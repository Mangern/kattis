#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt-->0) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = 0;
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                ll x;
                cin >> x;
                a[i] += x;
            }
        }
        sort(begin(a), end(a));

        ll tot = 0;
        ll cum = 0;
        for (auto x : a) {
            tot += x;
            cum += tot;
        }
        cout << setprecision(10) << fixed << (double)cum / (double)n << endl;
    }
}
