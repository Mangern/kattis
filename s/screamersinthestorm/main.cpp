#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

using mat = array<ll, 66*66>;

ll K, N;

mat mul(const mat& a, const mat& b) {
    mat c = {0};

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < K; ++k) {
                c[i*K + j] += a[i * K + k] * b[k * K + j] % MOD;
                c[i*K + j] %= MOD;
            }
        }
    }
    return c;
}

mat I;

mat pow(const mat& a, ll n) {
    if (n == 0) {
        return I;
    }

    mat ret = pow(a, n / 2);
    ret = mul(ret,ret);
    if (n & 1) ret = mul(ret, a);
    return ret;
}

int main() {

    cin >> K >> N;

    for (int i = 0; i < K; ++i) {
        I[i*K+i] = 1;
    }
    mat a = {0};

    for (ll i = 1; i <= K; ++i) {
        for (ll j = 1; j <= K; ++j) {
            if (gcd(i, j) == 1) {
                a[(i-1)*K+j-1] = 1;
            }
        }
    }


    a = pow(a, N);

    ll ans = 0;
    for (ll i = 0; i < K; ++i) {
        ans = (ans + a[i]) % MOD;
    }
    cout << ans << endl;
}
