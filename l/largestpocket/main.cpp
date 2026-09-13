#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> phgt(n);

    ll mn = a[0];

    for (int i = 0; i < n; ++i) {
        mn = max(mn, a[i]);
        phgt[i] = mn;
    }
    mn = a.back();
    for (int i = n - 1; i >= 0; --i) {
        mn = max(mn, a[i]);
        phgt[i] = min(phgt[i], mn);
    }

    vector<int> pid(n, -1);

    int pT = 0;

    for (int i = 0; i < n; ++i) {
        if (phgt[i] > a[i]) {
            assert(i > 0);
            if (pid[i-1] != -1) {
                pid[i] = pid[i-1];
            } else {
                pid[i] = pT++;
            }
        }
    }

    vector<ll> ar(pT, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (pid[i] != -1) {
            ar[pid[i]] += phgt[i] - a[i];
            ans = max(ans, ar[pid[i]]);
        }
    }

    cout << ans << endl;
}
