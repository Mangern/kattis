#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mat = vector<vector<ll>>;

mat matmul(const mat& a, const mat& b, ll mod) {
    int n = a.size();
    int m = b[0].size();
    int l = a[0].size();
    assert(a[0].size() == b.size());

    mat c(n, vector<ll>(m,0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < l; ++k) {
                c[i][j] += a[i][k] * b[k][j] % mod;
                c[i][j] %= mod;
                if (c[i][j]<0)c[i][j] += mod;
            }
        }
    }
    return c;
}

mat id(int n) {
    mat m(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)m[i][i] = 1;
    return m;
}

mat matpow(const mat& a, ll b, ll mod) {
    if (b == 0) {
        return id(a.size());
    }
    mat r = matpow(a, b>>1, mod);
    r = matmul(r, r, mod);
    if (b & 1) r = matmul(r, a, mod);
    return r;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    mat A(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    mat res = matpow(A, k, m);

    ll s, e;
    cin >> s;
    vector<ll> st(s);
    for (auto & x : st) cin >> x;
    cin >> e;
    vector<ll> en(e);
    for (auto & x : en) cin >> x;

    ll ans = 0;
    for (auto i : st) {
        for (auto j : en) {
            ans += res[i][j];
            ans %= m;
        }
    }
    cout << ans << endl;
}
