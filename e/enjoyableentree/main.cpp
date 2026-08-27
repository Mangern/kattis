#include <bits/stdc++.h>
using namespace std;
using mat = array<double, 4>;
using ll = long long;
mat I;

mat mul(const mat& a, const mat& b) {
    return mat{
        a[0]*b[0]+a[1]*b[2], a[0]*b[1]+a[1]*b[3],
        a[2]*b[0]+a[3]*b[2], a[2]*b[1]+b[3]*b[3]
    };
}

mat pow(const mat& m, ll n) {
    if (n == 0) {
        return I;
    }
    auto r = pow(m, n / 2);
    r = mul(r,r);
    if (n & 1) r = mul(r,m);
    return r;
}

int main() {
    I = {
        1.0, 0.0,
        0.0, 1.0
    };
    mat A = {
        0.5, 0.5,
        1.0, 0.0
    };

    ll n;
    cin >> n;
    A = pow(A, n - 1);
    double ans2 = A[2];

    double ans1 = 1.0 - ans2;

    cout << setprecision(8) << fixed << ans1*100 << " " << ans2*100 << endl;
}
