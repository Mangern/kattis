#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+45;

class Segtree {
    vector<ll> arr;
    vector<int> st;
    int n;

private:
    void build(int p, int l, int r) {
        if (l == r)st[p] = l;
        else {
            build(p<<1, l, (l+r)/2);
            build(p<<1|1, (l+r)/2+1, r);
            int p1 = st[p<<1];
            int p2 = st[p<<1|1];
            st[p] = (arr[p1] <= arr[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int l, int r, int i, int j) {
        if (i > r || j < l)return -1;
        if (i <= l && r <= j)return st[p];

        int p1 = rmq(p<<1, l, (l+r)/2, i, j);
        int p2 = rmq(p<<1|1, (l+r)/2+1, r, i, j);
        if (p1 == -1)return p2;
        if (p2 == -1)return p1;
        return (arr[p1] <= arr[p2]) ? p1 : p2;
    }

    int update(int p, int l, int r, int idx, ll val) {
        if (idx < l || r < idx)return st[p];
        if (l == idx && r == idx) {
            arr[idx] = val;
            st[p] = idx;
            return st[p];
        }

        int p1 = update(p<<1, l, (l+r)/2, idx, val);
        int p2 = update(p<<1|1, (l+r)/2+1, r, idx, val);

        st[p] = (arr[p1] <= arr[p2]) ? p1 : p2;
        return st[p];
    }

public:
    Segtree(int n) : n(n) {
        arr = vector<ll>(n, INT_MAX);
        st = vector<int>(4 * n, 0);

        build(1, 0, n - 1);
    }

    ll rmq(int i, int j) {
        return arr[rmq(1, 0, n - 1, i, j)];
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> d(n), g(m), p(m), r(k);
    for (auto& x : d)cin >> x;
    for (auto& x : g)cin >> x;
    for (auto& x : p)cin >> x;
    for (auto& x : r)cin >> x;

    vector<ll> dp(n+1, INT_MAX);
    Segtree dpseg(n+1);
    Segtree drseg(n+1);
    dp[0] = 0;

    dpseg.update(0, 0);


    vector<ll> pr;
    vector<ll> dr;
    int r_ptr = 0;
    for (int i = 1; i <= n; ++i) {
        if (r_ptr < k) {
            while (r_ptr < k && r[r_ptr] <= d[i-1]) {
                pr.push_back(r[r_ptr]);
                drseg.update(pr.size() - 1, dp[i-1]);
                ++r_ptr;
            }
        }
        //cout << "DAY: " << d[i-1] <<  endl;
        for (int j = 0; j < m; ++j) {
            ll dur = g[j];
            int dp_ptr = i;
            ll mdp = dp[dp_ptr];

            ll lower_day = d[i-1] - (g[j] - 1);

            size_t ld_idx = lower_bound(begin(d), end(d), lower_day) - begin(d);

            dp[i] = min(dp[i], dpseg.rmq(ld_idx, i - 1) + p[j]);

            if (pr.size()) {
                size_t pr_idx = lower_bound(begin(pr), end(pr), lower_day) - begin(pr);

                //cout << pr_idx << " " << pr.size() - 1 << endl;

                if (pr_idx <= pr.size() - 1) {
                    dp[i] = min(dp[i], drseg.rmq(pr_idx, pr.size() - 1) + p[j]/2);
                }
            }
            
        }
        dpseg.update(i, dp[i]);
    }

    cout << dp[n] << endl;

    return 0;
}
