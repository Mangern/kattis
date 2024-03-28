#include <iostream>
#include <array>
using namespace std;

using ll = long long;

using Mat = array<array<ll,2>, 2>;

const ll MOD = 1e9+7;

const Mat I = {1LL, 0LL, 0LL, 1LL};

Mat matmul(Mat A, Mat B) {
    Mat C;

    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    return C;
}

Mat matpow(Mat m, ll p) {
    if (p == 0)return I;
    if (p == 1)return m;

    Mat r = matpow(m, p >> 1);

    r = matmul(r, r);

    if (p & 1)r = matmul(r, m);
    return r;
}

int main() {
    Mat A = {1LL, 1LL, 1LL, 0LL};
    ll n;
    cin >> n;

    Mat coeff = matpow(A, n - 1);
    Mat rest = matpow(A, n);
    rest[0][0] -= 1;
    if (rest[0][0] < 0)rest[0][0] += MOD;

    rest[1][1] -= 1;
    if (rest[1][1] < 0)rest[1][1] += MOD;


    ll ans = (coeff[0][0] + rest[0][0]) % MOD;
    cout << ans << endl;
    return 0;
}
