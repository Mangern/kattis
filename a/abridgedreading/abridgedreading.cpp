#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

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

ll modpow(ll x, ll y, ll m) {
    if (y == 0)return 1;
    ll r = modpow(x, y / 2, m);
    r = (r * r) % m;
    if (y & 1)r = (r * x) % m;
    return r;
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

    bool merge(int i, int j) {
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

const ll MOD = 1e9+7;

const int mxN = 3e4+3;

void testCase() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    cin >> a;

    const int K = 11;

    vector<vi> adj(n, vi());
    vector<vi> p(K, vi(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;

        adj[a].push_back(b);
        p[0][b] = a;
    }

    vi p_sum(n, 0);
    vi dep(n, 0);
    function<void(int, int, int)> dfs = [&] (int u, int cul, int d) {
        p_sum[u] = cul + a[u];
        dep[u] = d;
        for (auto v : adj[u])dfs(v, p_sum[u], d+1);
    };

    for (int i = 0; i < n; ++i) if (p[0][i] == -1) {
        dfs(i, 0, 0);
    }

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }

    function<int(int,int)> lca = [&] (int u, int v) {
        if (dep[u] > dep[v])swap(u,v);

        int dif = dep[v] - dep[u];
        for (int m = 0; m < K; ++m) {
            if (dif & (1<<m))v = p[m][v];
        }

        if (u == v)return u;

        for (int m = K - 1; m >= 0; --m) {
            if (p[m][u] != p[m][v]) {
                u = p[m][u];
                v = p[m][v];
            }
        }
        return p[0][v];
    };

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) if (adj[i].empty() && adj[j].empty()) {
            int l = lca(i,j);
            //cout << i+1 << " " << j+1 << " " << l+1 << " " << p_sum[i] << " " << p_sum[j] << endl;
            int sl;
            if (l == -1)sl = 0;
            else sl = p_sum[l];
            ans = min(ans, p_sum[i]+p_sum[j] - sl);
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
