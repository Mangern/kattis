#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 4;

struct frac {
    ll num, den;

    void reduce() {
        ll g = gcd(num,den);
        num /= g;
        den /= g;
    }
};

frac operator+(const ll &a, const frac &f) {
    frac res{a*f.den + f.num, f.den};
    res.reduce();
    return res;
}

bool operator<(const frac &f1, const frac &f2) {
    // a / b < c / d
    return f1.num * f2.den < f2.num * f1.den;
}

const int mxN = 2e5 + 5;

ll n, m, k;
vector<int> adj[mxN];
int isw[mxN];
vector<int> worm;
ll d1[mxN], dn[mxN];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int w;
        cin >> w, --w;

        isw[w] = 1;
        worm.push_back(w);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        d1[i] = INF;
        dn[i] = INF;
    }

    queue<int> q;
    d1[0] = 0;
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (d1[v] > d1[u] + 1) {
                d1[v] = d1[u] + 1;
                q.push(v);
            }
        }
    }

    dn[n - 1] = 0;
    q.push(n - 1);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dn[v] > dn[u] + 1) {
                dn[v] = dn[u] + 1;
                q.push(v);
            }
        }
    }

    frac ans{dn[0], 1};

    ll sworm = 0;
    for (int i : worm) {
        sworm += dn[i];
    }

    for (int i : worm) {
        frac cur = d1[i] + frac{(sworm - dn[i]), (k - 1)};
        if (cur < ans) {
            ans = cur;
        }
    }

    cout << ans.num << "/" << ans.den << endl;
}
