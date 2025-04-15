#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 100000000;

ll id(ll x, ll y) {
    return (x * (N + 1)) + y;
}

const int mxN = 100;

ll n, k;

ll x[mxN], y[mxN], b[mxN];

ll dxv[mxN];
ll dyv[mxN];

bool fcheck(ll dx, ll dy, ll b) {
    ll adx = abs(dx);
    ll ady = abs(dy);
    if (adx * adx >= b) return false;
    if (ady * ady >= b) return false;
    return adx * adx * adx + ady * ady * ady <= b;
}

// 0: none, 1: partial, 2: full
int inter(ll xl, ll xh, ll yl, ll yh, int i) {
    if ((xl > xh) || (yl > yh)) return 0;

    bool tl = fcheck(xl - x[i], yl - y[i], b[i]);
    bool tr = fcheck(xh - x[i], yl - y[i], b[i]);
    bool bl = fcheck(xl - x[i], yh - y[i], b[i]);
    bool br = fcheck(xh - x[i], yh - y[i], b[i]);

    if (tl && tr && bl && br) return 2;
    if (tl || tr || bl || br) return 1;

    if (xl == xh && yl == yh) return 0;

    ll c = cbrt(b[i]) + 1;

    if (x[i] - c > xh || x[i] + c < xl || y[i] - c > yh || y[i] + c < yl) return 0;

    return 1;
}

ll solve(ll xl, ll xh, ll yl, ll yh, const vector<int> &cand) {
    if (xh < xl || yh < yl) return 0;
    vector<int> nxt;
    nxt.reserve(cand.size());

    for (int i : cand) {
        int in = inter(xl, xh, yl, yh, i);

        if (in == 2) return 0;
        else if (in) {
            nxt.push_back(i);
        }
    }
    if (nxt.empty()) {
        return (xh - xl + 1) * (yh - yl + 1);
    }

    ll mpx = (xh + xl + 1) / 2;
    ll mpy = (yh + yl + 1) / 2;
    if (mpx == xh)--mpx;
    if (mpy == yh)--mpy;
    return solve(xl, mpx, yl, mpy, nxt)
         + solve(mpx+1,xh,yl, mpy, nxt)
         + solve(xl, mpx,mpy+1,yh, nxt)
         + solve(mpx+1,xh,mpy+1,yh,nxt);
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i] >> b[i];
    }

    vector<int> cand(k, 0);
    iota(begin(cand), end(cand), 0);
    cout << solve(0, n, 0, n, cand) << endl;
}
