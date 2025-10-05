//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;
using vi = vector<int>;
using vll = vector<ll>;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x))


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    set<arr> isadj;
    vector<vi> radj(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        --u,--v;
        if (u == v) continue;
        isadj.insert({u, v});
        radj[v].push_back(u);
    }

    int ans = 0;
    int ansi = 1;
    for (int i = 0; i < n; ++i) {
        int sz = 0;
        for (int j : radj[i]) {
            if (!isadj.count({i, j}))++sz;
        }
        if (sz > ans) {
            ans = sz;
            ansi = i + 1;
        }
    }
    cout << ansi << " "<< ans << endl;
}
