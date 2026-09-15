#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Mat = vector<vector<ll>>;

constexpr ll MOD = 1e9+7;

void mmul(const Mat& A, const Mat& B, Mat& C) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += (A[i][k] * B[k][j]) % MOD;
                if (C[i][j] >= MOD) C[i][j] -= MOD;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;

    ll n;
    cin >> n;

    ll m = s.length();

    vector<vector<ll>> M(m+1, vector<ll>(m+1, 0));

    vector<vector<ll>> res = M;
    vector<vector<ll>> tmp = M;

    for (int i = 0; i < m + 1; ++i) {
        res[i][i] = 1;
        if (i < m) {
            M[i][i] = 25;
            M[i][i+1] = 1;
        } else {
            M[i][i] = 26;
        }
    }

    while (n) {
        if (n & 1) {
            mmul(res, M, tmp);
            swap(tmp, res);
        }
        mmul(M, M, tmp);
        swap(tmp, M);
        n >>= 1;
    }

    ll ans = 0;

    for (int i = 0; i < m; ++i) {
        ans += res[0][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
