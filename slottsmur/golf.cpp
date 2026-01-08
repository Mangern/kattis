#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int mxN = 2e5+5;
const ll K = 450;
ll a[mxN];
ll S[mxN];
ll ch[2*K][K+50];
ll sl[2*K][K+50];
ll sr[2*K][K+50];
ll pl[2*K][K+50];
ll pr[2*K][K+50];
ll pre[2*K][K+50];
ll m[mxN];

void cc(ll c) {
    ll mx = 0;
    ll sz = S[c];
    pl[c][0] = 0;
    pr[c][0] = 0;
    pre[c][0] = 0;
    for (int i = 0; i < sz; ++i) {
        if (ch[c][i] > mx) {
            m[c] = i;
            mx = ch[c][i];
        }
        sl[c][i] = mx;
    }
    mx = 0;
    for (int i = sz - 1; i >= 0; --i) {
        mx = max(mx, ch[c][i]);
        sr[c][i] = mx;
    }
    for (int i = 0; i < sz; ++i) {
        pre[c][i+1] = ch[c][i] + pre[c][i];
        pl[c][i+1] = sl[c][i] + pl[c][i];
        pr[c][i+1] = sr[c][i] + pr[c][i];
    }
}

int main() {
    ll n, q;
    scanf("%lld%lld", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        ch[i/K][S[i/K]++] = a[i];
    }
    for (int c = 0; c < (n+K-1)/K; ++c) {
        cc(c);
    }
    while (q-->0) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r;
            cin >> l >> r, --l, --r;
            ll A = 0;
            ll cl = l / K, cr = r / K, mx = a[l], mxc = cl, mxi = l;
            for (int i = l; i <= r && i / K == l / K; ++i) {
                if(a[i] > mx) {
                    mx = a[i];
                    mxi = i;
                }
            }
            for (int i = r; i >= l && i / K == r / K; --i) {
                if(a[i] > mx) {
                    mx = a[i];
                    mxc = cr;
                    mxi = i;
                }
            }
            for (ll c = cl + 1; c < cr; ++c) {
                if (ch[c][m[c]] > mx) {
                    mx = ch[c][m[c]];
                    mxi = c * K + m[c];
                    mxc = c;
                }
            }
            ll ml = a[l];
            ll mr = a[r];
            if (cl < mxc) {
                for (ll i = l; i < (cl+1) * K; ++i) {
                    ml = max(ml, a[i]);
                    A += ml - a[i];
                }
            }
            if (mxc < cr) {
                for (ll i = r; i >= cr * K; --i) {
                    mr = max(mr, a[i]);
                    A += mr - a[i];
                }
            }
            for (ll c = cl + 1; c < mxc; ++c) {
                ll sz = S[c];
                ll cut = upper_bound(sl[c], sl[c] + sz, ml) - sl[c];
                A += ml * cut - pre[c][cut];
                A += pl[c][sz] - pl[c][cut] - (pre[c][sz] - pre[c][cut]);
                ml = max(ml, sl[c][sz-1]);
            }
            for (ll c = cr - 1; c > mxc; --c) {
                ll sz = S[c];
                ll cut = upper_bound(sr[c], sr[c] + sz, mr, greater<ll>()) - sr[c];
                A += (sz - cut) * mr - (pre[c][sz] - pre[c][cut]);
                A += pr[c][cut] - pre[c][cut];
                mr = max(mr, sr[c][0]);
            }
            for (ll i = max(l, mxc * K); i < mxi; ++i) {
                ml = max(ml, a[i]);
                A += ml - a[i];
            }
            for (ll i = min(r, (mxc + 1) * K - 1); i > mxi; --i) {
                mr = max(mr, a[i]);
                A += mr - a[i];
            }
            printf("%lld\n", A);
        } else {
            ll i, w;
            cin >> i >> w, --i;
            ll c = i / K;
            a[i] += w;
            ch[c][i - c * K] = a[i];
            cc(c);
        }
    }
}
