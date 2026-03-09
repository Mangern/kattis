#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

ll T, N;
ll a[mxN];

ll t(ll n) {
    return 20 + 10 * ((n + 9) / 10);
}

// Can we do it 
bool can(ll m) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < m; ++i) {
        pq.push(0);
    }

    for (int i = 0; i < N; ++i) {
        ll tp = pq.top();
        pq.pop();
        if (tp + a[i] > T)return false;
        pq.push(tp + a[i]);
    }
    return true;
}

int main() {
    cin >> T >> N;

    bool ok = 1;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];

        if (t(a[i]) > T) {
            ok = 0;
        }
        a[i] = t(a[i]);
    }
    if (!ok) {
        cout << "impossible" << endl;
        return 0;
    }
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll lo = 1;
    ll hi = T; // at most one machine per order

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (can(mid)) {
            hi = mid;
        } else lo = mid + 1;
    }
    cout << lo << endl;
}
