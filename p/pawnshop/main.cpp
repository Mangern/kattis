#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    ll missing = 0; // number of nonzero cnt
    unordered_map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] == 0) {
            // new nonzero
            ++missing;
        } else if (cnt[a[i]] == -1) {
            // goes to zero
            --missing;
        }
        ++cnt[a[i]];

        if (cnt[b[i]] == 0) {
            ++missing;
        } else if (cnt[b[i]] == 1) {
            --missing;
        }
        --cnt[b[i]];

        cout << b[i] << ' ';

        if (missing == 0 && i < n - 1) {
            cout << "# ";
        }
    }
    cout << endl;
}
