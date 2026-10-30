#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 3005;

ll n, l;

ll a[mxN];
ll b[mxN];
int ind[mxN];
ll ass[mxN];

ll dp[mxN][mxN];
ll choice[mxN][mxN];

void rec(int cur_j, ll l, ll r, ll lo, ll hi) {
    if (l >= r) return;
    ll mid = (l+r)/2;

    ll opt_k = -1;
    ll opt = 0;
    for (ll k = max(lo, 1LL); k < min(hi, mid+1); ++k) {
        ll here = dp[cur_j-1][k-1] + b[k] * (mid - k + 1);
        if (opt_k == -1 || here > opt) {
            opt_k = k;
            opt = here;
        }
    }


    dp[cur_j][mid] = opt;
    choice[cur_j][mid] = opt_k;

    rec(cur_j, l, mid, lo, opt_k + 1);
    rec(cur_j, mid+1, r, opt_k, hi);
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ind[i] = i;
    }
    sort(ind, ind+n, [&](auto i, auto j){
        return a[i] < a[j];
    });
    for (int id = 0; id < n; ++id) {
        b[id+1] = a[ind[id]];
    }
    for (ll i = 1; i <= n; ++i) {
        dp[1][i] = b[1] * i;
    }

    for (int j = 2; j <= l; ++j) {
        rec(j, 1, n + 1, 1, n + 1);
    }
    double ans = (double)dp[l][n] / (double)n;
    cout << setprecision(10) << fixed << ans << endl;
    int j = l;
    for (int ptr = n; ptr > 0; ) {
        int k = max(1LL, choice[j][ptr]);
        for (int i = k; i <= ptr; ++i) {
            ass[ind[i-1]] = j;
        }
        --j;
        ptr = k - 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ass[i] << " \n"[i==n-1];
    }
}
