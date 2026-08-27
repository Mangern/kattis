#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
template<typename t, size_t N>
using ar = array<t, N>;
using ii = ar<ll, 2>;
using vii = vector<ii>;
using vll = vector<ll>;

template<typename t>
istream& operator>>(istream& in, vector<t>& vec) {
    for (t& x : vec) {
        in >> x;
    }
    return in;
}

template<typename t>
ostream& operator<<(ostream& os, vector<t>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << " ";
    }
    return os;
}
#define all(v) begin(v), end(v)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (uint64_t)rng() % B;
}

template<typename t>
t min(const vector<t>& v) {
    return *min_element(all(v));
}

template<typename t>
t max(const vector<t>& v) {
    return *max_element(all(v));
}
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;
const int K = 18;

int n;
int p[K][mxN];
int depth[mxN];
vi adj[mxN];

void dfs(int u, int cf = -1) {
    for (int v : adj[u]) if (v != cf) {
        depth[v] = depth[u] + 1;
        p[0][v] = u;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])swap(u, v);
    int d = depth[v] - depth[u];
    for (int k = 0; k < K; ++k) if ((d>>k)&1)v = p[k][v];
    if (u == v) return u;

    for (int k = K - 1; k >= 0; --k) {
        if (p[k][u] != p[k][v]) {
            u = p[k][u];
            v = p[k][v];
        }
    }
    return p[0][u];
}

ll dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u,v)];
}

void testCase() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (int k = 1; k < K; ++k) for (int i = 0; i < n; ++i) {
        p[k][i] = p[k-1][p[k-1][i]];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; i * j <= n; ++j) {
            ans += dist(i-1, i*j-1) + 1;
        }
    }
    cout << ans << endl;
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
