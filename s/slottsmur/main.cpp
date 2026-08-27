#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//#define DEBUG


const int mxN = 2e5+5;
const ll K = 450;
//const ll K = 3;

ll a[mxN];
// values in a chunk
vector<ll> chunk[mxN];
// smoothed from the left
vector<ll> smoothl[mxN];
// smoothed from right
vector<ll> smoothr[mxN];
// prefix sums of smoothl
vector<ll> psl[mxN];
// prefix sums of smoothr
vector<ll> psr[mxN];
// prefix sums of chunk
vector<ll> pre[mxN];
// index of max in chunk
ll fsmax[mxN];

void calc_chunk(ll c) {
    ll mx = 0;
    ll sz = chunk[c].size();
    psl[c][0] = 0;
    psr[c][0] = 0;
    pre[c][0] = 0;
    for (int i = 0; i < sz; ++i) {
        if (chunk[c][i] > mx) {
            fsmax[c] = i;
            mx = chunk[c][i];
        }

        smoothl[c][i] = mx;
    }
    mx = 0;
    for (int i = sz - 1; i >= 0; --i) {
        mx = max(mx, chunk[c][i]);
        smoothr[c][i] = mx;
    }
    for (int i = 0; i < sz; ++i) {
        pre[c][i+1] = chunk[c][i] + pre[c][i];
        psl[c][i+1] = smoothl[c][i] + psl[c][i];
        psr[c][i+1] = smoothr[c][i] + psr[c][i];
    }
}

int main() {
    ll n, q;
    scanf("%lld%lld", &n, &q);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);

        chunk[i/K].push_back(a[i]);
    }

    for (int c = 0; c < (n+K-1)/K; ++c) {
        ll sz = chunk[c].size();
        smoothl[c].resize(sz);
        smoothr[c].resize(sz);
        psl[c].resize(sz+1);
        psr[c].resize(sz+1);
        pre[c].resize(sz+1);

        calc_chunk(c);
    }

    while (q-->0) {
        ll t;
        cin >> t;

        if (t == 1) {
            ll l, r;
            cin >> l >> r, --l, --r;

            ll ans = 0;
            ll cl = l / K;
            ll cr = r / K;

#ifdef DEBUG
            cout << "Left chunk: " << cl << endl;
            cout << "Right chunk: " << cr << endl;
#endif // DEBUG

            ll mx = a[l];
            ll mxc = cl;
            ll mxi = l;

            // find index of max element
            {
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
                    if (chunk[c][fsmax[c]] > mx) {
                        mx = chunk[c][fsmax[c]];
                        mxi = c * K + fsmax[c];
                        mxc = c;
                    }
                }
            }

#ifdef DEBUG
            cout << "Max el: " << mx << "@" << mxi << endl;
#endif // DEBUG

            // running left bound
            ll ml = a[l];
            // running right bound
            ll mr = a[r];

            if (cl < mxc) {
                // left chunk manual
                // redundant if mxi is in left chunk
                for (ll i = l; i < (cl+1) * K; ++i) {
                    ml = max(ml, a[i]);
                    ans += ml - a[i];
                }
            }

            if (mxc < cr) {
                // right chunk manual
                // redundant if mxi in right chunk
                for (ll i = r; i >= cr * K; --i) {
                    mr = max(mr, a[i]);
                    ans += mr - a[i];
                }
            }

            // up until but not including chunk containing max
            for (ll c = cl + 1; c < mxc; ++c) {
                ll sz = chunk[c].size();
                ll cut = upper_bound(begin(smoothl[c]), end(smoothl[c]), ml) - begin(smoothl[c]);
                // first cut are filled to ml
                ans += ml * cut - pre[c][cut];
                // last sz - cut are filled to smoothl
                ans += psl[c][sz] - psl[c][cut] - (pre[c][sz] - pre[c][cut]);
                ml = max(ml, smoothl[c].back());
            }

            // same but from the right
            for (ll c = cr - 1; c > mxc; --c) {
                ll sz = chunk[c].size();
                // index of first where mr > val
                ll cut = upper_bound(begin(smoothr[c]), end(smoothr[c]), mr, greater<ll>()) - begin(smoothr[c]);
                // last sz - cut are filled by mr
                ans += (sz - cut) * mr - (pre[c][sz] - pre[c][cut]);
                // first cut are filled by smoothr
                ans += psr[c][cut] - pre[c][cut];
                mr = max(mr, smoothr[c][0]);
            }

            // finally, go into mxi
            for (ll i = max(l, mxc * K); i < mxi; ++i) {
                ml = max(ml, a[i]);
                ans += ml - a[i];
            }

            for (ll i = min(r, (mxc + 1) * K - 1); i > mxi; --i) {
                mr = max(mr, a[i]);
                ans += mr - a[i];
            }

            printf("%lld\n", ans);
        } else {
            ll i, w;
            cin >> i >> w, --i;

            ll c = i / K;
            a[i] += w;
            chunk[c][i - c * K] = a[i];
            calc_chunk(c);
        }
    }
}
