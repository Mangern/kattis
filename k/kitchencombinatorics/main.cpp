#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll BIG = 1e18;

void many() {
    cout << "too many" << endl;
    exit(0);
}

int main() {
    ll r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;

    vector<ll> ways(r);
    for (auto &x : ways) cin >> x;

    vector<vector<int>> recipe(s+m+d);

    for (int i = 0; i < s+m+d; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int id;
            cin >> id, --id;
            recipe[i].push_back(id);
        }
    }

    vector<vector<bool>> incompat(s+m+d,vector<bool>(s+m+d,0));

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        incompat[u][v] = 1;
        incompat[v][u] = 1;
    }

    ll ans = 0;
    for (int a = 0; a < s; ++a) {
        for (int b = 0; b < m; ++b) {
            for (int c = 0; c < d; ++c) {
                int ia = a;
                int ib = s + b;
                int ic = s + m + c;
                if (incompat[ia][ib] || incompat[ia][ic] || incompat[ib][ic]) continue;

                set<int> ing;
                for (auto x : recipe[ia])ing.insert(x);
                for (auto x : recipe[ib])ing.insert(x);
                for (auto x : recipe[ic])ing.insert(x);

                ll cur = 1;
                for (int ir : ing) {
                    __int128 nxt = cur;
                    nxt *= ways[ir];
                    if (nxt > BIG - ans) {
                        many();
                    }
                    cur = nxt;
                }

                ans += cur;
                if (ans > BIG) many();
            }
        }
    }
    cout << ans << endl;
}
