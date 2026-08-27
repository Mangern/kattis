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
    ll n = 64;
    mat A(n, vector<ll>(n));
    ll k;
    cin >> k;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) continue;
                    A[i * 8 + j][ni * 8 + nj] = 1;
                }
            }
        }
    }

    mat res = matpow(A, k, 1e9+7);
    cout << res[0][63] << endl;
}
