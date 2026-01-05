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
    ll n = 8;
    mat A(n, vector<ll>(n));
    ll k;
    cin >> k;

    for (int from = 0; from < 8; ++from) {
        for (int to = 0; to < 8; ++to) {
            if (to == from) {
                A[from][to] = 2; // ...g, ...y
                continue;
            }
            int x = from^to;
            if (__builtin_popcount(x) > 1) {
                A[from][to] = 0; // more than one change
                continue;
            }

            if (x & 1) {
                A[from][to] = 2; // ...s, ...w
            } else {
                A[from][to] = 1; // ...r, ...b
            }
        }
    }

    const ll mod = 1e9+7;
    mat ret = matpow(A, k, mod);
    // starting state: 0b000
    // ending state: 0b010

    cout << ret[0][0b010] << endl;
}
