#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mxN = 3e5+6;

int n;
ll a[mxN];
ll lb[mxN];
vi child[mxN];

void dfs1(int u) {
    lb[u] = max(1LL, a[u]);
    if (child[u].empty())return;
    bool alk = 1;
    ll sm = 0;
    for (int v : child[u]) {
        dfs1(v);
        if (a[v] == 0)alk = 0;
        else assert(a[v] == lb[v]);
        sm += lb[v];
    }

    if (alk) {
        if (a[u] != 0 && a[u] != sm) {
            cout << "impossible" << endl;
            exit(0);
        }
        a[u] = sm;
        lb[u] = sm;
    } else if (a[u] > 0) {
        lb[u] = a[u];
    } else {
        lb[u] = sm;
    }
}

void dfs2(int u) {
    if (a[u] > 0) {
        ll smk = 0;
        ll smuk = 0;
        int cnt = 0;
        for (int v : child[u]) {
            if (a[v] != 0)smk += a[v];
            else {
                smuk += lb[v];
                ++cnt;
            }
        }
        ll rem = a[u] - smk;
        if (smuk == rem) {
            for (int v : child[u]) if (a[v] == 0) {
                a[v] = lb[v];
            }
        } else if (cnt == 1) {
            for (int v : child[u]) if (a[v] == 0) {
                a[v] = rem;
            }
        }
    }
    for (int v : child[u])dfs2(v);
}

bool check(int u) {
    if (!a[u])return false;
    if (child[u].empty())return true;
    ll sm = 0;
    for (int v : child[u]) {
        if (!check(v))return false;
        sm += a[v];
    }
    return sm == a[u];
}

int main() {
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p, --p;
        child[p].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dfs1(0);
    dfs2(0);
    if (!check(0))cout << "impossible" << endl;
    else {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << endl;
        }
    }
}
