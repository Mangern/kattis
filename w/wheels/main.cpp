#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b,a%b);
}

void reduce(ii& x) {
    auto &[a, b] = x;
    if (!a){
        b = 1;
        return;
    }
    ll g = gcd(a,b);
    a /= g;
    b /= g;
}

ii operator/(const ii& p1, const ii& p2) {
    auto [a, b] = p1;
    auto [c, d] = p2;
    // (a/b)/(c/d)
    // a*d/(b*c)
    ii ret = {a*d,b*c};
    reduce(ret);
    return ret;
}
ii operator*(const ii& p1, const ii& p2) {
    auto [a, b] = p1;
    auto [c, d] = p2;
    ii ret = {a*c,b*d};
    reduce(ret);
    return ret;
}

const int mxN = 1005;
ii pos[mxN];
ii rot[mxN];
ll r[mxN];
// 0: unvis, 1: cw, 2: ccw
int dir[mxN];
vector<int> adj[mxN];

void dfs(int u) {
    for (int v : adj[u]) {
        if (dir[v]) continue;
        dir[v] = (dir[u] == 1 ? 2 : 1);
        rot[v] = rot[u] * ii{r[u], 1} / ii{r[v], 1};
        dfs(v);
    }
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            cin >> pos[i][0] >> pos[i][1];
            cin >> r[i];
            rot[i] = {0,1};
            dir[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (i != j) {
                auto [xi, yi] = pos[i];
                auto [xj, yj] = pos[j];
                if ((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) == (r[i]+r[j])*(r[i]+r[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        dir[0] = 1;
        rot[0] = {1,1};
        dfs(0);

        for (int i = 0; i < n; ++i) {
            if (!dir[i]) {
                cout << "not moving\n";
            } else {
                cout << rot[i][0];
                if (rot[i][1] != 1) {
                    cout << "/" << rot[i][1];
                }
                cout << " " << (dir[i] == 1 ? "clockwise" : "counterclockwise") << '\n';
            }
        }
    }
}
