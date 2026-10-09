#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

using Mat = vector<ll>;

int n, m;

void mul(const Mat& A, const Mat& B, Mat& C) {
    C.assign(n * n, 0);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                C[i * n + j] += (A[i * n + k] * B[k * n + j]) % MOD;
                C[i * n + j] %= MOD;
            }
        }
    }
}

Mat mpow(const Mat& A, ll b) {
    if (b == 1) return A;
    Mat res;
    Mat sub = mpow(A, b >> 1);
    mul(sub, sub, res);
    if (b & 1) {
        swap(res, sub);
        mul(sub, A, res);
    }
    return res;
}

int main() {
    cin >> n >> m;

    Mat A(n*n,0);

    // for (int i = 0; i < n; ++i)A[i*n+i] = 1;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        A[u * n + v] += 1;
        A[v * n + u] += 1;
    }

    ll T;
    cin >> T;

    auto res = mpow(A, T);
    cout << res[0] << endl;
}
