#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 3e5+5;

const int mxT = 1<<19;

ll n, k, m;

vector<ll> idxs[mxN];
ll freq[mxN];

bool check(double x) {
    for (int j = 0; j < m; ++j) {
        const auto & idx = idxs[j];
        ll num = idx.size();
        vector<double> contrib(num, 0.0);
        contrib[num-1] = 1.0 - x;
        for (int i = num - 2; i >= 0; --i) {
            contrib[i] = 1.0 - x + max(0.0, contrib[i+1] - x * (idx[i+1] - idx[i] - 1));
        }

        int ptr = 0;
        for (int i = 0; i < num; ++i) {
            while (ptr < num && idx[ptr] - idx[i] < k)++ptr;
            if (ptr == num) break;

            double tot = contrib[ptr] - x * (idx[ptr] - idx[i]) + ptr - i;
            if (tot >= 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> k;

    vector<ll> a(n);
    for (auto & x : a) cin >> x;
    vector<ll> b(begin(a), end(a));
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)), end(b));

    m = b.size();

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b);
    }

    double lo = 0.0;

    for (int i = 0; i < k; ++i) {
        lo = max(lo, (double)++freq[a[i]] / (double)k);
    }
    for (int i = k; i < n; ++i) {
        --freq[a[i-k]];
        lo = max(lo, (double)++freq[a[i]] / (double)k);
    }

    for (int i = 0; i < n; ++i) {
        idxs[a[i]].push_back(i);
    }

    double hi = 1.0;
    const double EPS = 1e-8;
    while (hi - lo > EPS) {
        double x = (lo + hi) / 2.0;
        if (check(x)) {
            lo = x;
        } else {
            hi = x;
        }
    }
    cout << setprecision(8) << fixed << lo << endl;
}
