#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;
using ld = long double;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

// t should support min-function (operator <)
template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

// t should support max-function (operator <)
template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};
const int mxN = 3e4+3;

void testCase() {
    int n,m,p;
    cin >> n >> m >> p;

    vector<bool> insec(n,false);
    for (int i = 0; i < p; ++i) {
        int u;
        cin >> u, --u;
        insec[u] = 1;
    }

    UnionFind uf(n);
    using edge = ar<ll,3>;

    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        --edges[i][1];
        --edges[i][2];
    }

    if (n == 2 && p == 2) {
        cout << edges[0][0] << endl;
        return;
    }

    sort(all(edges));
    vector<vi> adj(n,vi());
    for (int i = 0; i < m; ++i) {
        if (insec[edges[i][1]] && insec[edges[i][2]])continue;
        int u = edges[i][1];
        if (!insec[u])u = edges[i][2];
        if (!insec[u])continue;
        adj[u].push_back(i);
    }

    ll sm = 0;
    for (auto [w,u,v] : edges) {
        if (insec[u] || insec[v])continue;
        if (uf.join(u,v))sm += w;
    }

    for (int u = 0; u < n; ++u) {
        if (!insec[u])continue;
        if (adj[u].empty())continue;

        ll mn = INFLL;
        int mini = -1;
        for (int e : adj[u]) {
            if (edges[e][0] < mn) {
                mn = edges[e][0];
                mini = e;
            }
        }
        assert(mini >= 0);
        uf.join(u,edges[mini][1]);
        uf.join(u,edges[mini][2]);
        sm += mn;
    }

    if (uf.num_sets > 1) {
        cout << "impossible" << endl;
        return;
    }
    cout << sm << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 1;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
