#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mat_t = unsigned int;

using mat = mat_t*;

mat a, b, c;

void matmul(mat a, mat b, mat_t n, mat_t mod) {
    memset(c, 0, n * n * sizeof(mat_t));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (a[i*n+k] == 0) continue;
            for (int j = 0; j < n; ++j) {
                c[i*n+j] += (ll)a[i*n+k] * (ll)b[k*n+j] % mod;
                if (c[i*n+j]>=mod)c[i*n+j] -= mod;
            }
        }
    }
}

void id(int n) {
    memset(c, 0, n * n * sizeof(mat_t));
    for (int i = 0; i < n; ++i)c[i*n+i] = 1;
}

// a^p, result in c
void matpow(ll p, ll n, mat_t mod) {
    if (p == 0) {
        id(n);
        return;
    }
    matpow(p>>1, n, mod);
    swap(c, b);
    matmul(b, b, n, mod);
    if (p & 1) {
        swap(c, b);
        matmul(a, b, n, mod);
    }
}

int main() {
    ll n, k;
    cin >> k >> n;

    ll N = 1LL<<k;

    a = (mat)calloc(1, N * N * sizeof(mat_t));
    b = (mat)calloc(1, N * N * sizeof(mat_t));
    c = (mat)calloc(1, N * N * sizeof(mat_t));

    for (ll m1 = 0; m1 < N; ++m1) {
        for (ll m2 = 0; m2 < N; ++m2) {
            ll v1 = m1&m2;
            ll v2 = (m2&(m2<<1));
            ll v3 = (m1&(m1<<1));

            if (v1 || v2 || v3) {
                a[m1*N+m2] = 0;
                continue;
            } 
            a[m1*N+m2] = 1;
        }
    }

    int rp = 0;

    auto swp = [&] (int r1, int r2) {
        if (r1 == r2) return;

        for (int i = 0; i < N; ++i) {
            swap(a[r1 * N + i], a[r2 * N + i]);
            swap(a[i * N + r1], a[i * N + r2]);
        }
    };

    for (int i = 0; i < N; ++i) {
        bool alz = 1;
        for (int j = 0; j < N; ++j) {
            if (a[i * N + j]) {
                alz = 0;
                break;
            }
        }
        if (!alz) {
            swp(rp, i);
            ++rp;
            continue;
        }
    }

    swap(a, b);

    for (int i = 0; i < rp; ++i) {
        for (int j = 0; j < rp; ++j) {
            a[i * rp + j] = b[i * N + j];
        }
    }

    N = rp;

    // for (int i = 0; i < N; ++i) {
    //    for (int j = 0; j < N; ++j) {
    //        cout << a[i*N+j] << " ";
    //    }
    //    cout << endl;
    // }


    const ll mod = 1e9+7;

    matpow(n, N, mod);

    // for (int i = 0; i < N; ++i) {
    //    for (int j = 0; j < N; ++j) {
    //        cout << c[i*N+j] << " ";
    //    }
    //    cout << endl;
    // }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + c[i*N]) % mod;
    }
    cout << ans << endl;
}
